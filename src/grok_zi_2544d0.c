typedef unsigned char u8;
typedef signed short s16;

extern int func_00188690(u8 *);
extern int func_00188ED0(u8 *);
extern int func_00188C70(u8 *);
extern int func_00189130(u8 *);
extern int func_002549C0(u8 *);
extern int func_00254910(u8 *);
extern int func_002547F0(u8 *);
extern int func_00254880(u8 *);
extern int func_002546F0(u8 *);
extern int func_00254680(u8 *);
extern int func_00254780(u8 *);
extern int func_00254B30(u8 *);
extern int func_00254A50(u8 *);
extern int func_00254AC0(u8 *);
extern int func_00254C00(u8 *);
extern int func_001891F0(u8 *, int);
extern int func_00254BA0(u8 *);
extern void func_00187BB0(u8 *);
extern void func_00188330(u8 *);

void func_002544D0(u8 *p)
{
    if (*(s16 *)(p + 0x2B8) == 0) {
        if (func_00188690(p))
            return;
        if (func_00188ED0(p))
            return;
        if (func_00188C70(p))
            return;
        if (func_00189130(p))
            return;
        if (func_002549C0(p))
            return;
        if (func_00254910(p))
            return;
        if (func_002547F0(p))
            return;
        if (func_00254880(p))
            return;
        if (func_002546F0(p))
            return;
        if (func_00254680(p))
            return;
        if (func_00254780(p))
            return;
    } else {
        if (func_00188ED0(p))
            return;
        if (func_00189130(p))
            return;
        if (func_00254B30(p))
            return;
        if (func_00254A50(p))
            return;
        if (func_00254AC0(p))
            return;
        if (func_002546F0(p))
            return;
        if (func_00254680(p))
            return;
        if (func_00254780(p))
            return;
    }
    if (func_00254C00(p))
        return;
    if (func_001891F0(p, 9)) {
        func_00254BA0(p);
        return;
    }
    func_00187BB0(p);
    func_00188330(p);
}
