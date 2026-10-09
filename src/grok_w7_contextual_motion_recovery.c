typedef unsigned char u8;
typedef float f32;

extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_00183D50(u8 *);
extern void func_00307760(u8 *, void *);

void func_00308000(u8 *p, void *context)
{
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);

    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        func_00307760(p, context);
        p[6]++;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        func_001757E0(p, 22, 8);
        func_00183D50(p);
    }
}
