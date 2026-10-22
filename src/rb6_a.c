typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad[4]; u8 b4, b5, b6, b7; } T4;
typedef struct { u8 f0[4]; s8 f4; u8 f5[0x14]; u8 f19; u8 f1a[0x71]; u8 f8b; u8 f8c[8]; s32 f94; u8 f98[4]; u8 f9c; } G_a;
extern G_a *D_004C2840;
extern u8 D_004F20B0[], D_004F2668[], D_004F2C20[], D_004F31D8[], D_004F3790[], D_004F3D48[];

void func_001718D0(void)
{
    extern void func_00180490();
    extern void func_00161AD0();
    extern void func_001E4480(s32, s32);
    extern void func_001E3FE0();
    extern void func_001E4340(s32);
    extern void func_003D35C0();

    T4 *q1, *q6, *q5, *q4, *q3, *q2;
    q1 = (T4*)(D_004F20B0); q2 = (T4*)(D_004F2668); q3 = (T4*)(D_004F2C20); q4 = (T4*)(D_004F31D8); q5 = (T4*)(D_004F3790); q6 = (T4*)(D_004F3D48);
    D_004C2840->f4 = D_004C2840->f4 + 1;
    D_004C2840->f19 = 1;
    D_004C2840->f8b = 0;
    D_004C2840->f94 = 0;
    D_004C2840->f9c = 0;
    q1->b4 = 0; q1->b5 = 0; q1->b6 = 0; q1->b7 = 0;
    q2->b4 = 0; q2->b5 = 0; q2->b6 = 0; q2->b7 = 0;
    q3->b4 = 0; q3->b5 = 0; q3->b6 = 0; q3->b7 = 0;
    q4->b4 = 0; q4->b5 = 0; q4->b6 = 0; q4->b7 = 0;
    q5->b4 = 0; q5->b5 = 0; q5->b6 = 0; q5->b7 = 0;
    q6->b4 = 0; q6->b5 = 0; q6->b6 = 0; q6->b7 = 0;
    func_00180490();
    func_00161AD0();
    func_001E4480(6, 1);
    func_001E3FE0();
    func_001E4340(1);
    func_003D35C0();
}
