typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00376DE0(u8 *p, u8 *q) {
    extern s8 func_00175700(u8 *, u8 *);
    extern s32 func_003777B0(u8 *);
    extern void func_001E3210(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E7F60(u8 *);
    u8 *s0;
    f32 x, y, k, px;

    if (func_00175700(p, q) < 0) {
        *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) - 1;
    }
    if (func_003777B0(p) != 0) {
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    } else {
        s0 = *(u8 **)(q + 0x220);
        k = 106.66666412353516f;
        y = *(f32 *)(s0 + 0x34);
        px = *(f32 *)(p + 0x34);
        if ((y - k < px && !(y + k <= px) && s0[0x20D] != 2) || *(s16 *)(p + 0x1C) == 1) {
            u32 t = p[5];
            p[5] = t + 1;
            func_001E3210(p, 0x34);
            x = *(f32 *)(s0 + 0x34);
            if (*(s16 *)(p + 0x1C) == 1) {
                *(u32 *)(p + 0x5C) = 0xC0D55555;
                *(u32 *)(p + 0x68) = 0;
                if (*(s16 *)(p + 0x140) != 0) {
                    *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
                }
            } else {
                *(f32 *)(p + 0x5C) = (x - *(f32 *)(p + 0x34)) / 20.0f;
                *(u32 *)(p + 0x68) = 0;
            }
            *(s16 *)(p + 0x1C) = 0x14;
            *(u32 *)(p + 0x60) = 0x412B6DB6;
            *(u32 *)(p + 0x6C) = 0xBF892492;
            func_001757E0(p, 0x17, 7);
        } else {
            *(u32 *)(p + 0x60) = 0x40CDB6DB;
            *(u32 *)(p + 0x6C) = 0xBF892492;
        }
    }
    func_001E7F60(p);
}
