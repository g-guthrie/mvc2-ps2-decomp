typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;

extern u8 D_0044F990[];
extern u8 D_0044F991[];

extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_001266A0(u8 *, int, int);

void func_001F5470(u8 *p)
{
    u8 *s1 = p;
    u8 *s0 = s1 + 0x2B8;
    u8 *q;
    *(f32 *)(s1 + 0x34) += *(f32 *)(s1 + 0x5C);
    *(f32 *)(s1 + 0x5C) += *(f32 *)(s1 + 0x68);
    *(f32 *)(s1 + 0x38) += *(f32 *)(s1 + 0x60);
    *(f32 *)(s1 + 0x60) += *(f32 *)(s1 + 0x6C);
    if ((s8)func_00175700(s1) < 0) {
        u32 t = s1[7];
        s1[7] = t + 1;
        *(f32 *)(s1 + 0x5C) = 6.66666651f;
        *(f32 *)(s1 + 0x68) = -0.104166664f;
        *(f32 *)(s1 + 0x60) = 19.2857132f;
        *(f32 *)(s1 + 0x6C) = -0.669642806f;
        if (s1[0x1E6] != 0) {
            *(f32 *)(s1 + 0x5C) = -*(f32 *)(s1 + 0x5C);
            *(f32 *)(s1 + 0x68) = -*(f32 *)(s1 + 0x68);
        }
        func_001757E0(s1, 15, 33);
        return;
    }
    if (*(s8 *)(s1 + 0x151) == 0)
        return;
    s1[0x151] = 0;
    func_001266A0(s1, 0, 0);
    q = *(u8 **)(s1 + 0x1DC);
    q[0x20A] = D_0044F990[(s8)s0[2] * 2];
    q[0x1B5] = D_0044F991[(s8)s0[2] * 2];
    s1[0x1B5] = D_0044F991[(s8)s0[2] * 2];
    s1[0x40D] = 0;
    s1[0x40C] = 0;
    s1[0x33B] = 0;
    s1[0x33C] = 0;
    s1[0x219] = (u8)((s8)s0[2] / 2 + 32);
}
