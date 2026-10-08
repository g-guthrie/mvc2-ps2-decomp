typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
extern volatile u8 D_00630000[0x4380];
#define CURSOR (*(volatile s32 *)(D_00630000 + 0x3e20))
int func_004235D0(u32 value)
{
    volatile u32 *queue;
    volatile u32 *slot;
    s32 index;
    unsigned long long packed;
    s32 wrapped;

    queue = (volatile u32 *)(D_00630000 + 0x3e30);
    index = CURSOR;
    slot = queue + index * 2;
    if ((s32)slot[0] >= 0)
        return -1;
    packed = ((unsigned long long)(value & 0xff)) << 16;
    slot[0] = 0x48000000 | (u32)(packed & 0x00ffffffULL);
    index = CURSOR + 1;
    CURSOR = index;
    wrapped = index & 0x3f;
    if (index < 0 && wrapped != 0)
        wrapped -= 64;
    CURSOR = wrapped;
    return 0;
}
