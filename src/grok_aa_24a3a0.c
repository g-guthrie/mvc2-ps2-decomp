typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);

void func_0024A3A0(u8 *p)
{
    s16 t;
    f32 z = 0.0f;
    f32 *pv = (f32 *)(p + 0x60);
    f32 *pg = (f32 *)(p + 0x6C);
    f32 v;

    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    v = *(f32 *)(p + 0x60) + *(f32 *)(p + 0x6C);
    *(f32 *)(p + 0x60) = v;
    if (v != z) {
        if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
            *pv = z;
            *pg = z;
        }
    }
    t = *(s16 *)(p + 0x1C);
    t = t - 1;
    *(s16 *)(p + 0x1C) = t;
    if (t <= 0) {
        p[6]++;
        if (p[0x1E6] == 0)
            *(u32 *)(p + 0x68) = 0xBE855555;
        else
            *(u32 *)(p + 0x68) = 0x3E855555;
        func_001757E0(p, 2, 3);
    }
}
