typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;

extern void func_002E2F10(u8 *);

void func_002E1460(u8 *p)
{
    u8 *q = p + 0x2B8;
    u8 *c = q + 13;
    if (*(s8 *)(p + 0x2C5)) {
        p[0x201] = 2;
        {
            s16 n = *(s16 *)(q + 4) - 1;
            *(s16 *)(q + 4) = n;
            if (n < 0) {
                *c = 0;
                p[0x201] = 0;
                *(s8 *)(p + 0x1B1) = -128;
            }
        }
    }
    if (p[0x215] && p[5] == 0) {
        u8 *r = p + 0x2B8;
        s16 n = *(s16 *)(r + 6) - 1;
        *(s16 *)(r + 6) = n;
        if (n == 0) {
            u8 x = p[0x1E4];
            s16 *t = (s16 *)(r + 6);
            if (x == 0x15 || x == 0x1D)
                *t = 1;
            else
                func_002E2F10(p);
        }
    }
}
