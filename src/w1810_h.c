typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x7C]; s16 v[1]; } G0;
extern G0 *D_004C2794;
typedef struct {
    u8 p0[2]; u8 b2; u8 p3[3]; u8 b6; u8 p7[0x2D]; f32 f34; u8 p38[0x24]; f32 f5c; u8 p60[8]; f32 f68;
    u8 p6c[0xE5]; s8 b151; u8 p152[0xE]; s8 b[8]; u8 p168[0x4A]; u8 b1b2; u8 p1b3[2]; u8 b1b5; u8 p1b6[0xA];
    u16 h1c0; u8 p1c2[0x16]; u32 w1d8; u8 p1dc[0x160]; u8 b33c;
} P;
void func_001F4350(P *a) {
    extern void func_001830D0(P *, f32 *, s32);
    extern s32 func_00175700(P *);
    extern void func_001757E0(P *, s32, s32);
    f32 v[4];
    s8 *p;
    s8 *q;
    s8 f;
    p = a->b;
    f = p[1];
    q = p + 1;
    if (f != 0) {
        *q = 0;
        v[0] = -40.0f;
        v[1] = 154.28570556640625f;
        func_001830D0(a, v, 1);
        return;
    }
    a->b33c = 5;
    if (a->b151 == 1) {
        a->b151 = 0;
        a->b1b5 = 0x37;
        a->b1b2 = a->h1c0 = 0;
        a->w1d8 = 0;
        D_004C2794->v[a->b2]++;
    }
    if (a->b151 == 2) {
        a->b151 = 0;
        a->b1b5 = 0x38;
        a->b1b2 = a->h1c0 = 0;
        a->w1d8 = 0;
        D_004C2794->v[a->b2]++;
    }
    a->f34 += a->f5c;
    a->f5c += a->f68;
    if ((s8)func_00175700(a) < 0) {
        a->b6++;
        func_001757E0(a, 0x18, 4);
    }
}
