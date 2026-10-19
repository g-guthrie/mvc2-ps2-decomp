typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00175700(u8 *);
extern void func_00183d50(u8 *);
extern void func_001757E0(u8 *, s32, s32);

void residual_002388C0(u8 *p, u8 *q)
{
    f32 *a2 = (f32 *)(p + 0x5C);
    f32 *t0 = (f32 *)(p + 0x68);
    f32 *a3 = (f32 *)(p + 0x60);
    f32 *t1 = (f32 *)(p + 0x6C);
    f32 z;
    s32 a1;
    s32 a2i;

    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    z = 0.0f;
    if (!(*(f32 *)(p + 0x5C) * *(f32 *)(p + 0x68) < z)) {
        *a2 = z;
        *t0 = z;
    }
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        p[7]++;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        *a3 = 0.0f;
        *t1 = 0.0f;
        func_00183d50(p);
        if ((s8)q[0x38] == 0) {
            a1 = 1;
            a2i = 3;
        } else {
            a1 = 0x16;
            a2i = 0x25;
        }
        func_001757E0(p, a1, a2i);
    }
}
