typedef unsigned char u8;
typedef signed char s8;

extern s8 func_00175700(u8 *);
extern void func_00365F60(u8 *, int);
extern void func_001843A0(u8 *);

void func_00250210(u8 *p)
{
    if (func_00175700(p) < 0) {
        *(int *)(p + 0x5C) = 0;
        *(int *)(p + 0x60) = 0;
        *(int *)(p + 0x68) = 0;
        *(int *)(p + 0x6C) = 0;
        func_001843A0(p);
        return;
    }
    if ((s8)p[0x151] == 0)
        return;
    p[0x151] = 0;
    if (p[0x1B7])
        func_00365F60(p, 2);
    else
        func_00365F60(p, 0);
    p[0x28F] = 0;
    p[0x28E] = 16;
}
