typedef unsigned char u8;
typedef signed char s8;

extern void func_001820A0(u8 *);
extern void func_00182300(u8 *);
extern void func_002E77B0(u8 *);
extern void func_002E5490(u8 *);
extern void func_002E54F0(u8 *);
extern int func_00185980(u8 *);
extern int func_00175700(u8 *);
extern void func_00184540(u8 *);
extern void func_001865B0(u8 *);
extern void func_002E7850(u8 *);

void func_002E5410(u8 *p)
{
    func_001820A0(p);
    func_00182300(p);
    if (*(s8 *)(p + 0x2C1) != 0 && p[0x1B7] != 0) {
        func_002E77B0(p);
        return;
    }
    if (p[0x212] == 0)
        func_002E5490(p);
    else
        func_002E54F0(p);
}

void func_002E77B0(u8 *p)
{
    if (*(s8 *)(p + 0x151) != 0 && func_00185980(p)) {
        func_002E7850(p);
        return;
    }
    if ((s8)func_00175700(p) < 0) {
        func_00184540(p);
    } else if (*(float *)(p + 56) < *(float *)(p + 0x430)) {
        *(float *)(p + 56) = *(float *)(p + 0x430);
        p[0x20D] = 0;
        func_001865B0(p);
    }
}
