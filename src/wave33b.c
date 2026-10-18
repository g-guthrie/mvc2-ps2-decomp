typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_004C2AD4, D_004C2AD0, D_004C2AE4, D_004C2AE0;
void func_003ED2C0(void);
void func_003ED2D0(void);
void func_003E06D0(s32, s32);
void func_003DF850(s32, s32);
void func_003E00D0(s32, s32, s32, s32, s32);
s32 func_003DF7D0(void) {
    D_004C2AD4 = 258;
    D_004C2AD0 = 0x38B032;
    func_003ED2C0();
    func_003E06D0(D_004C2AD0, 0);
    func_003DF850(108, 1);
    func_003DF850(98, 0);
    func_003E00D0(0, 0, D_004C2AE4, D_004C2AE0, 2);
    func_003ED2D0();
    return 1;
}

typedef struct V3 { f32 x, y, z; } V3;
typedef struct N33EF90 { u8 p0[0x10]; void (*fn)(void); u8 p1[0x20]; V3 pos; u8 p2[0x10]; V3 v50; u8 p3[0x28]; s32 w84; u8 p4[0x44]; s16 hcc; u8 p5[2]; s32 wd0; u8 p6[0x68]; u8 b13c; } N33EF90;
extern V3 D_0045F8E0;
extern f32 D_0045F8B0[4];
extern s16 D_0045F880[8];
extern s32 D_004C283C;
N33EF90 *func_003DA750(s32, s32, s32);
void func_0033F030(void);
void func_0033EF90(void) {
    N33EF90 *n = func_003DA750(0, 6, 1);
    if (n) {
        n->b13c = 1;
        n->fn = func_0033F030;
        n->wd0 = 0x811;
        n->hcc = D_0045F880[0];
        n->w84 = D_004C283C;
        n->pos = D_0045F8E0;
        n->v50.x = D_0045F8B0[0];
        n->v50.y = D_0045F8B0[0];
        n->v50.z = D_0045F8B0[0];
    }
}
