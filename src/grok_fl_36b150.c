typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 *D_004C2794 __attribute__((section(".sdata")));
extern void func_0036AAF0(u8 *, s32, s32);
extern void func_001757E0(u8 *, s32, s32);

void func_0036B150(u8 *p)
{
    f32 add;
    p[0x13C] = 1;
    p[0x24] = 0;
    add = *(s16 *)(p + 0x140) ? 63.333332061767578125f : -63.333332061767578125f;
    *(f32 *)(p + 0x34) += add;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(u32 *)(p + 0x54) = 0x3C23D70A;
    *(u32 *)(p + 0x60) = 0x3EC28F5C;
    *(u32 *)(p + 0x6C) = 0xBCA3D70A;
    *(u32 *)(p + 0x118) = 0x3F800000;
    *(s16 *)(p + 0x1C) = 5;
    *(f32 *)(p + 0x5C) = *(s16 *)(p + 0x140) ? 1.6666666269302368f : -1.6666666269302368f;
    *(f32 *)(p + 0x68) = *(s16 *)(p + 0x140) ? -0.02604166604578495f : 0.02604166604578495f;
    func_0036AAF0(p, 8, p[0x23]);
    p[0x23]++;
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    p[0x1B5] = 0x3E;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794[p[2] + 0x3E]++;
    func_001757E0(p, 0x17, 7);
}
