typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_00259320(u8 *);
extern void func_001AFCB0(u8 *);

void func_00259320(u8 *p)
{
    f32 vx, ax;

    func_00175700(p);
    if ((s8)p[0x151] == 1) {
        p[6]++;
        func_00259320(p);
        return;
    }
    if (p[0x425] == 0 && (s8)p[0x151] == 2) {
        func_001AFCB0(p);
        *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
        p[0x151] = 0;
    }
    vx = *(f32 *)(p + 0x5C);
    ax = *(f32 *)(p + 0x68);
    if (vx * ax < 0.0f) {
        *(f32 *)(p + 0x34) += vx;
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    }
}
