typedef unsigned char u8;

extern void func_001B5350(u8 *, u8 *);
extern void func_001754A0(u8 *, int, int);
extern void func_00176160(u8 *, int, int, int);

void func_001B4580(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    p[6]++;
    p[0x13C] = 1;
    func_001B5350(q, p);
    func_001754A0(p, 0x1B, p[0x20]);
    p[0x24] = 0xB;
    func_00176160(p, 2, 2, 2);
}
