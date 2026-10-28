typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    s8 b0;
    s8 b1;
    s8 b2;
    s8 b3;
    s8 b4;
    s8 b5;
} G41DBA0;

extern G41DBA0 *D_004C2840;
extern s32 D_004D1788[];
extern s32 D_004D178C[];
extern u8 D_004D17C9[];

static void func_0041DB80(void)
{
    D_004C2840->b3 = 0;
    D_004C2840->b4 = 0;
    D_004C2840->b5 = 0;
}

void func_0041DBA0(void)
{
    extern s32 func_003299D0();
    extern s32 func_0012ABC0(s32, s32);
    extern s32 func_0012ABA0(s32, s32, s32);
    extern void func_003D6D50();
    extern void func_003D6E20();
    extern void func_00170160(s32);
    extern void func_003DA410();
    extern void func_0041F860(s32);
    extern void func_00150ED0(s32);
    extern void func_00146C80(s32);
    extern void func_003298B0(s32, s32, s32);
    extern s32 func_001315F0();
    extern s32 func_001316D0();
    extern void func_0041DF20();
    extern void func_0041DF70();
    extern void func_0041EE80();
    u32 k;

    if (func_003299D0() != 0) return;
    k = func_0012ABC0(3, 0) & 0xFFFF;
    switch (D_004C2840->b3) {
    case 0:
        func_003D6D50();
        func_003D6E20();
        func_00170160(0x13);
        func_00170160(0x1D);
        D_004C2840->b4 = 0;
        D_004C2840->b5 = 0;
    case 1:
        D_004C2840->b3 = 2;
        func_003DA410();
        D_004D1788[0] = 0;
        D_004D178C[0] = 0;
        func_0041F860(0);
        D_004D17C9[0] = 0xFF;
        func_00150ED0(0);
        func_00146C80(8);
        func_003298B0(0xFF000000, 10, 0);
        break;
    case 2:
        if (func_003299D0() != 0) return;
        D_004C2840->b3++;
        break;
    case 3:
        D_004C2840->b4 = func_0012ABA0(k, D_004C2840->b4, 2);
        if (func_001315F0() != 0) {
            if (D_004C2840->b4 == 2) {
                D_004C2840->b3 = 6;
                func_003298B0(0xFF000000, 10, 1);
                return;
            }
            D_004C2840->b3 = 4;
            func_003298B0(0xFF000000, 10, 1);
            return;
        }
        if (func_001316D0() == 0) return;
        D_004C2840->b3 = 6;
        func_003298B0(0xFF000000, 10, 1);
        break;
    case 4:
        func_0041DF20();
        if (func_003299D0() != 0) return;
        D_004C2840->b3++;
        break;
    case 5:
        switch (D_004C2840->b4) {
        case 0:
            func_0041DF70();
            break;
        case 1:
            func_0041EE80();
            break;
        default:
            D_004C2840->b3++;
            func_003298B0(0xFF000000, 10, 1);
            break;
        }
        break;
    case 6:
        if (func_003299D0() == 0) goto L;
        break;
    }
    return;
L:
    D_004C2840->b2 = 0;
    D_004C2840->b1 = 0;
    func_0041DB80();
}
