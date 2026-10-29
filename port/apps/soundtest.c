/* Sound test for the port audio layer (port/audio/).
 *
 *   soundtest [--iso PATH] [--track N] [--bank B] [--sound S] [--slot K]
 *             [--render OUT.wav --seconds T] [--no-loop] [--mono]
 *             [--decode-adx N OUT.wav] [--verify PYDIR] [--loop-check OUT.txt]
 *             [--frames N]   (interactive: quit after N frames)
 *
 * Interactive (window; keyboard, controller or the touch pad):
 *   UP/DOWN      AFS00 track -/+          LP (A key / Square)  play track
 *   LEFT/RIGHT   sound id -/+             LK (Z key / Cross)   play sound
 *   HP (S/Tri)   AFS01 bank +1            HK (X key / Circle)  bank -1
 *   START        stop everything          keyboard: M mono, L loop, H touch pad, Esc quit
 * Sounds play through the game's own client boundary (tsd_client.h) the way
 * func_001E59E0 does: EE table from block [3] of the bank (layered entries,
 * fixed pan), then tsdc_play(bank << 16 | sound << 8 | 1, -1, pan, -1) and a flush.
 *
 * Headless modes need no window:
 *   --render       mixes the chosen track and/or sound for T seconds at 48 kHz
 *   --decode-adx   straight ADX decode (first pass, native rate) for comparison
 *   --verify DIR   compares the C decoders with adx.py / hdbd.py WAVs in DIR
 *   --loop-check   checks every AFS00 loop through the port's ADX player
 */
#include "../audio/adx.h"
#include "../audio/audio.h"
#include "../audio/hdbank.h"
#include "../audio/tsd.h"
#include "../audio/tsd_client.h"
#include "../audio/vag.h"
#include "../audio/wav.h"
#include "../platform/fs.h"
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef SOUNDTEST_HEADLESS_ONLY
#include "../platform/platform.h"
#include "../render/render.h"
#include <SDL.h>
#endif
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

/* D_004B6A70: BGM id -> AFS00 file (48 entries); stage s plays BGM id s (func_00171700) */
static const int BGM_FILE[48] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 0, 1, 11, 3, 4, 5, 6, 7, 9, 10, 13, 14, 12, 15, 16,
                                  17, 18, 19, 20, 21, 22, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
/* D_0044F1C0: screen x / 40 -> pan */
static const int PAN_TAB[16] = { 0, 12, 24, 36, 44, 52, 58, 64, 64, 70, 76, 84, 92, 104, 116, 127 };

static struct {
    GameDisc disc;
    int have_disc;
    int track, bank, sound, slot;
    int loaded_bank;          /* AFS01 index in `slot`, -1 none */
    int n_tracks, n_banks;
    uint8_t ee_tbl[8][512];   /* D_004CC150 per slot (func_001E5710) */
    int mono, loop;
    int quit_after;           /* --frames N: quit after N frames (smoke tests) */
    char status[160];
    uint32_t font_tex;
#ifndef SOUNDTEST_HEADLESS_ONLY
    PadEdge pad;
#endif
} T;

static void say(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(T.status, sizeof T.status, fmt, ap);
    va_end(ap);
    fprintf(stderr, "soundtest: %s\n", T.status);
}

static uint8_t *afs_loader(void *ctx, int ptid, int fid, size_t *n)
{
    (void)ctx;
    return T.have_disc ? disc_load(&T.disc, ptid, fid, n) : NULL;
}

static int open_disc(const char *path)
{
    if (T.have_disc) disc_close(&T.disc);
    T.have_disc = 0;
    if (disc_open(&T.disc, path) || !T.disc.afs_ok[0] || !T.disc.afs_ok[1]) {
        say("could not open %s", path);
        return -1;
    }
    T.have_disc = 1;
    T.n_tracks = T.disc.afs[0].count;
    T.n_banks = T.disc.afs[1].count;
    T.loaded_bank = -1;
    say("disc: %s", path);
    return 0;
}
#ifdef __EMSCRIPTEN__
EMSCRIPTEN_KEEPALIVE int viewer_open_js(const char *path) { return open_disc(path); } /* shared web shell */
#endif

