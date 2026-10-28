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
typedef struct { u8 pad[0x34]; f32 f34; } O34;
typedef struct { s32 a; s32 b; s16 c; s16 d; u8 e; u8 f; u8 pad[2]; } E16;
extern G3c *D_004C2794;
extern E16 D_00464BC0[];

void residual_003899D0(u8 *o) {
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00389C20(u8 *);
    u8 *q;
    E16 *e;
    u32 z;
    u8 *r;
    u32 t;
    t = o[4];
    o[4] = t + 1;
    *(s16 *)(o + 0x26) = 0x1C09;
    q = *(u8 **)(o + 0x18);
    *(B3c *)(o + 0xEC) = *(B3c *)(q + 0xEC);
    o[0x13C] = 1;
    r = o + 2;
    o[2] = q[2];
    o[1] = q[1];
    *(f32 *)(o + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(o + 0x54) = *(f32 *)(q + 0x54);
    o[0x1B7] = q[0x1B7];
    o[0x1B8] = q[0x1B8];
    *(s8 *)(o + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(o + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(o + 0x24) = *(s8 *)(q + 0x24);
    e = &D_00464BC0[o[0x20]];
    *(V3 *)(o + 0x34) = *(V3 *)(q + 0x34);
    if (*(s16 *)(o + 0x140) == 0) {
        ((O34 *)o)->f34 += 1.6666666269302368f * (f32)e->c;
        *(f32 *)(o + 0x5C) = 1.6666666269302368f * (f32)e->a / 65536.0f;
    } else {
        ((O34 *)o)->f34 -= 1.6666666269302368f * (f32)e->c;
        *(f32 *)(o + 0x5C) = -(1.6666666269302368f * (f32)e->a / 65536.0f);
    }
    *(f32 *)(o + 0x38) += 2.142857074737549f * (f32)e->d;
    *(f32 *)(o + 0x60) = 2.142857074737549f * (f32)e->b / 65536.0f;
    *(s32 *)(o + 0x68) = 0;
    *(s32 *)(o + 0x6C) = 0;
    o[0x1B0] = 0x44;
    o[0x1B1] = 0x44;
    o[0x1B5] = e->f;
    z = o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
    *(s32 *)(o + 0x1D8) = 0;
    { s32 x = *r; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    func_001757E0(o, 0x16, e->e);
    func_00389C20(o);
}
