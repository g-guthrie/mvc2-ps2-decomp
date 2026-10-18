typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_0011D8F8(void *, s32, s32);
extern s32 D_004C2420;
extern u8 D_00485F80[];
void func_00405130(void) {
    if (D_004C2420 == 0) func_0011D8F8(D_00485F80, 0, 0x1360);
    D_004C2420++;
}

extern s32 D_004C24DC;
extern u8 D_00494DD8[];
void func_0040FD78(void) {
    s32 v = D_004C24DC - 1;
    D_004C24DC = v;
    if (v == 0) func_0011D8F8(D_00494DD8, 0, 0xC00);
}

extern s32 D_004C24E4, D_004C24F4, D_004C24EC;
extern void func_004093E8(s32);
extern void func_0010AE38(s32);
extern void func_00409698(void);
void func_004110D8(void) {
    s32 v = D_004C24E4 - 1;
    D_004C24E4 = v;
    if (v == 0) {
        func_004093E8(D_004C24F4);
        D_004C24F4 = 0;
        if (D_004C24EC != 0) {
            func_0010AE38(D_004C24EC);
            D_004C24EC = 0;
        }
        func_00409698();
    }
}
