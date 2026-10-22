typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G39;
typedef struct { s32 x[49]; } S49;
typedef struct { f32 x, y, z; } V3;
extern G39 *D_004C2794;

#define PAR (*(u8 **)(p + 0x18))

void func_00379C70(u8 *p)
{
    extern void func_001E3210(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u8 *o;
    s16 *x;
    u8 *c;
    f32 dx, dy;
    s32 t;

    o = PAR;
    x = (s16 *)(p + 0xD0);
    p[4]++;
    *(S49 *)(p + 0xEC) = *(S49 *)(PAR + 0xEC);
    p[0x13C] = 1;
    p[2] = PAR[2];
    p[1] = PAR[1];
    *(f32 *)(p + 0x50) = *(f32 *)(PAR + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(PAR + 0x54);
    p[0x1B7] = PAR[0x1B7];
    p[0x1B8] = PAR[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(PAR + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(PAR + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(PAR + 0x24);
    p[0x13C] = 1;
    *(V3 *)(p + 0x34) = *(V3 *)(PAR + 0x34);
    c = p + 2;
    if (o[0x20D] == 2) {
        if (*(s16 *)(p + 0x140) != 0) dx = 143.0f; else dx = -143.0f;
        *(f32 *)(p + 0x34) += dx;
        dy = 187.0f;
        *(f32 *)(p + 0x38) += dy;
    } else {
        if (*(s16 *)(p + 0x140) != 0) dx = 130.0f; else dx = -130.0f;
        *(f32 *)(p + 0x34) += dx;
        dy = 136.0f;
        *(f32 *)(p + 0x38) += dy;
    }
    *(f32 *)(p + 0x64) = *(f32 *)(p + 0x34);
    if (*(s16 *)(p + 0x140) != 0) t = p[0x23] * 40; else t = -(p[0x23] * 40);
    *(f32 *)(p + 0x34) += (f32)t;
    *(f32 *)(p + 0x70) = *(f32 *)(p + 0x38);
    if (p[0x23] != 0) {
        p[0x24] = 0;
        p[0x31] = p[0x23];
    } else {
        p[0x24] = 0xB;
        p[0x31] = p[0x23];
        func_001E3210(p, 0x20);
    }
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(s16 *)(p + 0x1C) = *(s16 *)(PAR + 0x1E);
    p[0x1B0] = 0;
    p[0x1B1] = 0;
    p[0x1B5] = (((s32)p[0x23] / 2) % 2 == 1) ? 0x30 : 0x38;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[*c]++;
    x[1] = 8;
    *(s32 *)(o + 0x2DC) = 0;
    if (p[0x23] == 0xE) {
        func_001757E0(p, 0x17, 2);
    } else if (p[0x23] == 0) {
        func_001757E0(p, 0x17, 1);
    } else {
        func_001757E0(p, 0x17, 0);
    }
    x[3] = 2;
}
