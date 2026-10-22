typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

u8 func_00185CA0(u8 *p)
{
    extern u8 func_00185BB0(u8 *);
    extern void func_00191210();
    extern s32 func_00185F90(s32);
    extern s32 func_00186CE0(u8 *, s32);
    f32 x;
    f32 y;
    f32 c;
    u8 *pp;
    u8 ok;
    u32 h;
    u32 m;
    func_00191210();
    if ((p[0x216] & 0x80) != 0 || *(s8 *)(p + 0x204) != 0 || p[0x425] != 0)
        return 0;
    if (p[0x20D] == 2)
        return func_00185BB0(p);
    if (p[0x1E6] == 0)
        c = -23.333332061767578f;
    else
        c = 23.333332061767578f;
    pp = *(u8 **)(p + 0x220);
    x = *(f32 *)(p + 0x34);
    y = *(f32 *)(pp + 0x34);
    y += c;
    ok = (x > y) ? 0 : 1;
    h = *(u16 *)(p + 0x35C); m = 1 << (ok + 10); if ((h & m) == 0)
        return 0;
    if ((*(u16 *)(p + 0x354) & 0x1000) != 0)
        p[0x20D] = 1;
    if (func_00185F90(p[2]) == 0)
        return 0;
    return func_00186CE0(p, 0x12);
}
