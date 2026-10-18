typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
void func_003BCCF0(u8 *p)
{
    extern s8 func_00175700(u8 *);
    extern s8 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E7F60(u8 *);
    extern void func_003BD830(u8 *);
    u8 *o = *(u8 **)(p + 0x18);
    s16 h;
    u32 t;
    if (p[6] == 0) {
        func_00175700(p);
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        if (!(*(f32 *)(o + 0x430) <= *(f32 *)(p + 0x38))) {
            t = p[6];
            p[6] = t + 1;
            *(f32 *)(p + 0x38) = *(f32 *)(o + 0x430);
            func_001757E0(p, 0x19, 2);
            return;
        }
        h = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = h;
        if (h < 0 || *(s8 *)(p + 0x1B3) != 0 || *(s8 *)(p + 0x1B2) != 0) {
            t = p[6];
            p[6] = t + 1;
            func_001757E0(p, 0x19, 2);
        }
        func_001E7F60(p);
    } else {
        if (func_00175700(p) < 0) func_003BD830(p);
    }
}
