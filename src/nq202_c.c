/* residual_00385F70: MW 3.0 "-O3 -Op -sdatathreshold 8" (./try30.sh), no warm-up needed. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } Bq;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } Gq;
typedef struct { u8 pad[0x34]; f32 f34; } Of;
typedef struct { s32 x; s32 y; s16 h8; s16 hA; u8 c; u8 d; u8 pad[2]; } E16;
extern Gq *D_004C2794;
extern E16 D_00464880[];

void residual_00385F70(u8 *o) {
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E3210(u8 *, s32);
    extern void func_00386210(u8 *);
    u32 t;
    u8 *par;
    E16 *e;
    u8 *q;
    Of *so;
    par = *(u8 **)(o + 0x18);
    t = o[4];
    o[4] = t + 1;
    *(s16 *)(o + 0x26) = 0x1C01;
    *(s16 *)(o + 0x1C) = -1;
    *(Bq *)(o + 0xEC) = *(Bq *)(par + 0xEC);
    o[0x13C] = 1;
    o[2] = par[2];
    o[1] = par[1];
    *(f32 *)(o + 0x50) = *(f32 *)(par + 0x50);
    *(f32 *)(o + 0x54) = *(f32 *)(par + 0x54);
    o[0x1B7] = par[0x1B7];
    o[0x1B8] = par[0x1B8];
    *(s8 *)(o + 0x30) = *(s8 *)(par + 0x30);
    *(V3 *)(o + 0x50) = *(V3 *)(par + 0x50);
    *(s8 *)(o + 0x24) = *(s8 *)(par + 0x24);
    o[0x24] = 8;
    o[0x13C] = 1;
    o[0x14C] = 0x10;
    o[0x14D] = 0x10;
    o[0x14E] = 0x10;
    o[0x14F] = 0x10;
    q = o + 2;
    so = (Of *)o;
    if (par[1] == 0x1D) {
        o[0x13D] = 1;
        *(s16 *)(o + 0x13E) = *(s16 *)(par + 0x13E) - 2;
    }
    e = &D_00464880[o[0x20]];
    *(V3 *)(o + 0x34) = *(V3 *)(par + 0x34);
    if (*(s16 *)(o + 0x140) == 0) {
        so->f34 += 1.6666666269302368f * (f32)e->h8;
        *(f32 *)(o + 0x5C) = 1.6666666269302368f * (f32)e->x / 65536.0f;
    } else {
        so->f34 -= 1.6666666269302368f * (f32)e->h8;
        *(f32 *)(o + 0x5C) = -(1.6666666269302368f * (f32)e->x / 65536.0f);
    }
    *(f32 *)(o + 0x38) += 2.142857074737549f * (f32)e->hA;
    *(f32 *)(o + 0x60) = 2.142857074737549f * (f32)e->y / 65536.0f;
    *(s32 *)(o + 0x68) = 0;
    *(s32 *)(o + 0x6C) = 0;
    o[0x1B0] = 0x42;
    o[0x1B1] = 0x42;
    o[0x1B5] = e->d;
    o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
    *(s32 *)(o + 0x1D8) = 0;
    { s32 x = *q; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    func_001757E0(o, 0x17, e->c);
    func_001E3210(par, 0x26);
    func_00386210(o);
}
