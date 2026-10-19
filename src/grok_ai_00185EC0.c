typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00185F90(s32);

s32 func_00185EC0(u8 *p)
{
    u8 ok;
    if (p[0x20D] == 2)
        ok = *(f32 *)(p + 0x34) < *(f32 *)(*(u8 **)(p + 0x220) + 0x34);
    else {
        u32 bits = 0x41BAAAAA;
        f32 off = *(f32 *)&bits;
        if (!p[0x1E6])
            off = -off;
        ok = *(f32 *)(p + 0x34) <= *(f32 *)(*(u8 **)(p + 0x220) + 0x34) + off;
    }
    ok = (u8)ok;
    if (!(*(u16 *)(p + 0x354) & (1 << (ok + 10))))
        return 0;
    return func_00185F90(p[2]) != 0;
}
