typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 D_004F1D20;
extern s32 D_004F1D24;
extern f32 D_004F1D2C;
extern u8 D_004F1D29, D_004F1D2A, D_004F1D2B;
extern f32 D_004F1D0C, D_004F1D10, D_004F1D14;

void func_0016D2A0(void)
{
    extern f32 func_003DE780(f32, f32);
    extern s32 func_00119098(f32);
    extern void func_003DF850(s32, s32);
    extern void func_0016D460(void);
    volatile f32 v[2];
    s32 *q;
    f32 pw;
    s32 c;
    s32 r;

    if (D_004F1D20 != 0) {
        pw = func_003DE780(2.0f, (f32)(D_004F1D24 >> 4));
        c = D_004F1D24;
        v[0] = D_004F1D2C / ((f32)((c & 0xF) + 0x10) * pw / 16.0f);
        v[1] = D_004F1D2C;
        c = ((c & 0xFF) << 24) | ((u8)func_00119098(D_004F1D0C * (f32)(u32)D_004F1D29) << 16);
        r = (u8)func_00119098(D_004F1D10 * (f32)(u32)D_004F1D2A);
        c = (r << 8) | c;
        r = (u8)func_00119098(D_004F1D14 * (f32)(u32)D_004F1D2B);
        func_003DF850(0xF, r | c);
        func_003DF850(0x10, *(q = (s32 *)v));
        func_003DF850(0x11, *(q = (s32 *)&v[1]));
    } else {
        func_0016D460();
    }
}
