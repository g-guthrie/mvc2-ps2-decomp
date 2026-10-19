typedef unsigned char u8;
typedef signed char s8;

extern void func_001820A0(u8 *);
extern void func_00182300(u8 *);
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern int func_00184720(u8 *);
extern int func_001864A0(u8 *);
extern int func_00185A90(u8 *);
extern void func_001865B0(u8 *);

void func_0017B970(u8 *p)
{
    func_001820A0(p);
    func_00182300(p);
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        func_001757E0(p, 6, 1);
        return;
    }
    if (!func_00184720(p) && func_001864A0(p) && !func_00185A90(p))
        func_001865B0(p);
}
