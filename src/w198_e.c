typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

typedef struct { u8 b0, b1, b2, b3, b4, b5, b6, b7; s16 h8, hA, hC, hE; u8 pad10[4]; s32 w14; s8 b18; u8 pad19[0x83]; s8 f9c; } G840;

typedef struct { u8 pad[0x5B8]; } E20;
extern E20 D_004F20B0[];
extern G840 *D_004C2840;

extern u8 D_004F2580[], D_004F2B38[], D_004F258C[], D_004F2B44[];

void func_001294D0(void) {
    extern s32 func_003299D0();
    extern void func_0011D8F8(void *, s32, s32);
    extern void func_00173F90(void *);
    extern void func_001E4150();
    s8 i;
    s32 off;
    s8 *g;
    if (func_003299D0() != 0) return;
    D_004C2840->b0 = 2;
    D_004C2840->b1 = 0;
    D_004C2840->b2 = 0;
    D_004C2840->b3 = 0;
    D_004C2840->b4 = 0;
    D_004C2840->b5 = 0;
    D_004C2840->b6 = 0;
    D_004C2840->b7 = 0;
    D_004C2840->h8 = 0;
    D_004C2840->hA = 0;
    D_004C2840->hC = 0;
    D_004C2840->hE = 0;
    D_004C2840->w14 = 0x60;
    for (i = 0, off = 0; i < 6; i++, off += 0x5B8) {
        u8 *e = (u8 *)D_004F20B0 + off;
        func_0011D8F8(e, 0, 0x5B8);
        e[0x538] = i;
        func_00173F90(e);
    }
    g = &D_004C2840->b18;
    if (*g & 1) D_004F2580[0] = 1;
    if (*g & 2) D_004F2B38[0] = 1;
    D_004F258C[0] = 1;
    D_004F2B44[0] = 2;
    func_001E4150();
}
