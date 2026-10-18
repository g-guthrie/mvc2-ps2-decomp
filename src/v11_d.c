typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_002F8740(u8 *p) {
    extern void func_00175700();
    extern double func_00119058(f32);
    extern void func_001757E0();
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700();
    if (!(*(f32 *)(p + 0x430) < *(f32 *)(p + 0x38))) {
        { u32 t = p[6]; p[6] = t + 1; }
        p[0x20D] = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        *(f32 *)(p + 0x68) = -(func_00119058(*(f32 *)(p + 0x5C)) / 8.0);
        func_001757E0(p, 2, 3);
    }
}
