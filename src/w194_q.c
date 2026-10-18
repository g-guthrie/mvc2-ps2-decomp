typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad0[8]; s16 f8; u8 pad1[4]; s16 fe; u8 pad2[0x70 - 0x10]; u8 f70, f71; } K0;
extern K0 *D_004C2840;
extern s32 func_003299D0();
extern void func_003DA650(s32);
extern void func_00146C80(s32);
extern void func_001489E0(s32, s32);
extern void func_00148AA0(s32);
extern void func_003D4880();
extern void func_003298B0(s32, s32, s32);
extern void func_0012ACC0(void *);
extern void func_00148FD0();
extern void func_0012AC70(s32, void *);
extern void func_00149020();
extern void func_00148E90();

void func_00148DE0(void) {
    if (func_003299D0() == 0) {
        func_003DA650(0xD);
        func_003DA650(0xF);
        D_004C2840->f70 = 0;
        D_004C2840->f71 = 0;
        D_004C2840->fe = 0;
        D_004C2840->f8 = 0;
        func_00146C80(1);
        func_001489E0(2, 2);
        func_00148AA0(2);
        func_003D4880();
        func_003298B0(0xFF000000, 0xA, 0);
        func_0012ACC0(func_00149020);
        func_00148FD0();
        func_0012AC70(1, func_00148E90);
    }
}
