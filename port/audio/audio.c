#include "audio.h"
#include "adx.h"
#include "resample.h"
#include "tsd.h"
#include "tsd_client.h"
#include <SDL.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

typedef struct Bgm {
    AdxStream adx;
    uint8_t *own;          /* owned ADX bytes */
    int stat;
    int paused;            /* ADXT_Pause */
    int loop;              /* ADXT_SetLpFlg */
    int mono;
    int carry;             /* ADX_LOOP_CARRY: PS2-exact loop history */
    int vol;               /* 0.1 dB */
    float gain, cur;       /* target / smoothed linear gain */
    RsStream rs;           /* ADX rate -> 48 kHz (passthrough at 48 kHz) */
    uint32_t played;
} Bgm;

static struct {
    int init;
    Tsd tsd;
    Bgm bgm;
    float master;
    SDL_AudioDeviceID dev;
    int dev_rate;
    RsStream out_rs;       /* 48 kHz -> device rate */
    AudioAfsLoader loader;
    void *loader_ctx;
    float *scratch;
    int scratch_n;
} A;

/* ---- locking ---- */
void audio_lock(void) { if (A.dev) SDL_LockAudioDevice(A.dev); }
void audio_unlock(void) { if (A.dev) SDL_UnlockAudioDevice(A.dev); }

/* ---- tsd_client sink: flush -> driver, status -> driver ---- */
static void sink_rpc(void *ctx, const uint8_t *buf, size_t n)
{
    (void)ctx;
    audio_lock();
    tsd_exec(&A.tsd, buf, n);
    audio_unlock();
}

static int sink_status(void *ctx, int fno, uint32_t arg)
{
    (void)ctx;
    audio_lock();
    int r = tsd_status(&A.tsd, fno, arg);
    audio_unlock();
    return r;
}

struct Tsd *audio_tsd(void) { return &A.tsd; }

/* ---- BGM ---- */
static float db10_to_gain(int v) { return v <= -999 ? 0.0f : powf(10.0f, v / 200.0f); }

static int bgm_pull(void *ctx, float *dst, int max)
{
    Bgm *b = (Bgm *)ctx;
    int16_t tmp[2 * 512];
    if (max > 512) max = 512;
    int n = adx_decode(&b->adx, tmp, max);
    int ch = b->adx.h.channels;
    for (int i = 0; i < n; i++) {
        float l = tmp[i * ch] * (1.0f / 32768.0f);
        float r = ch > 1 ? tmp[i * ch + 1] * (1.0f / 32768.0f) : l;
        dst[2 * i] = l;
        dst[2 * i + 1] = r;
    }
    if (n < max && b->adx.ended && b->stat == PADX_PLAYING) b->stat = PADX_PLAYEND;
    return n;
}

static void bgm_render(Bgm *b, float *out, int frames)
{
    if (b->stat != PADX_PLAYING || b->paused) return;
    if (A.scratch_n < frames) {
        free(A.scratch);
        A.scratch = (float *)malloc(sizeof(float) * 2 * frames);
        A.scratch_n = frames;
    }
    float *s = A.scratch;
    rs_stream_run(&b->rs, bgm_pull, b, s, frames);
    for (int i = 0; i < frames; i++) {
        if (b->cur != b->gain) {
            b->cur += (b->gain - b->cur) * (1.0f / 256);
            if (fabsf(b->cur - b->gain) < 1e-5f) b->cur = b->gain;
        }
        float l = s[2 * i], r = s[2 * i + 1];
        if (b->mono) l = r = 0.5f * (l + r);
        out[2 * i] += l * b->cur;
        out[2 * i + 1] += r * b->cur;
    }
    b->played += (uint32_t)frames;
}

static void bgm_free(Bgm *b)
{
    free(b->own);
    b->own = NULL;
    b->stat = PADX_STOP;
}

