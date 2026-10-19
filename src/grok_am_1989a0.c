typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern void func_001754A0(u8 *, s32, s32);

void residual_001989A0(u8 *p)
{
    u8 *g = *(u8 **)(p + 0x14);
    if (g[4] != 2 && g[5] != 0) {
        p[5] = 3;
        func_001754A0(p, 0x1B, 4);
        return;
    }
    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) - 1;
    if (*(s16 *)(p + 0x1C) < 0)
        return;
    {
        u8 one = 1;
        p[5] = p[5] + 1;
        p[0x13C] = one;
        *(s16 *)(p + 0x1C) = 6;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        *(f32 *)(p + 0x5C) = (*(f32 *)(g + 0x34) - *(f32 *)(p + 0x34)) / 8.0f;
        *(f32 *)(p + 0x60) = (*(f32 *)(g + 0x38) - *(f32 *)(p + 0x38)) / 8.0f;
        func_001754A0(p, 0x1B, 3);
    }
}
