typedef unsigned char u8;
typedef unsigned short u16;
typedef void (*DispatchFn)(void);
extern void func_0039E450(void);
extern DispatchFn D_004C1E70[2] __attribute__((section(".sdata")));
void func_0039C960(u8 *p)
{
    if (*(u16 *)(*(u8 **)(p + 0x18) + 0x168) != *(u16 *)(p + 0x88))
        func_0039E450();
    else
        D_004C1E70[p[4]]();
}
