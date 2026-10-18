typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x7C]; s16 v[1]; } G0;
extern G0 *D_004C2794;
extern s32 D_004C1740[1], D_004C1744[1], D_004C1748[1];
typedef struct {
    u8 p0[2]; u8 b2; u8 p3[0x1AF]; u8 b1b2; u8 p1b3[2]; u8 b1b5; u8 p1b6[5]; u8 b1bb; u8 p1bc[4];
    u16 h1c0; u8 p1c2[0x16]; u32 w1d8; u8 p1dc[0xE]; s8 b1ea; u8 p1eb[0x11]; u8 b1fc; u8 p1fd[0x20B]; s32 *w408;
} P;
void func_0031BF20(P *a, s32 b) {
    extern void func_001E3210(P *, s32);
    extern void func_001757E0(P *, s32, u8);
    s32 x;
    s32 s;
    s8 y;
    switch (a->b1fc) {
    case 0:
        x = 0xC; s = 0; a->w408 = D_004C1740; b = 0x1E; a->b1bb = 0;
        break;
    case 1:
        x = 0xD; s = 1; a->w408 = D_004C1744; b = 0x1F; a->b1bb = 1;
        break;
    case 2:
        x = 0xE; s = 2; a->w408 = D_004C1748; b = 0x20; a->b1bb = 2;
        break;
    }
    a->b1b5 = x;
    a->b1b2 = a->h1c0 = 0;
    a->w1d8 = 0;
    D_004C2794->v[a->b2]++;
    func_001E3210(a, b & 0xFF);
    func_001757E0(a, 0xB, s);
    y = a->b1ea;
    if ((y & 0xF) != 0) a->b1ea = y - 1;
}
