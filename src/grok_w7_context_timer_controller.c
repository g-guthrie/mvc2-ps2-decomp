typedef unsigned char u8;
typedef signed char s8;
extern void func_00175C00(u8 *, int);
extern void func_00176160(u8 *, int, int, int);

void func_002FC6B0(u8 *p, void *context)
{
    u8 *q = (u8 *)context;
    s8 countdown;

    if (q[7] == 0)
        return;
    if (p[0x1E4] != 29) {
        q[7] = 0;
        func_00175C00(p, 0);
        return;
    }

    countdown = (s8)q[8];
    q[8] = (u8)(countdown - 1);
    if (countdown != 0)
        return;

    q[8] = 2;
    func_00176160(p, 0, q[9] + 15 + p[37] * 32, 1);
    if (q[9] < 7)
        q[9]++;
    else
        q[9] = 0;
}
