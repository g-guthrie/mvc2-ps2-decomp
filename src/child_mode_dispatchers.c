typedef unsigned char u8;
typedef void (*DispatchFn)(void);
extern void func_0020D2A0(void);
extern DispatchFn D_004BFE30[2] __attribute__((section(".sdata")));
extern DispatchFn D_004BFE38[2] __attribute__((section(".sdata")));
void func_0020C040(u8 *a, u8 *b)
{
    if (b[9] != 0)
        func_0020D2A0();
    else
        D_004BFE30[a[7]]();
}
void func_0020C230(u8 *a, u8 *b)
{
    if (b[9] != 0)
        func_0020D2A0();
    else
        D_004BFE38[a[7]]();
}
