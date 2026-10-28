typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 f0, f1, f2, f3, f4; s8 f5; s8 f6; s8 f7; u8 f8, f9; s16 fA; } G_c;
typedef struct { s32 a, b, c; } T_c;
extern G_c *D_004C2840;
extern s32 D_004D17CC[];
extern u8 D_004D17C9[];
extern u8 D_004D17CA[];
extern u8 D_004D17C2[];
extern u8 D_004D17C0[];
extern s8 D_004D179B[];
extern s32 D_004D1788[];
extern s32 D_004D17A4[];
extern s32 D_006336E8[];
extern T_c D_00633670[];

void func_0041E290(u16 input)
{
    extern void func_0041DF20();
    extern void func_00151640();
    extern u8 func_0012AA90(u16, u8, s32);
    extern s32 func_001315F0();
    extern s32 func_001316D0();
    extern s32 func_00418D70(s32);
    extern s32 func_00419730(s32, s32);
    extern s32 func_001317B0();
    extern void func_0041F860(s32);
    extern void func_001E3CE0(s32);
    extern s32 func_0038B2E0(s32, s32, s32);
    extern void func_003298B0(s32, s32, s32);
    extern s32 func_003299D0();
    s32 idx;
    s32 t;
    s32 r;

    switch (D_004C2840->f6) {
    case 0:
        switch (D_004C2840->f7) {
        case 0:
            func_0041DF20();
            idx = D_004D17CC[0];
            if (D_006336E8[idx] == 0) return;
            if (D_00633670[idx].a != 2) goto abort;
            if (D_00633670[idx].c == 0) {
                D_004D17C9[0] = 4;
                D_004D17CA[0] = 1;
                func_00151640();
                D_004C2840->f7++;
            } else {
                D_004C2840->f7 = 100;
            }
            break;
        case 1:
            func_0041DF20();
            idx = D_004D17CC[0];
            if (D_006336E8[idx] != 0) {
                if (D_00633670[idx].a != 2) goto abort;
            }
            D_004D17CA[0] = func_0012AA90(input, D_004D17CA[0], 1);
            if (func_001315F0() != 0) {
                if (D_004D17CA[0] != 0) goto abort;
                D_004D17C9[0] = 5;
                func_00151640();
                D_004C2840->f7 = 2;
            } else {
                if (func_001316D0() != 0) goto abort;
            }
            break;
        case 2:
            if (func_00418D70(0) != 0) return;
            D_004C2840->f7 = 3;
            break;
        case 3:
            D_004D17C2[0] = 1;
            if (func_00419730(D_004D17CC[0], 0) != 0) return;
            D_004C2840->f7 = 4;
            break;
        case 4:
            r = func_00418D70(0);
            if (r == 0) {
                D_004C2840->f6 = 2;
                D_004C2840->f7 = 0;
                D_004D17C9[0] = 8;
                func_00151640();
                break;
            }
            if (r != 1) return;
            D_004D17C9[0] = 6;
            func_00151640();
            D_004C2840->f7 = 5;
            D_004D17C2[0] = 0;
            break;
        case 5:
            func_0041DF20();
            if (func_001317B0() == 0 && D_004D1788[0] != 0) return;
            if (D_004D17A4[0] != D_004D17CC[0]) goto abort;
            if (D_004D179B[0] != 1) goto abort;
            D_004D179B[0] = 0;
            D_004D17C9[0] = 0x1A;
            func_00151640();
            D_004C2840->f7 = 6;
            break;
        case 6:
            func_0041DF20();
            if (D_004D1788[0] == 0) {
                if (D_004D17C9[0] == 0x19) goto abort;
                D_004D17C9[0] = 0x19;
                func_00151640();
                goto abort;
            }
            if (func_001317B0() != 0) goto abort;
            break;
        case 100:
            func_0041DF20();
            idx = D_004D17CC[0];
            t = D_006336E8[idx];
            if (t == 0) return;
            if (D_00633670[idx].a != 2) goto abort;
            if (t == 4) {
                D_004C2840->f6 = 1;
                D_004C2840->f7 = 0;
                D_004D17C9[0] = 0xB;
                D_004D17CA[0] = 1;
                func_00151640();
            } else {
                D_004C2840->f6 = 2;
                D_004C2840->f7 = 0;
            }
            break;
        default:
            for (;;) {
            }
        }
        break;
    case 1:
        func_0041DF20();
        idx = D_004D17CC[0];
        if (D_006336E8[idx] != 0) {
            if (D_00633670[idx].a != 2) goto abort;
        }
        switch (D_004C2840->f7) {
        case 0:
            D_004D17CA[0] = func_0012AA90(input, D_004D17CA[0], 1);
            if (func_001315F0() != 0) {
                if (D_004D17CA[0] == 0) {
                    D_004C2840->f7 = 1;
                } else {
                    D_004C2840->f7 = 2;
                }
                break;
            }
            if (func_001316D0() == 0) return;
            D_004C2840->f7 = 2;
            break;
        case 1:
            if (D_004D17CA[0] != 0) return;
            D_004D17C0[0] = 0;
            D_004C2840->f6 = 4;
            D_004C2840->f7 = 0;
            D_004D17C9[0] = 8;
            func_00151640();
            break;
        case 2:
            goto abort;
        default:
            for (;;) {
            }
        }
        break;
    case 2:
        if (D_004C2840->f7 == 0) {
            if (func_00418D70(0) != 0) return;
            func_0041F860(0);
            D_004C2840->f7++;
        }
        func_0041DF20();
        idx = D_004D17CC[0];
        t = D_006336E8[idx];
        if (t == 0) return;
        if (t == -1) return;
        if (D_00633670[idx].b >= 0x3A) {
            D_004C2840->f6 = 9;
            D_004C2840->f7 = 0;
            D_004D17C0[0] = 0;
        } else {
            D_004C2840->f6 = 3;
            D_004C2840->f7 = 0;
            D_004D17C9[0] = 3;
            D_004D17CA[0] = 0x3A;
            func_00151640();
        }
        break;
    case 3:
        func_0041DF20();
        if (D_004D1788[0] == 0) {
            if (D_004D17C9[0] == 0x19) goto abort;
            D_004D17C9[0] = 0x19;
            func_00151640();
            goto abort;
        }
        if (func_001317B0() == 0) return;
        func_001E3CE0(3);
        goto abort;
    case 4:
        D_004D17C2[0] = 1;
        r = func_0038B2E0(1, D_004D17CC[0], 0);
        if (r == -1) return;
        if (r == 0) {
            D_004C2840->f6 = 6;
            D_004C2840->f7 = 0;
            D_004D17C9[0] = 0xA;
            D_004D17CA[0] = D_004D17CC[0];
        } else {
            D_004C2840->f6 = 7;
            if (D_004D17A4[0] == D_004D17CC[0] && D_004D179B[0] == 1) {
                D_004C2840->f7 = 0;
            } else {
                D_004C2840->f7 = 1;
            }
            D_004D17C9[0] = 0xC;
        }
        func_00151640();
        break;
    case 5:
    case 6:
        func_0041DF20();
        switch (D_004C2840->f7) {
        case 0:
            if (D_004D1788[0] == 0) {
                if (D_004D17C9[0] != 0x19) {
                    D_004D17C9[0] = 0x19;
                    func_00151640();
                }
                D_004D17C2[0] = 0;
                D_004D179B[0] = 1;
                D_004D17A4[0] = D_004D17CC[0];
                D_004C2840->f6 = 8;
                func_003298B0(0xFF000000, 10, 1);
            }
            if (func_001317B0() == 0) return;
            D_004D17C2[0] = 0;
            D_004D179B[0] = 1;
            D_004D17A4[0] = D_004D17CC[0];
            D_004C2840->f6 = 8;
            func_003298B0(0xFF000000, 10, 1);
            break;
        case 1:
            return;
        case 2:
            if (D_004D1788[0] == 0) {
                if (D_004D17C9[0] != 0x19) {
                    D_004D17C9[0] = 0x19;
                    func_00151640();
                }
                func_001E3CE0(3);
                D_004C2840->f6 = 8;
                D_004D17C2[0] = 0;
                func_003298B0(0xFF000000, 10, 1);
            }
            if (func_001317B0() == 0) return;
            func_001E3CE0(3);
            D_004C2840->f6 = 8;
            D_004D17C2[0] = 0;
            func_003298B0(0xFF000000, 10, 1);
            break;
        }
        break;
    case 7:
        func_0041DF20();
        switch (D_004C2840->f7) {
        case 0:
            if (D_004D1788[0] == 0) {
                func_001E3CE0(3);
                D_004D179B[0] = 0;
                D_004D17C9[0] = 0x1A;
                D_004D17C2[0] = 0;
                func_00151640();
                D_004C2840->f7++;
                break;
            }
            if (func_001317B0() == 0) return;
            func_001E3CE0(3);
            D_004D179B[0] = 0;
            D_004D17C9[0] = 0x1A;
            D_004D17C2[0] = 0;
            func_00151640();
            D_004C2840->f7++;
            break;
        case 1:
            if (D_004D1788[0] == 0) {
                if (D_004D17C9[0] != 0x19) {
                    D_004D17C9[0] = 0x19;
                    func_00151640();
                }
                D_004D17C2[0] = 0;
                goto abort;
            }
            if (func_001317B0() == 0) return;
            func_001E3CE0(3);
            D_004D17C2[0] = 0;
            goto abort;
        }
        break;
    case 8:
        if (func_003299D0() != 0) return;
        D_004C2840->f3 = 1;
        D_004C2840->f5 = 0;
        D_004C2840->f6 = 0;
        D_004C2840->f7 = 0;
        D_004D17C9[0] = 0;
        break;
    case 9:
        D_004D17C2[0] = 1;
        r = func_0038B2E0(1, D_004D17CC[0], 1);
        if (r == -1) return;
        if (r == 0) {
            D_004C2840->f6 = 6;
            D_004C2840->f7 = 0;
            D_004D17C9[0] = 0xA;
            D_004D17CA[0] = D_004D17CC[0];
        } else {
            D_004C2840->f6 = 7;
            if (D_004D17A4[0] == D_004D17CC[0] && D_004D179B[0] == 1) {
                D_004C2840->f7 = 0;
            } else {
                D_004C2840->f7 = 1;
            }
            D_004D17C9[0] = 0xC;
        }
        func_00151640();
        break;
    }
    return;
abort:
    D_004C2840->f5 = 1;
    D_004C2840->f6 = 0;
    D_004C2840->f7 = 0;
    D_004C2840->fA = 0;
    D_004D1788[0] &= ~(1 << D_004D17CC[0]);
}
