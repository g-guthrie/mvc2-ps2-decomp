/* MW 3.0.3 (also 3.0): MWWARM@src/sb16_a.c "-O3 -Op -fp off -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_0045EA90[];
extern s32 D_0045EA00[];
extern s32 D_0045EA04[];

typedef struct {
    u8 pad0[0x1C];
    s16 h1c;
    s16 h1e;
} P8d;

void func_0033A590(P8d *p) {
    extern f32 func_00417440(u32);
    extern void func_0033A700(P8d *, s32, s32, f32);
    f32 s;
    s32 a, b;
    s16 h;
    p->h1c++;
    if (p->h1c >= D_0045EA90[p->h1e]) {
        p->h1c = 0;
        p->h1e++;
        if ((u32)p->h1e >= 0x22) p->h1e = 0;
    }
    s = func_00417440((u32)(s32)(0.5 + 65536.0 * (double)(180.0f * ((f32)p->h1c / (f32)D_0045EA90[p->h1e]) - 90.0f) / 360.0) & 0xFFFF);
    s = 0.5f + 0.5f * s;
    h = p->h1e;
    a = D_0045EA00[h];
    if ((u32)(h + 1) >= 0x22) b = D_0045EA00[0];
    else b = D_0045EA04[h];
    func_0033A700(p, a, b, s);
}
