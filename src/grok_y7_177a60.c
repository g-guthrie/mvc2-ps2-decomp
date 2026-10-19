typedef unsigned char u8;
typedef signed short s16;
typedef float f32;

extern void func_0018F320(u8 *);
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern int func_001864A0(u8 *);
extern void func_00177D50(u8 *);

void func_00177A60(u8 *p)
{
    s16 t;

    func_0018F320(p);
    func_00175700(p);
    t = *(s16 *)(p + 0x1C);
    if (t != 0) {
        t = t - 1;
        *(s16 *)(p + 0x1C) = t;
        if (t <= 0)
            func_001757E0(p, 13, 34);
    }
    if (*(f32 *)(p + 0x60) <= 0.0f) {
        if (func_001864A0(p)) {
            func_00177D50(p);
            p[6]++;
            p[0x20D] = 3;
            if (*(f32 *)(p + 0x5C) > 0.0f)
                *(int *)(p + 0x5C) = 0x41200000;
            else
                *(int *)(p + 0x5C) = 0xC1200000;
            *(int *)(p + 0x68) = 0;
            func_001757E0(p, 13, 13);
        }
    }
}
