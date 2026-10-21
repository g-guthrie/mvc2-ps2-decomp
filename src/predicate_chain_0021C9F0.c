typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern s32 func_00188690(u8 *);
extern s32 func_00188ED0(u8 *);
extern s32 func_00188C70(u8 *);
extern s32 func_00189130(u8 *);
extern s32 func_0021CB10(u8 *);
extern s32 func_0021CF50(u8 *);
extern s32 func_0021CD50(u8 *);
extern s32 func_0021CBD0(u8 *);
extern s32 func_0021CCA0(u8 *);
extern s32 func_0021CE10(u8 *);
extern s32 func_0021CFD0(u8 *);
extern s32 func_0021CEF0(u8 *);
extern s32 func_0021D210(u8 *);
extern s32 func_00187BB0(u8 *);
extern s32 func_00188330(u8 *);

void func_0021C9F0(u8 *p)
{
    if (func_00188690(p)) return;
    if (func_00188ED0(p)) return;
    if (func_00188C70(p)) return;
    if (func_00189130(p)) {
        if ((s8)p[0x4DD] != 1)
            *(s16 *)(p + 0x2DA) = 1;
        return;
    }
    if (func_0021CB10(p)) return;
    if (func_0021CF50(p)) return;
    if (func_0021CD50(p)) return;
    if (func_0021CBD0(p)) return;
    if (func_0021CCA0(p)) return;
    if (func_0021CE10(p)) return;
    if (func_0021CFD0(p)) return;
    if (func_0021CEF0(p)) return;
    if (func_0021D210(p)) return;
    func_00187BB0(p);
    func_00188330(p);
}
