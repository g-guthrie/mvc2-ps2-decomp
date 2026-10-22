typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

extern f32 func_00417440(u32);
extern s32 D_004B82A0[];
typedef struct { f32 x, y, z; } V3c;
extern V3c D_004B82B0[];
extern f32 D_004B82C8[];

extern f32 D_00460608[];
typedef struct { f32 x, y, z; } V3;
extern V3 D_004605E0[];

static void func_003421E0(u8 *p)
{
    s32 idx = p[0x20];
    f32 s = func_00417440(((u32)(s32)((double)*(s16 *)(p + 0x1C) * 65536.0 / 360.0 + 0.5) & 0xFFFFu));
    {
        f32 amplitude = D_00460608[idx];
        f32 baseline = D_004605E0[idx].y;
        s = amplitude * s;
        *(f32 *)(p + 0x38) = baseline + s;
    }
    *(s16 *)(p + 0x1C) = (s16)(*(s16 *)(p + 0x1C) + 1);
    if (*(s16 *)(p + 0x1C) >= 360)
        *(s16 *)(p + 0x1C) = 0;
}
static void (*keep_003421E0)(u8 *) = func_003421E0;

typedef struct { u8 pad0[0x1C]; s16 h1C; u8 pad1E[2]; u8 b20; u8 pad21[0x13]; f32 f34; f32 f38; } Pc;

void func_00341170(Pc *p)
{
    f32 s;
    f32 a;
    f32 k;
    f32 t;

    a = 360.0f * (f32)p->h1C / (f32)D_004B82A0[p->b20];
    s = func_00417440(((u32)(s32)((double)a * 65536.0 / 360.0 + 0.5) & 0xFFFFu));
    k = 100.0f;
    k *= s;
    t = D_004B82B0[p->b20].x;
    t += k;
    p->f34 = t;
    p->f38 = D_004B82B0[p->b20].y + (f32)p->h1C * D_004B82C8[p->b20] / (f32)D_004B82A0[p->b20];
    p->h1C = p->h1C + 1;
    if (p->h1C >= D_004B82A0[p->b20])
        p->h1C = 0;
}
