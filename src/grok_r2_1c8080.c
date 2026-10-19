typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_001757E0(u8 *, int, int);
extern void func_0015E630(u8 *);
extern void func_001C8150(u8 *, u8 *);

void residual_001C8080(u8 *p, u8 *q)
{
    s16 t;
    p[7]++;
    *(s16 *)(p + 28) = 70;
    t = *(s16 *)(q + 320);
    *(s16 *)(p + 320) = t;
    if (t == 0)
        *(f32 *)(p + 52) = *(f32 *)(q + 52) + -98.3333282f;
    else
        *(f32 *)(p + 52) = *(f32 *)(q + 52) - -98.3333282f;
    *(f32 *)(p + 56) = *(f32 *)(q + 56) + 6.42857122f;
    func_001757E0(p, 25, 22);
    p[0] = 1;
    func_0015E630(p);
    func_001C8150(p, q);
}
