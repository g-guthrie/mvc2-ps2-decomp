#include "sony29_gs_half_offset.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s32 D_0062BC40, D_0062BC44, D_0062BC3C, D_0062BC00;
extern s16 D_0062BC38;
extern u8 D_0062BCB0[], D_0062BD30[], D_0062BE20[], D_0062BEA0[], D_0062BC50[];
void func_003ECBE0(void) {
    extern void func_001023C8(u8 *, s32);
    extern void func_00100F00(s32, s32);
    extern void func_003FE9E8(s32);
    s32 t;
    t = D_0062BC40 + 1;
    D_0062BC40 = t;
    if (D_0062BC44 == 1) {
        D_0062BC44 = 0;
        D_0062BC3C = D_0062BC3C ^ 1;
        if (D_0062BC00 != 2) {
            if (D_0062BC3C != 0) {
                func_00101DF0((GsDrawContext *)D_0062BCB0, 0x800, 0x800, D_0062BC38);
                func_00102058((GsDrawContext *)D_0062BD30, 0x800, 0x800, D_0062BC38);
            } else {
                func_00101DF0((GsDrawContext *)D_0062BE20, 0x800, 0x800, D_0062BC38);
                func_00102058((GsDrawContext *)D_0062BEA0, 0x800, 0x800, D_0062BC38);
            }
        }
        func_001023C8(D_0062BC50, D_0062BC3C);
        func_00100F00(0, 0);
    }
    func_003FE9E8(0);
    __asm__ volatile ("sync\n\tei");
}
