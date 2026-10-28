/* MWCC 3.0: ./try30.sh src/nq181_c.c "-O3 -Op -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } B3c;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G3c;
typedef struct { s32 a, b, c, d; u8 f10, f11; u8 pad[2]; } E14;
extern G3c *D_004C2794;
extern E14 D_00464C30[];


void residual_0038A0C0(u8 *o) {
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_0038A300(u8 *);
    u32 t;
    u32 z;
    E14 *e;
    u8 *q;
    u8 *p2;
    q = *(u8 **)(o + 0x18);
    t = o[4];
    o[4] = t + 1;
    *(s16 *)(o + 0x26) = 0x1D00;
    *(B3c *)(o + 0xEC) = *(B3c *)(q + 0xEC);
    o[0x13C] = 1;
    o[2] = q[2];
    o[1] = q[1];
    *(f32 *)(o + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(o + 0x54) = *(f32 *)(q + 0x54);
    o[0x1B7] = q[0x1B7];
    o[0x1B8] = q[0x1B8];
    *(s8 *)(o + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(o + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(o + 0x24) = *(s8 *)(q + 0x24);
    *(s8 *)(o + 0x24) = 0xB;
    o[0x13D] = 1;
    p2 = o + 2;
    if (q[2] != 0) {
        *(s16 *)(o + 0x13E) += 0xE;
    } else {
        *(s16 *)(o + 0x13E) += 6;
    }
    e = &D_00464C30[o[0x20]];
    if (*(s16 *)(o + 0x140) == 0) {
        *(f32 *)(o + 0x5C) = 1.6666666269302368f * (f32)e->a / 65536.0f;
        *(f32 *)(o + 0x68) = 1.6666666269302368f * (f32)e->b / 65536.0f;
    } else {
        *(f32 *)(o + 0x5C) = -(1.6666666269302368f * (f32)e->a / 65536.0f);
        *(f32 *)(o + 0x68) = -(1.6666666269302368f * (f32)e->b / 65536.0f);
    }
    *(f32 *)(o + 0x60) = 2.142857074737549f * (f32)e->c / 65536.0f;
    *(f32 *)(o + 0x6C) = 2.142857074737549f * (f32)e->d / 65536.0f;
    o[0x1B0] = 0x44;
    o[0x1B1] = 0x44;
    o[0x1B5] = e->f11;
    z = o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
    *(s32 *)(o + 0x1D8) = 0;
    { s32 x = *p2; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    func_001757E0(o, 0x17, e->f10);
    func_0038A300(o);
}
