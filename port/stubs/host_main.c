/*
 * Host entry point for mvc2_host (Port G).
 *
 * The game's main is func_00170C30 (src/z2_b.c): platform init in a retry
 * loop, three init calls, then an endless 60 Hz frame loop.  This main runs
 * the same sequence step by step, with the frame loop bounded:
 *
 *   mvc2_host [--iso DISC.iso] [--frames N] [--init-only] [--skip-platform-init] [--timeout S] [-v]
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

#include "../host/host_loop.h"

#define STEP(name, call) do { fprintf(stderr, "[host] %s\n", name); call; } while (0)

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

extern unsigned char mvc2_ee_bss[];
#define G_STATE(i) (mvc2_ee_bss[0x004F4300 - 0x004C2580 + (i)])

int main(int argc, char **argv)
{
    long frames = 0;
    int init_only = 0, skip_platform = 0, i;
    long timeout = 10;
    const char *e = getenv("MVC2_FRAMES");
    const char *iso = getenv("MVC2_ISO");
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
        else if (!strcmp(argv[i], "--iso") && i + 1 < argc)
            iso = argv[++i];
        else if (!strcmp(argv[i], "--no-unlock"))
            mvc2_unlock_all = 0;
        else if (!strcmp(argv[i], "-v"))
            host_verbose = 1;
        else {
            fprintf(stderr, "usage: %s [--iso DISC.iso] [--frames N] [--init-only] [--skip-platform-init] [--timeout S] [-v]\n", argv[0]);
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

    if (host_disc_open(iso ? iso : "private/disc/mvc2.iso") != 0)
        fprintf(stderr, "[host] no disc image (--iso PATH or MVC2_ISO): file loads will fail\n");
    STEP("boot (func_00170C30 init calls)", mvc2_boot(!skip_platform));
    if (!init_only) {
        while (mvc2_host_frame < frames)
            mvc2_frame();
        fprintf(stderr, "[host] ran %ld frame(s)\n", frames);
    }
    mvc2_host_step = (const char *)"done";
    fprintf(stderr, "[host] init path complete\n");
    mvc2_stub_report();
    return 0;
}
