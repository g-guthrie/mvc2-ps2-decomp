typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2794;
extern int func_001757E0(void *, int, int);

s32 func_002780D0(u8 *p)
{
    p[6]++;
    p[0x20D] = 2;
    *(u32 *)(p + 0x5C) = 0x41F00000;
    if (p[0x1E6] == 0) *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0x40892492;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    p[0x1B5] = 0x34;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    (*(s16 *)((p[2] << 1) + (u32)D_004C2794 + 0x7C))++;
    return func_001757E0(p, 0x14, 0);
}

s32 func_00261950(u8 *p)
{
    p[6]++;
    p[0x20D] = 2;
    *(u32 *)(p + 0x5C) = 0x41F00000;
    if (p[0x1E6] == 0) *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0x40892492;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    p[0x1B5] = 0x13;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    (*(s16 *)((p[2] << 1) + (u32)D_004C2794 + 0x7C))++;
    return func_001757E0(p, 0x14, 0);
}

s32 func_0025AF60(u8 *p)
{
    p[6]++;
    p[0x20D] = 2;
    *(u32 *)(p + 0x5C) = 0x41F00000;
    if (p[0x1E6] == 0) *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0x40892492;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    p[0x1B5] = 0x41;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    (*(s16 *)((p[2] << 1) + (u32)D_004C2794 + 0x7C))++;
    return func_001757E0(p, 0x14, 0);
}
