typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } B31;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G7c;
typedef struct { s32 i0; s32 i4; s16 x; s16 y; s8 c; u8 bd; u8 be; u8 bf; } Row;
typedef struct { u8 pad[0x34]; f32 f34; f32 f38; } PS;
extern G7c *D_004C2794;
extern Row D_00463610[];

typedef struct { f32 v; f32 pad[3]; } Tq;
extern u8 *D_004C29FC;
extern u8 *D_004C29F8;
extern Tq D_00472610[];
extern Tq D_00472614[];
extern Tq D_00472618[];
extern Tq D_0047261C[];

void residual_00363270(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_003634D0(u8 *);
    u8 *o;
    Row *row;
    f32 h, v;
    u8 *q;
    o = *(u8 **)(p + 0x18);
    p[4]++;
    *(u16 *)(p + 0x26) = 0x1002;
    *(B31 *)(p + 0xEC) = *(B31 *)(o + 0xEC);
    p[0x13C] = 1;
    p[2] = o[2];
    p[1] = o[1];
    *(f32 *)(p + 0x50) = *(f32 *)(o + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(o + 0x54);
    p[0x1B7] = o[0x1B7];
    p[0x1B8] = o[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(o + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(o + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(o + 0x24);
    p[0x14C] = 0x20;
    p[0x14D] = 0x20;
    p[0x14E] = 0x20;
    p[0x14F] = 0x20;
    row = &D_00463610[p[0x20]];
    *(s8 *)(p + 0x24) = row->c;
    *(V3 *)(p + 0x34) = *(V3 *)(o + 0x34);
    h = 1.66666662693023681640625f;
    q = p + 2;
    if (*(s16 *)(o + 0x140) == 0) {
        ((PS *)p)->f34 += h * (f32)row->x;
        *(f32 *)(p + 0x5C) = h * (f32)row->i0 / 65536.0f;
    } else {
        ((PS *)p)->f34 -= h * (f32)row->x;
        *(f32 *)(p + 0x5C) = -(h * (f32)row->i0 / 65536.0f);
    }
    v = 2.142857074737548828125f;
    ((PS *)p)->f38 += v * (f32)row->y;
    *(s32 *)(p + 0x68) = 0;
    *(f32 *)(p + 0x60) = v * (f32)row->i4 / 65536.0f;
    *(s32 *)(p + 0x6C) = 0;
    p[0x1B0] = 0x44;
    p[0x1B1] = 0x44;
    p[0x1B5] = row->bf;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[*q]++;
    func_001757E0(p, 0x17, row->be);
    func_003634D0(p);
}

#define PAR (*(u8 **)(o + 0x18))

void residual_003997F0(u8 *o) {
    extern void func_001757E0(u8 *, s32, s32);
    u32 t;
    f32 a, b;
    t = o[4];
    o[4] = t + 1;
    *(B31 *)(o + 0xEC) = *(B31 *)(PAR + 0xEC);
    o[0x13C] = 1;
    o[2] = PAR[2];
    o[1] = PAR[1];
    *(f32 *)(o + 0x50) = *(f32 *)(PAR + 0x50);
    *(f32 *)(o + 0x54) = *(f32 *)(PAR + 0x54);
    o[0x1B7] = PAR[0x1B7];
    o[0x1B8] = PAR[0x1B8];
    *(s8 *)(o + 0x30) = *(s8 *)(PAR + 0x30);
    *(V3 *)(o + 0x50) = *(V3 *)(PAR + 0x50);
    *(s8 *)(o + 0x24) = *(s8 *)(PAR + 0x24);
    D_004C29FC[0] = 0x10;
    D_004C29F8[0] = 1;
    *(f32 *)(o + 0x34) = *(f32 *)(PAR + 0x34);
    *(f32 *)(o + 0x38) = *(f32 *)(PAR + 0x38);
    o[0x24] = 0;
    o[0x1B5] = (o[0x1B7] != 0) ? 0x38 : 0x36;
    o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
    *(s32 *)(o + 0x1D8) = 0;
    { s32 x = o[2]; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    if (PAR[0x1E6] != 0) a = D_00472610[o[0x1B7]].v; else a = -D_00472610[o[0x1B7]].v;
    *(f32 *)(o + 0x5C) = a;
    if (PAR[0x1E6] != 0) b = D_00472614[o[0x1B7]].v; else b = -D_00472614[o[0x1B7]].v;
    *(f32 *)(o + 0x68) = b;
    *(f32 *)(o + 0x60) = D_00472618[o[0x1B7]].v;
    *(f32 *)(o + 0x6C) = D_0047261C[o[0x1B7]].v;
    *(f32 *)(o + 0x34) += 26.66666603088379f;
    *(f32 *)(o + 0x38) += 154.28570556640625f;
    o[0x1B0] = 0x42;
    o[0x1B1] = 0x42;
    o[0x14E] = 0x40;
    o[0x14F] = 0x40;
    o[0x14C] = 0x40;
    o[0x14D] = 0x40;
    func_001757E0(o, 0x17, 0);
}
