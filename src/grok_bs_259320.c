typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern void func_00175700(u8 *);
extern void func_001AFCB0(u8 *);

void func_00259320(u8 *p)
{
    s8 a;

    func_00175700(p);
    a = (s8)p[0x151];
    if (a != 1) {
        goto not_one;
    }
    p[6]++;
    func_00259320(p);
    return;
not_one:
    if (p[0x425] == 0 && a == 2) {
        func_001AFCB0(p);
        *(s16 *)(p + 0x1C) += 1;
        p[0x151] = 0;
    }
    if (*(f32 *)(p + 0x5C) * *(f32 *)(p + 0x68) < 0.0f) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    }
}
