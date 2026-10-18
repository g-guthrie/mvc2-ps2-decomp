typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s32 func_00179E50(u8 *p)
{
    extern s32 func_001884C0(u8 *);
    extern s32 func_00187D70(u8 *);
    extern s32 func_00184B30(u8 *);
    extern s32 func_00184720(u8 *);
    extern s32 func_00185A90(u8 *);
    extern s32 func_001853E0(u8 *);
    extern s32 func_00184C60(u8 *);
    extern s32 func_00186030(u8 *);
    extern s32 func_00186170(u8 *);
    extern s32 func_001846D0(u8 *, s32);
    if (p[0x215] == 0) {
        if (func_001884C0(p) != 0) return 1;
    }
    if (func_00187D70(p) != 0) return 1;
    if (func_00184B30(p) != 0) return 1;
    if (func_00184720(p) != 0) return 1;
    if (func_00185A90(p) != 0) return 1;
    if (func_001853E0(p) != 0) return 1;
    if (func_00184C60(p) != 0) return 1;
    if (func_00186030(p) != 0) return 1;
    if (func_00186170(p) != 0) return 1;
    return func_001846D0(p, 0) != 0;
}
