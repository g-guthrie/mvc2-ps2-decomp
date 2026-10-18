typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004F1FC8[];
extern f32 D_004F1FCC[];
extern s16 D_004C1D7A;

void func_00387710(u8 *p, u8 *q) {
    extern void func_001757E0();
    extern void func_001E3710();
    extern void func_00175700();
    extern void func_001E7F60();
    f32 z;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(s32 *)(p + 0xD8) == 0) {
        z = 0.0f;
        if (*(f32 *)(p + 0x5C) < z) {
            if (*(f32 *)(p + 0x34) <= 53.33333206176758f + D_004F1FC8[0]) {
                *(s32 *)(p + 0xD8) = 0xFF;
                *(f32 *)(p + 0x5C) = z;
                *(f32 *)(p + 0x68) = z;
            }
        } else {
            if (!(*(f32 *)(p + 0x34) < D_004F1FCC[0] - 53.33333206176758f)) {
                *(s32 *)(p + 0xD8) = 0xFF;
                *(f32 *)(p + 0x5C) = z;
                *(f32 *)(p + 0x68) = z;
            }
        }
    }
    if (*(f32 *)(p + 0x38) <= *(f32 *)(q + 0x430)) {
        u32 t = p[5];
        p[5] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
        *(s16 *)(p + 0x1C) = D_004C1D7A;
        p[0x24] = 0xF;
        func_001757E0(p, 0x17, 5);
        func_001E3710(p, 0x4B);
    }
    func_00175700(p);
    func_001E7F60(p);
}
