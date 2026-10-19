typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern int func_001757E0(u8 *, int, int);
extern void func_0015E630(u8 *);
extern void func_001C7340(u8 *, u8 *);
extern f32 D_004F1FD0;

void func_001C7250(u8 *p, u8 *q)
{
    s16 t;
    p[7]++;
    t = (s16)(*(s16 *)(q + 320) ^ 1);
    *(s16 *)(p + 320) = t;
    if (t == 0)
        *(f32 *)(p + 52) = *(f32 *)(q + 52) + 80.0f;
    else
        *(f32 *)(p + 52) = *(f32 *)(q + 52) - 80.0f;
    *(f32 *)(p + 56) = D_004F1FD0 + 34.2857132f;
    *(u32 *)(p + 92) = 0;
    *(u32 *)(p + 104) = 0;
    *(u32 *)(p + 96) = 0xC0892492;
    *(u32 *)(p + 108) = 0xBF4DB6DB;
    func_001757E0(p, 25, 18);
    p[0] = 1;
    func_0015E630(p);
    func_001C7340(p, q);
}
