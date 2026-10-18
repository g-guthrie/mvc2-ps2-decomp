typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00312100(u8 *p, u8 *q) {
    extern s32 func_00175700();
    extern void func_00183d50();
    extern void func_001757E0();
    f32 *v1, *a1, *a2, *a3;
    s32 fl;
    func_00175700(p);
    fl = *(s8 *)(p + 0x151);
    if (fl & 1) return;
    if (fl & 2) {
        p[0x151] = fl & -3;
        q[7] = 1;
    }
    v1 = (f32 *)(p + 0x5C);
    a2 = (f32 *)(p + 0x68);
    a1 = (f32 *)(p + 0x60);
    a3 = (f32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x430) < *(f32 *)(p + 0x38)) return;
    {
        u32 t = p[6];
        p[6] = t + 1;
    }
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    *(f32 *)(p + 0x34) = (f32)*(s16 *)(q + 4);
    *(u32 *)v1 = 0;
    *(u32 *)a1 = 0;
    *(u32 *)a2 = 0;
    *(u32 *)a3 = 0;
    func_00183d50(p);
    func_001757E0(p, 1, 5);
}
