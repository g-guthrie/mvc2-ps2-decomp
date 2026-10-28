typedef unsigned char u8;
typedef signed char s8;
typedef int s32;
typedef float f32;

void func_0018D290(u8 *p)
{
    extern s32 fptosi(f32);
    extern void func_0018D0C0(u8 *);
    f32 a, b, v;
    s8 c;
    if (p[5] != 0 || *(s8 *)(p + 0x1B4) != 0 || (c = *(s8 *)(p + 0x296)) == 0) return;
    p[0x296] = c - 1;
    v = *(f32 *)(p + 0x2A4);
    if (fptosi(v) == 0) return;
    a = *(f32 *)(p + 0x5C);
    b = *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x5C) = v;
    *(f32 *)(p + 0x68) = *(f32 *)(p + 0x2A8);
    func_0018D0C0(p);
    *(f32 *)(p + 0x2A4) = *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x2A8) = *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x5C) = a;
    *(f32 *)(p + 0x68) = b;

}
