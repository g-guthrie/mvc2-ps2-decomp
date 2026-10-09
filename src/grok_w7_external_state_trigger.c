typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
extern int func_00175700(u8 *);
extern void func_00186A20(u8 *);
extern void func_003AE8B0(u8 *);
extern int func_003AA280(u8 *);
extern void func_001E3210(u8 *, int);
void func_002F4E00(u8 *p, void *q)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        p[6]++;
        p[0x209] = 2;
        if (*(u16 *)q != 0)
            func_00186A20(p);
        func_003AE8B0(p);
    }
}

void func_002F5230(u8 *p)
{
    p[0x40c] = 2;
    p[0x33c] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        p[6]++;
        if (func_003AA280(p) == 0)
            p[6] = 3;
        else
            func_001E3210(p, 32);
    }
}
