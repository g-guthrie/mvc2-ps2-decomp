typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;

extern void func_00176160(u8 *, int, int, int);
extern void func_00175C00(u8 *, int);

void func_002FC440(u8 *p, u8 *q)
{
    s16 t;

    if (p[0x216] == 0)
        return;
    if (*(s16 *)(p + 0x434) == 0)
        *(s16 *)(q + 4) = 0;
    t = *(s16 *)(q + 4);
    if (t != 0) {
        *(s16 *)(q + 4) = (s16)(t - 1);
        func_00176160(p, 0, (int)(s8)q[3] + (p[0x25] << 5), 1);
        {
            s8 c = q[3];
            if (c < 7)
                q[3] = c + 1;
            else
                q[3] = 0;
        }
    } else {
        func_00175C00(p, 0);
        p[0x216] = 0;
    }
}
