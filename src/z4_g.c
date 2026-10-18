typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_00458A40[], D_00458A50[], D_00458AE0[], D_00458AF0[];

static s32 func_002AB9A0(u8 *p)
{
    s32 i, r = 0;
    for (i = 0; i < 8; i++)
        r += p[i * 3];
    return r;
}

s32 func_002ABCA0(u8 *p)
{
    extern s32 func_00189310(u8 *, u8 *, u8 *);
    extern void func_0018A990(u8 *, u8 *);
    extern void func_00186A60(u8 *, s32);
    u8 *t;
    if (*(u32 *)(p + 0xD0) == 0) {
        if (*(s8 *)(p + 0x539) != 0 && p[0x20D] == 2)
            t = D_00458A50;
        else
            t = D_00458A40;
    } else {
        if (*(s8 *)(p + 0x539) != 0 && p[0x20D] == 2)
            t = D_00458AF0;
        else
            t = D_00458AE0;
    }
    if (!func_00189310(p, t, p + 0x390))
        return 0;
    if (!func_002AB9A0(p))
        return 0;
    func_0018A990(p, p + 0x390);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    if (p[0x20D] != 2)
        p[0x1FD] = 0;
    else
        p[0x1FD] = 0xD;
    func_00186A60(p, 0x15);
    return 1;
}
