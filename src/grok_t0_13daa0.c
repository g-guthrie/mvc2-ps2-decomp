typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;

extern s8 *D_004CB5D0;
extern void func_003DAA40(void);
extern void func_0013D8E0(u8 *);

void func_0013DAA0(u8 *p)
{
    if (D_004CB5D0[3] == 2 && *(s16 *)((u8 *)D_004CB5D0 + 0xE) == 3) {
        func_003DAA40();
        return;
    }
    if (*(s16 *)(p + 0x1C) != 0x1E) {
        *(s16 *)(p + 0x1C) += 1;
        func_0013D8E0(p);
    }
}
