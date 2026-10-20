typedef unsigned char u8;
typedef signed char s8;

extern void (*D_00464990[])(u8 *, u8 *);

void residual_003874F0(u8 *p, u8 *q)
{
    if (q[4] < 2) {
        if (p[1] == q[1])
            goto chk2;
    }
    p[4]++;
    p[0x13C] = 0;
    return;
chk2:
    if (q[5] < 2)
        goto tbl;
    p[4]++;
    p[0x13C] = 0;
    q[0x2BE] = 0;
    return;
tbl:
    D_00464990[p[5]](p, q);
}
