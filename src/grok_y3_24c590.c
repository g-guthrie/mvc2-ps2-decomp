typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;

extern void func_00363640(u8 *, int, int);
extern s8 D_00453080[];

int func_0024C590(u8 *p)
{
    s8 s0;
    int a1;
    s16 n;

    n = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = n;
    if (n != 0)
        return 0;
    do {
        a1 = *(s16 *)(p + 0x1C);
        s0 = D_00453080[a1 * 2];
        if (s0 == -1)
            break;
        func_00363640(p, (u8)s0, (u8)a1);
        *(s16 *)(p + 0x1E) = D_00453080[*(s16 *)(p + 0x1C) * 2 + 1];
        *(s16 *)(p + 0x1C) += 1;
    } while (*(s16 *)(p + 0x1E) == 0);
    return s0;
}
