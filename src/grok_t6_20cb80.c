/* Metrowerks 3.0: ./try.sh src/grok_t6_20cb80.c "-O3 -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;
typedef float f32;
typedef double f64;

extern s8 func_00175700(u8 *);
extern void func_001266A0(u8 *, int, int);
extern f64 func_00119058(f32);
extern f64 dpadd(f64, f64);
extern f64 func_00119568(f64, f64);
extern f32 func_00119C90(f64);
extern f64 dpdiv(f64, f64);
extern void func_001E3210(u8 *, int);
extern void func_001757E0(u8 *, int, int);
extern f32 D_004F1F4C;

void func_0020CB80(u8 *p, u8 *q)
{
    if (func_00175700(p) < 0) {
        f64 d;
        f32 f;
        p[7]++;
        func_001266A0(p, 1, 1);
        q[0xA] = 0;
        *(f32 *)(p + 0x5C) = 0;
        *(f32 *)(p + 0x60) = 0;
        *(f32 *)(p + 0x68) = 0;
        *(f32 *)(p + 0x6C) = 0;
        if (p[0x1E6]) {
            d = dpadd(380.0, func_00119058(D_004F1F4C));
            d = dpadd(d, 13.333333333333332);
        } else {
            d = func_00119568(func_00119058(D_004F1F4C), 380.0);
            d = func_00119568(d, 13.333333333333332);
        }
        f = func_00119C90(d);
        f = func_00119C90(dpdiv(func_00119058(f - *(f32 *)(p + 0x34)), 3.0));
        *(f32 *)(p + 0x5C) = f;
        q[0xC] = 0x20;
        func_001E3210(p, 6);
        func_001757E0(p, 0x14, 8);
    }
}
