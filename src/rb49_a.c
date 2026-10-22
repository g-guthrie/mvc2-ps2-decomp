typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0029D8B0(u8 *p) {
    extern void func_00175700(u8 *);
    extern s32 func_00185980(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00185770(u8 *, s32);
    p[0x40C] = 2;
    p[0x33C] = 5;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (*(s8 *)(p + 0x1B2) != 0) {
        if (func_00185980(p) != 0) {
            p[6] = 6;
            *(s16 *)(p + 0x1C) = 0x2F;
            *(s16 *)(p + 0x1E) = 0;
            func_001757E0(p, 0x16, 4);
            p[0x20B] = 0xC2;
            func_00185770(p, *(s32 *)(p + 0x1C4));
        } else {
            p[0x40D] = 0;
            p[0x40C] = 0;
            p[0x33B] = 0;
            p[0x33C] = 0;
            p[0x20D] = 2;
            p[6] = 4;
            *(u32 *)(p + 0x5C) = 0xBFD55555;
            *(u32 *)(p + 0x68) = 0x3BD55555;
            *(u32 *)(p + 0x60) = 0x414DB6DB;
            *(u32 *)(p + 0x6C) = 0xBF092492;
            if (*(s16 *)(p + 0x140) == 0) {
                *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
                *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
            }
            func_001757E0(p, 0x16, 2);
        }
        p[0x1B4] = 10;
    } else {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v < 0) {
            p[6] = 5;
            func_001757E0(p, 0x16, 3);
            p[0x40D] = 0;
            p[0x40C] = 0;
            p[0x33B] = 0;
            p[0x33C] = 0;
        }
    }
}
