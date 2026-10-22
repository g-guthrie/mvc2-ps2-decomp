typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 p0[3]; s8 f3; s8 f4; s8 f5; s8 f6; s8 f7; s16 f8; u8 pa[0xF]; s8 f19; u8 p1a[0x32]; s8 f4C; u8 p4d[0x3B]; s8 f88; u8 p89[7]; s8 f90; s8 f91; s8 f92; u8 p93[11]; s8 f9E; } G_x;
extern G_x *D_004C2840;
extern u8 D_004D179A[], D_00583BDE[], D_00583BDF[], D_00583B9D[];
extern s8 D_004C27C4, D_004C27D0, D_004C27C0, D_004C292C;
extern s8 D_004F7F34[];
extern u16 D_00583BDC[];
extern u8 D_00583B9C[], D_00583BC1[], D_00583BC0[], D_00583BC5[], D_00583BC4[], D_00583BC8[], D_00583B9A[], D_00583BE1[], D_00583BE0[], D_00583B98[], D_00583B99[];
extern u32 D_004D178C[], D_004D1788[], D_004D17B4[], D_004D17B0[];
extern s32 D_004C2928;
extern u8 D_00583B92[];
extern u8 D_00583B93[];
extern volatile u32 D_00583BA0[], D_00583BA4[], D_00583BA8[], D_00583BAC[], D_00583BB0[], D_00583BB4[], D_00583BB8[], D_00583BBC[];
extern volatile u32 D_00583BCC[], D_00583BD0[], D_00583BD4[], D_00583BD8[];
extern u8 D_004F1F40[], D_004F1F48[];
extern u32 D_004F1F4C[], D_004F1F50[], D_004F1F54[], D_004F1F98[], D_004F1F94[], D_004F1F9C[], D_004F1FC0[];
extern u8 D_00583BC3[], D_00583BC6[];
extern s32 D_004C2924;
extern s32 D_004C2920[2];

