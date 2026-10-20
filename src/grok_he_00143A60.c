typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

extern void func_00122860(u32, u32);
extern void func_00143860(void);
extern void func_00143430(void);
extern void func_001434A0(void);
extern void func_001428E0(void);
extern void func_00414A40(void);
extern void func_00416AB0(s32);
extern void func_004171E0(void);
extern void func_00417860(void *, void *, s32);
extern void func_00416D40(void *);
extern void func_00416AE0(s32);
extern void func_00417950(f32, f32);
extern void func_00416CC0(s32);
extern void func_00142320(void);
extern void func_00141CF0(u8 *);
extern void func_00143CA0(void **, void *, s32);
extern void func_001431A0(u8 *);
extern void func_0016D190(void);
extern u32 D_004C2638 __attribute__((section(".sdata")));
extern u32 D_004C263C __attribute__((section(".sdata")));
extern signed char *D_004C2840 __attribute__((section(".sdata")));
extern u8 *D_004C2650 __attribute__((section(".sdata")));
extern f32 D_004CACA0;
extern f32 D_004CAC90;
extern u8 D_004CAC50[];
extern void *D_004CACB0[];
extern void *D_004CABB0[];

void func_00143A60(void)
{
    s32 i;
    s16 t;
    u8 *q;

    func_00122860(D_004C2638, D_004C263C);
    t = *(s16 *)(D_004C2840 + 10);
    *(s16 *)(D_004C2840 + 10) = (s16)(t + 1);
    func_00143860();
    func_00143430();
    func_001434A0();
    func_001428E0();
    func_00414A40();
    q = D_004C2650;
    func_00416AB0(2);
    func_004171E0();
    func_00417860(&D_004CACA0, &D_004CAC90, 0);
    func_00416D40(q + 0x88);
    func_00416AB0(1);
    func_004171E0();
    func_00416AE0(0);
    func_00417950(640.0f, 480.0f);
    func_00416D40(&D_004CAC50);
    func_00416CC0(1);
    t = *(s16 *)(D_004C2840 + 10);
    if ((t >= 0x233 && t < 0x346) || (t >= 0x41A && t < 0x52F))
        func_00142320();
    for (i = 0; i < 0x28; i++) {
        if (D_004CACB0[i] != 0 && ((u8 *)D_004CACB0[i])[0] != 0)
            func_00141CF0(D_004CACB0[i]);
    }
    func_00143CA0(D_004CABB0, D_004CACB0, 0x28);
    for (i = 0; i < 0x28; i++) {
        if (D_004CABB0[i] != 0 && ((u8 *)D_004CABB0[i])[0] != 0)
            func_001431A0(D_004CABB0[i]);
    }
    if (*(s16 *)(D_004C2840 + 10) > 0x6BA) {
        D_004C2840[2] = 0;
        D_004C2840[1] = (s8)(D_004C2840[1] + 1);
    }
    func_0016D190();
}