int padx_start_mem(const uint8_t *adx, size_t size, int take)
{
    audio_lock();
    Bgm *b = &A.bgm;
    bgm_free(b);
    if (take) b->own = (uint8_t *)adx;
    int r = adx_open_mem(&b->adx, adx, size, b->loop);
    if (r) {
        b->stat = PADX_ERROR;
    } else {
        b->adx.loop_mode = b->carry ? ADX_LOOP_CARRY : ADX_LOOP_RESTORE;
        rs_stream_init(&b->rs, b->adx.h.rate, AUDIO_RATE);
        b->stat = PADX_PLAYING; /* host decode is instant: DECINFO/PREP are skipped */
        b->played = 0;
    }
    audio_unlock();
    return r;
}

int padx_start_afs(int ptid, int fid)
{
    size_t n = 0;
    uint8_t *d = A.loader ? A.loader(A.loader_ctx, ptid, fid, &n) : NULL;
    if (!d) {
        audio_lock();
        bgm_free(&A.bgm);
        A.bgm.stat = PADX_ERROR;
        audio_unlock();
        return -1;
    }
    return padx_start_mem(d, n, 1);
}

void padx_stop(void) { audio_lock(); bgm_free(&A.bgm); audio_unlock(); }
int padx_get_stat(void) { return A.bgm.stat; }
void padx_set_out_vol(int vol)
{
    audio_lock();
    A.bgm.vol = vol;
    A.bgm.gain = db10_to_gain(vol);
    audio_unlock();
}
int padx_get_out_vol(void) { return A.bgm.vol; }
void padx_pause(int sw) { audio_lock(); A.bgm.paused = sw != 0; audio_unlock(); }
int padx_get_stat_pause(void) { return A.bgm.paused; }
void padx_set_lp_flg(int on)
{
    audio_lock();
    A.bgm.loop = on != 0;
    A.bgm.adx.loop = on && A.bgm.adx.h.has_loop;
    audio_unlock();
}
int padx_get_lp_cnt(void) { return (int)A.bgm.adx.loops; }
void padx_set_loop_carry(int carry) { audio_lock(); A.bgm.carry = carry != 0; A.bgm.adx.loop_mode = carry ? ADX_LOOP_CARRY : ADX_LOOP_RESTORE; audio_unlock(); }
void padx_set_output_mono(int mono) { audio_lock(); A.bgm.mono = mono != 0; audio_unlock(); }
uint32_t padx_get_time(void) { return A.bgm.played; }

/* ---- mixing ---- */
void audio_render(float *out, int frames)
{
    memset(out, 0, sizeof(float) * 2 * frames);
    tsd_render(&A.tsd, out, frames);
    bgm_render(&A.bgm, out, frames);
    float g = A.master;
    for (int i = 0; i < 2 * frames; i++) {
        float x = out[i] * g;
        out[i] = x > 1.0f ? 1.0f : x < -1.0f ? -1.0f : x;
    }
}

static int pull48(void *ctx, float *dst, int max)
{
    (void)ctx;
    audio_render(dst, max);
    return max;
}

static void SDLCALL device_cb(void *ud, Uint8 *stream, int len)
{
    (void)ud;
    float *out = (float *)stream;
    int frames = len / (int)(2 * sizeof(float));
    if (A.dev_rate == AUDIO_RATE) audio_render(out, frames);
    else rs_stream_run(&A.out_rs, pull48, NULL, out, frames);
}

void audio_set_master(float g) { audio_lock(); A.master = g; audio_unlock(); }
int audio_device_rate(void) { return A.dev ? A.dev_rate : 0; }

#ifdef __EMSCRIPTEN__
/* SDL2 creates Module.SDL2.audioContext; browsers start it 'suspended' until a
 * user gesture. Resume it from the first pointer/touch/key event (inside the
 * event handler, which iOS requires) and start a 1-sample silent buffer. */
