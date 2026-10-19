typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;

extern void func_002E2F10(u8 *);

void func_002E1460(u8 *p)
{
    u8 *q = p + 696;
    u8 *c = q + 13;
    if (*(s8 *)(p + 0x2C5)) {
        p[0x201] = 2;
        if ((*(s16 *)(q + 4) = *(s16 *)(q + 4) - 1) < 0) {
            *c = 0;
            p[0x201] = 0;
            *(s8 *)(p + 0x1B1) = -128;
        }
    }
    if (p[0x215] && p[5] == 0) {
        s16 *t;
        if ((*(s16 *)(p + 0x2BE) = *(s16 *)(p + 0x2BE) - 1) == 0) {
            u8 x = p[0x1E4];
            t = (s16 *)(q + 6);
            if (x == 0x15 || x == 0x1D)
                *t = 1;
            else
                func_002E2F10(p);
        }
    }
}
