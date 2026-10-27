typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern void func_003CAB00(u8 *, u8 *);
extern void (*const D_004765E0[])(u8 *, u8 *);
void func_003CAAA0(u8 *a, u8 *b) {
    if (a[1] != b[1]) {
        func_003CAB00(a, b);
    } else {
        D_004765E0[a[5]](a, b);
    }
}
