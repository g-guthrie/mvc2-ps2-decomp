typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s32 func_0016A1F0();
extern s32 func_0016A130();
s32 func_001692A0(u8 *p, s32 n) {
    s32 r;
    if (n > 4) return 0;
    if (p[0x215]) return func_0016A1F0(p, 9);
    if (p[0x1E5] == 0x11) {
        r = func_0016A130(p, 9, 4);
    } else {
        r = func_0016A1F0(p, 9);
    }
    return r;
}

extern void func_001820A0();
extern s32 func_00178B00();
extern s32 func_001864a0();
extern void func_00178D80();
extern void func_00185490();
extern void func_00183d50();
void func_00178870(u8 *p) {
    func_001820A0(p);
    if (func_00178B00(p) == 0) {
        if (func_001864a0(p)) {
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
            func_00178D80(p, 1);
            func_00185490(p);
            func_00183d50(p);
        }
    }
}
