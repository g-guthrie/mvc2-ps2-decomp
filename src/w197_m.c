typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s32 func_001662D0(u8 *p, u8 *q) {
    extern s32 func_0016B240(u8 *, s32);
    extern void func_0016B0C0(u8 *, u8 *, s32);
    extern s32 func_00166C80(u8 *, u8 *, s32);
    s32 s;
    f32 z = 0.0f;
    if (func_0016B240(p, 4) == 0) {
        return 0;
    }
    func_0016B0C0(p, q, 0);
    func_0016B0C0(p, q, 1);
    s = *(s8 *)(p + 0x4C8);
    func_0016B0C0(p, q, 4);
    if (!(*(f32 *)(p + 0x4C8) <= *(f32 *)(p + 0x38) - *(f32 *)(p + 0x430))) {
        if ((s8)s < 0) {
            if (*(f32 *)(p + 0x60) <= z) {
                goto g1;
            }
        }
        return func_00166C80(p, q, 0);
    } else {
        if ((s8)s < 0) {
            return func_00166C80(p, q, 0);
        }
        if (*(f32 *)(p + 0x60) < z) {
            return func_00166C80(p, q, 0);
        }
    }
g1:
    return func_00166C80(p, q, 1);
}
