typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *D_004C2840;
extern u8 D_004F4300[];
extern s32 D_004F7FD8[];
extern u8 D_004C27B8, D_004C27B4, D_004C27B0;
extern u8 D_004C27D0, D_004C27CC, D_004C27C4, D_004C27C0, D_004C27C8;
extern s32 D_004C2850;
extern u8 D_004C2A38[8];
extern u8 D_004C2A40[8];
extern u8 D_004C2A41, D_004C2A42, D_004C2A43;

void func_003D6B70(void)
{
    extern void func_001741C0(s32);
    extern void func_0011D8F8(u8 *, s32, s32);
    extern s32 func_00416A70(void);
    extern void func_0012F860(void);
    extern void func_003D35C0(void);
    extern void func_0016ED00(void);
    extern void func_003D6D50(void);
    extern void func_003D6E20(void);
    extern void func_00329890(void);
    extern void func_0016CDA0(void);
    extern void func_0016D160(s32);
    extern void func_003CE490(void);
    extern void func_00127990(void);
    extern void func_001E4260(s32);
    extern void func_0038A6A0(void);
    extern void func_003D6B60(u8 *);
    extern s32 func_0010FC98(u8 *);
    extern void func_003D7220(u8 *);
    extern void func_00420340(void);
    func_001741C0(1);
    D_004C2840 = D_004F4300;
    func_0011D8F8(D_004C2840, 0, 0x80);
    *(s32 *)(D_004C2840 + 0x14) = 0x20;
    D_004C2840[0x40] = 0;
    D_004C27B8 = 6;
    D_004C27B4 = 0;
    D_004C27B0 = 0;
    D_004C2840[0x29] = 1;
    switch (func_00416A70()) {
    case 1:
        D_004C2840[0x40] = 1;
        D_004F7FD8[0] = 0;
        break;
    case 0:
        D_004F7FD8[0] = 1;
        break;
    case 2:
        D_004F7FD8[0] = 2;
        break;
    }
    D_004C2840[0x4E] = 8;
    *(s8 *)(D_004C2840 + 0x59) = -1;
    func_0012F860();
    func_003D35C0();
    func_0016ED00();
    D_004C2840[0x2B] = 0;
    D_004C2840[0x2F] = 0;
    D_004C2850 = 3;
    D_004C27D0 = 0;
    D_004C27CC = 0;
    D_004C27C4 = 0;
    D_004C27C0 = 0;
    D_004C27C8 = 0;
    *(s32 *)(D_004C2840 + 0x30) = 0xFFFF77;
    *(s32 *)(D_004C2840 + 0x34) = 0x2000004;
    func_003D6D50();
    func_003D6E20();
    func_00329890();
    func_0016CDA0();
    func_0016D160(10);
    func_003CE490();
    func_00127990();
    if (*(s8 *)(D_004C2840 + 0x42) != 0) {
        func_001E4260(1);
    } else {
        func_001E4260(0);
    }
    func_0038A6A0();
    func_003D6B60(D_004C2A38);
    if (func_0010FC98(D_004C2A40) == 0) {
        D_004C2A43 = 0;
        D_004C2A42 = 0;
        D_004C2A41 = 0;
    } else {
        func_003D7220(D_004C2A40);
    }
    func_00420340();
    *(s16 *)(D_004C2840 + 0x106) = 0;
    *(s16 *)(D_004C2840 + 0x108) = 0;
}
