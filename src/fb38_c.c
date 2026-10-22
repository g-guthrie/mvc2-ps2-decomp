typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_004C2628;
extern u8 D_004C2858;
extern s8 D_004C2854;
extern s8 D_004C286C;
extern s32 D_004C28B4;
extern u8 *D_004C2890;
extern u8 *D_004C288C;
extern u8 *D_004C2888;
extern u8 D_004F6CD0[];

void func_0012F4C0(void)
{
    extern s32 func_00414CB0(s32);
    extern void func_0016F0E0(void);
    extern void func_0012DC00(void);
    extern void func_00174B50(void);
    extern void func_003DF850(s32, s32);
    extern void func_003DB970(s32);
    extern void func_00414E30(void);
    extern void func_004152E0(void);
    extern void func_00415450(void);
    extern void func_00416AC0(u8 *, s32);
    extern void func_004171E0(void);
    extern void func_00413E60(void);
    extern void func_00414AA0(void);
    extern void func_00418910(void);
    extern void func_001E2050(void);
    extern void func_0012F710(s32);
    extern void func_001E41B0(s32);
    extern void func_001E41C0(s32);
    extern void func_001E46D0(s32);
    extern void func_001E4260(s32);
    extern void func_0012DA40(s32, u8 *, s32);
    extern void func_0016F4D0(s32, s32);
    extern void func_0016F1A0(s32, u8 *);
    extern u8 *func_00418200(u8 *, s32);

    if (func_00414CB0(0x200000) == 0) {
        for (;;) {
        }
    }
    func_0016F0E0();
    func_0012DC00();
    func_00174B50();
    func_003DF850(0x6C, 1);
    func_003DB970(1);
    func_00414E30();
    func_004152E0();
    func_00415450();
    func_00416AC0(D_004F6CD0, 0x40);
    func_004171E0();
    func_00413E60();
    func_00414AA0();
    D_004C2628 = 0;
    func_00418910();
    func_001E2050();
    func_0012F710(0xFF);
    D_004C2858 = 7;
    D_004C2854 = 7;
    func_001E41B0(0x38);
    func_001E41C0((u8)(D_004C2858 << 3));
    func_001E46D0(D_004C2854 * 35);
    if (D_004C286C != 0) {
        func_001E4260(1);
    } else {
        func_001E4260(0);
    }
    func_0012DA40(0x34A, (u8 *)D_004C28B4, 2);
    func_0012DA40(0x349, (u8 *)(D_004C28B4 + 0x4500), 2);
    func_0016F4D0(D_004C28B4 + 0x4500, D_004C28B4);
    func_0016F1A0(0, (u8 *)(D_004C28B4 + 0xA000));
    D_004C2890 = func_00418200((u8 *)(D_004C28B4 + 0x7FFF + 0x2001), 4);
    func_0016F1A0(1, (u8 *)(D_004C28B4 + 0x7FFF + 0x2001));
    D_004C288C = func_00418200((u8 *)(D_004C28B4 + 0x7FFF + 0x2001), 4);
    func_0016F1A0(0x3CA, (u8 *)(D_004C28B4 + 0x7FFF + 0x2001));
    D_004C2888 = func_00418200((u8 *)(D_004C28B4 + 0x7FFF + 0x2001), 4);
    func_0016F1A0(2, (u8 *)(D_004C28B4 + 0x1D000));
    {
        u8 *b = (u8 *)(D_004C28B4 + 0x1D000);
        *(s32 *)(b + 8) += (s32)b;
    }
    func_0012DA40(0x94, (u8 *)(D_004C28B4 + 0x1E000), 2);
    func_0012DA40(0x92, (u8 *)(D_004C28B4 + 0x2EA00), 2);
}
