typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004643A0[], D_004643A4[];

void func_00380510(u8 *p, u8 *q) {
    extern s32 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E7F60(u8 *);
    u32 t;
    s8 r;
    f32 f2, k1, k2;
    *(u32 *)(p + 0x50) = 0x3F979724;
    *(u32 *)(p + 0x54) = 0x3F6A0F91;
    r = func_00175700(p);
    if (r < 0) {
        t = p[5];
        p[5] = t + 1;
        *(s16 *)(p + 0x1C) = 0xB4;
        k1 = 25.0f;
        k2 = 246.42855834960938f;
        *(f32 *)(p + 0x34) += k1;
        *(f32 *)(p + 0x38) += k2;
        f2 = D_004643A0[p[0x23] * 2];
        if (p[0x23] == 0) {
            if (*(f32 *)(p + 0x34) < *(f32 *)(*(u8 **)(q + 0x220) + 0x34)) f2 = -f2;
        } else {
            if (*(s16 *)(q + 0x140) != 0) f2 = -f2;
        }
        *(f32 *)(p + 0x5C) = f2;
        *(f32 *)(p + 0x60) = D_004643A4[p[0x23] * 2];
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0xBE892492;
        func_001757E0(p, 0x17, 4);
    }
    func_001E7F60(p);
}
