typedef unsigned char u8;
typedef signed char s8;
extern u8 D_0044F620[];
extern int func_00189B90(u8 *, u8 *, u8 *);
extern void func_00186A60(u8 *, int);
int func_001EE480(u8 *p)
{
    int result = 0;
    if (!func_00189B90(p, D_0044F620, p + 0x3A8))
        return result;
    if (*(s8 *)*(u8 **)(p + 0x420) < 3)
        return result;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    func_00186A60(p, (p[0x1FD] = 17, 29));
    return 1;
}
