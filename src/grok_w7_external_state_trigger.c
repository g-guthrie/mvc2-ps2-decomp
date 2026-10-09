typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
extern int func_00175700(u8 *);
extern void func_00186A20(u8 *);
extern void func_003AE8B0(u8 *);
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
