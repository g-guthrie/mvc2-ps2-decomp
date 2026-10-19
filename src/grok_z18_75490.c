typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;

extern void func_001757E0(u8 *, int, int);
extern void func_001BAD80(u8 *, int);

void residual_00275490(u8 *p)
{
    p[0x20]++;
    p[0x13C] = 1;
    func_001757E0(p, 0x12, 1);
    *(u32 *)(p + 0x118) = 0x3E4CCCCD;
    *(f32 *)(p + 0x38) += 100.0f;
    p[0x20D] = 2;
    func_001BAD80(p, 4);
}
