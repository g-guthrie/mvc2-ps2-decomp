typedef unsigned char u8;
typedef signed char s8;

extern void func_001820A0(u8 *);
extern void func_00182300(u8 *);
extern void func_002E77B0(u8 *);
extern void func_002E5490(u8 *);
extern void func_002E54F0(u8 *);

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