void func_00329C50(void)
{
    extern s32 func_0012E560();
    extern void func_0012E770(u8);
    extern void func_0012F060(s32);
    extern void func_00417FA0(s32);
    extern void func_003DA410();
    extern void func_003D6D50();
    extern void func_003D6E20();
    extern void func_0038CBB0();
    extern void func_00329AC0(s32);
    extern void func_0032DF00();
    extern void func_00170160(s32);
    extern void func_00329890();
    extern void func_0016D160();
    extern void func_0016CDA0();
    extern void func_00122DA0();
    extern void func_001237A0();
    extern void func_0013BD10();
    extern s32 func_00136830(s32 *);
    extern void func_001397F0();
    extern void func_00136C80();
    extern void func_0013B060();
    extern void func_0016F040();
    extern void func_0016F090(u32 *);
    extern void func_003D7310(void (*)());
    extern void func_00152570();
    extern void func_0012E780(s32);
    u32 v[3];
    s8 *q;
    u8 z;
    u32 t0, t2, t3, t4, t1, t5;
    u32 u0, u3, u2, u4, u5, u1;

    if (func_0012E560() == 0) return;
    func_0012E770(D_004C2840->f88);
    if ((D_004C2840->f88 & 1) == 0) func_0012F060(0);
    if ((D_004C2840->f88 & 2) == 0) func_0012F060(1);
    if (D_004C2840->f4C == 5) func_00417FA0(1);
    D_004C2840->f3 = D_004C2840->f3 + 1;
    D_004C2840->f4 = 0;
    D_004C2840->f5 = 0;
    D_004C2840->f6 = 0;
    D_004C2840->f7 = 0;
    func_003DA410();
    func_003D6D50();
    func_003D6E20();
    D_00583BDE[0] = D_004D179A[0];
    if (D_004C2840->f4C == 1) {
        D_004C27C4 = 1;
        D_00583BDF[0] = 0;
        D_004C27D0 = 0x11;
        D_004C27C0 = 0x1D;
        func_0038CBB0();
    }
    D_004C2840->f9E = 1;
    D_00583B9D[0] = 0;
    if (D_004C2840->f4C == 1 || D_004F7F34[0] == 2) {
        D_004C292C = -1;
        D_004C2840->f90 = 0;
    } else {
        D_004C292C = 0;
        if ((D_004C2840->f88 & 1) != 0) D_004C292C = 2;
        q = &D_004C2840->f88;
        if ((*q & 2) != 0) D_004C292C = 1;
        if (D_004C2840->f90 == 0) {
            if (*q == 0) D_004C292C = -1;
        } else {
            D_004C292C = D_004C2840->f90;
            D_004C2840->f90 = 0;
        }
    }
    D_004C2840->f19 = 0;
    D_004C2840->f91 = 0;
    D_004C2840->f92 = 0;
    D_00583BDC[0] = 0xE10;
    D_00583B9C[0] = 0;
    z = D_004C2928 = 0;
    D_00583BC1[0] = 0;
    D_00583BC0[0] = 0;
    D_00583BC5[0] = 0;
    D_00583BC4[0] = 0;
    D_00583BC8[0] = 0;
    D_00583B9A[0] = 0;
    D_00583BE1[0] = 0;
    D_00583BE0[0] = 0;
    D_004D178C[0] = 0;
    D_004D1788[0] = 0;
    D_004D17B4[0] = 0;
    D_004D17B0[0] = 0;
    D_00583B98[0] = 0;
    D_00583B99[0] = 0;
    if ((D_004C2840->f88 & 3) != 0) {
        if ((D_004C2840->f88 & 1) == 0) {
            D_00583B92[0] = 0;
            func_00329AC0(0);
            t0 = D_00583BA0[0] | D_00583BA8[0];
            t1 = D_00583BA4[0] | D_00583BAC[0];
            t2 = D_00583BCC[0] | D_00583BD4[0];
            t3 = D_00583BD0[0] | D_00583BD8[0];
            D_00583BA0[0] = t0;
            t4 = D_00583BA0[0];
            D_00583BA4[0] = t1;
            t5 = D_00583BA4[0];
            D_00583BCC[0] = t2;
            D_00583BD0[0] = t3;
            D_00583BB0[0] = t4;
            D_00583BB4[0] = t5;
        }
        if ((D_004C2840->f88 & 2) == 0) {
            D_00583B93[0] = 0;
            func_00329AC0(1);
            u0 = D_00583BA8[0] | D_00583BA0[0];
            u1 = D_00583BAC[0] | D_00583BA4[0];
            u2 = D_00583BD4[0] | D_00583BCC[0];
            u3 = D_00583BD8[0] | D_00583BD0[0];
            D_00583BA8[0] = u0;
            u4 = D_00583BA8[0];
            D_00583BAC[0] = u1;
            u5 = D_00583BAC[0];
            D_00583BD4[0] = u2;
            D_00583BD8[0] = u3;
            D_00583BB8[0] = u4;
            D_00583BBC[0] = u5;
        }
    } else {
        D_00583B92[0] = z;
        D_00583B93[0] = 0;
        func_00329AC0(0);
        func_00329AC0(1);
    }
    func_0032DF00();
    func_00170160(5);
    func_00329890();
    func_0016D160();
    func_0016CDA0();
    func_00122DA0();
    if (D_004C2840->f4C == 1) {
        D_004F1F40[0] = 1;
        D_004F1F48[0] = 4;
        D_004F1F4C[0] = 0;
        D_004F1F50[0] = 0x433E0000;
        D_004F1F54[0] = 0x444B16DE;
        D_004F1F98[0] = 0x433E0000;
        D_004F1F94[0] = 0;
        D_004F1F9C[0] = 0;
        D_004F1FC0[0] = 0;
        D_004C2840->f8 = 0;
        func_001237A0();
    } else {
        D_004F1F40[0] = 1;
        D_004F1F48[0] = 1;
        D_004F1F50[0] = 0x44870000;
        D_004F1F54[0] = 0x3DCCCCCD;
        D_004F1F98[0] = 0x42BE0000;
        D_004F1F4C[0] = 0;
        D_004F1F94[0] = 0;
        D_004F1F9C[0] = 0;
        D_004F1FC0[0] = 0;
        D_004C2840->f8 = 0x64;
    }
    D_00583BC3[0] = 0;
    D_00583BC6[0] = 0;
    func_0013BD10();
    D_004C2924 = func_00136830(D_004C2920);
    func_001397F0();
    func_00136C80();
    if (D_004C2840->f4C != 1) func_0013B060();
    func_0016F040();
    v[0] = 0x3F800000;
    v[1] = 0x3F800000;
    v[2] = 0x3F800000;
    func_0016F090(v);
    func_003D7310(func_00152570);
    func_0012E780(0);
}
