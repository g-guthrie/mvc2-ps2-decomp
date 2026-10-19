typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);

void residual_003045C0(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x1DC);
    func_00175700(p);
    if ((s8)p[0x151] == 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        if (*(s8 *)(p + 0x211) || *(s8 *)(q + 0x211)) {
            p[6]++;
            func_001757E0(p, 15, 1);
            *(s16 *)(p + 0x1C) = 56;
        }
    }
}
