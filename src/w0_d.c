typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

static s32 func_003F1FF0(s32 *a) { s32 x = a[2]; s32 y = a[3]; s32 z = a[4]; s32 w = a[5]; s32 u = a[6]; s32 t = a[7]; s32 r = a[8]; s32 q = a[9]; return x * y + z * w + u * t + r * q; }
static s32 func_003F2060(s32 *a, s32 i) { s32 x = a[i]; s32 y = a[i + 1]; s32 z = a[i + 2]; s32 w = a[i+3]; s32 u = a[i+4]; s32 t = a[i+5]; return x * y + z * w + u * t; }
s32 func_003F3700(s32 *a) {
    s32 i, n, v;
    n = func_003F1FF0(a);
    v = func_003F2060(a, 0);
    i = 1;
    if (n > 1) do { if (func_003F2060(a, i) != v) return 1; i++; } while (i < n);
    return 0;
}
