/*
 * Arcade-accuracy toggles in the settings registry (port/platform/settings.h,
 * section "Arcade accuracy"), so they show in the in-game menu and the web
 * settings panel and are saved per device.  The work is in port/host/arcade.c
 * (port/docs/ARCADE_DIFF.md section 5); all three are off by default.
 *
 *   arcade.frame_data  (a) NAOMI TBL / HIT / HIT_FM: frame timing and boxes
 *   arcade.damage      (b) NAOMI HIT_DT: damage and hit properties
 *   arcade.cpu_ai      (c) NAOMI CPU AI tables
 *     (a)-(c) read the per-character table FILES of the mask ROMs.  The
 *     Rev A program never loads them: it unpacks its own tables (packed
 *     block at RAM 0x0DD00000, 16-bit LZ 0x0C02A762), and those equal the
 *     PS2's byte for byte (naomi_oracle, ARCADE_DIFF.md 11).  So for arcade
 *     accuracy (a)-(c) stay off; they remain for study of the ROM files.
 *   arcade.naomi       raw string: path of the user's mvsc2.zip (desktop;
 *                      the web page writes /mvsc2.zip itself)
 *
 * Code differences (port/host/arcade_code.c, ARCADE_DIFF.md section 10; no zip
 * needed, they take effect at once):
 *   arcade.fs_edge          (d) flying-screen edge clamp at the arcade's 35 units
 *   arcade.servbot_hitstop  (e) no PS2-only input clear for Servbot in hit stop
 *   arcade.freeze_order     (f) super-freeze countdown ticked first in the frame
 *   arcade.trig             (g) the NAOMI's computed sine / cosine
 *   arcade.timing           logic rate and input pipeline: Port (60 Hz, same
 *                           step) / Arcade (59.94 Hz, 1 frame) / PS2 (59.94 Hz, 2)
 *
 * --arcade abc / MVC2_ARCADE (and ?arcade=abc) still override for one run.
 * The tables are spliced when the game boots, so a change needs a restart.
 */
#include <stdlib.h>
#include "../host.h"
#include "../../platform/settings.h"
#include "../../platform/platform.h"

extern int mvc2_arcade_flags;

static void set_bit(int bit, int on)
{
    if (on)
        mvc2_arcade_flags |= bit;
    else
        mvc2_arcade_flags &= ~bit;
}
static void on_frames(int v) { set_bit(1, v); }
static void on_damage(int v) { set_bit(2, v); }
static void on_ai(int v) { set_bit(4, v); }

extern int mvc2_arc_code, mvc2_arc_input_delay;
static void code_bit(int bit, int on)
{
    if (on)
        mvc2_arc_code |= bit;
    else
        mvc2_arc_code &= ~bit;
}
static void on_fs_edge(int v) { code_bit(1, v); }
static void on_servbot(int v) { code_bit(2, v); }
static void on_freeze(int v) { code_bit(4, v); }
static void on_trig(int v) { code_bit(8, v); }
static void on_timing(int v)
{
    mvc2_arc_input_delay = v;   /* 0 port, 1 arcade (Maple, previous V-blank), 2 PS2 retail */
    plat_set_logic_hz(v ? 60000.0 / 1001.0 : PLAT_HZ);
}
static const char *const k_timing[] = {"Port (60 Hz, read this step)", "Arcade (59.94 Hz, 1 frame)",
                                       "PS2 (59.94 Hz, 2 frames)", NULL};
static const char *const k_timing_v[] = {"port", "arcade", "ps2", NULL};

static const SetDesc k_frames = {
    "arcade.frame_data", "NAOMI ROM files: frames + boxes", SET_SECTION_ARCADE, SET_BOOL, 0, 0, 1, NULL, NULL,
    on_frames, SET_RESTART,
    "Animation timing and boxes from the table files in your mvsc2.zip's mask ROMs. The Rev A arcade "
    "program does not use these files: its own tables equal the PS2's, so leave this off for arcade "
    "accuracy (ARCADE_DIFF 11). Needs the zip.", 0};
static const SetDesc k_damage = {
    "arcade.damage", "NAOMI ROM files: damage", SET_SECTION_ARCADE, SET_BOOL, 0, 0, 1, NULL, NULL,
    on_damage, SET_RESTART, "Damage and hit properties from the mask-ROM table files, which the Rev A "
    "arcade program does not use (its damage equals the PS2's). Leave off for arcade accuracy.", 0};
static const SetDesc k_ai = {
    "arcade.cpu_ai", "NAOMI ROM files: CPU AI", SET_SECTION_ARCADE, SET_BOOL, 0, 0, 1, NULL, NULL,
    on_ai, SET_RESTART, "CPU decision tables from the mask-ROM table files, which the Rev A arcade "
    "program does not use (its tables equal the PS2's). Leave off for arcade accuracy.", 0};

static const SetDesc k_fs_edge = {
    "arcade.fs_edge", "Arcade flying-screen edge", SET_SECTION_ARCADE, SET_BOOL, 0, 0, 1, NULL, NULL,
    on_fs_edge, 0,
    "While the opponent is in flying screen, stop at 35 units from the stage edge as the arcade does "
    "(the PS2 stops 16 units further in).", 0};
static const SetDesc k_servbot = {
    "arcade.servbot_hitstop", "Arcade Servbot hit-stop inputs", SET_SECTION_ARCADE, SET_BOOL, 0, 0, 1, NULL, NULL,
    on_servbot, 0,
    "Keep Servbot's buttons during hit stop while his +0x216 flag is set (the PS2 clears them; the arcade does not).",
    0};
static const SetDesc k_freeze = {
    "arcade.freeze_order", "Arcade super-freeze timing", SET_SECTION_ARCADE, SET_BOOL, 0, 0, 1, NULL, NULL,
    on_freeze, 0,
    "Tick the super-freeze countdown at the start of the frame as the arcade does; the PS2 ticks it at the end, "
    "so its freezes end one frame sooner.", 0};
static const SetDesc k_trig = {
    "arcade.trig", "Arcade sine / cosine", SET_SECTION_ARCADE, SET_BOOL, 0, 0, 1, NULL, NULL,
    on_trig, 0,
    "Compute sine and cosine as the arcade program does; the PS2 reads a table whose values differ in the last "
    "bits, which can change hit pushback and positions.", 0};
static const SetDesc k_timing_d = {
    "arcade.timing", "Logic rate + input pipeline", SET_SECTION_ARCADE, SET_ENUM, 0, 0, 2, k_timing, k_timing_v,
    on_timing, 0,
    "Port: 60 Hz, a press counts in the next step. Arcade: 59.94 Hz and one frame of input delay (NAOMI reads "
    "the controls in V-blank from the previous Maple transfer). PS2: 59.94 Hz, two frames.", 0};

void fe_arcade_register(void)
{
    const char *p = settings_get("arcade.naomi");
    settings_register(&k_frames);
    settings_register(&k_damage);
    settings_register(&k_ai);
    settings_register(&k_fs_edge);
    settings_register(&k_servbot);
    settings_register(&k_freeze);
    settings_register(&k_trig);
    settings_register(&k_timing_d);
    if (p && *p && !getenv("MVC2_NAOMI"))
        setenv("MVC2_NAOMI", p, 1);
}
