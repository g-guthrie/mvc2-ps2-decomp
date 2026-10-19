typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

extern u8 *D_004C2840;
extern s8 D_004F203A[];
extern void func_003D6D50(void);
extern void func_003D6E20(void);
extern void func_00122840(s32);
extern void func_003D7DF0(void);
extern void func_00170F60(void);
extern void func_003D35C0(void);
extern void func_00131340(s32);

void func_003D2B70(void)
{
    s8 v;
    D_004C2840[2] = 1;
    D_004C2840[3] = 0;
    D_004C2840[4] = 0;
    D_004C2840[5] = 0;
    D_004C2840[6] = 0;
    D_004C2840[7] = 0;
    D_004C2840[0x9E] = 1;
    D_004C2840[0x50] = 0;
    D_004C2840[0xA9] = D_004C2840[0x89];
    D_004C2840[0x85] = 0;
    v = (s8)D_004C2840[0x89];
    if ((v | (s8)D_004C2840[0x88]) != 3)
        D_004C2840[0x85] = D_004F203A[v * 0x5B8];
    func_003D6D50();
    func_003D6E20();
    func_00122840(0);
    func_003D7DF0();
    func_00170F60();
    D_004C2840[0xB4] = 0;
    func_003D35C0();
    v = (s8)D_004C2840[0x4C];
    if (v == 5)
        D_004C2840[0xB4] = 1;
    else if (v == 7 || v == 1)
        func_00131340(0x64);
    else if (v == 2 || v == 0)
        ;
}
