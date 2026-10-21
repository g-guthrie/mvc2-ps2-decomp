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
extern f32 D_004599A8[];
/* Native GP-relative storage; no array capacity is inferred. */
extern s8 D_004C0DAC[] __attribute__((section(".sdata")));
extern s8 D_004C0DB0[] __attribute__((section(".sdata")));
extern s8 D_004C0DB4[] __attribute__((section(".sdata")));
void func_002C0BA0(u8 *p) {

    extern void func_001E3710(u8 *, u8);
    extern int func_001757E0(u8 *, s32, s32);
    switch (p[0x1FC]) {
    case 0:
        if (func_00184110((OwnerThresholdState *)p, D_004599A8[3]) != 0) {
            p[6]++;
            p[0x168] = 3;
            p[0x1B5] = 0x39;
        } else {
            p[0x168] = 0;
            p[0x1B5] = 9;
        }
        func_001E3710(p, 0x14);
        *(s8 **)(p + 0x408) = D_004C0DAC;
        p[0x1BB] = 0;
        break;
    case 1:
        if (func_00184110((OwnerThresholdState *)p, D_004599A8[4]) != 0) {
            p[6]++;
            p[0x168] = 4;
            p[0x1B5] = 0x3A;
        } else {
            p[0x168] = 1;
            p[0x1B5] = 10;
        }
        func_001E3710(p, 0x15);
        *(s8 **)(p + 0x408) = D_004C0DB0;
        p[0x1BB] = 1;
        break;
    case 2:
        if (func_00184110((OwnerThresholdState *)p, D_004599A8[5]) != 0) {
            p[6]++;
            p[0x168] = 5;
            p[0x1B5] = 0x3B;
        } else {
            p[0x168] = 2;
            p[0x1B5] = 11;
        }
        func_001E3710(p, 0x16);
        *(s8 **)(p + 0x408) = D_004C0DB4;
        p[0x1BB] = 2;
        break;
    }
    p[0x1B5] = *(u8 *)(p + 0x1B5);
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 0xA, p[0x168]);
}
