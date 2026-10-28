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
extern Row D_00463540[];

void residual_00362080(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_003622F0(u8 *);
    u8 *o;
    Row *row;
    f32 h, v;
    u8 *q;
    o = *(u8 **)(p + 0x18);
    p[4]++;
    *(u16 *)(p + 0x26) = 0x1000;
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
    p[0x14C] = 0x30;
    p[0x14D] = 0x30;
    p[0x14E] = 0x10;
    p[0x14F] = 0x10;
    *(u16 *)(p + 0x1C) = 0x1E;
    row = &D_00463540[p[0x20]];
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
    *(f32 *)(p + 0x60) = v * (f32)row->i4;
    *(s32 *)(p + 0x6C) = 0;
    p[0x1B0] = 0x43;
    p[0x1B1] = 0x42;
    p[0x1B5] = row->bf;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[*q]++;
    func_001757E0(p, 0x17, row->be);
    func_003622F0(p);
}

