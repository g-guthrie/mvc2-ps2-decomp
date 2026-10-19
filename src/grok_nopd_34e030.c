typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_0034E130(u8 *);

void func_0034E030(u8 *p)
{
    u8 *q = *(u8 **)(p + 20);

    p[36] = *(s8 *)(q + 36);
    *(f32 *)(p + 52) = *(f32 *)(q + 52);
    *(f32 *)(p + 56) = *(f32 *)(q + 56);
    if ((s8)func_00175700(p) < 0)
        func_0034E130(p);
}
