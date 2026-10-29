typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 pad0;
    s8 b1;
    s8 b2;
    s8 b3;
    s8 b4;
    s8 b5;
    s8 b6;
    s8 b7;
    s16 h8;
} GC;

extern GC *D_004C2840;
extern u8 D_004D1793[];
extern u8 D_004D1792[];
extern u8 D_004D1795[];
extern u8 D_004D1794[];
extern u8 D_004D17C0[];
extern u32 D_004D17B8[];
extern u32 D_004D17BC[];
extern u8 D_004D17CA[];
extern u8 D_004D17C9[];
extern u8 D_004D17C2[];
extern u32 D_004D17A4[];
extern u32 D_004D17CC[];
extern s8 D_004D179B[];
extern s32 D_006336E8[];
extern s32 D_00633670[];

extern void (*D_0043CD08[])();
extern void (*D_0043CD0C[])();
extern void *D_004C25FC;

void func_0012ADE0(void)
{
    extern u16 func_0012ABC0(s32, s32);
    extern s32 func_0012ABA0(u16, s32, s32);
    extern void func_003DA410();
    extern void func_00146C80(s32);
    extern void func_00146BF0();
    extern void func_00149820(s32);
    extern void func_0041F860(s32);
    extern void func_003298B0(u32, s32, s32);
    extern s32 func_00418D70(s32);
    extern s32 func_003299D0();
    extern void func_0041DF20();
    extern void func_00151640();
    extern s32 func_001315F0();
    extern s32 func_001316D0();
    extern s32 func_0012AA90(s32, s32, s32);
    extern s32 func_00419730(s32, s32);
    extern s32 func_001317B0();
    extern s32 func_0038B2E0(s32, s32, s32);
    extern void func_00131390();
    extern void func_00131470();
    extern void func_0016CDA0();
    extern void func_0016D160();
    extern void func_003D6D50();
    extern void func_003D6E20();
    extern void func_00170160(int);
    extern void func_001489E0(s32, s32);
    extern void func_0014A3D0();
    extern void func_0014A4E0();
    extern void func_0014A640();
    extern void func_00149FA0();
    extern void func_0012C8E0();
    extern void func_0041C200();
    GC *g;
    s8 *pb;
    u16 buttons;
    u32 wide_buttons;
    s32 x;
    s32 y;
    s32 r;

    r = func_003299D0();
    if (r != 0) return;
    if (r == 0) { buttons = func_0012ABC0(3, 0); wide_buttons = buttons; }
    switch ((g = D_004C2840)->b3) {
    case 0:
        func_003D6D50();
        func_003D6E20();
        func_00170160(0x12);
        func_00170160(0x1B);
        g = D_004C2840;
        g->b3 = g->b3 + 1;
        D_004C2840->b4 = 0;
        D_0043CD08[0] = func_0012C8E0;
        D_004C25FC = 0;
        D_0043CD0C[0] = func_0041C200;
    case 1:
        D_004C2840->b3 = D_004C2840->b3 + 1;
        D_004C2840->b5 = 0;
        D_004C2840->b6 = 0;
        D_004C2840->b7 = 0;
        func_003DA410();
        func_00146C80(4);
        func_001489E0(9, 9);
        func_0014A3D0();
        func_0014A4E0();
        func_0014A640();
        func_00149FA0();
        func_003298B0(0xFF000000, 0xA, 0);
        return;
    case 2:
        if (func_003299D0() != 0) return;
        D_004C2840->b3 = D_004C2840->b3 + 1;
        break;
    case 3:
        D_004C2840->b4 = func_0012ABA0(buttons, g->b4, 3);
        if (func_001315F0() != 0) {
            func_003298B0(0xFF000000, 0xA, 1);
            g = D_004C2840;
            if (g->b4 == 3) g->b3 = g->b3 + 1;
            else g->b3 = 5;
        } else if (func_001316D0() != 0) {
            D_004C2840->b3 = D_004C2840->b3 + 1;
            func_003298B0(0xFF000000, 0xA, 1);
        }
        break;
    case 4:
        if (func_003299D0() != 0) return;
        D_004C2840->b3 = 7;
        D_004C2840->b7 = 0;
        D_004C2840->b6 = 0;
        break;
    case 5:
        if (func_003299D0() != 0) return;
        D_004C2840->b3 = D_004C2840->b3 + 1;
        break;
    case 6:
        D_0043CD08[g->b4](wide_buttons, 0);
        break;
    case 7:
        pb = &g->b6;
        switch (*pb) {
        case 0:
            if (D_004D179B[0] != 1) {
                g->b7 = 0;
                D_004C2840->b6 = 0;
                D_004C2840->b5 = 0;
                D_004C2840->b4 = 0;
                D_004C2840->b3 = 0;
                D_004C2840->b2 = 0;
                D_004C2840->b1 = 0;
                if (D_004D17B8[0] != 0) func_00131390();
                if (D_004D17BC[0] != 0) func_00131470();
            } else {
                D_004D17C0[0] = 0;
                *pb = *pb + 1;
                D_004C2840->b7 = 0;
                func_0016CDA0();
                func_0016D160();
                func_003D6D50();
                func_003D6E20();
                func_00170160(0x10);
                func_00170160(0x1C);
                func_003DA410();
                func_00146C80(9);
                D_004C2840->h8 = 1;
                D_004D17C9[0] = 0xD;
                D_004D1793[0] = 0;
                D_004D1792[0] = 0;
                D_004D1795[0] = 0;
                D_004D1794[0] = 0;
                func_00151640();
                func_00149820(2);
                D_004D17CC[0] = D_004D17A4[0];
                func_0041F860(0);
                func_003298B0(0xFF000000, 0xA, 0);
            }
            break;
        case 1:
            if (func_00418D70(0) != 0) break;
            if (func_003299D0() != 0) break;
            D_004C2840->b6 = D_004C2840->b6 + 1;
            break;
        case 2:
            func_0041DF20();
            x = D_006336E8[D_004D17CC[0]];
            if (x == 1) {
                D_004C2840->b6 = 3;
                D_004C2840->b7 = 0;
            } else if (x == 2) {
                D_004C2840->b6 = 4;
                D_004C2840->b7 = 0;
            } else if (x == 4) {
                D_004C2840->b6 = 5;
                D_004C2840->b7 = 0;
            } else if (x == 3) {
                D_004C2840->b6 = 8;
                D_004C2840->b7 = 0;
            } else if (x == 5) {
                D_004C2840->b6 = 7;
                D_004C2840->b7 = 0;
            } else {
                break;
            }
            break;
        case 3:
            switch (g->b7) {
            case 0:
                D_004D17C9[0] = 0x24;
                func_00151640();
                D_004C2840->b7 = D_004C2840->b7 + 1;
                break;
            case 1:
                if (func_001315F0() == 0) break;
                D_004C2840->b6 = 9;
                D_004C2840->b7 = 0;
                break;
            }
            break;
        case 4:
            if (g->b7 == 0 || g->b7 == 1) {
                func_0041DF20();
                y = D_004D17CC[0];
                if (D_006336E8[y] != 0) {
                    if (D_00633670[y * 3] != 2) {
                        D_004C2840->b6 = 3;
                        D_004C2840->b7 = 0;
                        break;
                    }
                }
            }
            switch (D_004C2840->b7) {
            case 0:
                if (D_004D17C9[0] != 0x23) {
                    D_004D17C9[0] = 0x23;
                    D_004D17CA[0] = 1;
                    func_00151640();
                }
                D_004C2840->b7 = D_004C2840->b7 + 1;
                break;
            case 1:
                D_004D17CA[0] = func_0012AA90(wide_buttons, D_004D17CA[0], 1);
                if (func_001315F0() == 0) break;
                if (D_004D17CA[0] != 0) {
                    D_004C2840->b6 = 9;
                    D_004C2840->b7 = 0;
                } else {
                    D_004D17C9[0] = 0x25;
                    func_00151640();
                    D_004C2840->b7 = 2;
                }
                break;
            case 2:
                if (func_00418D70(0) != 0) break;
                D_004C2840->b7 = 3;
                break;
            case 3:
                D_004D17C2[0] = 1;
                if (func_00419730(D_004D17CC[0], 0) != 0) break;
                D_004C2840->b7 = 4;
                break;
            case 4:
                r = func_00418D70(0);
                if (r == 0) {
                    D_004C2840->b6 = 8;
                    D_004C2840->b7 = 0;
                    D_004D17C9[0] = 0xD;
                    func_00151640();
                    D_004D17C2[0] = 0;
                } else if (r == 1) {
                    D_004D17C9[0] = 0x26;
                    func_00151640();
                    D_004C2840->b7 = 5;
                    D_004D17C2[0] = 0;
                } else {
                    break;
                }
                break;
            case 5:
                if (func_001317B0() == 0) break;
                D_004C2840->b6 = 9;
                D_004C2840->b7 = 0;
                break;
            }
            break;
        case 5:
            switch (g->b7) {
            case 0:
                D_004D17C2[0] = 1;
                r = func_0038B2E0(1, D_004D17CC[0], 0);
                if (r == -1) break;
                D_004D17C2[0] = 0;
                if (r == 0) {
                    D_004D17C9[0] = 0x27;
                    D_004C2840->b6 = 0xB;
                } else {
                    D_004D17C9[0] = 0x28;
                    D_004C2840->b7 = 0xA;
                }
                func_00151640();
                break;
            case 10:
                if (func_001315F0() == 0) break;
                D_004C2840->b6 = 9;
                D_004C2840->b7 = 0;
                break;
            }
            break;
        case 6:
            switch (g->b7) {
            case 0:
                D_004D17C9[0] = 0x29;
                func_00151640();
                D_004C2840->b7 = D_004C2840->b7 + 1;
                break;
            case 1:
                if (func_001315F0() == 0) break;
                D_004C2840->b6 = 9;
                D_004C2840->b7 = 0;
                break;
            }
            break;
        case 7:
            switch (g->b7) {
            case 0:
                D_004D17C9[0] = 0x2A;
                func_00151640();
                D_004C2840->b7 = D_004C2840->b7 + 1;
                break;
            case 1:
                if (func_001315F0() == 0) break;
                D_004C2840->b6 = 9;
                D_004C2840->b7 = 0;
                break;
            }
            break;
        case 8:
            switch (g->b7) {
            case 0:
                D_004D17C2[0] = 1;
                r = func_0038B2E0(1, D_004D17CC[0], 1);
                if (r == -1) break;
                D_004D17C2[0] = 0;
                if (r == 0) {
                    D_004D17C9[0] = 0x27;
                    D_004C2840->b6 = 0xB;
                } else {
                    D_004D17C9[0] = 0x28;
                    D_004C2840->b7 = 0xA;
                }
                func_00151640();
                break;
            case 10:
                if (func_001315F0() == 0) break;
                D_004C2840->b6 = 9;
                D_004C2840->b7 = 0;
                break;
            }
            break;
        case 9:
            switch (g->b7) {
            case 0:
                D_004D17C9[0] = 0x20;
                func_00151640();
                D_004C2840->b7 = D_004C2840->b7 + 1;
                break;
            case 1:
                if (func_001315F0() == 0) break;
                g = D_004C2840;
                D_004D179B[0] = 0;
                g->b6 = 0xA;
                func_003298B0(0xFF000000, 0xA, 1);
                break;
            }
            break;
        case 10:
            if (func_003299D0() != 0) break;
            func_003DA410();
            D_004C2840->b1 = 1;
            D_004C2840->b7 = 0;
            D_004C2840->b6 = 0;
            D_004C2840->b5 = 0;
            D_004C2840->b4 = 0;
            D_004C2840->b3 = 0;
            D_004C2840->b2 = 0;
            func_00146BF0();
            func_00146C80(0);
            func_003298B0(0xFF000000, 0xA, 0);
            break;
        case 11:
            if (func_001315F0() == 0) break;
            g = D_004C2840;
            g->b6 = 0xA;
            func_003298B0(0xFF000000, 0xA, 1);
            break;
        }

    }
}
