typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 t[8]; } G_F4A0;
extern G_F4A0 *D_004C2794;
typedef struct { u8 p0[2]; u8 b2; u8 p3[3]; u8 b6; u8 p7[0x15]; s16 h1c; u8 p1e[0x1A]; f32 f38; u8 p3c[0x20]; s32 w5c, w60; u8 p64[4]; s32 w68, w6c; u8 p70[0x142]; u8 b1b2; u8 p1b3[2]; u8 b1b5; u8 p1b6[0xA]; u16 h1c0; u8 p1c2[0x16]; s32 w1d8; u8 p1dc[0x31]; u8 b20d; u8 p20e[0x222]; f32 f430; } S_F4A0;

void func_0027EA20(S_F4A0 *p)
{
    extern int func_001757E0(void *, int, int);
    u32 t = p->b6;
    p->b6 = t + 1;
    p->b20d = 0;
    p->b1b5 = 0x38;
    p->b1b2 = p->h1c0 = 0;
    p->w1d8 = 0;
    D_004C2794->t[p->b2] += 1;
    func_001757E0(p, 0x15, 5);
    p->w5c = 0;
    p->w60 = 0;
    p->w68 = 0;
    p->w6c = 0;
}
