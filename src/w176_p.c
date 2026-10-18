typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0; u8 b1; u8 pad[0x36]; f32 f38; u8 pad2[0x14C - 0x3C]; u8 b14C; } G25D0;
extern G25D0 *D_004C25D0;
extern f32 D_004F1FB8[], D_004F1FF0[], D_004F1FFC[], D_004F1FEC[], D_004F1FF8[];

void func_00125C90(void) {
    extern void func_001269F0(f32 *, f32 *);
    extern void func_001262C0(s32, s32);
    extern void func_00126380(s32, s32);
    G25D0 *g = D_004C25D0;
    u32 n = g->b14C;
    f32 f1 = 2.142857074737549f * (f32)n;
    f32 f0;
    if (g->b1 >= 0x18 && g->b1 < 0x1B) f1 = 0.0f;
    f0 = g->f38 + f1;
    if (f0 > 350.0f) {
        f0 -= 350.0f;
        D_004F1FB8[0] = f0;
    }
    D_004F1FF0[0] = 95.0f + D_004F1FB8[0];
    func_001269F0(D_004F1FEC, D_004F1FF8);
    D_004F1FFC[0] = D_004F1FF0[0];
    if (D_004C25D0->b1 == 0x1A) {
        func_001262C0(0, 2);
        func_00126380(0, 2);
    } else {
        func_001262C0(0, 4);
        func_00126380(0, 4);
    }
}
