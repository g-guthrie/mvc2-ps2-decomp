typedef unsigned char u8;
typedef signed char s8;

extern void func_0011D8F8(u8 *, int, int);
extern void func_001820A0(u8 *);
extern void func_00182300(u8 *);
extern void func_003175D0(u8 *);
extern void func_0031C940(u8 *);
extern void func_0031CB00(u8 *);

void func_00308A70(u8 *p)
{
    u8 *q = p + 0x2B8;
    u8 v = q[5];
    func_0011D8F8(p + 0x2B8, 0, 0x80);
    q[5] = v;
}

void func_00316C40(u8 *p)
{
    u8 *q = p + 0x2B8;
    u8 v = q[8];
    func_0011D8F8(p + 0x2B8, 0, 0x80);
    q[8] = v;
}

void func_00317700(u8 *p)
{
    if (p[0x212] == 0) {
        if (*(s8 *)(p + 0x1EA) & 0xF)
            func_003175D0(p);
    } else if (*(s8 *)(p + 0x1EA) & 0xF0)
        func_003175D0(p);
}

void func_0031C8F0(u8 *p)
{
    func_001820A0(p);
    func_00182300(p);
    if (p[0x212] == 0)
        func_0031C940(p);
    else
        func_0031CB00(p);
}
