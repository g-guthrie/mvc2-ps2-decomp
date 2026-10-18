typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[5]; u8 b5; u8 pad1[2]; s16 h8; } G2840;
extern G2840 *D_004C2840;
extern s32 D_004C2660;
extern void func_003DA410();
extern void func_003298B0(u32 a, s32 b, s32 c);
extern s32 func_0016C280(s32 a, s32 b, f32 c, f32 d, f32 e, f32 f);
void func_0016BAC0(void) {
    s16 v = D_004C2840->h8 - 1;
    D_004C2840->h8 = v;
    if (v == 0) {
        D_004C2840->b5 = 8;
        D_004C2840->h8 = 0xF0;
        func_003DA410();
        func_003298B0(0xFF000000, 0x20, 0);
        D_004C2660 = func_0016C280(0x915, 6, 0.0f, -80.0f, 1.25f, 1.25f);
    }
}
