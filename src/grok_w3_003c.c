typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern u8 D_004D18A6;
extern s8 D_004F7F4C;
extern s8 D_004F7F30;
extern u8 D_00152930[];
extern u8 D_0058EFD0[];
extern u8 D_0058EC40[];

extern void func_00130040(void);
extern void func_00130820(void);
extern void func_00172760(void);
extern s32 func_00118FA8(f32);
extern void func_003C9370(u8 *);
extern void func_003C9A20(u8 *, s32, s32);
extern void func_003CDC70(u8 *, s32);
extern void func_003CDEE0(u8 *, s32);
extern void func_003D1190(void);
extern void func_003D14F0(void);
extern void func_003D26E0(void);
extern void func_003D26F0(void);
extern void func_003D7310(u8 *);
extern void func_003D79B0(u8 *, s32);
extern void func_003D7B50(u8 *, s32);
extern void func_003DA6F0(s32);
extern void func_003DAA40(u8 *);
extern void func_003DAC50(void *, s32);
extern s32 func_003DB9B0(s32);
extern void func_003DB9F0(void);
extern void func_003DC9C0(void);
extern s16 *func_003DD030(void);
extern void func_003DDA70(void *);
extern void func_003DE320(void *, void *);
extern void func_003F0310(void);

void func_003CE880(u8 *p)
{
    if (D_004F7F4C != 2)
        func_003DAA40(p);
}

void func_003CECA0(u8 *p)
{
    if (D_004F7F4C != 5)
        func_003DAA40(p);
}

void func_003CF790(u8 *p)
{
    if (D_004F7F4C != 3)
        func_003DAA40(p);
}

void func_003CF890(u8 *p)
{
    if (D_004F7F4C != 4)
        func_003DAA40(p);
}

void func_003D0820(u8 *p)
{
    if (D_004F7F30 != 2)
        func_003DAA40(p);
}

