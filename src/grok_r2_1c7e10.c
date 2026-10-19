typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_001757E0(u8 *, int, int);
extern void func_0015E630(u8 *);
extern void func_001C7EC0(u8 *, u8 *);

void residual_001C7E10(u8 *p, u8 *q)
{
    s16 t;
    p[7]++;
    *(s8 *)(p + 49) = -1;
    t = *(s16 *)(q + 320);
    *(s16 *)(p + 320) = t;
    if (t == 0)
        *(u32 *)(p + 92) = 0xC0D55555;
    else
        *(u32 *)(p + 92) = 0x40D55555;
    *(u32 *)(p + 104) = 0;
    *(u32 *)(p + 96) = 0;
    *(u32 *)(p + 108) = 0;
    *(f32 *)(p + 52) = *(f32 *)(q + 52);
    *(f32 *)(p + 56) = *(f32 *)(q + 56);
    func_001757E0(p, 25, 19);
    p[0] = 1;
    func_0015E630(p);
    func_001C7EC0(p, q);
}
