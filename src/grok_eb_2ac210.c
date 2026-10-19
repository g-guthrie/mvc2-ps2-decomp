typedef unsigned char u8;
typedef signed char s8;

extern u8 D_00458AA0[];
extern u8 D_00458B20[];
extern u8 D_00458AB0[];
extern u8 D_00458B30[];
extern u8 D_00458AC0[];
extern u8 D_00458B60[];
extern int func_00189310(u8 *, u8 *, u8 *);
extern int func_00189EE0(u8 *, u8 *, u8 *);

int func_002AC210(u8 *p)
{
    u8 *tbl;

    if (*(int *)(p + 0xD0) == 0)
        tbl = D_00458AA0;
    else
        tbl = D_00458B20;
    if (func_00189310(p, tbl, p + 0x378) && **(s8 **)(p + 0x420)) {
        p[0x26C] = 6;
        p[0x1B7] = 1;
        return 1;
    }
    if (*(int *)(p + 0xD0) == 0)
        tbl = D_00458AB0;
    else
        tbl = D_00458B30;
    if (func_00189310(p, tbl, p + 0x380) && **(s8 **)(p + 0x420)) {
        p[0x26C] = tbl[4];
        p[0x1B7] = 1;
        return 1;
    }
    if (func_00189310(p, D_00458AC0, p + 0x388) && **(s8 **)(p + 0x420)) {
        p[0x26C] = 14;
        p[0x1B7] = 1;
        return 1;
    }
    if (*(int *)(p + 0xD0)
        && func_00189EE0(p, D_00458B60, p + 0x3B8)
        && **(s8 **)(p + 0x420) >= 3) {
        p[0x26C] = 18;
        p[0x1B7] = 1;
        return 1;
    }
    return 0;
}
