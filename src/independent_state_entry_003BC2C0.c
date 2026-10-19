typedef unsigned char u8;
typedef float f32;

extern void func_003BD840(u8 *);
extern int func_001757E0(u8 *, int, int);

void func_003BC2C0(u8 *p)
{
    u8 *q;
    p[4]++;
    p[5] = 0;
    q = *(u8 **)(p + 0x18);
    func_003BD840(p);
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    func_001757E0(p, 0x17, 4);
}
