typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0; u8 f1; u8 pad2[0x35]; f32 f38; u8 pad3c[0x110]; u8 f14c; } P125;
extern P125 *D_004C25D4;
extern f32 D_004F1FB8[], D_004F1FF0[], D_004F1FFC[];
extern u8 D_004F1FEC[], D_004F1FF8[];
extern void func_001269F0(u8 *, u8 *);
extern void func_001262C0(s32, s32);
extern void func_00126380(s32, s32);

void func_00125AF0(s32 mode_unused) {
    u32 x = D_004C25D4->f14c;
    f32 f = (f32)x;
    f32 g = 2.142857f * f;
    f32 t;
    if (D_004C25D4->f1 >= 0x18 && D_004C25D4->f1 < 0x1B) g = 0.0f;
    t = D_004C25D4->f38 + g;
    if (t > 350.0f) {
        t -= 350.0f;
        D_004F1FB8[0] = t;
    }
    D_004F1FF0[0] = 95.0f + D_004F1FB8[0];
    func_001269F0(D_004F1FEC, D_004F1FF8);
    D_004F1FFC[0] = D_004F1FF0[0];
    if (D_004C25D4->f1 == 0x1A) {
        func_001262C0(0, 2);
        func_00126380(0, 2);
    } else {
        func_001262C0(0, 4);
        func_00126380(0, 4);
    }
}
