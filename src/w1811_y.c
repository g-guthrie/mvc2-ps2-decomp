typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct O {
    u8 pad0[5];
    u8 b5;
    u8 b6;
    u8 b7;
    u8 pad8[0x1FD - 8];
    u8 b1FD;
} O;

void func_002B26E0(O *p) {
    extern s32 func_00188690();
    extern s32 func_00188ED0();
    extern s32 func_00188C70();
    extern s32 func_00189130();
    extern s32 func_002B2860();
    extern s32 func_002B28F0();
    extern s32 func_002B2970();
    extern s32 func_002B29F0();
    extern s32 func_002B2A70();
    extern s32 func_002B2C50();
    extern s32 func_002B2CE0();
    extern s32 func_002B2D50();
    extern s32 func_002B2AE0();
    extern s32 func_002B2B50();
    extern s32 func_002B2BC0();
    extern s32 func_002B2DC0();
    extern s32 func_002B30B0();
    extern s32 func_001891F0();
    extern void func_00186A60();
    extern void func_00187BB0();
    extern void func_00188330();
    if (func_00188690(p) != 0) return;
    if (func_00188ED0(p) != 0) return;
    if (func_00188C70(p) != 0) return;
    if (func_00189130(p) != 0) return;
    if (func_002B2860(p) != 0) return;
    if (func_002B28F0(p) != 0) return;
    if (func_002B2970(p) != 0) return;
    if (func_002B29F0(p) != 0) return;
    if (func_002B2A70(p) != 0) return;
    if (func_002B2C50(p) != 0) return;
    if (func_002B2CE0(p) != 0) return;
    if (func_002B2D50(p) != 0) return;
    if (func_002B2AE0(p) != 0) return;
    if (func_002B2B50(p) != 0) return;
    if (func_002B2BC0(p) != 0) return;
    if (func_002B2DC0(p) != 0) return;
    if (func_002B30B0(p) != 0) return;
    if (func_001891F0(p, 8) != 0) {
        p->b1FD = 8;
        p->b5 = 0;
        p->b7 = 0;
        p->b6 = 0;
        func_00186A60(p, 0x15);
    } else {
        func_00187BB0(p);
        func_00188330(p);
    }
}
