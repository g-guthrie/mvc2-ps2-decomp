typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

extern u8 *D_004CB648;
extern u8 *D_004CB63C;
extern u8 *D_004CB5BC;
extern s8 D_004C8230[];
extern u8 D_004F20B0[];
extern void func_0016F4D0(u8 *, u8 *);
extern s32 func_00416180(s32, s32);
extern void func_0016F4B0(s32, s32, u8 *);
extern void func_0016F530(s32, u8 *, u8 *, u8 *, s32, s32);

void func_0016FF20(void)
{
    int i;

    func_0016F4D0(D_004CB63C, D_004CB648);
    for (i = 0; i < 6; i++) {
        s32 r = func_00416180(*(s32 *)(D_004F20B0 + i * 1464 + 0x194), 1);
        func_0016F4B0(D_004C8230[i] + 2, r, D_004CB648);
    }
    func_0016F530(0x810, D_004CB5BC, D_004CB63C, D_004CB648, 6, 0);
}
