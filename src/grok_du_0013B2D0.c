typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;

extern u8 D_00583B92[];
extern u8 D_004B1221[];
extern u32 D_004C2830 __attribute__((section(".sdata")));

void residual_0013B2D0(u8 *p)
{
    if (p[0x20] != 0)
        *(s32 *)(p + 0x48) = *(s32 *)(p + 0x48) - 0x400;
    else
        *(s32 *)(p + 0x48) = *(s32 *)(p + 0x48) + 0x400;
    if (D_00583B92[p[0x20]] & (1 << p[0x21])) {
        u32 phase;
        phase = p[4];
        p[4] = (u8)(phase + 1);
        *(s16 *)(p + 0xCC) = D_004B1221[(*(u8 **)(p + 0x18))[1] * 2] + 0x78;
        *(u32 *)(p + 0x84) = D_004C2830;
        *(u32 *)(p + 0xD0) = 0x810;
        *(s16 *)(p + 0x1C) = 0x14;
    }
}