static uint32_t le32(const uint8_t *p) { return (uint32_t)p[0] | (uint32_t)p[1] << 8 | (uint32_t)p[2] << 16 | (uint32_t)p[3] << 24; }

static int default_slot(int bank) { return bank == 59 ? 6 : bank == 60 ? 7 : bank >= 61 ? 5 : 0; }

/* func_001E5870 / func_001E5710: upload an AFS01 bank into a slot and build the EE table */
static int load_bank(int bank, int slot)
{
    size_t n;
    uint8_t *d = disc_load(&T.disc, 1, bank, &n);
    if (!d || n < 0x40) { free(d); return -1; }
    uint32_t o[4], s[4];
    for (int i = 0; i < 4; i++) { o[i] = le32(d + 8 * i); s[i] = le32(d + 8 * i + 4); }
    uint8_t *e = T.ee_tbl[slot];
    memset(e, 0, 512);
    const uint8_t *src = d + o[3];
    for (uint32_t i = 0; i < 0x80 && i < (s[3] >> 4); i++) {
        e[4 * i] = 1;
        e[4 * i + 1] = src[4];
        e[4 * i + 2] = src[0xE];
        e[4 * i + 3] = src[3];
        while (src[3] != 0 && src + 16 < d + o[3] + s[3]) src += 16;
        src += 16;
    }
    int before = tsdc_status((int)0x8000000C, 1);
    tsdc_load_bank_ptr((uint32_t)slot, d + o[0], (int32_t)s[0], d + o[1], (int32_t)s[1], d + o[2], (int32_t)s[2]);
    tsdc_flush(1);
    int after = tsdc_status((int)0x8000000C, 1);
    free(d); /* the driver copied it during the flush (the IOP's DMA) */
    if (after == before) return -1;
    T.loaded_bank = bank;
    return 0;
}

/* func_001E59E0 without the per-character voice-cut rules */
static void play_sound(int slot, int sound, int pan_idx)
{
    const uint8_t *e = T.ee_tbl[slot] + 4 * sound;
    for (int k = sound; k < 0x80; k++, e += 4) {
        if (e[0] == 1) {
            int pan = (e[1] & 0x80) ? (e[1] & 0x7F) : PAN_TAB[pan_idx & 15];
            tsdc_play((uint32_t)(slot & 0x7F) << 16 | (uint32_t)(k & 0x7F) << 8 | 1, -1, (int8_t)pan, -1);
        }
        if (e[3] == 0) break;
    }
    tsdc_flush(0);
}

static int start_track(int t)
{
    padx_set_lp_flg(T.loop);
    padx_set_output_mono(T.mono);
    return padx_start_afs(0, t);
}

static void select_bank(void)
{
    T.slot = default_slot(T.bank);
    if (load_bank(T.bank, T.slot)) say("bank %d failed to load", T.bank);
    else {
        HdBank *b = &audio_tsd()->port[T.slot].bank;
        say("bank %d -> slot %d, %d sounds", T.bank, T.slot, b->tq_num);
    }
}

/* ---------------- headless tools ---------------- */
static int decode_adx(int idx, const char *out)
{
    size_t n;
    uint8_t *d = disc_load(&T.disc, 0, idx, &n);
    if (!d) return -1;
    AdxStream s;
    if (adx_open_mem(&s, d, n, 0)) { free(d); return -1; }
    int ch = s.h.channels;
    int16_t *pcm = (int16_t *)malloc(sizeof(int16_t) * ch * (size_t)s.h.total);
    int got = adx_decode(&s, pcm, (int)s.h.total);
    int r = wav_write16(out, pcm, got, ch, (int)s.h.rate, s.h.has_loop ? (long)s.h.loop_start : 0,
                        s.h.has_loop ? (long)s.h.loop_end - 1 : -1);
    fprintf(stderr, "soundtest: %s: %d ch %u Hz %d samples\n", out, ch, s.h.rate, got);
    free(pcm);
    free(d);
    return r;
}

