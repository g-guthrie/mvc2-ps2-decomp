typedef unsigned char u8;
typedef signed char s8;

extern int func_00175700(u8 *);
extern void func_002CDA90(u8 *, u8 *);
extern void func_00186A20(u8 *);
extern void func_00183D10(u8 *);
extern void func_001820A0(u8 *);
extern void func_00182300(u8 *);
extern void func_002DD4C0(u8 *);
extern void func_002DD500(u8 *);
extern int func_001864A0(u8 *);
extern void func_001865B0(u8 *);

void func_002CDD00(u8 *p, u8 *q)
{
    func_00175700(p);
    func_002CDA90(p, q);
    if (*(s8 *)(p + 337) == 0) {
        p[6]++;
        func_00186A20(p);
        func_00183D10(p);
    }
}

void func_002DD450(u8 *p)
{
    func_001820A0(p);
    func_00182300(p);
    if (!p[530])
        func_002DD4C0(p);
    else
        func_002DD500(p);
    if (func_001864A0(p))
        func_001865B0(p);
}
