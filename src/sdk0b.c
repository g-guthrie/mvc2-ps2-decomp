typedef signed int s32;
typedef unsigned char u8;
extern void func_00103B80(void);
extern s32 *func_0011B370(void);
extern void func_004003C8(s32, s32, s32, s32, s32);
extern s32 func_003EBA40(void);
extern void func_003EB9C0(s32);
void func_00104A60(void) { func_00103B80(); __asm__ volatile("sync"); }
void func_004005C8(s32 a, s32 b, s32 c, s32 d) { func_004003C8(a, 0, b, c, d); }
s32 func_003EBD00(void) { s32 p = func_003EBA40(); if (p) func_003EB9C0(p); return 1; }
s32 func_0011D590(s32 a, s32 *out, u8 *src, s32 d) {
    s32 tmp;
    s32 *p = out ? out : &tmp;
    if (!src) return 0;
    if (!d) return -1;
    *p = *src;
    return *src != 0;
}
