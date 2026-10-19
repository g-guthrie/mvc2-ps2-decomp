typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

extern u8 *D_004D18B8;
extern u8 *D_004D18C4;
extern void func_00183BA0(u8 *);
extern void func_00183AD0(u8 *);

s32 func_001E8EB0(void)
{
    u8 *q;
    u8 *p;
    u8 bits;
    p = D_004D18B8;
    bits = (u8) *(s8 *)(p + 0x25C);
    q = D_004D18C4;
    bits = (u8)(bits | *(s8 *)(q + 0x25C));
    if (bits & (1 << p[2]))
        func_00183BA0(p);
    if (bits & (1 << q[2]))
        func_00183BA0(q);
    if (bits != (u8)(p[0x25C] | q[0x25C])) {
        if (bits & (1 << p[2]))
            func_00183AD0(p);
        if (bits & (1 << q[2]))
            func_00183AD0(q);
    }
    return bits;
}
