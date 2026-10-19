typedef unsigned char u8;
typedef signed short s16;
typedef float f32;
typedef double f64;

extern f64 func_00119058(f32);
extern f64 func_00119568(f64, f64);
extern f64 func_00119858(f64, f64);
extern f32 func_00119C90(f64);
extern void func_00135FA0(u8 *);

void func_00135F30(u8 *p)
{
    p[5]++;
    *(s16 *)(p + 0x1C) = 12;
    *(f32 *)(p + 0x64) = func_00119C90(
        func_00119858(
            func_00119568(-40.0, func_00119058(*(f32 *)(p + 0x3C))),
            12.0));
    func_00135FA0(p);
}
