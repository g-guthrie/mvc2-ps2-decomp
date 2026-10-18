typedef signed int s32;
typedef unsigned int u32;
typedef signed short s16;
typedef unsigned char u8;
extern void *func_0011D8F8(void *, s32, s32);

extern s32 D_004C2298;
extern s32 func_003FA1B0(s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003FA448(s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_003FA6E0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s16 g, s16 h) {
    if (D_004C2298 == 0) return func_003FA1B0(a, b, c, d, e, f, g, h);
    return func_003FA448(a, b, c, d, e, f, g, h);
}

extern s32 D_004C2AB0, D_004C2AB4;
extern char D_006267A0[];

extern s32 D_004C24D0;
extern char D_004908F8[];
void func_0040F030(void) {
    if (D_004C24D0 == 0) func_0011D8F8(D_004908F8, 0, 0x480);
    D_004C24D0++;
}

extern char D_00633DC0[], D_00633D70[], D_00633970[], D_00633940[], D_004C2B88[6];
extern struct { s32 a, b, c, d; } D_00633960;
extern s32 D_00633960b __attribute__((section(".bss")));

extern s32 D_004C253C;
extern s32 D_006340C0[4];
extern s32 D_006340C0b;
extern char D_00634030[];
extern void func_00103E20(s32);
extern void func_00103E00(s32);
extern void func_00423890(void);
extern s32 func_00106E68(void *, s32, s32, void *, s32, void *, s32, void *, long);
