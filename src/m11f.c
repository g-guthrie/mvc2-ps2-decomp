typedef unsigned char u8;
typedef unsigned int u32; typedef signed int s32;
extern u32 D_004F7FB4;
extern u32 D_004F7FB8;

s32 func_00131830(s32 n) {
    u32 *p;
    if (n >= 32) p = &D_004F7FB8; else p = &D_004F7FB4;
    if (*p & (1 << n)) return 1;
    return 0;
}
