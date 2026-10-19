typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00185BB0(u8 *);
extern void func_00191210(u8 *);
extern s32 func_00185F90(s32);
extern s32 func_00186CE0(u8 *, s32);

s32 func_00185CA0(u8 *p)
{
    u8 ok;
    func_00191210(p);
    if (p[0x216] & 0x80)
        return 0;
    if (*(s8 *)(p + 0x204))
        return 0;
    if (p[0x425])
        return 0;
    if (p[0x20D] == 2)
        return func_00185BB0(p);
    {
        u32 bits = 0x41BAAAAA;
        f32 off = *(f32 *)&bits;
        if (!p[0x1E6])
            off = -off;
        ok = *(f32 *)(p + 0x34) <= *(f32 *)(*(u8 **)(p + 0x220) + 0x34) + off;
    }
    ok = (u8)ok;
    if (!(*(u16 *)(p + 0x35C) & (1 << (ok + 10))))
        return 0;
    if (*(u16 *)(p + 0x354) & 0x1000)
        p[0x20D] = 1;
    if (!func_00185F90(p[2]))
        return 0;
    return (u8)func_00186CE0(p, 0x12);
}
