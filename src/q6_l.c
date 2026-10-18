typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_003202D0(u8 *p) {
    extern void func_00175700();
    extern void func_00175910(u8 *, s32, s32, s32);
    p[0x40C] = 2;
    p[0x33C] = 5;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        *(u32 *)(p + 0x60) = 0;
    }
    if (*(s16 *)(p + 0x1E) != 0) {
        u32 t;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        t = p[7];
        p[7] = t + 1;
        *(u32 *)(p + 0x5C) = 0xC0855555;
        if (p[0x1E6] != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        }
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x40AB6DB6;
        *(u32 *)(p + 0x6C) = 0xBF700000;
        func_00175910(p, 1, 1, 8);
    }
}
