typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;

extern void func_00175700(u8 *);
extern void func_001266A0(u8 *, int, int);
extern void func_001830D0(u8 *, u32 *, int);

void func_0024C2C0(u8 *p)
{
    u32 v[3];

    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        p[6]++;
        if (p[2] == 0)
            func_001266A0(p, 0xD, 3);
        else
            func_001266A0(p, 0xD, 4);
        p[0x404] = 0;
        p[0x405] = 0;
        v[0] = 0xC1C80000;
        v[1] = 0x43654924;
        v[2] = 0;
        func_001830D0(p, v, 1);
    }
}
