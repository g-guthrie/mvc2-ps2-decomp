typedef unsigned char u8;
typedef signed char s8;

extern void func_003DAA40(u8 *);

void func_0013B010(u8 *p)
{
    s8 *o = *(s8 **)(p + 0x18);
    p[0x13C] = o[0x13C];
    if (!p[4]) {
        if ((s8)p[0x13C] == 0)
            p[4] += 1;
    } else {
        func_003DAA40(p);
    }
}
