typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001266A0(u8 *, int, int);
extern void func_001830D0(u8 *, f32 *, int);

void func_0024C2C0(u8 *p)
{
    f32 v[3];

    p[0x40C] = 2;
    p[0x33C] = 5;
    if (p[0x269] == 6)
        p[0x405] = 2;
    else
        p[0x405] = 0;
    func_00175700(p);
    if ((s8)p[0x151] == 0)
        return;
    p[6]++;
    if (p[2] == 0) {
        func_001266A0(p, 13, 3);
        p[0x404] = 0;
    } else {
        func_001266A0(p, 13, 4);
        p[0x404] = 0;
    }
    p[0x405] = 0;
    v[0] = -25.0f;
    v[1] = 229.28570556640625f;
    v[2] = 0.0f;
    func_001830D0(p, v, 1);
}