static int verify(const char *dir)
{
    char path[512];
    int bad = 0, files = 0;
    /* ADX: every afs00_NN.wav */
    for (int i = 0; i < T.n_tracks; i++) {
        snprintf(path, sizeof path, "%s/afs00_%02d.wav", dir, i);
        int fr, ch, rate;
        int16_t *ref = wav_read16(path, &fr, &ch, &rate);
        if (!ref) continue;
        size_t n;
        uint8_t *d = disc_load(&T.disc, 0, i, &n);
        AdxStream s;
        adx_open_mem(&s, d, n, 0);
        int16_t *pcm = (int16_t *)malloc(sizeof(int16_t) * s.h.channels * (size_t)s.h.total);
        int got = adx_decode(&s, pcm, (int)s.h.total);
        long diff = 0, first = -1;
        if (got != fr || ch != s.h.channels) diff = -1;
        else
            for (long k = 0; k < (long)fr * ch; k++)
                if (pcm[k] != ref[k]) { if (first < 0) first = k; diff++; }
        printf("adx afs00_%02d: %d frames x %d ch: %s", i, got, s.h.channels,
               diff == 0 ? "sample-exact\n" : "MISMATCH");
        if (diff) { printf(" (%ld samples differ, first %ld; ref %d frames)\n", diff, first, fr); bad++; }
        files++;
        free(pcm); free(ref); free(d);
    }
    /* VAG: afs01_BB/vagNNN.wav */
    for (int b = 0; b < T.n_banks; b++) {
        size_t n;
        snprintf(path, sizeof path, "%s/afs01_%02d/vag000.wav", dir, b);
        FILE *probe = fopen(path, "rb");
        if (!probe) continue;
        fclose(probe);
        uint8_t *d = disc_load(&T.disc, 1, b, &n);
        HdBank bank;
        if (hd_bank_load_afs01(&bank, d, n)) { free(d); continue; }
        int vb = 0, vn = 0;
        for (int v = 0; v < bank.nvag; v++) {
            snprintf(path, sizeof path, "%s/afs01_%02d/vag%03d.wav", dir, b, v);
            int fr, ch, rate;
            int16_t *ref = wav_read16(path, &fr, &ch, &rate);
            if (!ref) continue;
            const VagPcm *p = &bank.vag[v];
            int ok = p->pcm && fr == p->first_len && (uint32_t)rate == p->rate &&
                     !memcmp(ref, p->pcm, sizeof(int16_t) * (size_t)fr);
            if (!ok) {
                vb++;
                if (vb <= 3) printf("vag afs01_%02d/%03d MISMATCH (ref %d, C %d)\n", b, v, fr, p->first_len);
            }
            vn++;
            free(ref);
        }
        printf("vag afs01_%02d: %d/%d samples sample-exact\n", b, vn - vb, vn);
        bad += vb;
        files += vn;
        hd_bank_free(&bank);
        free(d);
    }
    printf("verify: %d files, %d mismatches\n", files, bad);
    return bad ? 1 : 0;
}

/* stage s -> BGM id s -> file BGM_FILE[s]; which files are stage music */
static const char *uses(int f, char *buf, size_t n)
{
    buf[0] = 0;
    size_t k = 0;
    for (int s = 0; s < 17; s++)
        if (BGM_FILE[s] == f) k += (size_t)snprintf(buf + k, n - k, "%sstage %d", k ? ", " : "", s);
    return buf;
}

