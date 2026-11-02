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
 *   mvc2_arc_code bit 4 (ARC_FREEZE_ORDER, letter f)
 *       func_001E8CD0 (src/stage_update_001E8CD0.c; NAOMI 0x0C0382A4): the
 *       NAOMI ticks the super-freeze countdown (func_001E8EB0, NAOMI
 *       0x0C0383A4) and sets the freeze flag D_004D18A6 before the actor
 *       updates of the frame, the PS2 after them; a freeze started in a
 *       frame is ticked in that frame on the PS2, one frame later on the
 *       NAOMI (found by the arcade oracle, port/tools/naomi_oracle).
 *       Bit set: the NAOMI's order (host_overrides.py, ARCADE block).
 *
 *   mvc2_arc_code bit 8 (ARC_TRIG, letter g)
 *       func_00417440 / func_00417500 (sine / cosine of a 16-bit angle,
 *       src/lookup_runtime_sine_00417440.c, src/w184_c.c) read a 16384-entry
 *       float table on the PS2.  The NAOMI computes them (0x0C1EC2C0 sine,
 *       0x0C1EBD40 cosine = sine(0x4000 - |a|)): tan of the half angle by a
 *       continued fraction, then 2t / (1 + t*t).  The results differ in the
 *       last bits, which the arcade oracle saw grow into position
 *       differences (hit pushback, func_0018F1A0).  Bit set:
 *       mvc2_naomi_sin / mvc2_naomi_cos below, the NAOMI's operations in
 *       the NAOMI's order (single precision, round to nearest; FMAC fused).
 *
 *   Input pipeline (arcade.timing): the arcade reads the JVS inputs in its
 *   V-blank interrupt from the previous Maple transfer and runs the logic
 *   right after nlWaitVSync, so a press reaches the logic one frame late;
 *   the retail PS2 two frames late (the oracle in Play!); the port in the
 *   same step.  arcade_pad_filter() delays the game's pads by that many
 *   steps (the menus are not delayed).  The logic rate (59.94 Hz on both
 *   machines, 60 Hz in the port) is set by fe_arcade.c via plat_set_logic_hz.
 *
 * MVC2_ARCADE letters d, e, f and g (and "all") set the code bits for one run;
 * MVC2_ARCADE_DELAY=N sets the input pipeline (0..2).
 */
#include <math.h>
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
        mvc2_arc_code = ((all || strchr(e, 'd')) ? 1 : 0) | ((all || strchr(e, 'e')) ? 2 : 0) |
                        ((all || strchr(e, 'f')) ? 4 : 0) | ((all || strchr(e, 'g')) ? 8 : 0);
    }
    if (d)
        mvc2_arc_input_delay = atoi(d);
    if (mvc2_arc_input_delay < 0)
        mvc2_arc_input_delay = 0;
    if (mvc2_arc_input_delay > 2)
        mvc2_arc_input_delay = 2;
    if (mvc2_arc_code || mvc2_arc_input_delay)
        host_log("arcade: code toggles %s%s%s%s; input pipeline %d frame(s)",
                 mvc2_arc_code & 1 ? "d(flying-screen edge 35) " : "",
                 mvc2_arc_code & 2 ? "e(Servbot hit-stop inputs) " : "",
                 mvc2_arc_code & 4 ? "f(super-freeze tick order) " : "",
                 mvc2_arc_code & 8 ? "g(NAOMI sine/cosine) " : "", mvc2_arc_input_delay);
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

/* ---- arcade.trig (bit 8): the NAOMI's sine and cosine -------------------
 * 0x0C1EC2C0: x = a * 2pi / 65536; h = x / 2; k = trunc(h / (pi/2) + 0.5);
 * h -= k * pi/2; f = h*h / (3 - h*h / (5 - ... / (11 - 0))); t = h / (1 - f)
 * (= tan h); s = 2t / (1 + t*t) (the 1 + t*t by FMAC, fused); -s if k is
 * odd.  Each statement is one SH-4 float operation, so no contraction. */
float mvc2_naomi_sin(int ai)
{
    u32 a = (u32)ai;
    float x, h, q, kf, h2, f, d, t, t2, den, r;
    int k, n;
    x = (float)(a & 0xFFFF);
    x = x * 6.2831854820251465f;
    x = x / 65536.0f;
    h = x / 2.0f;
    q = h / 1.5707963705062866f;
    q = q + 0.5f;
    k = (int)q;                      /* ftrc */
    kf = (float)k;
    kf = kf * 1.5707963705062866f;
    h = h - kf;
    h2 = h * h;
    f = 0.0f;
    for (n = 11; n >= 3; n -= 2) {
        d = (float)n;
        d = d - f;
        f = h2 / d;
    }
    d = 1.0f - f;
    t = h / d;
    t2 = t * 2.0f;
    den = fmaf(t, t, 1.0f);
    r = t2 / den;
    return (k & 1) ? -r : r;
}

/* 0x0C1EBD40: a' = a & 0xFFFF, folded to 0x10000 - a' above 0x8000; then
 * the sine of (0x4000 - a') as a 16-bit angle */
float mvc2_naomi_cos(int ai)
{
    u32 a = (u32)ai;
    u32 m = a & 0xFFFF;
    if (m > 0x8000)
        m = 0x10000 - m;
    return mvc2_naomi_sin((0x4000 - m) & 0xFFFF);
}
