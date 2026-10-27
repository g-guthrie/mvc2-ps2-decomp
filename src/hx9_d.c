typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 p0[3]; s8 f3; s8 f4; s8 f5; s8 f6; s8 f7; s16 f8; } Gd;
extern Gd *D_004C2840;
extern s8 D_004C286C[2];
extern s32 D_004C25F8[2];
extern u8 D_00148DE0[];
extern void (*D_0043CC70[])(void *);
extern u8 D_004F7FC0[];

void func_00129620(void)
{
    extern s32 func_003299D0();
    extern void func_0012AC70(s32, u8 *);
    extern void func_0012ACC0(s32);
    extern void func_003DA650(s32);
    extern void func_00146C80(s32);
    extern void func_001489E0(s32, s32);
    extern void func_00148AA0(s32);
    extern void func_00147660();
    extern void func_003298B0(s32, s32, s32);
    extern void func_0012FC40();
    extern s32 func_001315F0();
    extern s32 func_001316D0();
    extern u16 func_0012ABC0(s32, s32);
    extern s32 func_0012ABA0(u16, s32, s32);
    switch (D_004C2840->f3) {
    case 0:
        if (func_003299D0() != 0) {
            break;
        }
        D_004C2840->f3 = D_004C2840->f3 + 1;
        D_004C2840->f8 = D_004C2840->f4;
        D_004C2840->f4 = 0;
        D_004C2840->f5 = 0;
        D_004C2840->f6 = 0;
        D_004C2840->f7 = 0;
        D_004C25F8[0] = D_004C286C[0];
        func_0012AC70(1, D_00148DE0);
        func_0012ACC0(0);
    case 1:
        func_003DA650(0xD);
        func_003DA650(0xF);
        func_00146C80(1);
        func_001489E0(1, 1);
        func_00148AA0(1);
        func_00147660();
        D_004C2840->f3 = D_004C2840->f3 + 1;
        func_003298B0(0xFF000000, 10, 0);
        func_0012FC40();
        break;
    case 2:
        if (func_003299D0() == 0) {
            D_004C2840->f3 = D_004C2840->f3 + 1;
        }
        break;
    case 3:
        if (func_001315F0() != 0) {
            D_004C2840->f3 = D_004C2840->f3 + 1;
            D_004C2840->f4 = D_004C2840->f8;
            D_004C2840->f5 = 0;
            D_004C2840->f6 = 0;
            D_004C2840->f7 = 0;
            func_003298B0(0xFF000000, 10, 1);
        } else if (func_001316D0() != 0) {
            D_004C2840->f3 = D_004C2840->f3 + 1;
            D_004C2840->f4 = 3;
            D_004C2840->f5 = 0;
            D_004C2840->f6 = 0;
            D_004C2840->f7 = 0;
            func_003298B0(0xFF000000, 10, 1);
        } else {
            D_004C2840->f8 = func_0012ABA0(func_0012ABC0(3, 0), D_004C2840->f8, 3);
        }
        break;
    case 4:
        D_0043CC70[D_004C2840->f4](D_004F7FC0);
        break;
    }
}
