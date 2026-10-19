typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001830D0(u8 *, f32 *);
extern void func_0036BFF0(u8 *, int, int, int);

void func_00260960(u8 *p)
{
    int v[2];
    int one = 1;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if ((s8)p[0x151] == one) {
        p[0x151] = 0;
        v[0] = 0xC1D55555;
        v[1] = 0x43892492;
        func_001830D0(p, (f32 *)v);
        func_0036BFF0(p, 0xE, 0x13, 0xE);
        *(s16 *)(p + 0x1C) = 0xB4;
    }
    if ((s8)p[0x153] < 0)
        p[6]++;
    func_00175700(p);
}
