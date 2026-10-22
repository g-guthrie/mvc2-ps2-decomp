/* MW 3.0: ./try30.sh src/xm6_a.c "-O3 -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_004D1792[];
extern u8 D_004D1793[];
extern s32 D_00633698[];
extern s32 D_00584AE0;
extern u8 D_00583CC0[];

s32 func_0038C750(s32 a, u8 m)
{
    extern s32 func_00418D70(s32);
    extern void func_0038CE40(s32);
    extern s32 func_00419610(s32, s32, u8 *, s32, u8 *);
    extern s32 func_0038C4A0(s32, s32);
    s32 r;
    u32 t;

    switch (D_004D1792[0]) {
    case 0:
        if (m == 2) {
            D_004D1792[0] = 1;
            break;
        }
        switch (D_004D1793[0]) {
            case 0:
                if (func_00418D70(0) < 0) break;
                t = D_004D1793[0];
                D_004D1793[0] = t + 1;
            case 1:
                func_0038CE40(1);
                if (func_00419610(a, 0, (u8 *)&D_00584AE0, 1, D_00583CC0) < 0) return 0;
                t = D_004D1793[0];
                D_004D1793[0] = t + 1;
                break;
            case 2:
                r = func_00418D70(0);
                switch (r) {
                case 0:
                    if (D_00633698[0] > 0) {
                        D_004D1793[0] = 10;
                        break;
                    }
                    return 0;
                case 1:
                    return 0;
                default:
                    break;
                }
                break;
            case 10:
                r = func_0038C4A0(1, a);
                if (r == -1) break;
                if (r == 0) {
                    if (m != 1) {
                        D_004D1792[0] = 1;
                        D_004D1793[0] = 0;
                        break;
                    }
                    return 1;
                } else {
                    D_004D1793[0] = 0;
                    D_004D1792[0] = 0;
                    return 0;
                }
                break;
            }
        break;
    case 1:
        switch (D_004D1793[0]) {
        case 0:
            if (func_00418D70(0) < 0) break;
            t = D_004D1793[0];
            D_004D1793[0] = t + 1;
        case 1:
            func_0038CE40(4);
            if (func_00419610(a, 0, (u8 *)&D_00584AE0, 1, D_00583CC0) < 0) {
                return !(m == 2);
            }
            t = D_004D1793[0];
            D_004D1793[0] = t + 1;
            break;
        case 2:
            r = func_00418D70(0);
            switch (r) {
            case 0:
                if (D_00633698[0] > 0) {
                    D_004D1793[0] = 10;
                    break;
                }
                return !(m == 2);
            case 1:
                return !(m == 2);
            default:
                break;
            }
            break;
        case 10:
            r = func_0038C4A0(4, a);
            if (r == -1) break;
            if (r == 0) return 1;
            D_004D1793[0] = 0;
            D_004D1792[0] = 0;
            return 0;
        }
        break;
    }
    return 2;
}
