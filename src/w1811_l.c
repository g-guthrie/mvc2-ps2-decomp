typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct G {
    u8 pad0[4];
    s8 b4;
    u8 pad5[3];
    s16 s8;
    u8 pada[4];
    s16 sE;
} G;

extern G *D_004C2840;
extern u16 D_004F4480[];
extern u16 D_004F4494[];
extern f32 D_004F1F4C[];
extern f32 D_004F1F58[];
extern f32 D_004F1F94[];
extern f32 D_004F1FA0[];

void func_003D9FE0(void) {
    extern s32 func_0012E560();
    extern void func_0016F0D0();
    extern void func_0016D190();
    u16 m = 0xFC9F;
    D_004C2840->s8 -= 1;
    D_004F4480[0] &= m;
    D_004F4494[0] &= 0xFC9F;
    if (D_004C2840->s8 == 0x3C) {
        if (func_0012E560() == 0) {
            D_004C2840->s8 += 1;
        } else {
            D_004C2840->b4++;
            D_004C2840->s8 = 0x3C;
            D_004C2840->sE = 2;
        }
    }
    if (D_004C2840->s8 == 0x96) {
        D_004C2840->sE = 1;
    }
    *(V3 *)D_004F1F58 = *(V3 *)D_004F1F4C;
    *(V3 *)D_004F1FA0 = *(V3 *)D_004F1F94;
    func_0016F0D0();
    func_0016D190();
}
