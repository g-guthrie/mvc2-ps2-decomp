typedef unsigned char u8;
typedef signed char s8;

extern u8 D_0045BD30[];
extern int func_00189310(u8 *, u8 *, u8 *);
extern void func_0018A990(u8 *, u8 *);
extern void func_00186A60(u8 *);

int func_002F6BF0(u8 *p)
{
    int n;
    int i;
    u8 *t;

    t = p + 0x2B8;
    if (!func_00189310(p, D_0045BD30, p + 0x388))
        return 0;
    n = 0;
    i = 0;
    do {
        if (t[i] == 0)
            n++;
        i++;
    } while (i < 6);
    if (n == 6)
        return 0;
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            if ((s8)p[0x1E8] != 0)
                return 0;
            p[0x1E8] = (s8)p[0x1E8] + 1;
        }
    }
    func_0018A990(p, p + 0x388);
    p[0x1B7] = p[0x1B7] + (u8)((s8)p[0x212] * 2);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 1;
    func_00186A60(p);
    return 1;
}