static int loop_check(const char *out)
{
    FILE *f = out ? fopen(out, "w") : stdout;
    if (!f) return -1;
    int problems = 0;
    fprintf(f, "AFS00 loop check through the port ADX player (port/audio/adx.c)\n");
    fprintf(f, "seam = |x[loopEnd-1] - x[loopStart]| (restore mode), typ = mean |x[n]-x[n-1]| of the track;\n"
               "restore = loop 2 vs loop 1 with the loop-start history restored (port default);\n"
               "carry = PS2/CRI behaviour: samples that differ after the jump, max |diff|, length of the transient;\n"
               "ADXT = port player at 48 kHz for loopEnd + 2 loops: stat and loop count.\n");
    fprintf(f, "trk ch rate  total    lpStart  lpEnd    sB  eB    seam    typ  restore    carry:n   max   len  ADXT     loops stage use\n");
    for (int i = 0; i < T.n_tracks; i++) {
        size_t n;
        uint8_t *d = disc_load(&T.disc, 0, i, &n);
        AdxHeader h;
        char ubuf[96];
        if (!d || adx_parse_header(d, n, &h)) { fprintf(f, "%2d unreadable\n", i); problems++; free(d); continue; }
        const int fsz = h.block * h.channels, spf = (h.block - 2) * 2;
        if (!h.has_loop) {
            /* one-shot: must end with PLAYEND after `total` samples */
            AdxStream s;
            adx_open_mem(&s, d, n, 1);
            int16_t buf[2 * 4096];
            long tot = 0;
            int g;
            while ((g = adx_decode(&s, buf, 4096)) > 0) tot += g;
            fprintf(f, "%2d %d %5u %8u  no loop: one-shot, %ld samples, ends with PLAYEND            %s\n", i, h.channels,
                    h.rate, h.total, tot, uses(i, ubuf, sizeof ubuf));
            if (tot != (long)h.total) problems++;
            free(d);
            continue;
        }
        int sb_ok = h.loop_start_byte == h.data_off + (h.loop_start / spf) * fsz;
        int eb_ok = h.loop_end_byte <= n && h.loop_end <= h.total && h.loop_start < h.loop_end;
        /* decode to loopEnd plus one more loop, in both history modes */
        long L = (long)(h.loop_end - h.loop_start);
        long need = (long)h.loop_end + L;
        long cd[2] = { 0, 0 }, cmax[2] = { 0, 0 }, clast[2] = { -1, -1 };
        double seam = 0, typ = 0;
        for (int mode = 0; mode < 2; mode++) {
            int16_t *pcm = (int16_t *)malloc(sizeof(int16_t) * h.channels * (size_t)need);
            AdxStream s;
            adx_open_mem(&s, d, n, 1);
            s.loop_mode = mode;
            long got = adx_decode(&s, pcm, (int)need);
            if (mode == 0) {
                /* seam: last sample of the loop -> first sample after the jump */
                for (int c = 0; c < h.channels; c++) {
                    long a = ((long)h.loop_end - 1) * h.channels + c, b = (long)h.loop_end * h.channels + c;
                    double dlt = fabs((double)pcm[b] - pcm[a]);
                    if (dlt > seam) seam = dlt;
                }
                double acc = 0;
                long cnt = 0;
                for (long k = h.channels; k < (long)h.loop_end * h.channels; k += 97, cnt++)
                    acc += fabs((double)pcm[k] - pcm[k - h.channels]);
                typ = cnt ? acc / cnt : 0;
            }
            /* second pass vs first pass over the loop body */
            for (long k = 0; k < L * h.channels && (long)h.loop_end * h.channels + k < got * h.channels; k++) {
                long dd = labs((long)pcm[(long)h.loop_end * h.channels + k] - pcm[(long)h.loop_start * h.channels + k]);
                if (dd) { cd[mode]++; clast[mode] = k / h.channels; if (dd > cmax[mode]) cmax[mode] = dd; }
            }
            free(pcm);
        }
        /* the ADXT shim: play 2 loops at 48 kHz, stat must stay PLAYING and the tail must not be silent */
        padx_set_lp_flg(1);
        padx_set_out_vol(0);
        padx_start_mem(d, n, 1); /* takes d */
        long frames = (long)((double)(h.loop_end + 2 * L + 4800) * AUDIO_RATE / h.rate);
        static float blk[2 * 4800];
        double tail = 0;
        int stat_ok = 1;
        for (long k = 0; k < frames; k += 4800) {
            int m = (int)(frames - k < 4800 ? frames - k : 4800);
            audio_render(blk, m);
            if (padx_get_stat() != PADX_PLAYING) stat_ok = 0;
            if (k + 3 * 4800 >= frames)
                for (int j = 0; j < 2 * m; j++) tail += blk[j] * blk[j];
        }
        int loops = padx_get_lp_cnt();
        padx_stop();
        int ok = sb_ok && eb_ok && stat_ok && loops >= 2 && tail > 0 && cd[0] == 0;
        if (!ok) problems++;
        fprintf(f, "%2d %d %5u %8u %8u %8u %-3s %-3s %6.0f %6.0f  %-9s  %5ld %6ld %5ld  %s %d  %s\n",
                i, h.channels, h.rate, h.total, h.loop_start, h.loop_end, sb_ok ? "yes" : "NO", eb_ok ? "yes" : "NO",
                seam, typ, cd[0] ? "DIFFERS" : "identical", cd[1], cmax[1], clast[1] + 1,
                stat_ok ? "PLAYING" : "STOPPED", loops, uses(i, ubuf, sizeof ubuf));
    }
    fprintf(f, "problems: %d\n", problems);
    if (f != stdout) fclose(f);
    return problems ? 1 : 0;
}

