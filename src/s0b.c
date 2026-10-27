typedef signed int s32;
typedef signed char s8;
typedef signed short s16;
extern s32 D_004C220C;
extern char D_00478E78[];
extern void func_0011D8F8(void *, int, int);
void func_003F5F00(void) {
    if (D_004C220C == 0) func_0011D8F8(D_00478E78, 0, 0x180);
    D_004C220C++;
}

extern s32 D_004C2238;
typedef struct { int a[8]; } Q;
extern Q D_004C2240;
extern void func_003F78F0(void);
extern void func_003F79A8(s8 *, s16 *, s16 *, s16 *);
void func_003F7B18(s16 *a, s16 *b, s16 *c) {
    if (D_004C2238 == 0) func_003F78F0();
    do { func_003F79A8((s8 *)&D_004C2240, a, b, c); } while (0);
}
