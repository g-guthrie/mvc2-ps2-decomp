/*
 * Arcade-accuracy toggles in the settings registry (port/platform/settings.h,
 * section "Arcade accuracy"), so they show in the in-game menu and the web
 * settings panel and are saved per device.  The work is in port/host/arcade.c
 * (port/docs/ARCADE_DIFF.md section 5); all three are off by default.
 *
 *   arcade.frame_data  (a) NAOMI TBL / HIT / HIT_FM: frame timing and boxes
 *   arcade.damage      (b) NAOMI HIT_DT: damage and hit properties
 *   arcade.cpu_ai      (c) NAOMI CPU AI tables
 *   arcade.naomi       raw string: path of the user's mvsc2.zip (desktop;
 *                      the web page writes /mvsc2.zip itself)
 *
 * --arcade abc / MVC2_ARCADE (and ?arcade=abc) still override for one run.
 * The tables are spliced when the game boots, so a change needs a restart.
 */
#include <stdlib.h>
#include "../host.h"
#include "../../platform/settings.h"

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

static const SetDesc k_frames = {
    "arcade.frame_data", "NAOMI frame data + hitboxes", SET_SECTION_ARCADE, SET_BOOL, 0, 0, 1, NULL, NULL,
    on_frames, SET_RESTART,
    "Animation timing and hit/hurt boxes from your own NAOMI mvsc2.zip (Rev A). Needs the zip.", 0};
static const SetDesc k_damage = {
    "arcade.damage", "NAOMI damage + hit data", SET_SECTION_ARCADE, SET_BOOL, 0, 0, 1, NULL, NULL,
    on_damage, SET_RESTART, "Base damage, hitstun and other hit properties from the arcade tables.", 0};
static const SetDesc k_ai = {
    "arcade.cpu_ai", "NAOMI CPU AI", SET_SECTION_ARCADE, SET_BOOL, 0, 0, 1, NULL, NULL,
    on_ai, SET_RESTART, "The CPU opponents' decision tables from the arcade.", 0};

void fe_arcade_register(void)
{
    const char *p = settings_get("arcade.naomi");
    settings_register(&k_frames);
    settings_register(&k_damage);
    settings_register(&k_ai);
    if (p && *p && !getenv("MVC2_NAOMI"))
        setenv("MVC2_NAOMI", p, 1);
}
