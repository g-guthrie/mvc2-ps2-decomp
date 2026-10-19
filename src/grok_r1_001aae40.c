typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern int func_001757E0(u8 *, int, int);
extern void func_001AAEE0(u8 *, u8 *);

void func_001AAE40(u8 *p, u8 *q)
{
    u32 t;

    p[7]++;
    t = *(u32 *)(q + 0x2F8);
    if (t != 0)
        *(u32 *)(q + 0x2F8) = t - 1;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x6C) = 0;
    if (*(f32 *)(p + 0x34) < *(f32 *)(q + 0x34))
        *(s16 *)(p + 0x140) = 1;
    else
        *(s16 *)(p + 0x140) = 0;
    func_001757E0(p, 0x17, 0xF);
    func_001AAEE0(p, q);
}
