/* func_00130040: state machine on D_004C2840->b2. MW 3.0, -O3 -sdatathreshold 8; needs objcopy --redefine-sym @N=jtbl_004B10A0.
   func_0012FFD0(s32) receives the current state, which keeps it in a0 across the jump-table dispatch. */
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
    u8 pad6[2];
    s16 h8;
} GB240;

extern GB240 *D_004C2840;
extern s32 D_004C2620[2];
extern u8 D_004D1792[];
extern u8 D_004D17CB[];
extern u8 D_004D179B[];
extern u8 D_004D17C9[];
extern u8 D_004D17CA[];
extern u32 D_004D17CC[];
extern u32 D_004D17A4[];

void func_00130040(void)
{
    extern u32 func_0012ABC0(s32, s32);
    extern void func_003D6D50();
    extern void func_003D6E20();
    extern void func_00170160(s32);
    extern void func_003DA410();
    extern void func_00131290();
    extern void func_001517C0(s32, s32);
    extern void func_00151640();
    extern void func_0041F860(s32);
    extern void func_003298B0(u32, s32, s32);
    extern s32 func_003299D0();
    extern s32 func_0012FD70();
    extern s32 func_00418D70(s32);
    extern s32 func_0038C750(u32, s32);
    extern void func_0038A900(u32);
    extern s32 func_001315F0();
    extern s32 func_001317B0();
    extern s32 func_0012AA90(s32, s32, s32);
    extern void func_00418CC0();
    extern void func_001E3CE0(s32);
    extern void func_0012FC40();
    extern s32 func_0012FFD0(s32);
    GB240 *g;
    s8 *pb;
    u32 s0;
    s32 v;
    s32 t;
    s32 r;

    s0 = func_0012ABC0(3, 0) & 0xFFFF;
    g = D_004C2840;
    pb = &g->b2;
    switch (*pb) {
    case 0:
        *pb = *pb + 1;
        D_004C2840->b3 = 0;
        D_004C2840->h8 = 0x3C;
        func_003D6D50();
        func_003D6E20();
        func_00170160(0x14);
        func_003DA410();
        func_00131290();
        D_004D1792[0] = 0;
        D_004D17CB[0] = 0;
        D_004D179B[0] = 0;
        func_001517C0(0, 0);
        D_004D17C9[0] = 0x1D;
        func_00151640();
        D_004C2620[1] = -1;
        D_004C2620[0] = -1;
        func_0041F860(0);
        func_003298B0(0xFF000000, 0xA, 0);
    case 1:
        if (func_003299D0() != 0) break;
        v = func_0012FD70();
        if (D_004C2620[0] == -1) break;
        if (D_004C2620[1] == -1) break;
        t = D_004C2840->h8;
        D_004C2840->h8 = t - 1;
        if (t == 0) {
            D_004C2840->b2 = v;
            break;
        }
        if (v != 5) {
            D_004C2840->b2 = v;
        }
        break;
    case 2:
        switch (g->b3) {
        case 0:
            if (func_00418D70(0) != 0) break;
            D_004C2840->b3 = D_004C2840->b3 + 1;
        case 1:
            r = func_0038C750(D_004D17CC[0], 1);
            if (r == 1) {
                D_004C2840->b3 = D_004C2840->b3 + 1;
                D_004C2840->b4 = 0;
                D_004C2840->h8 = 0xB4;
                D_004D179B[0] = 1;
                D_004D17C9[0] = 0x13;
                D_004D17A4[0] = D_004D17CC[0];
                func_00151640();
                func_0038A900(D_004D17A4[0]);
                break;
            }
            if (r != 0) break;
            D_004C2840->b3 = 3;
            D_004C2840->b4 = 0;
            D_004C2840->h8 = 0;
            D_004D17C9[0] = 0x2B;
            D_004D179B[0] = 0;
            func_00151640();
            break;
        case 2:
            t = g->h8;
            g->h8 = t - 1;
            if (t != 0) {
                if (func_001315F0() == 0) break;
            }
            D_004C2840->b2 = 6;
            func_003298B0(0xFF000000, 0xA, 1);
            break;
        case 3:
            if (g->b4 == 0) {
                if (func_00418D70(0) != 0) break;
                D_004C2840->b4 = D_004C2840->b4 + 1;
            }
            D_004C2840->b3 = D_004C2840->b3 + 1;
            break;
        case 4:
            if (func_001317B0() == 0) break;
            D_004C2840->b2 = 6;
            func_003298B0(0xFF000000, 0xA, 1);
            break;
        }
        break;
    case 3:
        switch (g->b3) {
        case 0:
            g->h8 = 0;
            D_004C2840->b3 = D_004C2840->b3 + 1;
            if (D_004D17C9[0] != 0x21) {
                D_004D17C9[0] = 0x21;
                func_00151640();
            }
        case 1:
            D_004C2840->h8 = D_004C2840->h8 + 1;
            if (func_001317B0() == 0 && D_004C2840->h8 < 0xB4) break;
            D_004D179B[0] = 0;
            D_004C2840->b2 = 6;
            func_003298B0(0xFF000000, 0xA, 1);
            break;
        }
        break;
    case 5:
        switch (g->b3) {
        case 0:
            D_004D17CA[0] = 1;
            if (D_004D17C9[0] != 0x18) {
                D_004D17C9[0] = 0x18;
                func_00151640();
            }
            D_004C2840->b3 = D_004C2840->b3 + 1;
        case 1:
            D_004D17CA[0] = func_0012AA90(s0, D_004D17CA[0], 1);
            if (func_001315F0() == 0) break;
            if (D_004D17CA[0] != 0) {
                D_004C2840->b2 = 1;
                D_004C2840->b4 = 0;
                D_004C2840->b3 = 0;
                D_004C2840->h8 = 0x3C;
                D_004D17C9[0] = 0x1D;
                D_004C2620[1] = -1;
                D_004C2620[0] = -1;
                func_0041F860(0);
                func_00418CC0();
                func_00151640();
                break;
            }
            D_004D17CA[0] = 0xFF;
            func_001E3CE0(2);
            D_004D179B[0] = 0;
            D_004C2840->b2 = 6;
            func_003298B0(0xFF000000, 0xA, 1);
            break;
        }
        break;
    case 6:
        if (func_003299D0() != 0) break;
        D_004C2840->b1 = D_004C2840->b1 + 1;
        D_004C2840->b2 = 0;
        D_004C2840->b3 = 0;
        D_004C2840->b4 = 0;
        D_004C2840->b5 = 0;
        if (D_004D17CB[0] != 0) {
            D_004D17CB[0] = 0;
            func_0012FC40();
        }
        break;
    case 9:
        switch (g->b3) {
        case 0:
            if (D_004D17C9[0] != 0x20) {
                D_004D17C9[0] = 0x20;
                func_00151640();
            }
            D_004C2840->h8 = 0xB4;
            D_004C2840->b3 = D_004C2840->b3 + 1;
            break;
        case 1:
            g->h8 = g->h8 - 1;
            if (D_004C2840->h8 != 0) {
                if (func_001317B0() == 0) break;
            }
            D_004D179B[0] = 0;
            D_004C2840->b2 = 6;
            func_003298B0(0xFF000000, 0xA, 1);
            break;
        }
        break;
    case 10:
        if (func_0012FFD0(*pb) != 0) break;
        if (D_004D17C9[0] != 0x2F) {
            D_004D17C9[0] = 0x2F;
            func_00151640();
        }
        break;
    case 11:
        switch (g->b3) {
        case 0:
            if (D_004D17C9[0] != 0x21) {
                D_004D17C9[0] = 0x21;
                func_00151640();
            }
            D_004C2840->h8 = 0;
            D_004C2840->b3 = D_004C2840->b3 + 1;
            break;
        case 1:
            g->h8 = g->h8 + 1;
            if (func_001315F0() == 0 && D_004C2840->h8 < 0xB4) break;
            D_004C2840->b3 = D_004C2840->b3 + 1;
            D_004D17C9[0] = 0x30;
            D_004D17CA[0] = 1;
            func_00151640();
            break;
        case 2:
            D_004D17CA[0] = func_0012AA90(s0, D_004D17CA[0], 1);
            if (func_001315F0() == 0) break;
            if (D_004D17CA[0] != 0) {
                D_004C2840->b2 = 1;
                D_004C2840->b4 = 0;
                D_004C2840->b3 = 0;
                D_004C2840->h8 = 0x3C;
                D_004D17C9[0] = 0x1D;
                D_004C2620[1] = -1;
                D_004C2620[0] = -1;
                func_0041F860(0);
                func_00418CC0();
                func_00151640();
                break;
            }
            D_004D17CA[0] = 0xFF;
            func_001E3CE0(2);
            D_004D179B[0] = 0;
            D_004C2840->b2 = 6;
            func_003298B0(0xFF000000, 0xA, 1);
            D_004C2840->b3 = 0;
            break;
        }
        break;
    default:
        func_0012FFD0(*pb);
        break;
    }
}
