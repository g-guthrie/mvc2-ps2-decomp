typedef unsigned char u8;
typedef float f32;

extern int func_001757E0(u8 *, int, int);

void residual_002C4130(u8 *p)
{
    p[6]++;
    p[0x20D] = 0;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    func_001757E0(p, 20, 15);
}
