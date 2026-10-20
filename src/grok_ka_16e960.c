typedef unsigned char u8;
typedef signed char s8;
typedef void (*DispatchFn)(void);

extern u8 *D_004C2840 __attribute__((section(".sdata")));
extern DispatchFn jtbl_00446780[4];

void func_0016E960(void)
{
    jtbl_00446780[(s8)D_004C2840[0x92]]();
}
