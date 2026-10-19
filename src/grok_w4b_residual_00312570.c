typedef unsigned char u8;
typedef float f32;

extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);

void func_00312570(u8 *p)
{
    func_00175700(p);
    if (p[7] == 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        if (*(f32 *)(p + 0x2AC) <= 53.333332061767578f) {
            p[7]++;
            func_001757E0(p, 19, 1);
        }
    }
}
