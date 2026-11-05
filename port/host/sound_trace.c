/*
 * Sound request trace for the oracle comparison (testing).
 *
 * MVC2_SOUND_TRACE=FILE: every call the game makes into the sound driver
 * (Tamsoft: tsd_host.c) and the ADX streamer (ADXT: cri.c) is written as
 *   f<frame> <EE address>(a0=.. a1=.. a2=.. a3=..)
 * the same shape as the oracle's `--trace ADDR` lines, so fuzz.py can line
 * the two up frame by frame.  The PCM itself is not comparable (the port
 * replaces the IOP driver and the ADX player); what the game asks for is.
 */
#include <stdio.h>
#include <stdlib.h>
#include "host.h"
#include "host_loop.h"

void host_sound_event(u32 addr, int a0, int a1, int a2, int a3)
{
    static FILE *f;
    static int init;
    if (!init) {
        const char *p = getenv("MVC2_SOUND_TRACE");
        init = 1;
        if (p && *p)
            f = fopen(p, "w");
    }
    if (!f)
        return;
    fprintf(f, "f%ld %08X(a0=%08X a1=%08X a2=%08X a3=%08X)\n", (long)mvc2_host_frame, (unsigned)addr,
            (unsigned)a0, (unsigned)a1, (unsigned)a2, (unsigned)a3);
    fflush(f);
}
