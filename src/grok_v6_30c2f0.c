typedef unsigned char u8;
typedef signed char s8;

extern int func_00175700(u8 *);
extern void func_0030C290(u8 *);
extern void func_001266A0(u8 *, int, int);
extern void func_00175C00(u8 *, int);
extern void func_001DAF30(u8 *, int);

void residual_0030C2F0(u8 *p)
{
    u8 *q;

    q = *(u8 **)(p + 0x1DC);
    q[0x23E] = 3;
    q = *(u8 **)(p + 0x1DC);
    q[0x23C] = 3;
    func_0030C290(p);
    func_00175700(p);
    if ((s8)p[0x151] != 0) {
        p[6]++;
        p[0x151] = 0;
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x1E6] = p[0x1E6] ^ 1;
        q[0x1B5] = 0x22;
        q[0x20A] = 10;
        func_001266A0(p, 0, 0);
        func_00175C00(q, 1);
        func_001DAF30(p, 3);
    }
}
