typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    s8 pad0[0x4C];
    s8 b4c;
    s8 pad4d[0x88 - 0x4D];
    s8 b88;
    s8 pad89[0x8F - 0x89];
    s8 b8f;
    s8 b90;
    s8 pad91;
    s8 b92;
    s8 pad93;
    u32 w94;
    s8 pad98[0x9C - 0x98];
    s8 b9c;
    s8 pad9d[0xAA - 0x9D];
    s8 bAA;
} G1;

typedef struct {
    s8 pad0[0x30];
    s8 b30;
    s8 b31;
    u8 b32;
    s8 pad33[0x3B - 0x33];
    s8 b3b;
} G2;

extern G1 *D_004C2840;
extern G2 *D_004C2794;
extern u8 D_004D18A0[];
extern s16 D_004D18B0[];
extern u8 D_004D18A6[];
extern u8 D_004F2294[];
extern u8 D_004F284C[];
extern u8 D_004F230C[];
extern u8 D_004F28C4[];
extern s8 D_004F7F50[];
extern s8 D_004F7F56[];
extern s8 D_004F7F57[];
extern s8 D_004F7F3E[];
extern s16 D_004F7F7C[];
extern s32 D_004F261C[];
extern s32 D_004F2BD4[];

void func_001719E0(void)
{
    extern void func_0016E960(void);
    extern void func_003D7310(void *);
    extern void func_003D33F0(void);
    extern void func_003D69A0(void);
    extern void func_00170FD0(void);
    extern void func_00131340(s32);
    extern void func_003D9080(void);
    extern void func_001E8CD0(void);
    extern void func_001E76D0(void);
    extern void func_003D8080(void);
    extern void func_0016D070(void);
    extern void func_003DAC00(void);
    extern void func_00326AF0(void);
    extern void func_003DA9D0(s32);
    extern void func_003D68B0(void *);
    extern void func_001529A0(void);
    extern void func_00152660(void);
    extern void func_001528B0(void);
    s8 *q;
    s32 *w;
    s32 t;
    if (D_004C2840->b90 != 0) {
        func_0016E960();
        if (D_004C2840->b92 > 1) {
            func_003D7310(func_00152660);
        } else {
            func_003D7310(func_001529A0);
        }
        return;
    }
    if (D_004D18A0[0] == 4) {
        func_003D33F0();
    }
    if (D_004F7F50[0] != 0) {
        if (D_004C2840->bAA != 0) {
            if (D_004F2294[0] == 0x1D || D_004F284C[0] == 0x1D || (D_004F230C[0] | D_004F28C4[0]) != 0
                || D_004D18A6[0] != 0 || D_004C2840->b9c != 0) {
                func_003D7310(func_001529A0);
                if (D_004F7F56[0] == 1 || D_004F7F57[0] == 1) {
                    if (D_004F7F3E[0] != 0) {
                        func_003D7310(func_001528B0);
                    } else {
                        func_003D7310(func_001529A0);
                    }
                    func_003D69A0();
                    return;
                }
                D_004F7F50[0] = 0;
                D_004F7F56[0] = 0;
                D_004F7F57[0] = 0;
            } else {
                if (D_004F7F3E[0] != 0) {
                    func_003D7310(func_001528B0);
                } else {
                    func_003D7310(func_001529A0);
                }
                func_003D69A0();
                return;
            }
        } else {
            if (D_004F7F3E[0] != 0) {
                func_003D7310(func_001528B0);
            } else {
                func_003D7310(func_001529A0);
            }
            func_003D69A0();
            return;
        }
    }
    if (D_004D18A0[0] == 4 && D_004C2840->b8f == 0) {
        if ((D_004C2840->b88 & 1) != 0) {
            D_004F261C[0] = D_004F261C[0] + 1;
        }
        if ((D_004C2840->b88 & 2) != 0) {
            D_004F2BD4[0] = D_004F2BD4[0] + 1;
        }
    }
    func_00170FD0();
    D_004C2794->b32 = 0;
    if (D_004C2794->b30 != 0) {
        D_004C2794->b31 = D_004C2794->b31 - 1;
    }
    do {
        if (D_004C2840->w94 != -1) {
            D_004C2840->w94 = D_004C2840->w94 + 1;
        }
        if (D_004C2840->b4c == 2) {
            if (D_004C2840->w94 % 0xE10 == 0) {
                func_00131340(10);
            }
        }
        func_003D9080();
        D_004C2794->b3b = (D_004C2794->b3b + 1) & 0xF;
        func_001E8CD0();
        func_001E76D0();
        func_003D8080();
        func_0016D070();
        if (D_004C2794->b30 != 0 && D_004C2794->b31 == 0) {
            D_004C2794->b31 = D_004C2794->b30;
            D_004C2794->b32 = 0xFF;
            continue;
        }
        break;
    } while (1);
    if (D_004D18A0[0] == 4) {
        D_004D18B0[0] = D_004D18B0[0] + 1;
    }
    func_003DAC00();
    func_00326AF0();
    func_003DA9D0(3);
    func_003DA9D0(4);
    func_003DA9D0(1);
    func_003DA9D0(2);
    func_003D7310(func_001529A0);
    if (D_004F7F7C[0] != 0) {
        func_003D68B0(D_004F7F50);
    }
}
