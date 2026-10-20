typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern u8 *D_004C2840 __attribute__((section(".sdata")));
extern void (*D_004BF4A8[])(void) __attribute__((section(".sdata")));
extern s16 D_004F24E4;
extern s16 D_004F24E8;
extern s16 D_004F2A9C;
extern s16 D_004F2AA0;
extern s16 D_004F3054;
extern s16 D_004F3058;
extern s16 D_004F360C;
extern s16 D_004F3610;
extern s16 D_004F3BC4;
extern s16 D_004F3BC8;
extern s16 D_004F417C;
extern s16 D_004F4180;
extern s8 D_004D18DB;
extern void func_003D9080(void);
extern void func_001E8CD0(void);
extern void func_001E76D0(void);
extern void func_0016D070(void);
extern void func_003DAC00(void);
extern void func_00326AF0(void);
extern void func_003DA9D0(s32);
extern void func_003D7310(void (*)(void));
extern void func_001529A0(void);

void func_00172760(void)
{
    u8 *p;
    s32 *slot;

    D_004C2840[0x2E] = 1;
    (*(s8 *)(D_004C2840 + 0x84))++;
    D_004BF4A8[(s8)D_004C2840[2]]();
    D_004F24E4 = 0x90;
    D_004F24E8 = 0x90;
    D_004F2A9C = 0x90;
    D_004F2AA0 = 0x90;
    D_004F3054 = 0x90;
    D_004F3058 = 0x90;
    D_004F360C = 0x90;
    D_004F3610 = 0x90;
    D_004F3BC4 = 0x90;
    D_004F3BC8 = 0x90;
    D_004F417C = 0x90;
    D_004F4180 = 0x90;
    p = D_004C2840;
    slot = (s32 *)(p + 0x94);
    if (*slot != -1)
        *slot = *slot + 1;
    func_003D9080();
    D_004D18DB = (s8)((D_004D18DB + 1) & 0xF);
    if (*(s16 *)(D_004C2840 + 8) != 0) {
        func_001E8CD0();
        func_001E76D0();
    }
    func_0016D070();
    func_003DAC00();
    if (*(s16 *)(D_004C2840 + 8) != 0) {
        func_00326AF0();
        func_003DA9D0(3);
        func_003DA9D0(4);
        func_003DA9D0(1);
        func_003DA9D0(2);
    }
    func_003D7310(func_001529A0);
}
