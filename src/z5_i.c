typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G1;
extern G1 *D_004C2794;

void func_00349140(u8 *p, u8 *q) {
    u8 *o;
    u16 *r;
    extern void func_00175910();
    extern void func_0034A080();
    o = *(u8 **)(p + 0x14);
    *(u32 *)(p + 0x14C) = 0x20203030;
    p[0x1B0] = 0x42;
    p[0x1B1] = 0;
    p[0x1B5] = *(s8 *)(o + 0x15B) + 0x45;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    *(u32 *)(p + 0x5C) = 0x43200000;
    *(u32 *)(p + 0x68) = 0x42D20000;
    r = (u16 *)(p + 0x88);
    if (*(s16 *)(p + 0x140) == 0) {
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
    }
    *r = *(u16 *)(q + 0x168);
    p[0x169] = 0x16;
    p[0x168] = 0x1E;
    func_00175910(p, p[0x169], p[0x168], *(s8 *)(o + 0x151));
    *(s8 *)(p + 0x31) = -4;
    func_0034A080(p, q);
}

typedef struct { u8 pad[8]; s16 idx; } GS;
extern GS *D_004C2840;
typedef struct { f32 x, y, z; f32 pad[4]; } E28;
typedef struct { f32 x, y, z; } V3x;
extern E28 D_00442B50[];
extern s32 D_004C2804;

void func_001484C0(u8 *p) {
    extern void func_0012AD00();
    *(V3x *)(p + 0x34) = *(V3x *)&D_00442B50[D_004C2840->idx];
    if (D_004C2840->idx == 8) {
        *(s16 *)(p + 0xCC) = 0x7D;
        *(s32 *)(p + 0x84) = D_004C2804;
        *(u32 *)(p + 0x3C) = 0xC14FD70A;
        *(u32 *)(p + 0x50) = 0x3F800000;
        *(u32 *)(p + 0x54) = 0x3F800000;
        *(u32 *)(p + 0x58) = 0x3F800000;
    } else {
        *(s16 *)(p + 0xCC) = 0xCD;
        *(s32 *)(p + 0x84) = D_004C2804;
        *(f32 *)(p + 0x3C) -= 0.00999999978f;
        *(u32 *)(p + 0x54) = 0x3F266666;
        if (D_004C2840->idx == 7) {
            *(u32 *)(p + 0x50) = 0x4051EB85;
        } else {
            *(u32 *)(p + 0x50) = 0x3FF70A3D;
        }
    }
    if (*(s32 *)(p + 0xD8) != D_004C2840->idx) {
        *(s32 *)(p + 0xD8) = D_004C2840->idx;
        *(s16 *)(p + 0x1E) = 0;
    }
    func_0012AD00(p);
}

typedef struct { f32 x, y, z; u16 h; s8 pad; s8 b; } E16;
extern E16 D_004428C0[];
extern V3x D_00442890;

void func_00147090(u8 *p) {
    E16 *e;
    extern void func_00146D80();
    u32 t = p[4];
    p[4] = t + 1;
    p[0x13C] = 1;
    e = &D_004428C0[p[0x20]];
    *(u16 *)(p + 0xCC) = e->h;
    *(s32 *)(p + 0x84) = D_004C2804;
    *(V3x *)(p + 0x34) = *(V3x *)e;
    *(V3x *)(p + 0x50) = D_00442890;
    if (p[0x20] == 0) {
        *(u32 *)(p + 0x78) = 0x3F75C28F;
        *(u32 *)(p + 0x7C) = 0x3F666666;
        *(u32 *)(p + 0x80) = 0x3F7AE148;
    } else if (D_004C2840->idx == (u8)(p[0x20]) - 1) {
        *(u32 *)(p + 0x78) = 0x3F7AE148;
        *(u32 *)(p + 0x7C) = 0x3F800000;
        *(u32 *)(p + 0x80) = 0x3EA8F5C3;
    } else {
        *(u32 *)(p + 0x78) = 0x3E947AE1;
        *(u32 *)(p + 0x7C) = 0x3EF5C28F;
        *(u32 *)(p + 0x80) = 0x3F3851EC;
    }
    func_00146D80(p, 0, e->b);
}
