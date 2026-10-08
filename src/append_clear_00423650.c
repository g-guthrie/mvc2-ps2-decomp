typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
extern volatile u8 D_00630000[0x4000];
#define CURSOR (*(volatile s32 *)(D_00630000 + 0x3e20))
int func_00423650(void)
{
    volatile u32 *queue;
    volatile u32 *slot;
    s32 index;
    s32 wrapped;

    queue = (volatile u32 *)(D_00630000 + 0x3e30);
    index = CURSOR;
    slot = queue + index * 2;
    if ((s32)slot[0] >= 0)
        return -1;
    slot[0] = 0x40000000;
    index = ++CURSOR;
    wrapped = index & 0x3f;
    if (index < 0 && wrapped != 0)
        wrapped -= 64;
    CURSOR = wrapped;
    return 0;
}
