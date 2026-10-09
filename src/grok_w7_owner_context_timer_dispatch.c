typedef unsigned char u8;
typedef unsigned int u32;
typedef signed char s8;
extern void func_0030C120(u8 *);
extern int func_00175700(u8 *);
extern int func_001266A0(u8 *, int, int);
extern void func_00175C00(u8 *, int);
void func_0030C090(u8 *p)
{
    u8 *q;
    func_0030C120(p);
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0)
        return;
    p[6]++;
    p[0x151] = 0;
    q = *(u8 **)(p + 0x1DC);
    *(u8 **)(q + 0x1C8) = p;
    q[0x1E6] = p[0x1E6] ^ 1;
    q[0x1B5] = 32;
    q[0x20A] = 1;
    func_001266A0(p, 0, 0);
    func_00175C00(q, 0);
}
