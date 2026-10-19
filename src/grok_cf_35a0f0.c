typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern void func_00175700(u8 *);
extern void func_0035ADE0(u8 *, u8 *);
extern void func_0035AE70(u8 *, u8 *);
extern void func_0035ACA0(u8 *, u8 *);
extern void func_0035A7B0(u8 *, u8 *);

void residual_0035A0F0(u8 *p, u8 *q)
{
    u8 *o = *(u8 **)(p + 0x18);
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_0035ADE0(p, q);
    {
        f32 g = *(f32 *)(o + 0x430);
        f32 a = 34.28571319580078125f;
        f32 y = *(f32 *)(p + 0x38);
        if (y < a + g) {
            *(f32 *)(p + 0x38) = a + g;
            p[0x21] = 0;
            func_0035AE70(p, q);
        }
    }
    func_0035ACA0(p, q);
    if (*(s8 *)(p + 0x13C))
        func_0035A7B0(p, q);
}
