/*
 * Frontend audio (Port J): the game's two sound boundaries bound to the
 * port's audio engine (port/audio).
 *
 *  - Sound effects / voices: the game's Tamsoft client (func_00422CC0 ..
 *    func_00423990, forwarded to port/audio/tsd_client.c by tsd_host.c)
 *    flushes its packets into the engine's TSD driver: audio_init() installs
 *    that sink.  Bank addresses in the packets are host pointers into the
 *    game's own memory (tsdc_resolve).
 *  - Music: CRI ADXT (cri.c) calls host_adxt_ops = the engine's padx_*
 *    player, which streams the AFS entry (loaded through the disc).
 *
 * Natively the SDL audio device renders; on the web the engine's Web Audio
 * output (AudioWorklet) is fed by fe_audio_pump() once per display frame.
 * Without either (the headless captures, or a web page still waiting for
 * the first click) fe_audio_frame() renders one frame's worth of samples
 * itself, so the music player's status still advances as on hardware.
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../host.h"
#include "../host_cri.h"
#include "../../audio/audio.h"
#include "../../audio/dcse.h"
#include "../../audio/wav.h"
#include "../../platform/settings.h"
#include <string.h>

static int have_device;

static uint8_t *afs_loader(void *ctx, int ptid, int fid, size_t *size)
{
    GameDisc *d = host_disc();
    (void)ctx;
    if (!d || ptid < 0 || ptid > 3 || !d->afs_ok[ptid])
        return NULL;
    return disc_load(d, ptid, fid, size);
}

static int ops_start_afs(int ptid, int fid) { return padx_start_afs(ptid, fid); }
static void ops_stop(void) { padx_stop(); }
static int ops_get_stat(void) { return padx_get_stat(); }
static void ops_set_out_vol(int vol) { padx_set_out_vol(vol); }
static void ops_pause(int sw) { padx_pause(sw); }
static void ops_set_mono(int mono) { padx_set_output_mono(mono); }

static const HostAdxtOps ops = {
    ops_start_afs, ops_stop, ops_get_stat, ops_set_out_vol, ops_pause, ops_set_mono, NULL,
};

/* The Dreamcast common effects (port/audio/dcse.h), from the user's own
 * Dreamcast disc: MVC2_DC_DISC, else audio.dc_disc (set by --dc-disc); on
 * the web the page writes SE_COMN.BIN to /dc_se_comn.bin. */
#ifdef __EMSCRIPTEN__
#define DC_WEB_FILE "/dc_se_comn.bin"
#endif
static int dc_effects_load(const char *path)
{
    size_t n = 0;
    uint8_t *d = dcse_read_disc(path, &n);
    int k = d ? dcse_load(d, n) : -1;
    free(d);
    if (k > 0)
        host_log("audio: %d common sound effects from the Dreamcast disc (%s)", k, path);
    else
        host_log("audio: %s: %s", path, d ? "not the known Dreamcast SE_COMN.BIN; PS2 effects kept"
                                          : "no Dreamcast SE_COMN.BIN there; PS2 effects kept");
    return k;
}

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
/* the page wrote a new /dc_se_comn.bin: use it now, also in loaded banks */
EMSCRIPTEN_KEEPALIVE int fe_dc_effects_js(void)
{
    int k = dc_effects_load(DC_WEB_FILE);
    if (k > 0) audio_dcse_refresh();
    return k;
}
#endif

int fe_audio_init(int open_device)
{
    if (getenv("MVC2_NO_AUDIO"))
        return 0;
    if (audio_init(open_device) != 0) {
        host_log("audio: no device; rendering headless");
        if (audio_init(0) != 0)
            return -1;
    } else {
        have_device = open_device && audio_device_rate() > 0;
    }
    audio_set_loader(afs_loader, NULL);
    host_adxt_ops = &ops;
    {
        const char *dc = getenv("MVC2_DC_DISC");
        if (!dc || !*dc) dc = settings_get("audio.dc_disc");
#ifdef DC_WEB_FILE
        FILE *f = fopen(DC_WEB_FILE, "rb");
        if (f) { fclose(f); dc = DC_WEB_FILE; }
#endif
        if (dc && *dc) dc_effects_load(dc);
    }
    host_log("audio: port engine bound (TSD sink + ADXT -> padx), %s",
             have_device ? "audio device" : "headless");
    return 0;
}

/* MVC2_AUDIO_WAV=path (headless): the rendered mix is also written there
 * (at exit, fe_audio_shutdown) as evidence that the game's sound plays. */
static float *rec;
static int rec_frames, rec_cap;

void fe_audio_frame(void)
{
    static float buf[(AUDIO_RATE / 60 + 1) * 2];
    static int rec_on = -1;
    if (host_adxt_ops != &ops || !audio_needs_manual_render())
        return; /* a device (SDL callback / Web Audio pump) pulls the samples */
    audio_render(buf, AUDIO_RATE / 60);
    if (rec_on < 0)
        rec_on = getenv("MVC2_AUDIO_WAV") != NULL;
    if (rec_on) {
        if (rec_frames + AUDIO_RATE / 60 > rec_cap) {
            rec_cap = rec_cap ? rec_cap * 2 : AUDIO_RATE * 60;
            rec = (float *)realloc(rec, (size_t)rec_cap * 2 * sizeof(float));
        }
        memcpy(rec + rec_frames * 2, buf, (size_t)(AUDIO_RATE / 60) * 2 * sizeof(float));
        rec_frames += AUDIO_RATE / 60;
    }
}

void fe_audio_shutdown(void)
{
    const char *p = getenv("MVC2_AUDIO_WAV");
    if (p && rec_frames) {
        double e = 0;
        int i;
        for (i = 0; i < rec_frames * 2; i++)
            e += (double)rec[i] * rec[i];
        wav_write_float_stereo(p, rec, rec_frames, AUDIO_RATE);
        host_log("audio: wrote %s (%d frames, rms %.4f)", p, rec_frames, rec_frames ? sqrt(e / (rec_frames * 2)) : 0.0);
    }
}

void fe_audio_pump(double ahead_s)
{
    if (host_adxt_ops == &ops)
        audio_pump(ahead_s);
}

void fe_audio_pause(int paused)
{
    if (host_adxt_ops == &ops)
        audio_set_paused(paused);
}
