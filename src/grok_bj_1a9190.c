typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_001754A0(u8 *, s32, s32);
extern void func_001A9290(u8 *, u8 *);

void func_001A9190(u8 *p, u8 *q)
{
    p[5]++;
    p[0x24] = 0xB;
    if (*(s16 *)(p + 0x140) == 0)
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) - 53.333332061767578f;
    else
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + 53.333332061767578f;
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38) + 102.85713958740234f;
    if (*(s16 *)(p + 0x140) == 0)
        *(u32 *)(p + 0x5C) = 0xBF555555;
    else
        *(u32 *)(p + 0x5C) = 0x3F555555;
    *(s32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0x419A4924;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    func_001754A0(p, 0x1B, 0xB);
    func_001A9290(p, q);
}
