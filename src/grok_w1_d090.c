typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;

extern int func_001757E0(u8 *, int, int);
extern void func_0020D130(u8 *, u8 *);

void residual_0020D090(u8 *p, u8 *q)
{
    p[7]++;
    *(f32 *)(p + 0x5C) = p[0x1E6] ? 5.0f : -5.0f;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0xC14DB6DB;
    *(u32 *)(p + 0x6C) = 0xBE892492;
    func_001757E0(p, 1, 1);
    func_0020D130(p, q);
}
