typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;

extern s8 func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_00175C00(u8 *, int);
extern void func_001E3710(u8 *, int);
extern void func_001548D0(u8 *, u32 *, int);
extern void func_001E3B70(u8 *, int);

void residual_002D57F0(u8 *p)
{
    u8 *q;
    u32 v[4];

    if (func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if (p[0x15B])
        func_00175C00(*(u8 **)(p + 0x1DC), 6);
    if (*(s8 *)(p + 0x150)) {
        func_001E3710(p, 0x4F);
        p[0x150] = 0;
    }
    {
        s8 c = *(s8 *)(p + 0x151);
        if (c == 0)
            return;
        if (c > 0) {
            p[0x151] = 0;
            q = *(u8 **)(p + 0x1DC);
            *(u8 **)(q + 0x1C8) = p;
            q[0x20A] = 0xE;
            q[0x1B5] = 0x20;
        } else {
            p[0x151] = 0;
            v[0] = 0xC321AAAA;
            v[1] = 0x42D64924;
            v[2] = 0;
            func_001548D0(p, v, 0);
            func_001E3B70(*(u8 **)(p + 0x1DC), 0);
        }
    }
}
