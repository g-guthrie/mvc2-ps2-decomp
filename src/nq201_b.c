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
typedef struct { s32 w0; s32 w4; s16 h8; s16 hA; u8 bC; u8 bD; u8 pad[2]; } E10;
extern G3c *D_004C2794;
typedef struct { u8 pad[0x34]; f32 f34; } P34;
extern E10 D_00464820[];

void residual_00385AA0(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E3210(u8 *, s32);
    extern void func_00385D40(u8 *);
    u8 *q;
    E10 *e;
    u32 t;
    u8 *c;
    q = *(u8 **)(p + 0x18);
    t = p[4];
    p[4] = t + 1;
    *(s16 *)(p + 0x26) = 0x1C00;
    *(B3c *)(p + 0xEC) = *(B3c *)(q + 0xEC);
    p[0x13C] = 1;
    p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    p[0x24] = 8;
    p[0x14C] = 0x10;
    p[0x14D] = 0x10;
    p[0x14E] = 0x10;
    p[0x14F] = 0x10;
    c = p + 2;
    if (q[1] == 0x1D) {
        p[0x13D] = 1;
        *(s16 *)(p + 0x13E) -= 2;
    }
    e = &D_00464820[p[0x20]];
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    if (*(s16 *)(p + 0x140) == 0) {
        ((P34 *)p)->f34 += 1.6666666269302368f * (f32)e->h8;
        *(f32 *)(p + 0x5C) = 1.6666666269302368f * (f32)e->w0 / 65536.0f;
    } else {
        ((P34 *)p)->f34 -= 1.6666666269302368f * (f32)e->h8;
        *(f32 *)(p + 0x5C) = -(1.6666666269302368f * (f32)e->w0 / 65536.0f);
    }
    *(f32 *)(p + 0x38) += 2.142857074737549f * (f32)e->hA;
    *(f32 *)(p + 0x60) = 2.142857074737549f * (f32)e->w4 / 65536.0f;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6C) = 0;
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    p[0x1B5] = e->bD;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[*c]++;
    func_001757E0(p, 0x17, e->bC);
    func_001E3210(q, 0x25);
    func_00385D40(p);
}
