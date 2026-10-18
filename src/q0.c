typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef signed long long s64;
typedef unsigned long long u64;

/* Recipe 2: static leaf with a real body so the compiler tracks its register footprint. */
static void func_001BF550(u8 *p) { p[0] = 1; }
void func_001BF860(u8 *p) {
    if (*(s16 *)(*(u8 **)(p + 0x18) + 0x1C) <= 0) {
        u32 t = p[5]; p[5] = t + 1;
        *(s16 *)(p + 0x1C) = 10;
        *(f32 *)(p + 0x54) = 1.0f;
    }
    func_001BF550(p);
}

extern s32 D_004BEDA0[];
s32 func_004166F0(u8 *p) {
    s32 x = *(u8 *)(*(u8 **)(p + 8) + 0x13);
    s32 r;
    if (x > 5) r = 0; else r = D_004BEDA0[(u8)x];
    return r;
}

static s32 func_00416770(s32 *p) { return p[0] + 1; }
s32 func_004167A0(s32 *p, s32 b, s32 n) {
    s32 r = func_00416770(p);
    return p[4] + r + n * p[3];
}

static u8 *func_003F1F90(s32 a, s32 b, s32 c, s32 d) { return (u8 *)(a + b); }
u8 *func_003F2510(s32 a, s32 n, s32 c) {
    u8 *r = func_003F1F90(a, 0x1000, c, n);
    u8 *q = r + 12;
    if (r == 0) return 0;
    return q + n * 12;
}

u16 func_00220260(s32 a, s32 b) {
    u16 t = b & 0x3C00;
    u16 hi = (t & 0x3000) / 0x1000;
    u16 lo = (t & 0xC00) / 0x100;
    hi |= lo;
    return hi;
}