static int render(const char *out, double seconds, int track, int bank, int sound)
{
    long frames = (long)(seconds * AUDIO_RATE);
    float *pcm = (float *)malloc(sizeof(float) * 2 * (size_t)frames);
    if (!pcm) return -1;
    if (track >= 0 && start_track(track)) fprintf(stderr, "soundtest: track %d failed\n", track);
    if (bank >= 0) {
        T.bank = bank;
        if (T.slot < 0) T.slot = default_slot(bank);
        if (load_bank(bank, T.slot)) { fprintf(stderr, "soundtest: bank %d failed\n", bank); }
        else if (sound >= 0) play_sound(T.slot, sound, 8);
    }
    for (long k = 0; k < frames; k += 1024) {
        int m = (int)(frames - k < 1024 ? frames - k : 1024);
        audio_render(pcm + 2 * k, m);
    }
    int r = wav_write_float_stereo(out, pcm, (int)frames, AUDIO_RATE);
    fprintf(stderr, "soundtest: wrote %s (%.2f s, 48 kHz stereo)\n", out, seconds);
    free(pcm);
    return r;
}

/* ---------------- interactive ---------------- */
#ifndef SOUNDTEST_HEADLESS_ONLY
static void update(void *u)
{
    (void)u;
    if (T.quit_after > 0 && --T.quit_after == 0) plat_request_quit();
    pad_edge_update(&T.pad, pad_game_word(plat_pad(0)));
    uint16_t p = T.pad.pressed;
    if (!T.have_disc) { if (plat_key_hit(SDL_SCANCODE_ESCAPE)) plat_request_quit(); return; }
    if (p & 0x2000) T.track = (T.track + T.n_tracks - 1) % T.n_tracks;   /* UP */
    if (p & 0x1000) T.track = (T.track + 1) % T.n_tracks;                 /* DOWN */
    int nsnd = audio_tsd()->port[T.slot].loaded ? audio_tsd()->port[T.slot].bank.tq_num : 1;
    if (nsnd < 1) nsnd = 1;
    if (p & 0x0800) T.sound = (T.sound + nsnd - 1) % nsnd;               /* LEFT */
    if (p & 0x0400) T.sound = (T.sound + 1) % nsnd;                       /* RIGHT */
    if (p & 0x0200) { if (start_track(T.track)) say("track %d failed", T.track); else say("track %d", T.track); } /* LP */
    if (p & 0x0040) {                                                     /* LK */
        if (T.loaded_bank != T.bank) select_bank();
        play_sound(T.slot, T.sound, 8);
    }
    if (p & 0x0100) { T.bank = (T.bank + 1) % T.n_banks; T.sound = 0; select_bank(); } /* HP */
    if (p & 0x0020) { T.bank = (T.bank + T.n_banks - 1) % T.n_banks; T.sound = 0; select_bank(); } /* HK */
    if (p & 0x8000) { padx_stop(); tsdc_stop_all(); tsdc_flush(0); say("stopped"); } /* START */
    if (plat_key_hit(SDL_SCANCODE_M)) { T.mono = !T.mono; padx_set_output_mono(T.mono); tsdc_set_stereo(!T.mono); tsdc_flush(0); }
    if (plat_key_hit(SDL_SCANCODE_L)) { T.loop = !T.loop; padx_set_lp_flg(T.loop); }
    if (plat_key_hit(SDL_SCANCODE_H)) plat_set_touch_visible(!plat_touch()->visible);
    if (plat_key_hit(SDL_SCANCODE_ESCAPE)) plat_request_quit();
}

