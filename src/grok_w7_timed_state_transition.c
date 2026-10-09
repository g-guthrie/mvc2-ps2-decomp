typedef unsigned char u8;

extern void func_00176160(u8 *, int, int, int);
extern void func_001E3710(u8 *, int);
extern void func_0030AC70(u8 *);

void func_0030AC10(u8 *p)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x33C] = 5;
    p[6]++;
    func_00176160(p, 2, 10, 1);
    func_001E3710(p, 77);
    func_0030AC70(p);
}
