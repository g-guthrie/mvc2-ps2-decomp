typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


typedef struct { u8 pad[0x1E]; s8 b[4]; } S1;

void func_00352540(u8 *p) {
    extern void func_00353690();
    extern s32 func_00174470();
    extern s32 func_00174780();
    extern void func_00175700();
    extern void func_001E7F60();
    extern void func_00176090();
    s16 v;
    s8 *q = ((S1 *)p)->b;
    func_00353690(p, q, q + 1);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v < 0 || *(s8 *)(p + 0x1B2) != 0 || *(s8 *)(p + 0x1B3) != 0 || func_00174470(p) == 0 || func_00174780(p) == 0) {
        p[4] = 2;
        p[0x13C] = 0;
        func_00176090(*(u32 *)(p + 0x18), 2, 2, 1);
        return;
    }
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_001E7F60(p);
}
