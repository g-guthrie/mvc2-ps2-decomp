#ifndef MVC2_PRESET_STEPS_H
#define MVC2_PRESET_STEPS_H
/* 16-byte scene preset step read by func_003CE980 (src/sa34_g.c) from actor+0xD8:
 * the walk stops at the first negative op (lb), skips op 0, applies D_00476700[sel]
 * when sel != 0 (lb), translates by pos[0..2] (lwc1) and draws model index model (lhu).
 * func_003CEF10 (src/fb75_c.c) also reads sel and pos of the single-step presets. */
typedef signed char s8;
typedef unsigned short u16;
typedef float f32;
typedef struct {
    s8 op;
    s8 sel;
    u16 model;
    f32 pos[3];
} Mvc2PresetStep;
typedef char Mvc2PresetStep_size_check[(sizeof(Mvc2PresetStep) == 16) ? 1 : -1];
#endif
