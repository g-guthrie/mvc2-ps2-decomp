#pragma opt_lifetimes off
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;
typedef float f32;
typedef struct { f32 a, b; } S2;

extern s32 D_0062BF8C;
extern s32 D_0062BF90;
extern s32 D_0062BF88;
extern s32 D_0062BF84;
extern s32 D_0062BC00;
extern f32 D_0062BC30;
extern s32 fptosi(f32);
extern u32 func_00119098(f32);

#define F(o) (*(f32 *)(s + (o)))
#define W(o) (*(u32 *)(s + (o)))

#define XYZ0(z) \
    zf = -0.5f * (F(z) - 1.0f) * D_0062BC30; \
    xy = (fptosi((f32)D_0062BF84 + xf) << 4); \
    xy |= (u64)(fptosi((f32)D_0062BF88 + yf) << 4) << 16; \
    { u64 hi = (u64)func_00119098(zf) << 32; p[2] = hi | xy; }
#define XYZ1(k, z) \
    xy = (u64)(fptosi((f32)D_0062BF88 + yf) << 4) << 16; \
    { s32 lo = fptosi((f32)D_0062BF84 + xf) << 4; xy = lo | xy; } \
    { u64 hi = (u64)func_00119098(-0.5f * (F(z) - 1.0f) * D_0062BC30) << 32; p[(k) * 3 + 2] = hi | xy; }
#define VERT(k, col, sc, u0, u1, x, y, z) \
    c = func_003E0CB0(W(col), 0); \
    p[(k) * 3] = (u64)((c >> 16) & 0xFF) | ((u64)((c >> 8) & 0xFF) << 8) | ((u64)(c & 0xFF) << 16) | ((u64)((c >> 24) & 0xFF) << 24) | ((u64)W(sc) << 32); \
    { u32 *ua = (u32 *)&uu; u32 *ub = (u32 *)&vv; \
    uu = F(u0) * F(sc); \
    vv = F(u1) * F(sc); \
    p[(k) * 3 + 1] = *ua | ((u64)*ub << 32); } \
    xf = F(x) - (f32)D_0062BF8C; \
    if (D_0062BC00 == 0) yf = 0.5f * (F(y) - (f32)D_0062BF90); \
    else yf = F(y) - (f32)D_0062BF90;

static s32 func_00420A00(s32 *p)
{
    s32 x = p[2];
    return (s32)((u8 *)p[4] + (x << 3) + 16);
}

s32 func_00420BF0(u8 *b, u8 *s) {
    extern s32 func_00420A20();
    extern u32 func_003E0CB0(u32, s32);
    u64 xy;
    u64 *p;
    f32 uu, vv;
    u32 c;
    p = (u64 *)func_00420A00((s32 *)b);
    if (func_00420A20(b, 12) == 0) return 0;
    { f32 zf, yf, xf;
    VERT(0, 0x30, 0xC, 0x3C, 0x40, 0x0, 0x4, 0x8)
    XYZ0(0x8)
    }
    { f32 xf, yf, zf;
    VERT(1, 0x34, 0x1C, 0x44, 0x48, 0x10, 0x14, 0x18)
    XYZ1(1, 0x18)
    }
    { f32 xf, yf, zf;
    VERT(2, 0x38, 0x2C, 0x4C, 0x50, 0x20, 0x24, 0x28)
    XYZ1(2, 0x28)
    }
    { f32 xf, yf, zf;
    VERT(3, 0x8C, 0x80, 0xA0, 0xA4, 0x74, 0x78, 0x7C)
    XYZ1(3, 0x7C)
    }
    *(u32 *)(b + 0xC) = *(u32 *)(b + 0xC) + 1;
    return 1;
}
