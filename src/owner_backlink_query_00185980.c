typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
typedef signed char s8;
typedef signed short s16;
extern u8 D_004F20B0[];
s32 func_00185980(u8 *p)
{
    u8 *owner;
    u8 *candidate;
    u8 state;
    s8 flags = *(s8 *)(p + 0x1B2);
    if ((flags & 0x80) == 0)
        return 0;
    owner = *(u8 **)(p + 0x1C4);
    if (owner[3] != 0)
        return 0;
    if ((flags & 0x11) != 0)
        return 0;
    candidate = *(u8 **)(owner + 0x1C8);
    if (p != candidate)
        return 0;
    if (owner[0x425] != 0)
        return 0;
    if (owner[0x20D] == 3)
        return 0;
    if (*(s16 *)(owner + 0x434) == 0)
        return 0;
    if ((*(u32 *)(owner + 0x428) & 0x07000000) != 0)
        return 0;
    if (owner[5] != 3)
        return 0;
    {
        u8 *slot = D_004F20B0 + (u32)p[0x1B8] * 0x5B8;
        state = slot[5];
    }
    if (state == 2 || state == 1)
        return 0;
    return 1;
}
