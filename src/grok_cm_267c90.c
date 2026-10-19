typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_001757E0(u8 *, int, int);

int func_00267C90(u8 *p, int alt)
{
    u16 bits;
    int ok = 1;
    if (alt)
        bits = *(u16 *)(p + 0x35C);
    else
        bits = *(u16 *)(p + 0x354);
    if (!(bits & 0xC00))
        return 0;
    p[7] = ok;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    p[0x210] = 0;
    p[0x20D] = 0;
    p[0x1E7] = (u8)((*(u16 *)(p + 0x35E) & 0x400) >> 10);
    func_001757E0(p, 0x16, ((s8)p[0x1E7] + 0x1D) & 0xFF);
    if (*(s16 *)(p + 0x140) == 0) {
        *(u32 *)(p + 0x5C) = 0xC0B40000;
        if ((s8)p[0x1E7])
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    } else {
        *(u32 *)(p + 0x5C) = 0x40B40000;
        if ((s8)p[0x1E7])
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    }
    return ok;
}
