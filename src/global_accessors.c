typedef unsigned char u8;
typedef signed int s32;

extern s32 D_004F1CCC;
extern s32 D_004F1CC0;
extern u8 D_004D1901;
extern s32 D_0062BF80;
extern s32 D_0062BFD4;
extern s32 D_004D17CC;
extern u8 D_004F2039;

s32 func_003299D0(void) { return D_004F1CCC; }
s32 func_003299E0(void) { return D_004F1CC0; }
s32 func_003D90D0(void) { return D_004D1901; }
void func_003E00B0(s32 v) { D_0062BF80 = v; }
s32 func_003E00C0(void) { return D_0062BF80; }
void func_003ED2C0(void) { D_0062BFD4 = 0; }
s32 func_00131540(void) { D_004D17CC = 0; return 1; }
void func_00126770(u8 *p) { D_004F2039 = p[2]; }
