typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;

extern u8 *D_004C2840;
extern void func_003DAA40(void);
extern void func_0013D8E0(u8 *);

void func_0013DAA0(u8 *p)
{
    u8 *g = D_004C2840;
    s16 t;

    if ((s8)g[3] == 2 && *(s16 *)(g + 14) == 3) {
        func_003DAA40();
        return;
    }
    t = *(s16 *)(p + 0x1C);
    if (t != 0x1E) {
        *(s16 *)(p + 0x1C) = t + 1;
        func_0013D8E0(p);
    }
}
