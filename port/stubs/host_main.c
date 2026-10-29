/*
 * Host entry point for mvc2_host (Port G).
 *
 * The game's main is func_00170C30 (src/z2_b.c): platform init in a retry
 * loop, three init calls, then an endless 60 Hz frame loop.  This main runs
 * the same sequence step by step, with the frame loop bounded:
 *
 *   mvc2_host [--frames N] [--init-only] [--skip-platform-init] [--timeout S]
 *   (MVC2_FRAMES=N in the environment works too; default N = 0)
 *
 * --timeout S (default 10, 0 = off; native builds only) is a watchdog: the
 * game hangs in `for (;;) {}` when an init step fails (e.g. a heap that the
 * platform init did not create), and the watchdog reports the step instead.
 *
 * Each step's name is kept in mvc2_host_step, so a crash report says how far
 * the boot got.  The platform layer (port/platform, port/render) replaces the
 * C-less pieces (func_003EC160 platform init, func_003ECD00 flip, ...); until
 * then they are the logging stubs listed in glue/stubs.csv.
 */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mvc2_stubs.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

/* prototypes as the credited definitions give them */
extern s32 func_003EC160(s32 w, s32 h);
extern void func_0012F4C0(void);
extern void func_00170BF0(void);
extern void func_003D6B70(void);
extern s32 func_0012F460(void);
extern s32 func_0016ECC0(void);
extern void func_0012F3E0(u16 *);
extern void func_003D7630(void);
extern void func_0012F450(void);
extern void func_0016EE50(void);
extern void func_00417FB0(void);
extern void func_0012F440(void);
extern void func_001E42A0(void);
extern void func_003D6FF0(void);
extern void func_00170D30(void);
extern void func_003D7400(void);
extern void func_003D7640(void);
extern void func_0012DD90(void);
extern void func_00170D70(void);
extern void func_003ECD00(s32);

extern s32 D_004C2870, D_004C2848, D_004C284C;
extern u8 D_004D17C2[];
extern u16 D_004F4480[], D_004F4494[];

const char *volatile mvc2_host_step = "start";
static volatile long mvc2_host_frame = -1;

#define STEP(name, call) do { mvc2_host_step = name; fprintf(stderr, "[host] %s\n", name); call; } while (0)
#define FSTEP(name, call) do { mvc2_host_step = name; call; } while (0)

static void on_fatal(int sig)
{
    fprintf(stderr, "[host] signal %d during step '%s' (frame %ld)\n", sig, mvc2_host_step,
            mvc2_host_frame);
    mvc2_stub_report();
    signal(sig, SIG_DFL);
    raise(sig);
}

#if !defined(__EMSCRIPTEN__)
#include <unistd.h>
static void on_alarm(int sig)
{
    (void)sig;
    fprintf(stderr, "[host] watchdog: no progress, stuck in step '%s' (frame %ld)\n", mvc2_host_step,
            mvc2_host_frame);
    mvc2_stub_report();
    _exit(3);
}
#endif

static void frame(void)
{
    FSTEP("func_0012F460 frame counters / CRI tick / pad", func_0012F460());
    FSTEP("func_0016ECC0 network stubs", func_0016ECC0());
    FSTEP("func_0012F3E0 auto-repeat P1", func_0012F3E0(D_004F4480));
    FSTEP("func_0012F3E0 auto-repeat P2", func_0012F3E0(D_004F4494));
    FSTEP("func_003D7630 overlay counters", func_003D7630());
    FSTEP("func_0012F450", func_0012F450());
    if (D_004C2870 == 1 && D_004D17C2[0] != 1) {
        FSTEP("func_0016EE50 soft reset", func_0016EE50());
        FSTEP("func_00417FB0 flip", func_00417FB0());
        FSTEP("func_0012F440", func_0012F440());
        D_004C2870 = 0;
    }
    FSTEP("func_001E42A0 sound tick", func_001E42A0());
    D_004C2848 = 0;
    D_004C284C = 0;
    FSTEP("func_003D6FF0 game update", func_003D6FF0());
    FSTEP("func_00170D30 begin scene", func_00170D30());
    FSTEP("func_003D7400 render pass 1", func_003D7400());
    FSTEP("func_003D7640 render pass 2", func_003D7640());
    FSTEP("func_0012DD90 file loader tick", func_0012DD90());
    FSTEP("func_00170D70 end scene", func_00170D70());
    FSTEP("func_003ECD00 vsync/flip", func_003ECD00(0));
}

int main(int argc, char **argv)
{
    long frames = 0;
    int init_only = 0, skip_platform = 0, i;
    long timeout = 10;
    const char *e = getenv("MVC2_FRAMES");
    if (e)
        frames = strtol(e, 0, 0);
    for (i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "--frames") && i + 1 < argc)
            frames = strtol(argv[++i], 0, 0);
        else if (!strcmp(argv[i], "--init-only"))
            init_only = 1;
        else if (!strcmp(argv[i], "--skip-platform-init"))
            skip_platform = 1;
        else if (!strcmp(argv[i], "--timeout") && i + 1 < argc)
            timeout = strtol(argv[++i], 0, 0);
        else {
            fprintf(stderr, "usage: %s [--frames N] [--init-only] [--skip-platform-init] [--timeout S]\n", argv[0]);
            return 2;
        }
    }
    signal(SIGSEGV, on_fatal);
    signal(SIGBUS, on_fatal);
    signal(SIGILL, on_fatal);
    signal(SIGFPE, on_fatal);
    signal(SIGABRT, on_fatal);
#if !defined(__EMSCRIPTEN__)
    if (timeout > 0) {
        signal(SIGALRM, on_alarm);
        alarm((unsigned)timeout);
    }
#else
    (void)timeout;
#endif
    fprintf(stderr, "[host] mvc2_host: %u faked symbols in the link (glue/stubs.csv)\n", mvc2_fake_count);

    if (!skip_platform) {
        s32 r;
        STEP("func_003EC160 platform init (640x480)", r = func_003EC160(0x280, 0x1E0));
        if (r == 0)
            fprintf(stderr, "[host] platform init returned 0 (the PS2 main retries forever); continuing\n");
    }
    STEP("func_0012F4C0 game init (heaps, resources, sound, fonts)", func_0012F4C0());
    STEP("func_00170BF0 file queue reset", func_00170BF0());
    STEP("func_003D6B70 state init", func_003D6B70());
    if (!init_only) {
        for (mvc2_host_frame = 0; mvc2_host_frame < frames; mvc2_host_frame++)
            frame();
        fprintf(stderr, "[host] ran %ld frame(s)\n", frames);
    }
    mvc2_host_step = "done";
    fprintf(stderr, "[host] init path complete\n");
    mvc2_stub_report();
    return 0;
}
