/* ./try.sh src/grok_kq_00386F30.c "-O4,p -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004F1FC8 __attribute__((section(".data")));
extern f32 D_004F1FCC __attribute__((section(".data")));
extern f32 D_004F1FD0 __attribute__((section(".data")));
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_001E3210(u8 *, s32);

void func_00386F30(u8 *p, u8 *q)
{
    s32 hit;
    f32 vx;
    f32 lim;

    hit = 0;
    vx = *(f32 *)(p + 0x5C);
    if (vx < 0.0f) {
        lim = 26.6666660308837890625f + D_004F1FC8;
        if (*(f32 *)(p + 0x34) < lim) {
            hit += 1;
            *(f32 *)(p + 0x5C) = -vx;
        }
    } else {
        lim = D_004F1FCC - 26.6666660308837890625f;
        if (*(f32 *)(p + 0x34) > lim) {
            hit += 1;
            *(f32 *)(p + 0x5C) = -vx;
        }
    }
    vx = *(f32 *)(p + 0x60);
    if (vx >= 0.0f) {
        lim = D_004F1FD0 - 25.7142848968505859375f;
        if (*(f32 *)(p + 0x38) > lim) {
            hit += 1;
            *(f32 *)(p + 0x60) = -vx;
        }
    } else {
        lim = 17.142856597900390625f + *(f32 *)(q + 0x430);
        if (*(f32 *)(p + 0x38) < lim) {
            hit += 1;
            *(f32 *)(p + 0x60) = -vx;
        }
    }
    if (hit) {
        p[0x21] += 1;
        p[0x1B5] = 0x39;
        p[0x1B2] = *(unsigned short *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 0x7C))[p[2]]++;
        func_001E3210(p, 0x1F);
    }
}