static void text(float x, float y, const char *str, uint32_t argb)
{
    /* FONT8_8.TM2 (128x64, 8x8 ASCII cells) through the fl quad path, as the viewer does */
    if (!T.font_tex) return;
    fl_set_render_state(4, T.font_tex);
    for (; *str; str++, x += 8) {
        int c = (unsigned char)*str & 0x7F;
        float u0 = (c % 16) * 8 / 128.f, v0 = (c / 16) * 8 / 64.f, u1 = u0 + 8 / 128.f, v1 = v0 + 8 / 64.f;
        FlQuad q;
        memset(&q, 0, sizeof q);
        float xs[4] = { x, x + 8, x, x + 8 }, ys[4] = { y, y, y + 8, y + 8 };
        float us[4] = { u0, u1, u0, u1 }, vs[4] = { v0, v0, v1, v1 };
        for (int k = 0; k < 3; k++) {
            q.t[0].v[k] = (FlVec4){ xs[k], ys[k], 0, 1 };
            q.t[0].argb[k] = argb;
            q.t[0].uv[k][0] = us[k]; q.t[0].uv[k][1] = vs[k];
        }
        q.t[1].v[2] = (FlVec4){ xs[3], ys[3], 0, 1 };
        q.t[1].argb[2] = argb;
        q.t[1].uv[2][0] = us[3]; q.t[1].uv[2][1] = vs[3];
        fl_quad_tex(&q);
    }
}

static void draw_touch(int W, int H)
{
    TouchPad *t = plat_touch();
    if (!t->visible) return;
    if (t->w != W || t->h != H) touch_layout(t, W, H);
    r_overlay_begin(W, H);
    r_overlay_disc(t->dcx, t->dcy, t->dr, 0x40FFFFFF);
    for (int k = 0; k < TB_COUNT; k++)
        r_overlay_disc(t->b[k].cx, t->b[k].cy, t->b[k].r, t->b[k].held ? 0xC0FFFFFF : 0x60FFFFFF);
    r_overlay_end();
}

static void render_frame(void *u)
{
    (void)u;
    int W, H;
    plat_drawable_size(&W, &H);
    if (!T.font_tex && T.have_disc) {
        size_t n;
        uint8_t *f = iso_load(&T.disc.iso, "/FONT8_8.TM2", &n);
        if (f) { T.font_tex = fl_tex_load_tim2(f, n, 0); free(f); }
    }
    fl_frame_begin();
    fl_set_clear_color(0xFF101018);
    fl_fill_screen(1, 0xFF101018);
    char b[128];
    float y = 40;
    text(40, y, "MvC2 port sound test", 0xFFFFFFFF); y += 20;
    if (!T.have_disc) { text(40, y, "no disc image (--iso PATH / file picker)", 0xFFFF8080); }
    else {
        int fid = T.track;
        char ub[96];
        snprintf(b, sizeof b, "track  AFS00 #%02d  %s  stat %d  loops %d", fid, uses(fid, ub, sizeof ub), padx_get_stat(), padx_get_lp_cnt());
        text(40, y, b, 0xFFC0FFC0); y += 14;
        snprintf(b, sizeof b, "bank   AFS01 #%02d -> slot %d   sound %d", T.bank, default_slot(T.bank), T.sound);
        text(40, y, b, 0xFFC0E0FF); y += 14;
        snprintf(b, sizeof b, "voices %d   %s %s   out %d Hz %s", synth_active_voices(&audio_tsd()->synth),
                 T.mono ? "mono" : "stereo", T.loop ? "loop" : "no-loop", audio_device_rate(),
                 audio_unlocked() ? "" : "(tap to enable audio)");
        text(40, y, b, 0xFFFFFFC0); y += 20;
        text(40, y, "UP/DN track  LP play  L/R sound  LK play", 0xFFA0A0A0); y += 12;
        text(40, y, "HP/HK bank  START stop  M mono  L loop", 0xFFA0A0A0); y += 20;
        text(40, y, T.status, 0xFFFFFFFF);
    }
    fl_frame_end();
    r_present(W, H, R_PRESENT_SHARP_FIT);
    draw_touch(W, H);
}

