typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;
typedef signed long long s64;
typedef float f32;

typedef struct { u8 p0[4]; u32 f4; u8 p8[0xA]; s16 f12; s16 f14; s16 f16; s16 f18; s16 f1A; u32 f1C; u8 p20[0x20]; } E32;
extern E32 D_006207A0[];
extern E32 D_0061C7A0[];

s32 func_003E0DB0(u32 a0, u64 *o1, u64 *o2, u32 fl) {
    E32 *e, *e2;
    s16 t, w;
    u32 i, m;
    u64 v;
    i = a0 & 0xFFFF;
    e = &D_006207A0[i - 1];
    if (i == 0) return 0;
    w = e->f12;
    if (w == 0) return 0;
    t = e->f18 / 64;
    if (t == 0) t = 1;
    if (e->f4 & 4) {
        e2 = &D_0061C7A0[((a0 & 0xFFFF0000) >> 16) - 1];
        v = (u64)(s64)w | ((u64)(s64)t << 14) | ((u64)e->f1C << 20) | ((u64)(s64)e->f14 << 26) | ((u64)(s64)e->f16 << 30) | ((u64)4 << 32) | ((u64)(s64)e2->f12 << 37) | ((u64)e2->f1C << 51) | ((u64)0x40000000 << 32);
        *o1 = v;
    } else {
        v = (u64)(s64)w | ((u64)(s64)t << 14) | ((u64)e->f1C << 20) | ((u64)(s64)e->f14 << 26) | ((u64)(s64)e->f16 << 30) | ((u64)4 << 32);
        *o1 = v;
    }
    m = fl & 0x60000;
    switch (m) {
    case 0:
        *o2 = 0;
        break;
    case 0x20000:
    default:
        *o2 = ((u64)(s64)e->f18 << 14) | 0xA | ((u64)(s64)e->f1A << 34);
        break;
    }
    return 1;
}
