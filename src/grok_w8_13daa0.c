typedef signed char s8;
typedef signed short s16;

typedef struct {
    s8 pad[3];
    s8 b3;
    s16 pad2;
    s16 w0e;
} G;

extern G *D_004C2840;
extern void func_003DAA40(void);
extern void func_0013D8E0(s8 *);

void func_0013DAA0(s8 *p)
{
    G *g = D_004C2840;

    if (g->b3 != 2 || g->w0e != 3)
        func_003DAA40();
    else if (*(s16 *)(p + 0x1C) != 30) {
        *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
        func_0013D8E0(p);
    }
}
