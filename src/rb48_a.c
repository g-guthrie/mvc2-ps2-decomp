typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s32 func_00184E70(u8 *p) {
    extern void func_00186A60(u8 *, s32);
    s32 a;
    s32 q;
    f32 f1;
    f32 f2;
    f32 c;
    a = *(s8 *)(p + 0x211);
    if (a == 0) return 0;
    if (p[1] == 0x20) {
        if (((s8)a ^ ((*(u16 *)(p + 0x35C) & 0xC00) >> 10)) != 0) return 0;
    } else {
        if (((s8)a | ((*(u16 *)(p + 0x354) & 0xC00) >> 10)) != 3) return 0;
    }
    if (*(s8 *)(p + 0x1E9) != 0) return 0;
    f1 = *(f32 *)(p + 0x430);
    f2 = *(f32 *)(p + 0x38);
    if (f2 < 240.0f + f1) return 0;
    if (!(f2 < 1028.5714111328125f + f1)) return 0;
    if (*(u16 *)(p + 0x354) & 0x2000) {
        *(f32 *)(p + 0x5C) = 5.0f;
        *(f32 *)(p + 0x60) = 21.428569793701172f;
        *(u32 *)(p + 0x6C) = 0xBF892492;
    } else {
        *(u32 *)(p + 0x5C) = 0x41055555;
        *(u32 *)(p + 0x60) = 0x414DB6DB;
        *(u32 *)(p + 0x6C) = 0xBF700000;
    }
    p[0x1E6] = (*(s8 *)(p + 0x211) >> 1) & 1;
    *(s16 *)(p + 0x140) = p[0x1E6] ^ 1;
    if (*(s16 *)(p + 0x140) != 0) *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    *(s32 *)(p + 0x68) = 0;
    func_00186A60(p, 0x19);
    p[7] = 0;
    p[6] = 0;
    return 1;
}