EM_JS(void, web_install_unlock, (void), {
    if (Module.__audioUnlock) return;
    var unlock = function() {
        var s = Module['SDL2'];
        var ctx = s && s.audioContext;
        if (!ctx || ctx.state === 'running') return;
        ctx.resume();
        try {
            var buf = ctx.createBuffer(1, 1, ctx.sampleRate);
            var src = ctx.createBufferSource();
            src.buffer = buf;
            src.connect(ctx.destination);
            src.start(0);
        } catch (e) {}
    };
    Module.__audioUnlock = unlock;
    ['pointerdown', 'touchend', 'mousedown', 'keydown'].forEach(function(t) {
        window.addEventListener(t, unlock, { capture: true, passive: true });
    });
});

EM_JS(int, web_running, (void), {
    var s = Module['SDL2'];
    return (s && s.audioContext && s.audioContext.state === 'running') ? 1 : 0;
});

EM_JS(void, web_suspend, (int paused), {
    var s = Module['SDL2'];
    var ctx = s && s.audioContext;
    if (!ctx) return;
    if (paused) { ctx.suspend(); return; }
    var ua = navigator.userActivation;
    if (ua === undefined || ua.hasBeenActive) ctx.resume();
});
#endif

int audio_unlocked(void)
{
#ifdef __EMSCRIPTEN__
    return web_running();
#else
    return 1;
#endif
}

void audio_set_paused(int paused)
{
    if (!A.dev) return;
    SDL_PauseAudioDevice(A.dev, paused);
#ifdef __EMSCRIPTEN__
    web_suspend(paused);
#endif
}

void audio_set_loader(AudioAfsLoader fn, void *ctx) { A.loader = fn; A.loader_ctx = ctx; }

int audio_init(int open_device)
{
    if (A.init) return 0;
    memset(&A, 0, sizeof A);
    rs_init();
    tsd_init(&A.tsd);
    A.tsd.resolve = tsdc_resolve;
    A.master = 1.0f;
    A.bgm.loop = 1;
    A.bgm.gain = A.bgm.cur = 1.0f;
    TsdcSink sink = { sink_rpc, sink_status, NULL };
    tsdc_set_sink(&sink);
    tsdc_init();
    A.init = 1;
    if (!open_device) return 0;
    if (SDL_InitSubSystem(SDL_INIT_AUDIO) != 0) {
        SDL_Log("audio: SDL_InitSubSystem(AUDIO): %s", SDL_GetError());
        return -1;
    }
    SDL_AudioSpec want, have;
    SDL_zero(want);
    want.freq = AUDIO_RATE;
    want.format = AUDIO_F32SYS;
    want.channels = 2;
#ifdef __EMSCRIPTEN__
    want.samples = 2048; /* ScriptProcessorNode runs on the main thread: keep headroom */
#else
    want.samples = 512;
#endif
    want.callback = device_cb;
    A.dev = SDL_OpenAudioDevice(NULL, 0, &want, &have, SDL_AUDIO_ALLOW_FREQUENCY_CHANGE);
    if (!A.dev) {
        SDL_Log("audio: SDL_OpenAudioDevice: %s", SDL_GetError());
        return -1;
    }
    A.dev_rate = have.freq;
    rs_stream_init(&A.out_rs, AUDIO_RATE, have.freq);
#ifdef __EMSCRIPTEN__
    web_install_unlock();
#endif
    SDL_PauseAudioDevice(A.dev, 0);
    SDL_Log("audio: %d Hz, %d frames/buffer%s", have.freq, have.samples,
            have.freq == AUDIO_RATE ? "" : " (resampled from 48 kHz)");
    return 0;
}

void audio_shutdown(void)
{
    if (!A.init) return;
    if (A.dev) SDL_CloseAudioDevice(A.dev);
    A.dev = 0;
    tsdc_set_sink(NULL);
    tsd_shutdown(&A.tsd);
    bgm_free(&A.bgm);
    free(A.scratch);
    A.scratch = NULL;
    A.init = 0;
}
