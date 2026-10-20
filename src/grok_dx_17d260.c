typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern u8 D_004D18A0;
extern void func_00175C00(u8 *, s32);
extern s32 func_00185010(u8 *);
extern void func_0017D390(u8 *);
extern void func_001843A0(u8 *);
extern void func_0018F4C0(u8 *);
extern s32 func_001864A0(u8 *);
extern void func_00184540(u8 *);

void func_0017D270(u8 *p)
{
    u8 *q;

    p[0x215] = 0;
    p[0x209] = 1;
    if (*(s16 *)(p + 0x434) != 0 && D_004D18A0 == 4) {
        if (func_00185010(p) != 0)
            return;
    }
    if (p[0x20A] != 0) {
        func_0017D390(p);
        return;
    }
    q = *(u8 **)(p + 0x1DC);
    if (q == 0) {
        func_001843A0(p);
        return;
    }
    if ((s8)q[0x1B4] == 0 && q[0x268] == 0) {
        if ((s8)q[0x1FE] == 0) {
            if (*(s16 *)(p + 0x434) == 0) {
                func_0018F4C0(p);
                return;
            }
            else {
                func_00175C00(p, 1);
                if (func_001864A0(p) != 0)
                    func_001843A0(p);
                else
                    func_00184540(p);
            }
            return;
        }
        q[0x1FE] = 0;
    }
    (*(void (**)(u8 *))(*(u8 **)(q + 0x43C) + 0x30))(p);
}
