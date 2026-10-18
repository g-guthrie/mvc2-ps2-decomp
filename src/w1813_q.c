typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 x[0x31]; } Blk;
typedef struct { f32 x, y, z; } V3;

void func_001B0690(u8 *p)
{
    extern void func_00176160(u8 *, s32, s32, s32);
    extern void func_001754A0(u8 *, s32, s32);
    extern void func_0015E630(u8 *);
    u8 *src;
    u32 t;
    f32 d;
    t = p[4];
    p[4] = t + 1;
    src = *(u8 **)(p + 0x18);
    *(Blk *)(p + 0xEC) = *(Blk *)(src + 0xEC);
    p[0x13C] = 1;
    p[2] = src[2];
    p[1] = src[1];
    *(f32 *)(p + 0x50) = *(f32 *)(src + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(src + 0x54);
    p[0x1B7] = src[0x1B7];
    p[0x1B8] = src[0x1B8];
    p[0x30] = *(s8 *)(src + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(src + 0x50);
    p[0x24] = *(s8 *)(src + 0x24);
    p[0x13C] = 1;
    p[0x24] = 7;
    *(u32 *)(p + 0x118) = 0x3F800000;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(*(u8 **)(p + 0x18) + 0x3C);
    d = (*(s16 *)(*(u8 **)(p + 0x18) + 0x140) != 0) ? 160.0f : -160.0f;
    *(f32 *)(p + 0x34) += d;
    *(u32 *)(p + 0x54) = 0x3F800000;
    func_00176160(src, 6, 6, 1);
    func_001754A0(p, 0x1B, 0xD);
    func_0015E630(p);
    p[0] = 1;
}

void func_001B03B0(u8 *p)
{
    extern void func_00176160(u8 *, s32, s32, s32);
    extern void func_001754A0(u8 *, s32, s32);
    extern void func_0015E630(u8 *);
    u8 *src;
    u32 t;
    f32 d;
    t = p[4];
    p[4] = t + 1;
    src = *(u8 **)(p + 0x18);
    *(Blk *)(p + 0xEC) = *(Blk *)(src + 0xEC);
    p[0x13C] = 1;
    p[2] = src[2];
    p[1] = src[1];
    *(f32 *)(p + 0x50) = *(f32 *)(src + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(src + 0x54);
    p[0x1B7] = src[0x1B7];
    p[0x1B8] = src[0x1B8];
    p[0x30] = *(s8 *)(src + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(src + 0x50);
    p[0x24] = *(s8 *)(src + 0x24);
    p[0x13C] = 1;
    p[0x24] = 7;
    *(u32 *)(p + 0x118) = 0x3F800000;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(*(u8 **)(p + 0x18) + 0x3C);
    d = (*(s16 *)(*(u8 **)(p + 0x18) + 0x140) != 0) ? 160.0f : -160.0f;
    *(f32 *)(p + 0x34) += d;
    *(u32 *)(p + 0x54) = 0x3F800000;
    func_00176160(src, 4, 4, 1);
    func_001754A0(p, 0x1B, 0xB);
    func_0015E630(p);
    p[0] = 1;
}
