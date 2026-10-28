/* MW 3.0.3 (also 3.0): MWWARM@src/sb22_a.c "-O3 -Op -fp off -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern s16 D_004B7D70[];
extern f32 D_004B7D58[];
extern V3 D_004B7DB0[];

void residual_003340A0(u8 *p) {
    extern void func_00334240(u8 *);
    f32 *scales;
    s16 *record;
    V3 *v;
    s32 i;
    double k;
    scales = D_004B7D58;
    v = D_004B7DB0;
    record = D_004B7D70;
    for (i = 0; i < p[4]; ++i) record += *record * 2;
    v += p[7];
    p[0x21] = *(s8 *)record;
    k = 65536.0;
    *(u32 *)(p + 0x44) = (u32)(s32)(0.5 + k * (double)scales[record[p[0x21]]] / 360.0) & 0xFFFF;
    *(f32 *)(p + 0x34) = v->x;
    *(f32 *)(p + 0x38) = v->y;
    *(f32 *)(p + 0x3C) = v->z;
    p[5] = 1;
    p[6] = 1;
    func_00334240(p);
}
