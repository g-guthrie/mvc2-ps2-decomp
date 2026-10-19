typedef unsigned char u8;
typedef signed short s16;
typedef float f32;

extern f32 func_001AC390(u8 *, int);
extern void func_001757E0(u8 *, int, int);
extern void func_001AA6C0(u8 *, u8 *);

void residual_001AA620(u8 *p, u8 *a1)
{
    p[7]++;
    *(s16 *)(p + 0x1C) = 40;
    *(f32 *)(p + 0x64) = func_001AC390(a1, -64);
    *(f32 *)(p + 0x70) = *(f32 *)(a1 + 0x430);
    if (!(*(f32 *)(p + 0x34) < *(f32 *)(p + 0x64)))
        *(s16 *)(p + 0x140) = 0;
    else
        *(s16 *)(p + 0x140) = 1;
    func_001757E0(p, 23, 13);
    func_001AA6C0(p, a1);
}
