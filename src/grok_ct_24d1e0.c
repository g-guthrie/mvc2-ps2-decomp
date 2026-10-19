typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern s8 func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_0015D010(u8 *, f32 *);
extern void func_00126400(int);

void residual_0024D1E0(u8 *p)
{
    u8 *q;
    int v[2];
    if (func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if ((s8)p[0x150] == 1) {
        p[0x150] = 0;
        v[0] = 0xC2FD5555;
        v[1] = 0x42B40000;
        func_0015D010(p, (f32 *)v);
        p[0x1B4] = 10;
    }
    if ((s8)p[0x151] == 1) {
        p[0x151] = 0;
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x1E6] = (s8)p[0x1E6] ^ 1;
        q[0x20D] = 2;
        q[0x1B5] = 0x20;
        q[0x20A] = 1;
        func_00126400(1);
    }
}
