typedef unsigned char u8;
typedef signed short s16;
typedef float f32;

extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);

void residual_00351EB0(u8 *p)
{
    func_00175700(p);
    *(f32 *)(p + 52) += *(f32 *)(p + 92);
    *(f32 *)(p + 92) += *(f32 *)(p + 104);
    *(f32 *)(p + 56) += *(f32 *)(p + 96);
    *(f32 *)(p + 96) += *(f32 *)(p + 108);
    if (--*(s16 *)(p + 28) == 0) {
        p[5]++;
        func_001757E0(p, 21, (u8)(p[33] + 33));
    }
}
