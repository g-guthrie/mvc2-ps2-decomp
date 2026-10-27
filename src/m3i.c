typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

#include "data/button_config_render.h"
typedef ButtonConfigRenderRecord Ent;

extern Ent D_004B36E0[];
extern void func_003D7350(u8, u8, u8, const char *, ...);

void func_00148D40(u8 *p, s32 idx, s32 n) {
    Ent *e = &D_004B36E0[idx];
    s32 i;
    for (i = 0; i < n; i++) {
        func_003D7350(e->rendererArgs[0] + *(s8 *)(p + 1) * 0x35, e->rendererArgs[1], e->rendererArgs[3], (const char *)e->resource);
        e++;
    }
}

extern Ent D_004B91D0[];

/* Three-argument native calls at 003D4F70 and 003D4F80. */
void func_003D4AD0(u8 *p, s32 idx, s32 n) {
    Ent *e = &D_004B91D0[idx];
    s32 i;
    for (i = 0; i < n; i++) {
        func_003D7350(e->rendererArgs[0] + *(s8 *)(p + 1) * 0x35, e->rendererArgs[1], e->rendererArgs[3], (const char *)e->resource);
        e++;
    }
}
