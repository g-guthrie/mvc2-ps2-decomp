typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

typedef struct { f32 x, y, z; } V3b;
typedef struct { u8 pad[0xB4]; } Eb;
typedef struct { u8 pad[0x14]; Eb *f14; } Gb;

extern s16 D_004C2788;
extern s16 D_004C2790;
extern Gb *D_004C2834;
extern s8 D_004D18FA[];
extern V3b D_0043E988[];
extern f32 D_0043E9A4[];
extern f32 D_0043E9A8[];
extern f32 D_0043E9AC[];
extern f32 D_0043E9B4[];
extern f32 D_0043E9B8[];
extern f32 D_0043E9BC[];
extern f32 func_00417440(s32);
extern s32 fptosi(f32);

void func_00134EA0(u8 *p)
{
    s32 s0;
    f32 t;
    f32 a, lo;

    s0 = D_004D18FA[p[0x20]];
    if (s0 >= 5) s0 = 5;
    if (s0 >= 5) {
        *(f32 *)(p + 0x50) = *(f32 *)(p + 0x54) = (f32)(1.25 + (f64)(func_00417440(D_004C2788) / 16.0f));
    } else {
        *(V3b *)(p + 0x50) = D_0043E988[0];
    }
    if (s0 >= 5) {
        *(f32 *)(p + 0x78) = (f32)(0.5 + (f64)(func_00417440(D_004C2788 + fptosi(*(f32 *)(p + 0x68))) / 2.0f));
        *(f32 *)(p + 0x7C) = (f32)(0.5 + (f64)(func_00417440(D_004C2788 + fptosi(*(f32 *)(p + 0x6C))) / 2.0f));
        *(f32 *)(p + 0x80) = (f32)(0.5 + (f64)(func_00417440(D_004C2788 + fptosi(*(f32 *)(p + 0x70))) / 2.0f));
    } else {
        t = (f32)(0.5 + (f64)(func_00417440(D_004C2790) / 2.0f));
        lo = *(volatile f32 *)D_0043E9B4; a = D_0043E9A4[0] - lo; a *= t;
        *(f32 *)(p + 0x78) = lo + a;
        lo = *(volatile f32 *)D_0043E9B8; a = D_0043E9A8[0] - lo; a *= t;
        *(f32 *)(p + 0x7C) = lo + a;
        lo = *(volatile f32 *)D_0043E9BC; a = D_0043E9AC[0] - lo; t = a * t;
        *(f32 *)(p + 0x80) = lo + t;
    }
    if (s0 >= 5) s0 = 9;
    *(Eb **)(p + 0x84) = D_004C2834->f14 + (s0 + 0x60);
    *(s16 *)(p + 0xCC) = s0 + 0x60;
    *(Gb **)(p + 0x84) = D_004C2834;
}
