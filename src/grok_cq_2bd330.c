typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;

extern f32 D_004F1FE8;
extern double func_00119058(f32);
extern double dpadd(double, double);
extern double func_00119568(double, double);
extern f32 func_00119C90(double);
extern void func_002BD610(u8 *, u8 *);
extern void func_001757E0(u8 *, int, int);

int func_002BD330(u8 *p, u8 *q)
{
    f32 h;
    f32 lim;

    if (p[0x22] == 0x18)
        return 0;
    h = *(f32 *)(p + 0x38);
    lim = func_00119C90(func_00119568(dpadd(240.0, func_00119058(D_004F1FE8)), 146.142578125));
    if (h < lim)
        return 0;
    p[7] = 1;
    func_002BD610(p, q);
    *(u32 *)(q + 8) = 0xC3092492;
    func_001757E0(p, 22, 1);
    return 1;
}
