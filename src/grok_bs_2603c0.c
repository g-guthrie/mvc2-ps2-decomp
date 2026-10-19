typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001830D0(u8 *, f32 *, int);
extern void func_0036BFF0(u8 *, int, int, int);

void func_002603C0(u8 *p)
{
    f32 v[4];
    int one = 1;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if ((s8)p[0x151] == one)
    if ((s8)p[0x151] == one) {
        *(int *)&v[0] = 0x41555555;
        p[0x151] = 0;
        *(int *)&v[1] = 0x433C9249;
        func_001830D0(p, v, one);
    }
    if ((s8)p[0x151] == 2) {
        p[6]++;
        p[0x1B7] = 0;
        func_0036BFF0(p, 0x16, 0x13, 0);
        p[0x151] = 0;
    }
    func_00175700(p);
}
