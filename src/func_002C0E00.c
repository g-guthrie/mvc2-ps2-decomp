#include "owner_vertical_threshold.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x7C]; s16 f7c[]; } G;
extern G *D_004C2794;
extern f32 D_0045999C[];
extern s8 D_004C0DB8[] __attribute__((section(".sdata")));
extern s8 D_004C0DBC[] __attribute__((section(".sdata")));
extern s8 D_004C0DC0[] __attribute__((section(".sdata")));
extern s8 D_004C0DD0[] __attribute__((section(".sdata")));
extern s8 D_004C0DD4[] __attribute__((section(".sdata")));
extern s8 D_004C0DD8[] __attribute__((section(".sdata")));
extern s32 func_00184150(u8 *, f32, f32);
extern void func_001E3710(u8 *, u8);
extern int func_001757E0(u8 *, s32, s32);
void func_002C0E00(u8 *p) {
    switch (p[0x1FC]) {
    case 0:
        if (func_00184150(p, D_0045999C[9], D_0045999C[15]) != 0) {
            p[0x168] = 6;
            p[0x1B5] = 0x3C;
        } else {
            p[0x168] = 0;
            p[0x1B5] = 0xC;
        }
        func_001E3710(p, 0x14);
        if (p[0x210] == 0)
            *(s8 **)(p + 0x408) = D_004C0DB8;
        else
            *(s8 **)(p + 0x408) = D_004C0DD0;
        p[0x1BB] = 0;
        break;
    case 1:
        if (func_00184110((OwnerThresholdState *)p, D_0045999C[10]) != 0) {
            p[0x168] = 7;
            p[0x1B5] = 0x3D;
        } else {
            p[0x168] = 1;
            p[0x1B5] = 0xD;
        }
        func_001E3710(p, 0x15);
        if (p[0x210] == 0)
            *(s8 **)(p + 0x408) = D_004C0DBC;
        else
            *(s8 **)(p + 0x408) = D_004C0DD4;
        p[0x1BB] = 1;
        break;
    case 2:
        if (func_00184150(p, D_0045999C[11], D_0045999C[16]) != 0) {
            p[0x168] = 8;
            p[0x1B5] = 0x3E;
            func_001E3710(p, 0x16);
        } else {
            p[0x168] = 2;
            p[0x1B5] = 0xE;
            func_001E3710(p, 0x16);
        }
        if (*(u16 *)(p + 0x20E) & 0x1000) {
            p[0x168] = 9;
            p[0x1FC] = 0x60;
            p[0x1B5] = 0x12;
        }
        if (p[0x210] == 0)
            *(s8 **)(p + 0x408) = D_004C0DC0;
        else
            *(s8 **)(p + 0x408) = D_004C0DD8;
        p[0x1BB] = 2;
        break;
    }
    p[0x1B5] = *(u8 *)(p + 0x1B5);
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 0xB, p[0x168]);
    if ((*(s8 *)(p + 0x1EA) & 0xF) != 0)
        (*(s8 *)(p + 0x1EA))--;
}
