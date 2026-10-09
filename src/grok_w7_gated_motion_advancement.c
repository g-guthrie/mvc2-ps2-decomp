typedef unsigned char u8;
typedef signed char s8;
typedef float f32;
extern int func_00175700(u8 *);
extern int func_001864A0(u8 *);
extern void func_00183D50(u8 *);
void func_0030F180(u8 *p)
{
    if (*(s8 *)(p + 0x151) == 0)
        func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_001864A0(p) != 0) {
        p[6]++;
        func_00183D50(p);
    }
}
