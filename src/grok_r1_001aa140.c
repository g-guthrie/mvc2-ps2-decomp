typedef unsigned char u8;
typedef signed short s16;
typedef float f32;

extern int func_001757E0(u8 *, int, int);
extern void func_001AA1C0(u8 *, u8 *);

void func_001AA140(u8 *p, u8 *q)
{
    p[7]++;
    if (*(f32 *)(p + 0x34) < *(f32 *)(q + 0x34))
        *(s16 *)(p + 0x140) = 1;
    else
        *(s16 *)(p + 0x140) = 0;
    func_001757E0(p, 0x17, 0x10);
    func_001AA1C0(p, q);
}
