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
typedef struct { u8 pad[0x34]; f32 f34; f32 f38; } Fq;
extern Gq *D_004C2794;

void residual_00360140(u8 *o, u8 *par) {
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00360300(u8 *, u8 *);
    u32 t;
    u8 *q;
    Fq *fo;
    t = o[4];
    o[4] = t + 1;
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
    o[0x13C] = 1;
    o[0x31] = 1;
    *(f32 *)(o + 0x34) = *(f32 *)(par + 0x34);
    *(f32 *)(o + 0x38) = *(f32 *)(par + 0x38);
    *(f32 *)(o + 0x3C) = *(f32 *)(par + 0x3C);
    fo = (Fq *)o;
    q = o + 2;
    if (*(s16 *)(o + 0x140) == 0) {
        fo->f34 += -120.0f;
    } else {
        fo->f34 -= -120.0f;
    }
    *(f32 *)(o + 0x38) += 377.1428527832031f;
    *(s32 *)(o + 0x5C) = 0;
    *(s32 *)(o + 0x60) = 0;
    *(s32 *)(o + 0x68) = 0;
    *(s32 *)(o + 0x6C) = 0;
    *(f32 *)(o + 0x60) = 17.14285659790039f;
    o[0x1B5] = 0x3C;
    o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
    *(s32 *)(o + 0x1D8) = 0;
    { s32 x = *q; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    o[0x1B0] = 0x43;
    o[0x1B1] = 0x42;
    func_001757E0(o, 0x17, 3);
    func_00360300(o, par);
}
