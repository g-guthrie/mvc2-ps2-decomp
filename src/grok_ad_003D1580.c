typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed int s32;

extern u8 *D_004C2840;
extern void (*D_00477170[])(void);
extern struct { u16 a; u8 pad[0x12]; u16 b; } D_004F4484;
extern void func_00417A40(void);
extern s32 func_00174170(void);
extern s32 func_0012F930(s32);
extern void func_001E4150(void);
extern void func_001E40E0(void);
extern void func_001E4140(void);
extern void func_001E46C0(s32);
extern void func_001E4480(s32, s32);
extern void func_001E4340(s32);
extern void func_001E3CE0(s32);
extern void func_0012E6B0(void);

void func_003D1580(void)
{
    s32 a1;
    s8 st;
    D_004C2840[0x2E] = 0;
    D_00477170[(s8)D_004C2840[1]]();
    func_00417A40();
    func_00174170();
    a1 = 0;
    if ((s8)D_004C2840[1] != 10)
        a1 = func_0012F930(1);
    if (a1)
        return;
    if (*(s32 *)(D_004C2840 + 0x14) != 0x40)
        return;
    st = (s8)D_004C2840[1];
    if (st == 9 || st == 0xC)
        return;
    if (st == 0xD)
        return;
    if (!(D_004F4484.a & 0x8000) && !(D_004F4484.b & 0x8000))
        return;
    if (st == 7 || st == 8 || st == 10)
        return;
    D_004C2840[1] = 7;
    D_004C2840[2] = 0;
    func_001E4150();
    func_001E40E0();
    func_001E4140();
    func_001E46C0(0x7F);
    func_001E4480(6, 1);
    func_001E4340(1);
    func_001E3CE0(0);
    func_0012E6B0();
}
