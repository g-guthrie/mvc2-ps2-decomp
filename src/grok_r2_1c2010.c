typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern int func_001757E0(u8 *, int, int);
extern void func_001C20E0(u8 *, u8 *);

void func_001C2010(u8 *p, u8 *q)
{
    s16 t;
    p[7]++;
    p[0] = 1;
    t = *(s16 *)(q + 320);
    if (t == 0)
        *(f32 *)(p + 52) = *(f32 *)(q + 52) + 80.0f;
    else
        *(f32 *)(p + 52) = *(f32 *)(q + 52) - 80.0f;
    *(f32 *)(p + 56) = *(f32 *)(q + 1072) + 548.571411f;
    *(u32 *)(p + 92) = 0;
    *(u32 *)(p + 104) = 0;
    *(u32 *)(p + 96) = 0;
    *(u32 *)(p + 108) = 0xBF4DB6DB;
    func_001757E0(p, 25, 12);
    func_001C20E0(p, q);
}
