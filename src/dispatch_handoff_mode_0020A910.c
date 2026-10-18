typedef unsigned char u8;
typedef int s32;
typedef void (*DispatchFn)(u8 *);
extern DispatchFn D_004BFE20[2] __attribute__((section(".sdata")));
extern s32 func_003D92F0(u8 *);
extern void func_001843A0(u8 *);
void func_0020A910(u8 *p)
{
    if (func_003D92F0(p))
        func_001843A0(p);
    else
        D_004BFE20[p[6]](p);
}
