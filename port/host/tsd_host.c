/*
 * The Tamsoft sound driver client (0x422BE0..0x423E30) on the host (Port J).
 *
 * port/audio/tsd_client.c is a C port of the whole EE client (same queue,
 * byte protocol and serializer 0x423E30); the game's entry points forward to
 * it.  Without a frontend the flushed packets go nowhere (no sink); the
 * frontend binds the sink to the port's IOP driver (port/audio/tsd.c), which
 * plays them.
 *
 * Every command entry is also logged for the oracle comparison (HOST_SND,
 * port/tools/oracle/dump_format.h "Sound commands").
 */
#include "host.h"
#include "../audio/tsd_client.h"

void host_sound_event(u32 addr, int a0, int a1, int a2, int a3); /* sound_trace.c */
#define SND(a, x0, x1, x2, x3) host_sound_event(a, (int)(x0), (int)(x1), (int)(x2), (int)(x3))

void func_00422BE0(void) {}                         /* empty in the game too */
void func_00422C70(void) {}                         /* semaphore lock/unlock: single-threaded */
void func_00422CC0(void) { SND(0x00422CC0, 0, 0, 0, 0); tsdc_reset(); }
int func_00422DB0(void) { SND(0x00422DB0, 0, 0, 0, 0); return tsdc_init(); }
int func_00422EA0(int id, int a1, int a2, int a3)
{
    HOST_SND(0x00422EA0u, id, a1, a2, a3);
    SND(0x00422EA0, id, a1, a2, a3);
    return tsdc_play((u32)id, a1, a2, a3);
}
int func_00422FB0(int id)
{
    HOST_SND(0x00422FB0u, id, 0, 0, 0);
    SND(0x00422FB0, id, 0, 0, 0);
    return tsdc_stop((u32)id);
}
int func_004230B0(int id, int vol, int pan, int pitch)
{
    HOST_SND(0x004230B0u, id, vol, pan, pitch);
    SND(0x004230B0, id, vol, pan, pitch);
    return tsdc_change((u32)id, vol, pan, pitch);
}
int func_004231D0(void)
{
    HOST_SND(0x004231D0u, 0, 0, 0, 0);
    SND(0x004231D0, 0, 0, 0, 0);
    return tsdc_stop_all_tq();
}
int func_00423240(int v)
{
    HOST_SND(0x00423240u, v, 0, 0, 0);
    SND(0x00423240, v, 0, 0, 0);
    return tsdc_master_volume((u32)v);
}
int func_004232C0(int a0, int a1, int a2)
{
    HOST_SND(0x004232C0u, a0, a1, a2, 0);
    SND(0x004232C0, a0, a1, a2, 0);
    return tsdc_cmd77((u32)a0, (u32)a1, (u32)a2);
}
int func_00423480(int slot, int hd, int hd_size, int bd, int bd_size, int tq, int tq_size)
{
    host_snd_log(0x00423480u, (u32)slot, (u32)hd, (u32)hd_size, (u32)bd, (u32)bd_size, (u32)tq, (u32)tq_size);
    SND(0x00423480, slot, hd, hd_size, bd);
    return tsdc_load_bank((u32)slot, (u32)hd, hd_size, (u32)bd, bd_size, (u32)tq, tq_size);
}
int func_004235D0(int slot)
{
    HOST_SND(0x004235D0u, slot, 0, 0, 0);
    SND(0x004235D0, slot, 0, 0, 0);
    return tsdc_unload_bank((u32)slot);
}
int func_00423650(void)
{
    HOST_SND(0x00423650u, 0, 0, 0, 0);
    SND(0x00423650, 0, 0, 0, 0);
    return tsdc_stop_all();
}
int func_004236C0(int en)
{
    HOST_SND(0x004236C0u, en, 0, 0, 0);
    SND(0x004236C0, en, 0, 0, 0);
    return tsdc_set_stereo(en);
}
int func_00423750(int wait) { return tsdc_flush(wait); }
int func_00423990(int fno, int arg)
{
    HOST_SND(0x00423990u, fno, arg, 0, 0);
    SND(0x00423990, fno, arg, 0, 0);
    return tsdc_status(fno, arg);
}
int func_004238A0(int a0, int a1) { (void)a0; (void)a1; return 0; } /* driver thread priority */

/* ---- MVC2_SND_LOG=FILE (testing, port/tools/oracle_av) -------------------
 * The sound commands the game sends, one line each, in the same format as
 * mvc2_av --snd-log: "FRAME G state" (game state change), "FRAME T hex"
 * (the TSD stream of one func_00423750 flush), "FRAME S fno arg" (status
 * query), "FRAME A start|stop|vol|pause|mono ..." (the ADXT calls, cri.c),
 * "FRAME W n" (mixed sample frames rendered so far, MVC2_AUDIO_WAV). */
#include <stdarg.h>
#include "host_loop.h"
#include "runahead.h"
#include <stdio.h>
#include <stdlib.h>
static FILE *snd_f;
static int snd_init, snd_last_state = -1;
static long snd_samples;

void host_av_log(const char *fmt, ...)
{
    va_list ap;
    if (!snd_f || mvc2_speculating) /* a speculated step is not the game's frame */
        return;
    fprintf(snd_f, "%ld ", mvc2_host_frame);
    va_start(ap, fmt);
    vfprintf(snd_f, fmt, ap);
    va_end(ap);
    fputc('\n', snd_f);
}

static void tap_rpc(const uint8_t *b, size_t n)
{
    char hex[0x401];
    size_t i;
    for (i = 0; i < n && i < 0x200; i++)
        snprintf(hex + 2 * i, 3, "%02X", b[i]);
    hex[2 * i] = 0;
    host_av_log("T %s", hex);
}

static void tap_status(int fno, uint32_t arg) { host_av_log("S %X %X", (unsigned)fno, (unsigned)arg); }

void host_av_log_samples(long n) { snd_samples += n; }

/* once per game frame, at the oracle's frame point (mvc2_frame) */
void host_av_log_frame(void)
{
    const u8 *g = (const u8 *)EE_BSS_PTR(0x004F4300);
    int st = g[0] << 16 | g[1] << 8 | g[2];
    if (mvc2_speculating)
        return;
    if (!snd_init) {
        const char *p = getenv("MVC2_SND_LOG");
        snd_init = 1;
        if (p && *p && (snd_f = fopen(p, "w")) != NULL) {
            tsdc_tap_rpc = tap_rpc;
            tsdc_tap_status = tap_status;
        }
    }
    if (!snd_f)
        return;
    if (st != snd_last_state)
        host_av_log("G %06X", st);
    snd_last_state = st;
    if (getenv("MVC2_AUDIO_WAV"))
        host_av_log("W %ld", snd_samples);
    fflush(snd_f);
}
