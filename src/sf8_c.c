/* MW 3.0.3 (also 3.0): MWWARM@src/sb13_a.c "-O3,p -Op -fp off -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_004B79A0[];
extern f32 D_004B7990[];

void func_003335B0(u8 *p) {
    extern void func_00333710(u8 *);
    s16 *record;
    f32 *scales;
    s32 i;
    double k;
    record = D_004B79A0;
    scales = D_004B7990;
    for (i = 0; i < p[4]; ++i) record += *record * 2;
    p[7] = *(s8 *)record;
    k = 65536.0;
    *(u32 *)(p + 0x44) = (u32)(s32)(0.5 + k * (double)scales[record[p[7]]] / 360.0) & 0xFFFF;
    p[5] = 1;
    func_00333710(p);
}
