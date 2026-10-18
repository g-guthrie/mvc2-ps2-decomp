typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { u8 b[28]; } E28;
typedef struct { u8 pad[0x184]; E28 *tab; } T184;

void func_0020A320(u8 *p, u8 *q)
{
    extern void func_00175700();
    extern double func_00119058(f32);
    extern void func_0034FA80();
    extern void func_001757E0();
    s16 v;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        u32 t = p[7];
        p[7] = t + 1;
        *(f32 *)(p + 0x5C) = func_00119058(*(f32 *)(q + 0x10) - *(f32 *)(p + 0x34)) / 32.0;
        *(s32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x41092492;
        *(u32 *)(p + 0x6C) = 0xBF2B6DB6;
        *(s16 *)(p + 0x1C) = 0x20;
        func_0034FA80(p, 1);
        func_001757E0(p, 0x12, 1);
    }
}
