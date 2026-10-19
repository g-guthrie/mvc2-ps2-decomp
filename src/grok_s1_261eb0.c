typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001548D0(u8 *, f32 *, int);
extern void func_001E3710(u8 *, int);
extern void func_001266A0(u8 *, int, int);
extern void func_00184540(u8 *);

void residual_00261EB0(u8 *p)
{
    u8 *q;
    f32 v[2];
    if ((s8)p[0x151] == 1) {
        *(unsigned int *)(v + 0) = 0xC2D55555;
        *(unsigned int *)(v + 1) = 0x42CDB6DB;
        func_001548D0(p, v, 2);
        func_001E3710(p, 2);
        p[0x151] = 0;
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x1E6] = p[0x1E6];
        q[0x1B5] = 0x21;
        q[0x20A] = 1;
        func_001266A0(p, 0, 0);
    }
    if ((s8)func_00175700(p) < 0)
        func_00184540(p);
}
