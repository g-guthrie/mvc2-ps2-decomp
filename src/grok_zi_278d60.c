typedef unsigned char u8;
typedef signed short s16;

extern u8 D_004D18E8;
extern void func_0015FF70(u8 *);
extern void func_001BDFC0(u8 *, int);
extern int func_001757E0(u8 *, int, int);

void func_00278D60(u8 *p)
{
    p[6]++;
    p[0x13C] = 0;
    *(int *)(p + 0x118) = 0;
    *(s16 *)(p + 0x1C) = 140;
    if (D_004D18E8 == 8)
        func_0015FF70(p);
    func_001BDFC0(p, 0);
    func_001BDFC0(p, 1);
    func_001BDFC0(p, 2);
    func_001BDFC0(p, 3);
    func_001BDFC0(p, 4);
    func_001BDFC0(p, 5);
    func_001BDFC0(p, 6);
    func_001BDFC0(p, 7);
    func_001BDFC0(p, 8);
    func_001BDFC0(p, 9);
    func_001BDFC0(p, 10);
    func_001BDFC0(p, 11);
    func_001BDFC0(p, 12);
    func_001BDFC0(p, 13);
    func_001BDFC0(p, 14);
    func_001BDFC0(p, 15);
    func_001BDFC0(p, 16);
    func_001BDFC0(p, 17);
    func_001BDFC0(p, 18);
    func_001BDFC0(p, 19);
    func_001BDFC0(p, 20);
    func_001BDFC0(p, 21);
    func_001BDFC0(p, 22);
    func_001BDFC0(p, 23);
    func_001BDFC0(p, 24);
    func_001BDFC0(p, 25);
    func_001757E0(p, 18, 0);
}
