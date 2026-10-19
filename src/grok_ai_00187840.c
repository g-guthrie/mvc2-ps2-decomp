typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00175C00(u8 *, s32);
extern void func_00185490(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern void func_00183D50(u8 *);

void func_00187840(u8 *p)
{
    u32 bits;
    f32 add;
    func_00175C00(p, 1);
    func_00185490(p);
    if (!p[0x20]) {
        {
            u32 b = 0x42892492;
            f32 g = *(f32 *)(p + 0x430);
            if (*(f32 *)(p + 0x38) < *(f32 *)&b + g)
                *(f32 *)(p + 0x38) = g;
        }
        p[0x20D] = 2;
        p[0x1EC] = 0;
        p[0x210] = 0;
        p[0x1E8] = 0;
        p[0x1E9] = 0;
        p[0x1EA] = 0x11;
        p[0x1ED] = 0;
        bits = 0x413AAAAA;
        *(u32 *)(p + 0x5C) = bits;
        if (*(s16 *)(p + 0x140))
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        *(u32 *)(p + 0x68) = 0;
        bits = 0x413C9249;
        *(u32 *)(p + 0x60) = bits;
        bits = 0xBF092492;
        *(u32 *)(p + 0x6C) = bits;
        p[0x1E7] = 1;
        func_001757E0(p, 0xD, 0x20);
        return;
    }
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x20D] = 1;
    p[0x1EC] = 0;
    p[0x210] = 0;
    p[0x1E8] = 0;
    p[0x1E9] = 0;
    bits = 0x41555555;
    *(u32 *)(p + 0x5C) = bits;
    bits = 0xBFA00000;
    *(u32 *)(p + 0x68) = bits;
    if (*(s16 *)(p + 0x140)) {
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
    }
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x6C) = 0;
    func_001757E0(p, 0xD, 0x21);
    func_00183D50(p);
}
