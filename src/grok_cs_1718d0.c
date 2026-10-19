typedef unsigned char u8;
typedef unsigned int u32;

extern u8 *D_004C2840 __attribute__((section(".sdata")));
extern u8 D_004F20B0[];
extern u8 D_004F2668[];
extern u8 D_004F2C20[];
extern u8 D_004F31D8[];
extern u8 D_004F3790[];
extern u8 D_004F3D48[];
extern void func_00180490(void);
extern void func_00161AD0(void);
extern void func_001E4480(int, int);
extern void func_001E3FE0(void);
extern void func_001E4340(int);
extern void func_003D35C0(void);

void func_001718D0(void)
{
    u8 *g = D_004C2840;
    g[4]++;
    D_004C2840[0x19] = 1;
    D_004C2840[0x8B] = 0;
    *(u32 *)(D_004C2840 + 0x94) = 0;
    D_004C2840[0x9C] = 0;
    D_004F20B0[4] = 0;
    D_004F20B0[5] = 0;
    D_004F20B0[6] = 0;
    D_004F20B0[7] = 0;
    D_004F2668[4] = 0;
    D_004F2668[5] = 0;
    D_004F2668[6] = 0;
    D_004F2668[7] = 0;
    D_004F2C20[4] = 0;
    D_004F2C20[5] = 0;
    D_004F2C20[6] = 0;
    D_004F2C20[7] = 0;
    D_004F31D8[4] = 0;
    D_004F31D8[5] = 0;
    D_004F31D8[6] = 0;
    D_004F31D8[7] = 0;
    D_004F3790[4] = 0;
    D_004F3790[5] = 0;
    D_004F3790[6] = 0;
    D_004F3790[7] = 0;
    D_004F3D48[4] = 0;
    D_004F3D48[5] = 0;
    D_004F3D48[6] = 0;
    D_004F3D48[7] = 0;
    func_00180490();
    func_00161AD0();
    func_001E4480(6, 1);
    func_001E3FE0();
    func_001E4340(1);
    func_003D35C0();
}
