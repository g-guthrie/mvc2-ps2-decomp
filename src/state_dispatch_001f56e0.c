typedef unsigned char u8;
typedef unsigned int u32;
typedef void (*StateAction)(u8 *);

extern u32 jtbl_0044F9C0[];

void func_001F56E0(u8 *p)
{
    p[0x1FE] = 1;
    p[0x201] = 2;
    p[0x209] = 2;
    p[0x40C] = 2;
    p[0x33C] = 5;
    ((StateAction)jtbl_0044F9C0[p[7]])(p);
}
