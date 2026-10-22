typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 p0[4]; s8 b4; u8 p5[0x83]; s8 b88; s8 b89; } G;
extern G *D_004C2840;
extern s8 D_00583BC7[];
extern u8 D_00583B92[];
extern u8 D_00583B93[];
extern s8 D_004F25D4[];
extern s8 D_004F2B8C[];
extern void func_001E3CE0(s32);
extern void func_0032DF90(s32);
extern void func_0012E780(s32);
extern s32 func_00417A40(void);
extern void func_0032E600(void);

void func_0032A210(void) {
    G *g;
    s8 *q;
    s32 x;
    D_004C2840->b4++;
    func_001E3CE0(0x38);
    g = D_004C2840;
    q = &g->b89;
    if (g->b89 & 1) D_00583BC7[0] = 1; else D_00583BC7[0] = 0;
    x = *q | g->b88;
    if (x != 3) {
        if (x == 1) D_00583BC7[0] = 1; else D_00583BC7[0] = 0;
        func_0032DF90(D_00583BC7[0]);
        D_00583B92[D_00583BC7[0]] = 0;
    }
    g = D_004C2840;
    if (g->b88 == 0) {
        if (g->b89 != 3) func_0012E780(D_00583BC7[0] + 0xF);
        else func_0012E780(0x18);
    }
    if (D_00583B92[0] != 7) {
        D_004F25D4[0] = func_00417A40() % 4;
    }
    if (D_00583B93[0] != 7) {
        D_004F2B8C[0] = func_00417A40() % 4;
    }
    func_0032E600();
}
