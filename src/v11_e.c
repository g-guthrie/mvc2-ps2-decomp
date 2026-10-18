typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


void func_001266A0(u8 *p, s32 a, s32 b) {
    extern void func_00126470();
    extern void func_001264D0();
    extern void func_00126770();
    extern u8 D_004F1F41;
    extern u8 D_004F1F42;
    s8 s1, s2;
    if (p == 0) {
        D_004F1F41 = a;
        D_004F1F42 = b;
        return;
    }
    if (p[0x425] != 0) return;
    s1 = a;
    if (s1 != 0xD) {
        D_004F1F41 = a;
        if (s1 == 0) func_00126470();
    }
    s2 = b;
    if (s2 != 0xD) {
        D_004F1F42 = b;
        if (s2 == 0) func_001264D0();
    }
    if (s1 == 1 || s2 == 1) {
        if (p != 0) func_00126770(p);
    }
}
