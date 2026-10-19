typedef unsigned char u8;
typedef signed short s16;

extern int func_0016B240(u8 *, int);
extern void func_0016B0C0(u8 *, u8 *, int);
extern int func_00185630(u8 *);
extern int func_00166C80(u8 *, u8 *, int);

int func_00166490(u8 *p, u8 *a1)
{
    int flag;

    if (!func_0016B240(p, 2))
        return 0;
    func_0016B0C0(p, a1, 0);
    p[530] = 0;
    flag = 1;
    p[439] = 1;
    *(s16 *)(p + 526) = 2048;
    if (!func_00185630(p)) {
        p[530] = 1;
        flag = 0;
        if (func_00185630(p))
            flag = 1;
    }
    p[530] = 0;
    p[439] = 0;
    *(s16 *)(p + 526) = 0;
    func_00166C80(p, a1, flag);
}
