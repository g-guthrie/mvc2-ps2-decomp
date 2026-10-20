typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef signed long long s64;
typedef unsigned long long u64;

extern u8 *D_004C2704;
static void func_001BF550(u8 *p) {
    if (*D_004C2704 < 11) {
        s16 t = *(s16 *)(p + 0x1E) - 1;
        *(s16 *)(p + 0x1E) = t;
        if (t <= 0) {
            u32 c;
            *(s16 *)(p + 0x1E) = 1;
            c = *D_004C2704;
            *D_004C2704 = c + 1;
            *(f32 *)(p + 0x34) += 53.333332f;
        }
    }
}
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

extern const s32 D_004BEDC0[];
static s32 func_00416770(void *owner, s32 scale) {
    s32 factor = D_004BEDC0[((s32 *)owner)[5]];
    return (scale * factor) >> 3;
}
s32 func_004167A0(s32 *p, s32 b, s32 n) {
    s32 r = func_00416770(p, b);
    return p[4] + r + n * p[3];
}

static u32 *func_003F1F90(u32 *p, u32 key)
{
    u32 *e = p;
    u32 i;
    if (p[0] & key) {
        e += 3;
        for (i = 0; i < p[1]; i++) {
            if (e[0] == key) return e;
            e = (u32 *)((u8 *)e + e[2]);
        }
    }
    return 0;
}

u8 *func_003F2510(s32 a, s32 n, s32 c) {
    u8 *r = (u8 *)func_003F1F90((u32 *)a, 0x1000);
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
