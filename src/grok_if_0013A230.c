typedef unsigned char u8;
typedef signed int s32;
typedef unsigned int u32;

void residual_0013A230(u8 *p)
{
    if (p[0x20] != 0) {
        *(s32 *)(p + 0x48) = *(s32 *)(p + 0x48) - 0x200;
        if (*(s32 *)(p + 0x48) > 0)
            return;
        {
            u32 phase;
            phase = p[4];
            p[4] = (u8)(phase + 1);
        }
        *(s32 *)(p + 0x48) = 0;
    } else {
        *(s32 *)(p + 0x48) = *(s32 *)(p + 0x48) + 0x200;
        if (*(s32 *)(p + 0x48) < 0x10000)
            return;
        {
            u32 phase;
            phase = p[4];
            p[4] = (u8)(phase + 1);
        }
        *(s32 *)(p + 0x48) = 0;
    }
}
