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
extern const f32 D_00459990[1], D_00459994[1], D_00459998[1];
/* Native GP-relative storage; no array capacity is inferred. */
extern s8 D_004C0DA0[] __attribute__((section(".sdata")));
extern s8 D_004C0DA4[] __attribute__((section(".sdata")));
extern s8 D_004C0DA8[] __attribute__((section(".sdata")));
void func_002C0730(u8 *p) {

    extern void func_001E3710(u8 *, u8);
    extern int func_001757E0(u8 *, s32, s32);
    switch (p[0x1FC]) {
    case 0:
        if (func_00184110((OwnerThresholdState *)p, D_00459990[0]) != 0) {
            p[0x168] = 3;
            p[0x1B5] = 0x30;
        } else {
            p[0x168] = 0;
            p[0x1B5] = 0;
        }
        func_001E3710(p, 0x14);
        *(s8 **)(p + 0x408) = D_004C0DA0;
        p[0x1BB] = 0;
        p[0x2B6] = 1;
        break;
    case 1:
        if (func_00184110((OwnerThresholdState *)p, D_00459994[0]) != 0) {
            p[0x168] = 4;
            p[0x1B5] = 0x31;
        } else {
            p[0x168] = 1;
            p[0x1B5] = 1;
        }
        func_001E3710(p, 0x15);
        *(s8 **)(p + 0x408) = D_004C0DA4;
        p[0x1BB] = 1;
        break;
    case 2:
        if (func_00184110((OwnerThresholdState *)p, D_00459998[0]) != 0) {
            p[0x168] = 5;
            p[0x1B5] = 0x32;
        } else {
            p[0x168] = 2;
            p[0x1B5] = 2;
        }
        func_001E3710(p, 0x16);
        *(s8 **)(p + 0x408) = D_004C0DA8;
        p[0x1BB] = 2;
        break;
    }
    p[0x1B5] = *(u8 *)(p + 0x1B5);
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 7, p[0x168]);
}
