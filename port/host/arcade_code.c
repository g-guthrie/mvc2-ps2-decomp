/*
 * Arcade-accuracy CODE toggles (port/docs/ARCADE_DIFF.md section 10): the
 * places where the PS2 game's code, not its data, behaves differently from
 * the NAOMI arcade program (mvsc2 Rev A).  The data toggles (frames, boxes,
 * damage, CPU AI) are in arcade.c.  All are off by default; nothing here
 * needs the user's mvsc2.zip.
 *
 *   mvc2_arc_code bit 1 (ARC_FS_EDGE, letter d)
 *       func_001827B0 (src/e080_e.c; NAOMI 0x0C042414): while the opponent
 *       is the flying-screen "camera follows" character (+0x249, NAOMI
 *       +0x235), the player is clamped near the stage edge at
 *       35 + 16 units inside the camera bound on the PS2 and at 35 on the
 *       arcade.  Bit set: the arcade's 35 (host_overrides.py, ARCADE block).
 *   mvc2_arc_code bit 2 (ARC_SERVBOT, letter e)
 *       func_00179590 (src/xl8_a.c; NAOMI 0x0C039928): in hit stop the
 *       PS2 clears every input word of character 0x3A (Servbot) when bit
 *       0x80 of +0x216 (NAOMI +0x202) is set; the arcade has no such clause
 *       (the hit-stop input buffering, +0x364/+0x366, keeps working).
 *       Bit set: the clause is skipped.
 *
 *   Input pipeline (arcade.timing): the arcade reads the JVS inputs in its
 *   V-blank interrupt from the previous Maple transfer and runs the logic
 *   right after nlWaitVSync, so a press reaches the logic one frame late;
 *   the retail PS2 two frames late (the oracle in Play!); the port in the
 *   same step.  arcade_pad_filter() delays the game's pads by that many
 *   steps (the menus are not delayed).  The logic rate (59.94 Hz on both
 *   machines, 60 Hz in the port) is set by fe_arcade.c via plat_set_logic_hz.
 *
 * MVC2_ARCADE letters d and e (and "all") set the code bits for one run;
 * MVC2_ARCADE_DELAY=N sets the input pipeline (0..2).
 */
#include <stdlib.h>
#include <string.h>
#include "host.h"
#include "../platform/pad.h"

int mvc2_arc_code;          /* ARC_* bits, read by the overridden game C */
int mvc2_arc_input_delay;   /* 0 port, 1 arcade, 2 PS2 retail */

#define ARC_DELAY_MAX 4
static PadRaw q[2][ARC_DELAY_MAX];

void arcade_code_init(void)
{
    const char *e = getenv("MVC2_ARCADE"), *d = getenv("MVC2_ARCADE_DELAY");
    if (e) {
        int all = !strcmp(e, "all") || !strcmp(e, "1");
        mvc2_arc_code = ((all || strchr(e, 'd')) ? 1 : 0) | ((all || strchr(e, 'e')) ? 2 : 0);
    }
    if (d)
        mvc2_arc_input_delay = atoi(d);
    if (mvc2_arc_input_delay < 0)
        mvc2_arc_input_delay = 0;
    if (mvc2_arc_input_delay > 2)
        mvc2_arc_input_delay = 2;
    if (mvc2_arc_code || mvc2_arc_input_delay)
        host_log("arcade: code toggles %s%s; input pipeline %d frame(s)",
                 mvc2_arc_code & 1 ? "d(flying-screen edge 35) " : "",
                 mvc2_arc_code & 2 ? "e(Servbot hit-stop inputs) " : "", mvc2_arc_input_delay);
}

/* The pads the game sees this step: the ones set mvc2_arc_input_delay steps
 * ago.  Called once per game step, before host_pad_set. */
void arcade_pad_filter(int port, PadRaw *p)
{
    int n = mvc2_arc_input_delay, k;
    PadRaw out;
    if (port < 0 || port > 1 || n <= 0)
        return;
    if (n > ARC_DELAY_MAX)
        n = ARC_DELAY_MAX;
    out = q[port][n - 1];
    for (k = n - 1; k > 0; k--)
        q[port][k] = q[port][k - 1];
    q[port][0] = *p;
    if (!out.connected) {          /* pipeline still filling: centred, nothing held */
        memset(&out, 0, sizeof out);
        out.rx = out.ry = out.lx = out.ly = 0x80;
        out.connected = p->connected;
    }
    *p = out;
}
