typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00175C00(u8 *, s32);
extern void func_00185490(u8 *);
extern int func_001757E0(u8 *, s32, s32);
extern void func_00183D50(u8 *);

void func_00187840(u8 *p)
{
    func_00175C00(p, 1);
    func_00185490(p);
    if (!p[0x20]) {
        f32 g = *(f32 *)(p + 0x430);
        if (*(f32 *)(p + 0x38) < 68.5714264f + g)
            *(f32 *)(p + 0x38) = g;
        p[0x20D] = 2;
        p[0x1EC] = 0;
        p[0x210] = 0;
        p[0x1E8] = 0;
        p[0x1E9] = 0;
        p[0x1EA] = 0x11;
        p[0x1ED] = 0;
        *(f32 *)(p + 0x5C) = 11.666666f;
        if (*(s16 *)(p + 0x140))
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x68) = 0.0f;
        *(f32 *)(p + 0x60) = 11.7857141f;
        *(f32 *)(p + 0x6C) = -0.535714269f;
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
    {
        *(f32 *)(p + 0x5C) = 13.333333f;
        *(f32 *)(p + 0x68) = -1.25f;
    }
    if (*(s16 *)(p + 0x140)) {
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
    }
    *(f32 *)(p + 0x60) = 0.0f;
    *(f32 *)(p + 0x6C) = 0.0f;
    func_001757E0(p, 0xD, 0x21);
    func_00183D50(p);
}
