typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

extern s32 func_00119AB8(void);
extern void func_00184540(u8 *);
extern void func_001CB5A0(u8 *, s32, s32);
extern int func_001757E0(u8 *, int, int);
extern void func_00178F20(u8 *, u8 *);
extern u8 D_0044DAC0[];
extern u8 data_u8_0044DDA0[18];
extern u8 *D_004C2840;

void func_001CB180(u8 *p)
{
    func_001CB5A0(p, 27, D_0044DAC0[*(s32 *)(p + 208) >> 1]);
}
