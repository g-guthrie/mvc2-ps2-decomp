typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_002E3E60(u8 *p) {
    extern s32 func_00188690();
    extern s32 func_00188ED0();
    extern s32 func_00188C70();
    extern s32 func_00189130();
    extern s32 func_002E4130();
    extern s32 func_002E41E0();
    extern s32 func_002E3F80();
    extern s32 func_002E4020();
    extern s32 func_002E40C0();
    extern s32 func_002E4290();
    extern s32 func_002E4310();
    extern void func_00187BB0();
    extern void func_00188330();
    u8 *q = p + 0x2B8;
    if (*(u16 *)(p + 0x168) == 0x201) return;
    if (*(s8 *)(q + 0x10) != 0) return;
    if (*(s8 *)(q + 9) == 0) {
        if (func_00188690(p) != 0) return;
    }
    if (func_00188ED0(p) != 0) return;
    if (func_00188C70(p) != 0) return;
    if (func_00189130(p) != 0) return;
    if (*(s8 *)(q + 9) == 0) {
        if (func_002E4130(p) != 0) return;
        if (func_002E41E0(p) != 0) return;
        if (func_002E3F80(p) != 0) return;
        if (func_002E4020(p) != 0) return;
        if (func_002E40C0(p) != 0) return;
        if (func_002E4290(p) != 0) return;
        if (func_002E4310(p) != 0) return;
    }
    func_00187BB0(p);
    func_00188330(p);
}
