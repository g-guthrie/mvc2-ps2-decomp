typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_0018FDB0(u8 *);
extern void func_001548D0(u8 *, f32 *, int);
extern void func_001E3210(u8 *, int);
extern void func_001E3710(u8 *, int);
extern void func_001266A0(u8 *, int, int);
extern void func_001843A0(u8 *);

void func_002AB4A0(u8 *p)
{
    unsigned v[3];
    u8 *q;

    if ((s8)func_00175700(p) < 0)
        goto neg;
    if ((s8)p[0x151] < 0) {
        p[0x151] = 0;
        (*(u8 **)(p + 0x1DC))[0x1B5] = 0x23;
        func_0018FDB0(p);
        v[0] = 0xC2555555;
        v[1] = 0x42892492;
        v[2] = 0;
        func_001548D0(p, (f32 *)v, 1);
        func_001E3210(p, 3);
        func_001E3710(p, 0);
    } else if ((s8)p[0x151] > 0) {
        p[0x151] = 0;
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x20A] = 1;
        q[0x1B5] = 0x21;
        func_001266A0(p, 0, 0);
    }
    return;
neg:
    func_001843A0(p);
}
