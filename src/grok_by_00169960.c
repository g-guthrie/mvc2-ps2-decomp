typedef unsigned char u8;
typedef signed int s32;

extern void func_00168E80(u8 *);
extern s32 func_001695A0(u8 *);
extern s32 func_00169F40(u8 *);
extern s32 func_00169AE0(u8 *, s32);
extern s32 func_00169BC0(u8 *, s32);

s32 func_00169960(u8 *p)
{
    u8 *o;
    u8 st;

    if (p[0x496] == 0) {
        o = *(u8 **)(p + 0x220);
        if (o[5] == 0) {
            if (o[0x1E4] < 2) {
                func_00168E80(p);
                func_001695A0(p);
                return 1;
            }
            if (p[0x1E4] >= 5 && p[0x1E4] < 10) {
                func_00168E80(p);
                func_001695A0(p);
                return 1;
            }
        }
    }
    st = p[0x451];
    switch (st) {
    case 2:
        return func_00169BC0(p, 2);
    case 1:
        return func_00169AE0(p, 2);
    case 0:
        p[0x451] = st + 1;
        func_00169F40(p);
        return func_00169AE0(p, 2);
    default:
        return 0;
    }
}
