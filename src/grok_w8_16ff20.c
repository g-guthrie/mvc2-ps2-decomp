typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

extern u8 *D_004C28B8;
extern u8 *D_004C28AC;
extern u8 *D_004C282C;
extern s8 D_004BF4A0[] __attribute__((section(".sdata")));
extern u8 D_004F20B0[];
extern void func_0016F4D0(u8 *, u8 *);
extern s32 func_00416180(s32, s32);
extern void func_0016F4B0(s32, s32, u8 *);
extern void func_0016F530(s32, u8 *, u8 *, u8 *, s32, s32);

void func_0016FF20(void)
{
    int i;

    func_0016F4D0(D_004C28AC, D_004C28B8);
    i = 0;
    do {
        s32 r = func_00416180(*(s32 *)(D_004F20B0 + i * 1464 + 0x194), 1);
        func_0016F4B0(D_004BF4A0[i] + 2, r, D_004C28B8);
        i++;
    } while (i < 6);
    func_0016F530(0x810, D_004C282C, D_004C28AC, D_004C28B8, 6, 0);
}
