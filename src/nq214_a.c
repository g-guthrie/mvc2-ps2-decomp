typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 a, b, c, d; } F4_a;
typedef struct {
    u8 pad0[0x20];
    u8 b20, b21, b22;
    u8 pad23[0x50 - 0x23];
    f32 f50;
    u8 pad54[0x68 - 0x54];
    f32 f68, f6c, f70;
    F4_a v74;
    u8 pad84[0x13C - 0x84];
    s8 b13c;
} O_a;

extern s8 D_004D18FA[];
extern s16 D_004D18F6[];
extern F4_a D_0043DFF0[];
extern F4_a D_0043E080[];
extern s16 D_004C278C;
extern s16 D_004C2788;

void func_00132C70(O_a *p)
{
    extern f32 func_00417440(s32);
    s32 s = D_004D18FA[p->b20];
    f32 one;
    if (p->b21 == 0) {
        p->v74 = D_0043DFF0[s];
        p->v74.b *= 1.0f + func_00417440(D_004C278C) / 8.0f;
        p->v74.c *= 1.0f + func_00417440(D_004C278C) / 8.0f;
        p->v74.d *= 1.0f + func_00417440(D_004C278C) / 8.0f;
        if (!(p->v74.b <= 1.0f)) p->v74.b = 1.0f;
        if (!(p->v74.c <= 1.0f)) p->v74.c = 1.0f;
        if (!(p->v74.d <= 1.0f)) p->v74.d = 1.0f;
        p->f50 = (f32)D_004D18F6[p->b20] / 144.0f;
    } else {
        p->b13c = s;
        if (p->b22 != s) {
            p->v74 = D_0043E080[s];
        }
        if (s == 5) {
            p->v74.b = 0.5f + func_00417440(D_004C2788 + (s32)p->f68) / 2.0f;
            p->v74.c = 0.5f + func_00417440(D_004C2788 + (s32)p->f6c) / 2.0f;
            p->v74.d = 0.5f + func_00417440(D_004C2788 + (s32)p->f70) / 2.0f;
        }
        if (!(p->v74.b <= 1.0f)) p->v74.b = 1.0f;
        if (!(p->v74.c <= 1.0f)) p->v74.c = 1.0f;
        if (!(p->v74.d <= 1.0f)) p->v74.d = 1.0f;
    }
    p->b22 = s;
}
