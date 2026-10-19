typedef unsigned char u8;
typedef signed int s32;
typedef unsigned int u32;

extern s32 func_00169BC0(u8 *, s32);
extern s32 func_00169AE0(u8 *, s32);
extern void func_00169E50(u8 *, s32, s32);

s32 func_00169850(u8 *p)
{
    u32 s = p[0x451];
    switch (s) {
    case 0:
        p[0x451] = s + 1;
        func_00169E50(p, p[0x450], 2);
    case 1:
        return func_00169AE0(p, 2);
    case 2:
        return func_00169BC0(p, 2);
    default:
        return 0;
    }
}
