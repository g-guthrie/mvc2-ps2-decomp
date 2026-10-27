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
    u8 pad4[4];
    s16 h8;
    u8 padA[0x4C - 0xA];
    s8 b4C;
    u8 pad4D[0x59 - 0x4D];
    s8 b59;
    u8 pad5A[0x88 - 0x5A];
    s8 b88;
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
typedef struct { u32 w[0x5B8 / 4]; } B5;
extern B5 D_004F259C[];
extern B5 D_004F2598[];

void func_00130820(void)
{
    extern u32 func_0012ABC0(s32, s32);
    extern void func_0016CDA0();
    extern void func_0016D160();
    extern void func_003D6D50();
    extern void func_003D6E20();
    extern void func_00170160(int);
    extern void func_003DA410();
    extern void func_00149820(s32);
    extern void func_00149AE0();
    extern void func_0041F860(s32);
    extern void func_00146C80(s32);
    extern void func_003298B0(u32, s32, s32);
    extern s32 func_00418D70(s32);
    extern s32 func_003299D0();
    extern void func_0041DF20();
    extern void func_00151640();
    extern s32 func_001315F0();
    extern s32 func_0012AA90(s32, s32, s32);
    extern s32 func_00419730(s32, s32);
    extern s32 func_001317B0();
    extern s32 func_0038B2E0(s32, s32, s32);
    extern s32 func_001316D0();
    extern void func_001318E0(u32 *, u32, u32);
    extern u32 func_00131980();
    extern void func_00131960(u32);
    extern void func_00131390();
    extern void func_00131470();
    extern void func_0012E6B0();
    GC *g;
    s8 *pb;
    u32 s0;
    s32 x;
    s32 y;
    s32 h;
    s32 r;
    s32 t;
    u32 buf[1];

    s0 = func_0012ABC0(3, 0) & 0xFFFF;
    g = D_004C2840;
    pb = &g->b2;
    switch (*pb) {
    case 0:
        *pb = *pb + 1;
        D_004C2840->b3 = 0;
        func_0016CDA0();
        func_0016D160();
        func_003D6D50();
        func_003D6E20();
        func_00170160(0x10);
        func_00170160(0x1C);
        func_003DA410();
        D_004C2840->h8 = 0x78;
        D_004D1793[0] = 0;
        D_004D1792[0] = 0;
        D_004D1795[0] = 0;
        D_004D1794[0] = 0;
        D_004D17C0[0] = 0;
        if (D_004D17B8[0] != 0 && D_004D17BC[0] != 0) {
            D_004D17CA[0] = 1;
            func_00149820(D_004D17CA[0]);
            D_004D17C9[0] = 3;
            func_00149AE0();
        } else if (D_004D17B8[0] != 0) {
            D_004D17CA[0] = 1;
            func_00149820(D_004D17CA[0]);
            D_004D17C9[0] = 1;
            func_00149AE0();
        } else if (D_004D17BC[0] != 0) {
            D_004D17CA[0] = 1;
            func_00149820(D_004D17CA[0]);
            D_004D17C9[0] = 2;
            func_00149AE0();
        } else if (D_004D179B[0] == 1) {
            D_004C2840->h8 = 1;
        } else {
            goto reset;
        }
        D_004D17CC[0] = D_004D17A4[0];
        func_0041F860(0);
        func_00146C80(9);
        func_003298B0(0xFF000000, 0xA, 0);
        break;
    case 1:
        if (g->b4C != 5) {
            if (func_00418D70(0) != 0) return;
        }
        if (func_003299D0() != 0) return;
        D_004C2840->b2 = 0xC;
        break;
    case 2:
        func_0041DF20();
        x = D_006336E8[D_004D17CC[0]];
        if (x == 0) return;
        if (x == -1) return;
        if (x == 1) {
            D_004C2840->b2 = 3;
            D_004C2840->b3 = 0;
        } else if (x == 2) {
            D_004C2840->b2 = 4;
            D_004C2840->b3 = 0;
        } else if (x == 4) {
            D_004C2840->b2 = 5;
            D_004C2840->b3 = 0;
        } else if (x == 3) {
            D_004C2840->b2 = 8;
            D_004C2840->b3 = 0;
        } else if (x == 5) {
            D_004C2840->b2 = 7;
            D_004C2840->b3 = 0;
        } else {
            return;
        }
        break;
    case 3:
        switch (g->b3) {
        case 0:
            D_004D17C9[0] = 0x24;
            func_00151640();
            D_004C2840->b3 = D_004C2840->b3 + 1;
            break;
        case 1:
            if (func_001315F0() == 0) return;
            D_004C2840->b2 = 9;
            D_004C2840->b3 = 0;
            break;
        }
        break;
    case 4:
        if (g->b3 == 0 || g->b3 == 1) {
            func_0041DF20();
            y = D_004D17CC[0];
            if (D_006336E8[y] != 0) {
                if (D_00633670[y * 3] != 2) {
                    D_004C2840->b2 = 3;
                    D_004C2840->b3 = 0;
                    break;
                }
            }
        }
        switch (D_004C2840->b3) {
        case 0:
            if (D_004D17C9[0] != 0x23) {
                D_004D17C9[0] = 0x23;
                D_004D17CA[0] = 1;
                func_00151640();
            }
            D_004C2840->b3 = D_004C2840->b3 + 1;
            break;
        case 1:
            D_004D17CA[0] = func_0012AA90(s0, D_004D17CA[0], 1);
            if (func_001315F0() == 0) return;
            if (D_004D17CA[0] != 0) {
                D_004C2840->b2 = 9;
                D_004C2840->b3 = 0;
            } else {
                D_004D17C9[0] = 0x25;
                func_00151640();
                D_004C2840->b3 = 2;
            }
            break;
        case 2:
            if (func_00418D70(0) != 0) return;
            D_004C2840->b3 = 3;
            break;
        case 3:
            D_004D17C2[0] = 1;
            if (func_00419730(D_004D17CC[0], 0) != 0) return;
            D_004C2840->b3 = 4;
            break;
        case 4:
            r = func_00418D70(0);
            if (r == 0) {
                D_004C2840->b2 = 8;
                D_004C2840->b3 = 0;
                D_004D17C9[0] = 0xD;
                func_00151640();
                D_004D17C2[0] = 0;
            } else if (r == 1) {
                D_004D17C9[0] = 0x26;
                func_00151640();
                D_004C2840->b3 = 5;
                D_004D17C2[0] = 0;
            } else {
                return;
            }
            break;
        case 5:
            if (func_001317B0() == 0) return;
            D_004C2840->b2 = 9;
            D_004C2840->b3 = 0;
            break;
        }
        break;
    case 5:
        switch (g->b3) {
        case 0:
            D_004D17C2[0] = 1;
            r = func_0038B2E0(1, D_004D17CC[0], 0);
            if (r == -1) return;
            D_004D17C2[0] = 0;
            if (r == 0) {
                D_004D17C9[0] = 0x27;
                D_004C2840->b2 = 0xB;
            } else {
                D_004D17C9[0] = 0x28;
                D_004C2840->b3 = 0xA;
            }
            func_00151640();
            break;
        case 10:
            if (func_001315F0() == 0) return;
            D_004C2840->b2 = 9;
            D_004C2840->b3 = 0;
            break;
        }
        break;
    case 6:
        switch (g->b3) {
        case 0:
            D_004D17C9[0] = 0x29;
            func_00151640();
            D_004C2840->b3 = D_004C2840->b3 + 1;
            break;
        case 1:
            if (func_001315F0() == 0) return;
            D_004C2840->b2 = 9;
            D_004C2840->b3 = 0;
            break;
        }
        break;
    case 7:
        switch (g->b3) {
        case 0:
            D_004D17C9[0] = 0x2A;
            func_00151640();
            D_004C2840->b3 = D_004C2840->b3 + 1;
            break;
        case 1:
            if (func_001315F0() == 0) return;
            D_004C2840->b2 = 9;
            D_004C2840->b3 = 0;
            break;
        }
        break;
    case 8:
        switch (g->b3) {
        case 0:
            D_004D17C2[0] = 1;
            r = func_0038B2E0(1, D_004D17CC[0], 1);
            if (r == -1) return;
            D_004D17C2[0] = 0;
            if (r == 0) {
                D_004D17C9[0] = 0x27;
                D_004C2840->b2 = 0xB;
            } else {
                D_004D17C9[0] = 0x28;
                D_004C2840->b3 = 0xA;
            }
            func_00151640();
            break;
        case 10:
            if (func_001315F0() == 0) return;
            D_004C2840->b2 = 9;
            D_004C2840->b3 = 0;
            break;
        }
        break;
    case 9:
        switch (g->b3) {
        case 0:
            D_004D17C9[0] = 0x20;
            func_00151640();
            D_004C2840->b3 = D_004C2840->b3 + 1;
            break;
        case 1:
            if (func_001315F0() == 0) return;
            g = D_004C2840;
            D_004D179B[0] = 0;
            g->b2 = 0xA;
            func_003298B0(0xFF000000, 0xA, 1);
            break;
        }
        break;
    case 10:
        if (func_003299D0() == 0) goto reset;
        return;
    case 11:
        if (func_001315F0() == 0) return;
        g = D_004C2840;
        g->b2 = 0xA;
        func_003298B0(0xFF000000, 0xA, 1);
        break;
    case 12:
        if (func_001316D0() != 0) {
            D_004C2840->h8 = 1;
        }
        g = D_004C2840;
        h = g->h8;
        g->h8 = h - 1;
        if (h != 0) return;
        g = D_004C2840;
        if (g->b59 == 7) {
            t = (g->b88 != 0) ? 1 : 0;
            func_001318E0(buf, D_004F259C[t].w[0], D_004F2598[t].w[0]);
            if (func_00131980() < buf[0]) {
                func_00131960(buf[0]);
            }
        }
        if (D_004D17B8[0] != 0) func_00131390();
        if (D_004D17BC[0] != 0) func_00131470();
        if (D_004D179B[0] == 1 && D_004C2840->b4C != 5) {
            g = D_004C2840;
            g->b2 = 2;
            D_004D17CA[0] = 2;
            func_00149820(D_004D17CA[0]);
            D_004D17C9[0] = 0xD;
            func_00151640();
        } else {
            D_004C2840->b2 = 0xA;
            func_003298B0(0xFF000000, 0xA, 1);
        }
        break;
    }
    return;
reset:
    func_0012E6B0();
    D_004C2840->b1 = 0;
    D_004C2840->b2 = 0;
    D_004C2840->b3 = 0;
    D_004C2840->b59 = -1;
}
