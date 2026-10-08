typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern volatile u8 D_00630000[0x4380];
#define CURSOR (*(volatile s32 *)(D_00630000 + 0x3e18))
#define BUFFER ((volatile u8 *)(D_00630000 + 0x4100))
int func_004239D0(u32 header, u8 field4, u8 field5, u16 field6)
{
    int length;
    int index;
    u32 flags;
    u16 tail;
    volatile u8 *out;

    flags = header >> 24;
    length = 4;
    if (flags & 1)
        length++;
    if (flags & 2)
        length++;
    if (flags & 4)
        length += 2;
    index = CURSOR;
    if (index + length >= 512)
        return -1;

    out = BUFFER + index;
    *out++ = (u8)(header >> 24);
    *out++ = (u8)(header >> 16);
    *out++ = (u8)(header >> 8);
    *out++ = (u8)header;
    if (flags & 1)
        *out++ = (u8)field4;
    if (flags & 2)
        *out++ = (u8)field5;
    if (flags & 4) {
        tail = (u16)field6;
        *out++ = (u8)(tail >> 8);
        *out++ = (u8)tail;
    }
    CURSOR = CURSOR + length;
    *out = 0xff;
    return 0;
}
