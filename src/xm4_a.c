typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 f0, f1, f2, f3, f4; s8 f5; u8 f6, f7; } G_a;
extern G_a *D_004C2840;
extern s32 D_004D17CC[];
extern u8 D_004D17C9[];
extern s32 D_004D1788[];
extern s32 D_004C2B78;
extern s32 D_004C2B7C;
extern s32 D_006336F0[];

void func_0041DF70(u8 *p)
{
    extern void func_0041DF20();
    extern void func_00418CC0();
    extern void func_003DA410();
    extern void func_00150ED0();
    extern void func_00146C80(s32);
    extern void func_003298B0(s32, s32, s32);
    extern void func_0041F860(s32);
    extern s32 func_003299D0();
    extern void func_00131540();
    extern s32 func_0041DE10();
    extern void func_00151640();
    extern void func_00131550(u8 *);
    extern s32 func_001315F0();
    extern s32 func_001316D0();
    extern void func_0041E290(u8 *);

    if (D_004C2840->f5 != 4 && D_004C2840->f5 != 0) func_0041DF20();
    switch (D_004C2840->f5) {
    case 0:
        func_00418CC0();
        func_003DA410();
        D_004C2840->f5 = 1;
        D_004D17CC[0] = -1;
        func_00150ED0();
        func_00146C80(8);
        func_003298B0(0xFF000000, 10, 0);
        func_0041F860(0);
        D_004D17C9[0] = 0xFF;
        break;
    case 1:
        if (func_003299D0() != 0) return;
        D_004C2840->f5 = D_004C2840->f5 + 1;
        break;
    case 2:
        func_00131540();
        if (func_0041DE10() != 0) {
            D_004C2840->f5 = D_004C2840->f5 + 1;
            D_004D17C9[0] = 7;
            func_00151640();
        } else {
            D_004C2840->f5 = 5;
            D_004C2840->f6 = 0;
            D_004D17CC[0] = -1;
        }
        break;
    case 3:
        if (D_004D1788[0] == 0) {
            D_004C2840->f5 = 5;
            D_004C2840->f6 = 0;
            D_004D17CC[0] = -1;
            break;
        }
        func_00131550(p);
        if (func_001315F0() != 0) {
            D_004C2840->f5 = 4;
            D_004C2840->f6 = 0;
            D_004C2840->f7 = 0;
            D_004D17C9[0] = 8;
            func_00151640();
        } else {
            if (func_001316D0() == 0) return;
            D_004C2840->f5 = 6;
            func_003298B0(0xFF000000, 10, 1);
        }
        break;
    case 4:
        func_0041E290(p);
        break;
    case 5:
        if (D_004D1788[0] != 0) {
            D_004D17C9[0] = 7;
            D_004C2840->f5 = 2;
            D_004C2840->f6 = 0;
            func_00151640();
        } else {
            if ((D_004C2B78 != -1 && D_004C2B7C != -1) || D_006336F0[0] != 0) {
                if (D_004D17C9[0] != 0x19) {
                    D_004D17C9[0] = 0x19;
                    func_00151640();
                }
            }
        }
        if (func_001316D0() == 0) return;
        D_004C2840->f5 = 6;
        func_003298B0(0xFF000000, 10, 1);
        break;
    case 6:
        if (func_003299D0() == 0) goto L6;
        break;
    }
    return;
L6:
        D_004C2840->f3 = 1;
        D_004C2840->f5 = 0;
        D_004C2840->f6 = 0;
        D_004C2840->f7 = 0;
        D_004D17C9[0] = 0;
}
