typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 b0, b1, b2, b3, b4; s8 state; u8 b6, b7; } GE;

extern GE *D_004C2840;
extern s32 D_004C2B78;
extern s32 D_004C2B7C;
extern s32 D_004D17CC[];
extern s32 D_004D1788[];
extern u8 D_004D17C9[];
extern s32 D_006336F0[];

void func_0041EE80(s32 arg)
{
    extern void func_0041DF20();
    extern void func_00418CC0();
    extern void func_003DA650(s32);
    extern void func_00150ED0(s32);
    extern void func_00146C80(s32);
    extern void func_003298B0(u32, s32, s32);
    extern void func_0041F860(s32);
    extern s32 func_003299D0();
    extern void func_00131550(s32);
    extern s32 func_001315F0();
    extern void func_00151640();
    extern s32 func_001316D0();
    extern void func_0041F190(s32);
    extern void func_00131540();
    extern s32 func_0041DE10();
    s32 st;
    st = D_004C2840->state;
    if (st != 3 && st != 0) {
        func_0041DF20();
    }
    switch (D_004C2840->state) {
    case 0:
        func_00418CC0();
        D_004C2840->state++;
        D_004D17CC[0] = -1;
        func_003DA650(0xD);
        func_00150ED0(1);
        func_00146C80(8);
        func_003298B0(0xFF000000, 10, 0);
        func_0041F860(0);
        break;
    case 1:
        if (func_003299D0() == 0) {
            D_004C2840->state = 0x14;
        }
        break;
    case 2:
        if (D_004D1788[0] == 0) {
            D_004C2840->state = 4;
            D_004C2840->b6 = 0;
            D_004D17CC[0] = -1;
        } else {
            func_00131550(arg);
            if (func_001315F0() != 0) {
                D_004C2840->state = 3;
                D_004C2840->b6 = 0;
                D_004C2840->b7 = 0;
                D_004D17C9[0] = 0x1B;
                func_00151640();
            } else if (func_001316D0() != 0) {
                D_004C2840->state = 5;
                func_003298B0(0xFF000000, 10, 1);
            }
        }
        break;
    case 3:
        func_0041F190(arg);
        break;
    case 4:
        if (D_004D1788[0] != 0) {
            D_004C2840->state = 0x14;
            D_004C2840->b6 = 0;
            D_004D17C9[0] = 0xE;
            func_00151640();
        } else {
            if ((D_004C2B78 != -1 && D_004C2B7C != -1) || D_006336F0[0] != 0) {
                if (D_004D17C9[0] != 0x19) {
                    D_004D17C9[0] = 0x19;
                    func_00151640();
                }
            }
        }
        if (func_001316D0() != 0) {
            D_004C2840->state = 5;
            func_003298B0(0xFF000000, 10, 1);
        }
        break;
    case 5:
        if (func_003299D0() == 0) {
            D_004C2840->b3 = 1;
            D_004C2840->state = 0;
            D_004C2840->b6 = 0;
            D_004C2840->b7 = 0;
        }
        break;
    case 0x14:
        func_00131540();
        if (func_0041DE10() != 0) {
            D_004C2840->state = 2;
            D_004D17C9[0] = 0xE;
            func_00151640();
        } else {
            D_004C2840->state = 4;
            D_004C2840->b6 = 0;
            D_004D17CC[0] = -1;
        }
        break;
    }
}
