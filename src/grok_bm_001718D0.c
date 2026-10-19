typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

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
    {
        u32 t = g[4];
        g[4] = t + 1;
    }
    D_004C2840[0x19] = 1;
    D_004C2840[0x8B] = 0;
    *(u32 *)(D_004C2840 + 0x94) = 0;
    D_004C2840[0x9C] = 0;
    {
        u8 i;
        s32 off;
        off = 0;
        for (i = 0; i < 6; i++) {
            u8 *e = D_004F20B0 + off;
            e[4] = 0;
            e[5] = 0;
            e[6] = 0;
            e[7] = 0;
            off += 0x5B8;
        }
    }
    func_00180490();
    func_00161AD0();
    func_001E4480(6, 1);
    func_001E3FE0();
    func_001E4340(1);
    func_003D35C0();
}
