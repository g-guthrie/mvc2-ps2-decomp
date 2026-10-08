typedef unsigned char u8;
typedef signed char s8;

extern u8 D_00459CD0[];
extern u8 D_00458080[];
extern int func_00189310(u8 *, u8 *, u8 *);

int func_002C5C30(u8 *p)
{
    if (!func_00189310(p, D_00459CD0, p + 952))
        return 0;
    if (*(s8 *)*(u8 **)(p + 1056) == 0)
        return 0;
    p[620] = 5;
    return 1;
}

int func_0029B910(u8 *p)
{
    if (!func_00189310(p, D_00458080, p + 896))
        return 0;
    if (*(s8 *)*(u8 **)(p + 1056) == 0)
        return 0;
    p[620] = 0;
    return 1;
}
