typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct G14 {
    u8 f0;
    s8 f1;
    u8 f2;
    u8 f3;
    u8 f4;
    u8 f5;
    u8 f6;
    u8 f7;
    u16 f8;
    u16 fA;
    u16 fC;
    u16 fE;
    u8 pad10[4];
    s32 f14;
    s8 f18;
    u8 pad19[2];
    s8 f1B;
    u8 pad1C[0xE];
    s8 f2A;
    u8 pad2B[0x19];
    s8 f44;
    u8 pad45[4];
    s8 f49;
    s8 f4A;
    u8 pad4B[1];
    s8 f4C;
    s8 f4D;
    u8 pad4E[1];
    s8 f4F;
    u8 pad50[9];
    s8 f59;
    u8 pad5A[0x2F];
    s8 f89;
} G14;

extern G14 *D_004C2840;
extern u16 D_004F4484[];
extern u16 D_004F4498[];
extern u8 D_004F20B0[];
extern u8 D_004F2580[];
extern u8 D_004F2B38[];
extern u8 D_004F258C[];
extern u8 D_004F2B44[];
extern u8 D_004F7F3F[];

void func_00129140(void) {
    extern s32 func_00129110(u16);
    extern void func_0012F860(void);
    extern void func_003D5260(void);
    extern void func_0038CBB0(void);
    extern void func_0011D8F8(u8 *, s32, s32);
    extern void func_00173F90(u8 *);
    extern void func_001E3CE0(s32);
    extern void func_003298B0(u32, s32, s32);
    s8 s0;
    s8 i;
    s32 off;
    u8 *q;
    s0 = 0;
    if ((D_004F4484[0] & 0x8000) || func_00129110(0)) {
        s0 += 1;
    }
    if (D_004C2840->f4C != 5) {
        if ((D_004F4498[0] & 0x8000) || func_00129110(1)) {
            s0 = s0 + 2;
        }
    }
    if (s0 != 0) {
        D_004C2840->f1++;
        D_004C2840->f2 = 0;
        D_004C2840->f3 = 0;
        D_004C2840->f4 = 0;
        D_004C2840->f5 = 0;
        D_004C2840->f6 = 0;
        D_004C2840->f7 = 0;
        D_004C2840->f8 = 0;
        D_004C2840->fA = 0;
        D_004C2840->fC = 0;
        D_004C2840->fE = 0;
        D_004C2840->f18 = 0;
        func_0012F860();
        func_003D5260();
        switch (D_004C2840->f4C) {
        case 0:
            func_0012F860();
            break;
        case 1:
            D_004C2840->f2A = 1;
            D_004C2840->f1B = 1;
            break;
        case 2:
            D_004C2840->f4A = -1;
            D_004C2840->f4D = 3;
            D_004C2840->f49 = 1;
            D_004F7F3F[0] = 0;
            func_0038CBB0();
            break;
        case 3:
        case 4:
        case 5:
        case 6:
            break;
        case 7:
            D_004C2840->f44 = 0;
            D_004C2840->f4A = -1;
            D_004C2840->f4F = 1;
            D_004C2840->f4D = 2;
            D_004C2840->f1B = 1;
            D_004C2840->f49 = 1;
            func_0038CBB0();
            break;
        case 8:
        case 9:
            break;
        }
        D_004C2840->f59 = D_004C2840->f4C;
        if (D_004C2840->f4A != 0) {
            if ((D_004F4484[0] & 0x8000) || func_00129110(0)) {
                s0 = 1;
            }
            if ((D_004F4498[0] & 0x8000) || func_00129110(1)) {
                s0 = 2;
            }
        }
        if (D_004C2840->f2A != 0) {
            s0 = 3;
        }
        D_004C2840->f18 = s0;
        i = 0;
        off = 0;
        D_004C2840->f89 = s0;
        D_004C2840->f14 = 0x60;
        while (i < 6) {
            q = D_004F20B0 + off;
            func_0011D8F8(q, 0, 0x5B8);
            q[0x538] = i;
            func_00173F90(q);
            i++;
            off += 0x5B8;
        }
        if (D_004C2840->f18 & 1) {
            D_004F2580[0] = 1;
        }
        if (D_004C2840->f18 & 2) {
            D_004F2B38[0] = 1;
        }
        D_004F258C[0] = 1;
        D_004F2B44[0] = 2;
        func_001E3CE0(2);
        func_003298B0(0xFF000000, 10, 1);
    } else {
        if ((D_004F4484[0] & 0x100) || (D_004F4498[0] & 0x100)) {
            D_004C2840->f2 = 2;
            func_001E3CE0(3);
            func_003298B0(0xFF000000, 10, 1);
        }
    }
}
