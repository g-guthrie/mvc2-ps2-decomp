typedef unsigned char u8;
typedef signed int s32;

extern u8 *D_004C2840;
extern s32 D_004C22CC;

s32 func_003D7120(void) { return *(signed char *)(D_004C2840 + 0x2E) & 1; }
s32 func_003FE5B0(void) { return D_004C22CC != 0; }
