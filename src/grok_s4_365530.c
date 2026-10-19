typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern void func_001757E0(u8 *, int, int);
extern void func_003655C0(u8 *);

void residual_00365530(u8 *p)
{
    unsigned n = 0xbfd55555;
    unsigned p5 = 0x3fd55555;
    unsigned a = 0x414db6db;
    unsigned b = 0xbfcdb6db;
    p[5]++;
    if (*(s16 *)(p + 0x140))
        *(f32 *)(p + 0x5c) = *(f32 *)&n;
    else
        *(f32 *)(p + 0x5c) = *(f32 *)&p5;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x60) = (s32)a;
    *(s32 *)(p + 0x6c) = (s32)b;
    func_001757E0(p, 0x17, 3);
    func_003655C0(p);
}
