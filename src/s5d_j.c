/* s5d: MW 3.0.3 WARM: mwccps2(3.0.3) src/sf2_b.c src/s5d_j.c -c -lang c -i src -O3 -Op -fp off -sdatathreshold 0 (driver MWWARM@src/sf2_b.c). Cold fails. case 0x63 written as break (not return) and the case-2 conversion as (double)v so the warm helper model blocks the beq-slot fill. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0013AAC0(u8 *p) {
    f32 v, w;
    *(s32 *)(p + 0x48) = *(s32 *)(*(u8 **)(p + 0x18) + 0x48);
    switch (p[6]) {
    case 0:
        if (*(s8 *)(*(u8 **)(p + 0x14) + 0x4DD) == p[0x21]) {
            p[6] = 1;
        } else {
            p[6] = 2;
        }
        break;
    case 1:
        *(f32 *)(p + 0x54) += 0.1f;
        if (*(f32 *)(p + 0x54) >= 1.0f) {
            p[6] = 0x63;
            *(f32 *)(p + 0x54) = 1.0f;
        }
        break;
    case 2:
        v = *(f32 *)(p + 0x54);
        w = v - 0.1f;
        *(f32 *)(p + 0x54) = w;
        if ((double)w <= 0.0) {
            p[6] = 0x63;
            *(u32 *)(p + 0x54) = 0x3C23D70A;
        }
        break;
    case 0x63:
        break;
    }
}

typedef struct O13 { u8 pad0[0x18]; struct O13 *o18; u8 pad1[0x10]; s32 i2c; u8 pad2[0x18]; s32 i48; } O13;
typedef struct { u8 pad0[6]; u8 b6; u8 pad1[0x11]; O13 *o18; u8 pad2[5]; u8 b21; u8 pad3[0x26]; s32 i48; u8 pad4[8]; f32 f54; } P13AC;

void func_0013AC90(P13AC *p) {
    extern double func_00119058(f32);
    f32 v;
    p->i48 = p->o18->i48;
    switch (p->b6) {
    case 0:
        if (p->o18->o18->i2c == p->b21) {
            p->b6 = 1;
        } else {
            p->b6 = 2;
        }
        break;
    case 1:
        p->f54 += 0.1f;
        v = p->f54;
        if (!(v < 1.0f)) {
            p->b6 = 0x63;
            p->f54 = 1.0f;
        }
        break;
    case 2:
        v = p->f54 - 0.1f;
        p->f54 = v;
        if ((double)v <= 0.0) {
            p->b6 = 0x63;
            *(u32 *)&p->f54 = 0x3C23D70A;
        }
        break;
    case 0x63:
        break;
    }
}
