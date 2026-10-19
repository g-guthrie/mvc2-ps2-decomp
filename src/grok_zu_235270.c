typedef unsigned char u8;
typedef signed int s32;

extern s32 func_003D92F0(u8 *);
extern void func_00126400(u8 *);
extern void func_001843A0(u8 *);
extern void func_00175700(u8 *);
extern void (*D_004522D0[])(u8 *, u8 *);

void func_00235270(u8 *p, u8 *q)
{
    if (func_003D92F0(q) != 0) {
        if (p[0x21] != 0) {
            func_00126400(p);
            p[0x39] = 1;
        }
        func_001843A0(p);
        return;
    }
    {
        u8 m = p[0x20];
        if (m == 3 || m == 1 || m == 4 || m == 2)
            return;
        if (m != 0)
            return;
        if (p[0x21] != 0)
            D_004522D0[p[7]](p, q);
        else
            func_00175700(p);
    }
}
