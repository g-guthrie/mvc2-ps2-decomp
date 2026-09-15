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
extern void func_003DAC50(u8 *, s32);
extern s32 func_003DB9B0(u8 *);
extern void func_003DB9F0(void);
extern void func_003DC9C0(void);
extern s16 *func_003DD030(void);
extern void func_003DDA70(void *);
extern void func_003DE320(void *, void *);
extern void func_003F0310(void);

void func_003D0F70(void)
{
    func_003D14F0();
    func_003D1190();
}

void func_003D1F60(void)
{
    func_00172760();
    func_003D26F0();
    func_003D26E0();
}

void func_003DD040(void)
{
    func_003DC9C0();
    func_003DB9F0();
    func_003F0310();
}

void func_003C9210(u8 *p)
{
    if (D_004D18A6 == 0)
        func_003DAA40(p);
}

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

void func_003D24A0(void)
{
    func_00130040();
    func_003DA6F0(13);
    func_003D7310(D_00152930);
}

void func_003D24D0(void)
{
    func_00130820();
    func_003DA6F0(13);
    func_003D7310(D_00152930);
}

s32 func_003DEC90(void)
{
    s16 *p = func_003DD030();
    if (p)
        return p[1];
    return 0;
}

void func_003DADD0(void)
{
    func_003DAC50(D_0058EFD0, 0x2A8);
    func_003DAC50(D_0058EC40, 0x2A8);
}

void func_003DDB20(void *p)
{
    u8 tmp[64];
    func_003DDA70(tmp);
    func_003DE320(p, tmp);
}

void func_003CDC30(u8 *p)
{
    if (p[0x20] == 0)
        func_003CDC70(p, *(s32 *)(p + 0x18));
    else
        func_003CDEE0(p, *(s32 *)(p + 0x18));
}

void func_003D7970(u8 *p)
{
    s32 v = *(s32 *)(p + 0x18);
    if (p[0x20] == 0)
        func_003D79B0(p, v);
    else
        func_003D7B50(p, v);
}

void func_003C9330(u8 *p)
{
    if (p[0x20] == 0)
        func_003C9370(p);
    else
        func_003C9A20(p, *(s32 *)(p + 0x18), *(s32 *)(p + 8));
}

s32 func_003DCFE0(u8 *p)
{
    s32 r = func_003DB9B0(p);
    if (r == 0) {
        func_003DD040();
        r = func_003DB9B0(p);
    }
    return r;
}

void func_003C15B0(u8 *p)
{
    s16 *slot = (s16 *)(p + 0xd0);
    *slot = (s16)func_00118FA8((f32)*slot + *(f32 *)(p + 0x5c));
}

void func_003C3D60(u8 *p)
{
    s16 *slot = (s16 *)(p + 0xd0);
    *slot = (s16)func_00118FA8((f32)*slot + *(f32 *)(p + 0x5c));
}


