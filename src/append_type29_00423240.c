typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed int s32;
extern volatile u8 D_00630000[0x4380];
#define CURSOR (*(volatile s32 *)(D_00630000 + 0x3e20))
#define QUEUE ((volatile u32 *)(D_00630000 + 0x3e30))
s32 func_00423240(u32 value)
{
    volatile u32 *slot;
    s32 index;
    s32 wrapped;

    index = CURSOR;
    slot = QUEUE + index * 2;
    if ((s32)slot[0] >= 0)
        return -1;
    slot[0] = (u32)(0x29000000ULL | ((((u64)(value & 0xffff)) << 8) & 0x00ffffffULL));
    index = CURSOR + 1;
    CURSOR = index;
    wrapped = index & 0x3f;
    if (index < 0 && wrapped != 0)
        wrapped -= 64;
    CURSOR = wrapped;
    return 0;
}
