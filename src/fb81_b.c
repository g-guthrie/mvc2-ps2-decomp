typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

#define E8(i) (*(s32 *)((u32)D_006336E8 + ((u32)(i) << 2)))
typedef struct { s32 a, b, c; } E12;
typedef struct { u16 h[4]; } H8;

extern s32 D_00633694[];
extern s32 D_006336F0[];
extern s32 D_006336F4[];
extern s32 D_006336E8[];
extern s32 D_00633698[];
extern E12 D_00633670[];
extern H8 D_006336FE[];
extern H8 D_006336F8[];
extern H8 D_00633908[];
extern s32 D_004C2B84;
extern u8 D_00584B50[];
extern u8 D_00633900[];

void func_0041F900(void) {
    extern s32 func_00418D70(s32);
    extern s32 func_00419610(s32, s32, u8 *, s32, u8 *);
    extern s32 func_00419310(s32, s32);
    s32 r;
    if (D_00633694[0] == 1) {
        D_006336F0[0] = 0;
        r = func_00418D70(0);
        if (r < 0) return;
        if (r == 0) {
            if (D_00633670[D_006336F4[0]].a != 2) {
                E8(D_006336F4[0]) = 1;
                D_006336FE[D_006336F4[0]].h[0] = 0xFFFF;
                D_006336F4[0] ^= 1;
            } else {
                if (D_00633670[D_006336F4[0]].c == 0) {
                    E8(D_006336F4[0]) = 2;
                    D_006336FE[D_006336F4[0]].h[0] = 0xFFFF;
                    D_006336F4[0] ^= 1;
                } else {
                    if (func_00419610(D_006336F4[0], 0, D_00584B50, 1, D_00633900) != 0) {
                        goto tail;
                    }
                    D_006336F0[0] = 1;
                    return;
                }
            }
tail:
            if (func_00419310(D_006336F4[0], 0) == 0) {
                E8(D_006336F4[0]) = 0;
            }
        } else {
            if (func_00419310(D_006336F4[0], 0) == 0) {
                E8(D_006336F4[0]) = 0;
            }
        }
    } else if (D_00633694[0] == 13) {
        r = func_00418D70(0);
        if (r < 0) return;
        if (r == 0) {
            if (D_00633698[0] > 0) {
                E8(D_006336F4[0]) = 4;
                D_006336F8[D_006336F4[0]] = D_00633908[0];
            } else {
                if (D_00633670[D_006336F4[0]].b >= D_004C2B84) {
                    E8(D_006336F4[0]) = 3;
                } else {
                    E8(D_006336F4[0]) = 5;
                }
                D_006336FE[D_006336F4[0]].h[0] = 0xFFFF;
            }
        } else {
            if (D_00633698[0] < -10) {
                E8(D_006336F4[0]) = 1;
            } else {
                if (D_00633670[D_006336F4[0]].b >= D_004C2B84) {
                    E8(D_006336F4[0]) = 3;
                } else {
                    E8(D_006336F4[0]) = 5;
                }
            }
            D_006336FE[D_006336F4[0]].h[0] = 0xFFFF;
        }
        D_006336F0[0] = 0;
        D_006336F4[0] ^= 1;
        if (func_00419310(D_006336F4[0], 0) == 0) {
            E8(D_006336F4[0]) = 0;
        }
    } else {
        if (func_00419310(D_006336F4[0], 0) == 0) {
            E8(D_006336F4[0]) = 0;
        }
    }
}
