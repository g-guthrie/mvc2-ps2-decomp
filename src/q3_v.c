typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_002364A0(u8 *p, u8 *q) {
    extern void func_001865B0();
    extern void func_00185490();
    extern void func_00183D50();
    extern void func_001757E0();
    extern s8 func_00175700();
    extern void func_002365D0();
    extern void func_001843A0();
    f32 lim;
    if (p[7] == 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
            u32 t;
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
            p[0x20D] = 0;
            if (p[0x20] == 0) {
                func_001865B0();
            } else {
                t = p[7];
                p[7] = t + 1;
                func_00185490(p);
                func_00183D50(p);
                func_001757E0(p, 1, 3);
            }
            return;
        } else {
            func_00175700();
            if (*(s8 *)(p + 0x151) != 0) func_002365D0(p, q);
        }
    } else {
        if (func_00175700(p) < 0) func_001843A0(p);
    }
}
