typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;
typedef int s32;

extern s32 func_00185F90(u8);

s32 func_00185EC0(u8 *p)
{
    u8 flag;
    f32 d;
    u32 bits;
    u8 *o;

    if (p[0x20D] == 2) {
        o = *(u8 **)(p + 0x220);
        flag = *(f32 *)(p + 0x34) < *(f32 *)(o + 0x34);
    } else {
        d = 23.333332061767578125f;
        if (p[0x1E6] == 0)
            d = -d;
        o = *(u8 **)(p + 0x220);
        flag = *(f32 *)(p + 0x34) <= *(f32 *)(o + 0x34) + d;
    }
    if ((*(u16 *)(p + 0x354) & (1 << (flag + 0xA))) == 0)
        return 0;
    return func_00185F90(p[2]) != 0;
}
