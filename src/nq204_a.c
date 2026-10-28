/* MWCC 3.0.3: ./try.sh src/nq204_a.c "-O3,p -sdatathreshold 8" (also matches on 3.0) */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 w[32]; } S128;
typedef struct { u8 pad[0x50]; s32 f50; s32 f54; } QS;

extern u8 *D_004C2840;
extern u32 *D_004C2730;
extern u8 D_004CD2D0[];
extern u32 D_004CD2B0[];
extern u32 *D_004C2734;
extern u32 D_004D1774[];
extern u32 D_004D1778[];
extern u32 D_004D177C[];
extern u32 D_004D1780[];

void func_0041FD20(s8 *a)
{
    s32 i;
    s32 k;
    u8 *q = (u8 *)a;
    u32 *dst = (u32 *)D_004CD2D0;
    *(S128 *)dst = *(S128 *)a;
    D_004C2734 = dst;
    D_004C2840[0x1B] = a[0];
    D_004C2840[0x46] = a[1];
    D_004C2840[0x4D] = a[2];
    D_004C2840[0x49] = a[3];
    D_004C2840[0xAE] = a[4];
    D_004C2840[0x52] = a[5];
    D_004C2840[0x53] = a[6];
    D_004C2840[0x54] = a[7];
    D_004C2840[0x55] = a[8];
    D_004C2840[0x56] = a[9];
    D_004C2840[0x57] = a[10];
    D_004C2840[0x58] = a[11];
    D_004C2840[0xB0] = a[12];
    D_004C2840[0xB7] = a[13];
    D_004C2840[0xB8] = a[14];
    D_004C2840[0xB9] = 0;
    D_004C2840[0xBA] = 0;
    if (a[15] == 1) {
        D_004C2840[0xB9] = 1;
    }
    if (a[15] == 2) {
        D_004C2840[0xBA] = 1;
    }
    D_004C2840[0x58] = 0;
    D_004C2840[0xBB] = 0;
    if (a[11] & 1) {
        D_004C2840[0x58] = 1;
    }
    if (a[11] & 2) {
        D_004C2840[0xBB] = 1;
    }
    if (*(s32 *)(q + 0x50) == 0 && *(s32 *)(q + 0x54) == 0) {
        ((QS *)q)->f50 = 0xFFFF77;
        ((QS *)q)->f54 = 0x2000004;
    }
    *(s16 *)(D_004C2840 + 0x108) = 0;
    *(s16 *)(D_004C2840 + 0x106) = 0;
    for (i = 0; i < 2; i++) {
        for (k = 0; k < 3; k++) {
            ((u32 *)D_004CD2B0 + i * 3)[k] = 1 << ((s32 *)q + i * 3)[k + 10];
        }
    }
    *(u32 *)(q + 0x60) = *(u32 *)(q + 0x40) & (*(u32 *)(q + 0x50) | (D_004D1774[0] | D_004C2730[0]));
    *(u32 *)(q + 0x64) = *(u32 *)(q + 0x44) & (*(u32 *)(q + 0x54) | (D_004D1778[0] | D_004C2730[1]));
    *(u32 *)(q + 0x68) = *(u32 *)(q + 0x48) & (*(u32 *)(q + 0x58) | (D_004D177C[0] | D_004C2730[2]));
    *(u32 *)(q + 0x6C) = *(u32 *)(q + 0x4C) & (*(u32 *)(q + 0x5C) | (D_004D1780[0] | D_004C2730[3]));
}
