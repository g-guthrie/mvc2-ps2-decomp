typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001266A0(u8 *, int, int);
extern void func_001548D0(u8 *, f32 *, int);
extern void func_001E3710(u8 *, int);
extern void func_001843A0(u8 *);

void residual_0025B800(u8 *p)
{
    u8 *q;
    f32 v[2];
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if ((s8)p[0x151] != 6) {
        return;
    }
    func_001266A0(p, 0, 0);
    *(unsigned int *)(v + 0) = 0xC3055555;
    *(unsigned int *)(v + 1) = 0x43092492;
    func_001548D0(p, v, 15);
    func_001E3710(p, 6);
    q = *(u8 **)(p + 0x1DC);
    *(u8 **)(q + 0x1C8) = p;
    p[0x1E6] = p[0x140];
    *(s16 *)(q + 0x140) = p[0x1E6] ^ 1;
    q[0x1E6] = (s8)q[0x140];
    q[0x1B5] = 0x20;
    q[0x20A] = 1;
}
