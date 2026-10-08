typedef signed char s8;
typedef unsigned char u8;

typedef signed short s16;
typedef signed int s32;

extern u8 *D_004C2840;
extern s32 D_004C28B8;
extern void func_003D6D50(void);
extern void func_003D6E20(void);
extern void func_0012DA40(s32 value, s32 profile, s32 mode);
extern void func_003DA410(void);
extern void func_00122DA0(void);
extern void func_0016CDA0(void);
extern void func_0016D160(void);
extern void func_00329890(void);
extern void func_00122840(s32 value);
extern void func_0016F0C0(float value);

void func_00420720(void)
{
    ((s8 *)D_004C2840)[2]++;
    *(s16 *)(D_004C2840 + 8) = 180;
    *(s16 *)(D_004C2840 + 10) = 0;
    func_003D6D50();
    func_003D6E20();
    func_0012DA40(976, D_004C28B8, 2);
    func_003DA410();
    func_00122DA0();
    func_0016CDA0();
    func_0016D160();
    func_0016D160();
    func_00329890();
    func_00122840(-1);
    func_0016F0C0(1.0f);
}
