typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_0021EA40(u8 *);

void residual_0021E9D0(u8 *p)
{
    func_00175700(p);
    if ((s8)p[0x151] == 0) {
        p[6]++;
        *(f32 *)(p + 0x5C) = p[0x1E6] ? -20.0f : 20.0f;
        func_0021EA40(p);
    }
}
