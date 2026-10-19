typedef unsigned char u8;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);

void residual_00197C20(u8 *p, u8 *q)
{
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) > *(f32 *)(q + 0x430))
        func_00175700(p);
    else {
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
        p[5]++;
        func_001757E0(p, 0x12, 4);
    }
}
