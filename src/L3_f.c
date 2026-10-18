typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *(*D_004C2B0C)(s32);
extern s32 func_00119098(f32);

/* local stand-ins: real bodies keep the temporaries out of the caller's way */
static s32 func_003F1FF0(a, i, j, k) u8 *a; s32 i, j, k; {
    a = *(u8 **)(a + 4); i = *(s32 *)(a + 8); j = *(s32 *)(a + 12) + i; k = *(s32 *)(a + 16) ^ j;
    return *(s32 *)(a + k) + i + j;
}
static s32 func_003F3700(a, i, j, k) u8 *a; s32 i, j, k; {
    a = *(u8 **)(a + 4); i = *(s32 *)(a + 8); j = *(s32 *)(a + 12) + i; k = *(s32 *)(a + 16) ^ j;
    return *(s32 *)(a + k) + i + j;
}
static s32 func_003F20A0(a, i, j, k) u8 *a; s32 i, j, k; {
    s32 b = *(s32 *)(a + 4), c = *(s32 *)(a + 8);
    *(s32 *)(a + 28) = i; *(s32 *)(a + 32) = b; *(s32 *)(a + 36) = c;
    a = *(u8 **)(a + c); i += b; j += c; k += i;
    return *(s32 *)(a + i) ^ (j + k);
}
static s32 func_003F21F0(a, i, j, k) u8 *a; s32 i, j, k; {
    s32 b = *(s32 *)(a + 4), c = *(s32 *)(a + 8);
    *(s32 *)(a + 28) = i; *(s32 *)(a + 32) = b; *(s32 *)(a + 36) = c;
    a = *(u8 **)(a + c); i += b; j += c; k += i;
    return *(s32 *)(a + i) ^ (j + k);
}
static s32 func_003F2060(a, i, j, k) u8 *a; s32 i, j, k; {
    a = *(u8 **)(a + 4); i = *(s32 *)(a + 8); j = *(s32 *)(a + 12) + i; k = *(s32 *)(a + 16) ^ j;
    return *(s32 *)(a + k) + i + j;
}
static s32 func_003F2350(a, i, j, k) u8 *a; s32 i, j, k; {
    s32 b = *(s32 *)(a + 4), c = *(s32 *)(a + 8), d = *(s32 *)(a + 12);
    *(s32 *)(a + 28) = i; *(s32 *)(a + 32) = b; *(s32 *)(a + 36) = c;
    a = *(u8 **)(a + c); i += b; j += d; k += i;
    return *(s32 *)(a + i) ^ (c - d) ^ (j + k);
}
static s32 func_003F2030(a, i, j, k) u8 *a; s32 i, j, k; {
    a = *(u8 **)(a + 4); i = *(s32 *)(a + 8); j = *(s32 *)(a + 12) + i; k = *(s32 *)(a + 16) ^ j;
    return *(s32 *)(a + k) + i + j;
}
static f32 * func_003F24D0(a, i, j, k) u8 *a; s32 i, j, k; {
    a = *(u8 **)(a + 4); i = *(s32 *)(a + 8); j = *(s32 *)(a + 12) + i; k = *(s32 *)(a + 16) ^ j;
    return (f32 *)(a + k + i + j);
}
static f32 * func_003F2510(a, i, j, k) u8 *a; s32 i, j, k; {
    a = *(u8 **)(a + 4); i = *(s32 *)(a + 8); j = *(s32 *)(a + 12) + i; k = *(s32 *)(a + 16) ^ j;
    return (f32 *)(a + k + i + j);
}
static f32 * func_003F2550(a, i, j, k) u8 *a; s32 i, j, k; {
    a = *(u8 **)(a + 4); i = *(s32 *)(a + 8); j = *(s32 *)(a + 12) + i; k = *(s32 *)(a + 16) ^ j;
    return (f32 *)(a + k + i + j);
}
static f32 * func_003F2590(a, i, j, k) u8 *a; s32 i, j, k; {
    a = *(u8 **)(a + 4); i = *(s32 *)(a + 8); j = *(s32 *)(a + 12) + i; k = *(s32 *)(a + 16) ^ j;
    return (f32 *)(a + k + i + j);
}

s32 func_003F2EB0(u8 *p, u8 *src) {
    s32 i;
    u16 *w;
    s32 n;
    s32 sum;
    s32 j;
    s32 cnt;
    s32 sz;
    f32 *c;
    s32 k;
    u8 *r;
    f32 *v;
    s32 m;
    u8 *q;
    *(u32 *)p = 0x21000;
    *(s32 *)(p + 4) = func_003F1FF0(src);
    if (func_003F3700(src) == 1) *(u32 *)p |= 0x400000;
    sum = 0;
    for (i = 0; i < *(s32 *)(p + 4); i++) sum += func_003F20A0(src, i);
    cnt = *(s32 *)(p + 4);
    sz = (cnt + sum) * 2;
    if (*(u32 *)p & 0x400000) sz += cnt * 2;
    r = D_004C2B0C(sz);
    *(u8 **)(p + 8) = r;
    if (r == 0) return 0;
    *(s32 *)(p + 0x1C) = sz;
    w = *(u16 **)(p + 8);
    for (j = 0; j < *(s32 *)(p + 4); j++) {
        n = func_003F20A0(src, j);
        *w = n;
        if (func_003F21F0(src, j)) *w |= 0x8000;
        else *w |= 0x4000;
        w++;
        if (*(u32 *)p & 0x400000) {
            *w = func_003F2060(src, j);
            w++;
        }
        if (*(u32 *)p & 0x1000) {
            for (k = 0; k < n; k++) {
                *w = func_003F2350(src, j, k);
                w++;
            }
        }
    }
    *(s32 *)(p + 0xC) = 0x35;
    *(s32 *)(p + 0x14) = func_003F2030(src);
    sz = *(s32 *)(p + 0x14) * 36;
    r = D_004C2B0C(sz);
    *(u8 **)(p + 0x10) = r;
    if (r == 0) return 0;
    *(s32 *)(p + 0x18) = sz;
    q = *(u8 **)(p + 0x10);
    for (m = 0; m < *(s32 *)(p + 0x14); m++) {
        v = func_003F24D0(src, m);
        *(f32 *)(q + 0) = v[0];
        *(f32 *)(q + 4) = v[1];
        *(f32 *)(q + 8) = v[2];
        v = func_003F2510(src, m);
        *(f32 *)(q + 0xC) = v[0];
        *(f32 *)(q + 0x10) = v[1];
        *(f32 *)(q + 0x14) = v[2];
        v = func_003F2550(src, m);
        *(f32 *)(q + 0x1C) = v[0];
        *(f32 *)(q + 0x20) = v[1];
        c = func_003F2590(src, m);
        *(u32 *)(q + 0x18) = (func_00119098(c[3]) << 24) | (func_00119098(c[0]) << 16) | (func_00119098(c[1]) << 8) | func_00119098(c[2]);
        q += 0x24;
    }
    return 1;
}
