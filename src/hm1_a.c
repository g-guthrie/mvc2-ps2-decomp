typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_003956F0(u8 *p)
{
    extern void func_00395870(u8 *);
    extern void func_00395890(u8 *);
    extern int func_00174470(const void *);
    extern f32 func_00417440(s32);
    extern void func_00175700(u8 *);
    extern void func_001E7F60(u8 *);
    s16 x;
    s32 t;
    f32 r;

    if (*(s8 *)(p + 0x1B3) != 0 || *(s8 *)(p + 0x1B2) != 0) {
        func_00395870(p);
        return;
    }
    if (func_00174470(p) == 0) {
        func_00395890(p);
        return;
    }
    if (p[0x21] != 0) {
        r = func_00417440(((0x28 - p[0x22]) & 0x1F) << 11);
        r = r * 8.5714283f;
        *(f32 *)(p + 0x38) += r;
        x = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = x;
        if (x == 0) {
            *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1E);
            t = p[0x22] + 1;
            p[0x22] = t;
            t = (s8)(t & 0xFF);
            p[0x22] = t & 0x1F;
        }
    }
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_001E7F60(p);
}