static void on_pause(void *u, int paused) { (void)u; audio_set_paused(paused); }
#endif

int main(int argc, char **argv)
{
    const char *iso = NULL, *render_out = NULL, *decode_out = NULL, *verify_dir = NULL, *loop_out = NULL;
    int decode_idx = -1, do_loop_check = 0, track = -1, bank = -1, sound = -1;
    double seconds = 10;
    T.loop = 1;
    T.slot = -1;
    for (int i = 1; i < argc; i++) {
        const char *a = argv[i], *n = i + 1 < argc ? argv[i + 1] : NULL;
        if (!strcmp(a, "--iso") && n) { iso = n; i++; }
        else if (!strcmp(a, "--track") && n) { track = atoi(n); i++; }
        else if (!strcmp(a, "--bank") && n) { bank = atoi(n); i++; }
        else if (!strcmp(a, "--sound") && n) { sound = atoi(n); i++; }
        else if (!strcmp(a, "--slot") && n) { T.slot = atoi(n) & 7; i++; }
        else if (!strcmp(a, "--render") && n) { render_out = n; i++; }
        else if (!strcmp(a, "--seconds") && n) { seconds = atof(n); i++; }
        else if (!strcmp(a, "--no-loop")) T.loop = 0;
        else if (!strcmp(a, "--frames") && n) { T.quit_after = atoi(n); i++; }
        else if (!strcmp(a, "--mono")) T.mono = 1;
        else if (!strcmp(a, "--decode-adx") && i + 2 < argc) { decode_idx = atoi(argv[i + 1]); decode_out = argv[i + 2]; i += 2; }
        else if (!strcmp(a, "--verify") && n) { verify_dir = n; i++; }
        else if (!strcmp(a, "--loop-check")) { do_loop_check = 1; if (n && n[0] != '-') { loop_out = n; i++; } }
        else if (a[0] != '-') iso = a;
        else { fprintf(stderr, "unknown option %s\n", a); return 2; }
    }
    if (!iso && !getenv("SOUNDTEST_NO_DEFAULT_ISO")) {
        FILE *p = fopen("private/disc/mvc2.iso", "rb");
        if (p) { fclose(p); iso = "private/disc/mvc2.iso"; }
    }
    int headless = render_out || decode_out || verify_dir || do_loop_check;
    if (headless) {
        if (!iso || open_disc(iso)) { fprintf(stderr, "soundtest: need --iso\n"); return 1; }
        audio_init(0);
        audio_set_loader(afs_loader, NULL);
        tsdc_set_stereo(!T.mono);
        tsdc_flush(0);
        int r = 0;
        if (decode_out) r |= decode_adx(decode_idx, decode_out);
        if (verify_dir) r |= verify(verify_dir);
        if (do_loop_check) r |= loop_check(loop_out);
        if (render_out) r |= render(render_out, seconds, track, bank, sound);
        audio_shutdown();
        return r ? 1 : 0;
    }
#ifdef SOUNDTEST_HEADLESS_ONLY
    fprintf(stderr, "soundtest: headless build; use --render / --verify / --loop-check\n");
    return 2;
#else
    PlatConfig cfg = { "MvC2 port sound test", 960, 720, 0, 1, 0 };
    if (plat_init(&cfg)) return 1;
    if (r_init()) return 1;
    audio_init(1);
    audio_set_loader(afs_loader, NULL);
    T.track = track >= 0 ? track : 0;
    T.bank = bank >= 0 ? bank : 59;
    T.sound = sound >= 0 ? sound : 0;
    T.slot = default_slot(T.bank);
    if (iso && !open_disc(iso)) {
        select_bank();
        if (track >= 0) start_track(T.track);
        if (sound >= 0) play_sound(T.slot, T.sound, 8);
    }
    else say("no disc image: pass --iso PATH (web: use the file picker)");
    static PlatApp app = { NULL, update, render_frame, on_pause };
    plat_run(&app);
#ifndef __EMSCRIPTEN__
    audio_shutdown();
    r_shutdown();
    plat_shutdown();
#endif
    return 0;
#endif
}
