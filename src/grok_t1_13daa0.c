typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;

extern u8 *D_004CB5D0;
extern void func_003DAA40(void);
extern void func_0013D8E0(u8 *);

void func_0013DAA0(u8 *p)
{
    u8 *g = D_004CB5D0;

    if ((s8)g[3] != 2)
        func_003DAA40();
    else if (*(s16 *)(g + 14) != 3) {
        if (*(s16 *)(p + 0x1C) != 0x1E) {
            *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
            func_0013D8E0(p);
        }
    } else
        func_003DAA40();
}
