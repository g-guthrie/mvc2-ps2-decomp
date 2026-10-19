typedef unsigned char u8;
typedef signed short s16;

extern u8 *D_004CB5D0;
extern void func_003DAA40(void);
extern void func_0013D8E0(u8 *);

void func_0013DAA0(u8 *p)
{
    u8 *g = D_004CB5D0;
    if ((signed char)g[3] != 2 || *(s16 *)(g + 14) != 3)
        func_003DAA40();
    else if (*(s16 *)(p + 0x1C) != 30) {
        (*(s16 *)(p + 0x1C))++;
        func_0013D8E0(p);
    }
}
