typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;



void func_001EB5E0(u8 *p) {
    extern double func_00119058(f32);
    extern void func_00175700();
    extern void func_001757E0();
    extern void func_001EB470();
    f32 o = *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_00119058(o * *(f32 *)(p + 0x60)) > 0.0) {
        func_00175700(p);
    } else {
        u32 t = p[6];
        p[6] = t + 1;
        *(s16 *)(p + 0x1C) = p[0x1B7] << 1;
        func_001757E0(p, 0x15, 6);
        func_001EB470(p);
    }
}
