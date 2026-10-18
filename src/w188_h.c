typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks 3.0 (older): ./try30.sh src/w188_h.c "-O3 -sdatathreshold 0" */

extern s8 D_004D1900;
typedef struct { u8 pad[0x1C]; s16 h1C; } H_0015C740;
void func_0015C740(u8 *a) {
    s32 v;
    extern void func_0015C8B0(u8 *, s32);
    extern void func_0015CD30(u8 *, s32);
    extern void func_0015C9D0(u8 *, s32);
    extern void func_0015CED0(u8 *, s32, s32);
    extern void func_0015CAF0(u8 *, s32);
    extern void func_0015CC10(u8 *, s32);
    extern void func_003DAA40(u8 *);
    switch (*(s16 *)(a + 0x1C)) {
    case 0:
        func_0015C8B0(a, a[0x23]);
        func_0015CD30(a, a[0x23]);
        break;
    case 3:
        func_0015C9D0(a, a[0x23]);
        break;
    case 4:
        func_0015CED0(a, 0, a[0x23]);
        break;
    case 6:
        func_0015CAF0(a, a[0x23]);
        func_0015CED0(a, 1, a[0x23]);
        break;
    case 7:
        func_0015CED0(a, 3, a[0x23]);
        break;
    case 9:
        func_0015CC10(a, a[0x23]);
        break;
    case 10:
        func_0015CED0(a, 2, a[0x23]);
        break;
    case 12:
        func_0015CED0(a, 5, a[0x23]);
        break;
    case 14:
        func_0015CED0(a, 4, a[0x23]);
        break;
    }
    v = *(s16 *)(a + 0x1C);
    if (v > 0x12) {
        func_003DAA40(a);
        D_004D1900--;
    } else {
        ((H_0015C740 *)a)->h1C = v + 1;
    }
}
