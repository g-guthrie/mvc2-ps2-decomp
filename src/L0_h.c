typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 f0[4]; s8 f4; u8 f5[3]; s16 f8; u8 fa[4]; s16 fe; u8 f10[9]; s8 f19; u8 f1a[0x6E]; s8 f88; } G_h;
extern G_h *D_004C2840;
extern s8 D_004F25F0[], D_004F3160[], D_004F3CD0[], D_004F2BA8[], D_004F3718[], D_004F4288[];
extern u32 D_004F1F4C[], D_004F1F50[], D_004F1F54[], D_004F1F98[], D_004F1F94[], D_004F1F9C[], D_004F1FC0[];
extern s8 D_004F1D20[];
extern u8 D_004F1D29[], D_004F1D2A[], D_004F1D2B[];
extern s32 D_004F1D24[];
extern u32 D_004F1D2C[];

void func_003D9CE0(void)
{
    extern s32 func_0012E560();
    extern void func_003DA410();
    extern void func_0016F040();
    extern void func_0016CDA0();
    extern void func_003D6D50();
    extern void func_003D6E20();
    extern void func_00170160(int);
    extern void func_001E3CE0(s32);
    extern void func_0012E780(s32);
    extern void func_00122DA0();
    extern void func_0013D6F0();
    extern void func_0013D9A0(s32);
    extern void func_0013DBE0(s32, s32);
    extern void func_003298B0(s32, s32, s32);
    extern void func_0016D160();
    extern void func_0016D190();

    if (func_0012E560() == 0) return;
    D_004C2840->f4 = D_004C2840->f4 + 1;
    D_004C2840->f8 = 0x12C;
    D_004C2840->fe = 0;
    D_004C2840->f19 = (D_004C2840->f88 != 0) ? 0 : 1;
    if (D_004F25F0[0] == 0x18 && D_004F3160[0] == 0x18 && D_004F3CD0[0] == 0x18) {
        D_004F3160[0] = 0x19;
        D_004F3CD0[0] = 0x1A;
    }
    if (D_004F2BA8[0] == 0x18 && D_004F3718[0] == 0x18 && D_004F4288[0] == 0x18) {
        D_004F3718[0] = 0x19;
        D_004F4288[0] = 0x1A;
    }
    func_003DA410();
    func_0016F040();
    func_0016CDA0();
    func_003D6D50();
    func_003D6E20();
    func_00170160(6);
    func_001E3CE0(0x44);
    func_0012E780(10);
    func_0012E780(3);
    func_0012E780(9);
    func_00122DA0();
    D_004F1F4C[0] = 0;
    D_004F1F50[0] = 0x43200000;
    D_004F1F54[0] = 0x44610000;
    D_004F1F98[0] = 0x43200000;
    D_004F1F94[0] = 0;
    D_004F1F9C[0] = 0;
    D_004F1FC0[0] = 0;
    func_0013D6F0();
    func_0013D9A0(0);
    func_0013D9A0(1);
    func_0013D9A0(2);
    func_0013D9A0(3);
    func_0013D9A0(4);
    func_0013D9A0(5);
    func_0013DBE0(0, 2);
    func_0013DBE0(1, 2);
    func_0013DBE0(2, 2);
    func_0013DBE0(3, 2);
    func_0013DBE0(4, 2);
    func_0013DBE0(5, 2);
    func_0013DBE0(0, 1);
    func_0013DBE0(1, 1);
    func_0013DBE0(2, 1);
    func_0013DBE0(3, 1);
    func_0013DBE0(4, 1);
    func_0013DBE0(5, 1);
    func_0013DBE0(0, 0);
    func_0013DBE0(1, 0);
    func_0013DBE0(2, 0);
    func_0013DBE0(3, 0);
    func_0013DBE0(4, 0);
    func_0013DBE0(5, 0);
    func_0016CDA0();
    func_003298B0(-1, 0x1E, 0);
    func_0016D160();
    D_004F1D20[0] = 1;
    D_004F1D24[0] = 0x2A;
    D_004F1D2C[0] = 0x45DAC000;
    D_004F1D29[0] = 0xFF;
    D_004F1D2A[0] = 0xFF;
    D_004F1D2B[0] = 0x80;
    func_0016D190();
}
