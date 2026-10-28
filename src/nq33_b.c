typedef unsigned char u8;
typedef signed int s32;

extern s32 D_00633DD8[];
extern s32 D_00633DDC[];
extern s32 D_00633DE0[];
extern u8 D_00633DD7[];
extern u8 D_00633DD6[];
extern u8 D_004C2B9C;
extern u8 D_004C2B98;
extern u8 D_004C2B94;
extern u8 D_004C2B90;
extern s32 D_00633E14[];
extern char D_004BF0D0[], D_004BF0F0[], D_004BF110[], D_00633DF0[];

s32 func_00420150(void)
{
    extern void func_0041FFD0(void);
    extern void func_003DCAD0(char *, s32, s32, s32);
    extern s32 func_0011FFA0(char *);
    extern void func_00420070(char *, s32, char *, s32);
    extern void func_00100E68(s32);
    extern s32 func_00106C98(char *, s32, s32);

    func_0041FFD0();
    D_00633DD8[0] = 0;
    D_00633DDC[0] = 0;
    D_00633DE0[0] = 0;
    D_004C2B9C = 0;
    D_00633DD7[0] = 0;
    D_004C2B98 = 0;
    D_00633DD6[0] = 0;
    D_004C2B94 = 0;
    D_004C2B90 = 0;
    func_003DCAD0(D_004BF0D0, 0, 0, 0);
    func_00420070(D_004BF0F0, func_0011FFA0(D_004BF110) + 1, D_004BF110, 0);
    D_004C2B9C = 1;
    do {
        func_00100E68(0);
    } while (func_00106C98(D_00633DF0, 0x1270010, 0) < 0 || D_00633E14[0] == 0);
    D_004C2B98 = 1;
    return 1;
}
