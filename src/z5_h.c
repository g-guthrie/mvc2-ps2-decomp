typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_002CD580(u8 *p) {
    s16 h;
    f32 v;
    extern void func_00175700();
    extern void func_001757E0();
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h <= 0) {
        u32 t = p[6];
        p[6] = t + 1;
        if (p[0x1E6] != 0) v = -4.1666665f; else v = 4.1666665f;
        *(f32 *)(p + 0x5C) = v;
        if (p[0x1E6] != 0) v = 0.33854165f; else v = -0.33854165f;
        *(f32 *)(p + 0x68) = v;
        func_001757E0(p, 2, 3);
    }
}

void func_0028FB90(u8 *p) {
    s16 h;
    extern void func_00175700();
    extern void func_001757E0();
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h == 0) {
    u32 t = p[7];
    p[7] = t + 1;
    *(s16 *)(p + 0x1C) = 0x10;
    if ((p[0x1E6] & 1) == 0) {
        *(f32 *)(p + 0x34) += -20.0f;
        *(u32 *)(p + 0x5C) = 0x40555555;
    } else {
        *(f32 *)(p + 0x34) -= -20.0f;
        *(u32 *)(p + 0x5C) = 0xC0555555;
    }
    *(f32 *)(p + 0x38) -= 107.142853f;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0x41092492;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    { u32 x = p[0x1E6]; p[0x1E6] = x ^ 1; }
    func_001757E0(p, 0x12, 5);
    } else {
        func_00175700(p);
    }
}
