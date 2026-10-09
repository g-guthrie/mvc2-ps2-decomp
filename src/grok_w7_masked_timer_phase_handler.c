typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
extern void func_0030E440(u8 *, int);
extern int func_00175700(u8 *);
extern void func_00176090(u8 *, int, int, int);
extern void func_0030F650(u8 *);
extern void func_00176160(u8 *, int, int, int);
void func_0030EA00(u8 *p)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_0030E440(p, 20);
    *(unsigned int *)(p + 0x2D8) = 0xFF;
    if ((s8)func_00175700(p) < 0) {
        func_00176090(p, 0, 0, 1);
        func_0030F650(p);
        return;
    }
    if ((s8)p[0x150] == 0)
        return;
    *(s16 *)(p + 0x1C) ^= 7;
    if (((s8)p[0x150] & 1) != 0)
        func_00176160(p, 1, *(s16 *)(p + 0x1C), 1);
    if (((s8)p[0x150] & 4) != 0) {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        func_00176090(p, 0, 0, 1);
    }
}
