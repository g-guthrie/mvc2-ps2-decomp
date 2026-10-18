typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
void func_00193870(u8 *a, u8 *b) {
    extern f32 func_00417500(s32);
    extern f32 func_00417440(s32);
    extern f32 func_00417D50(f32, f32);
    u8 *s = a + 0x88;
    f32 t;
    s32 k;
    t = func_00417500(*(s32 *)(a + 0x9C));
    k = *(s8 *)(s + 0x1C);
    *(f32 *)(a + 0x5C) = t * func_00417D50(2.0f, (f32)k) / 2.0f;
    t = func_00417440(*(s32 *)(s + 0x14));
    k = *(s8 *)(s + 0x1C);
    *(f32 *)(a + 0x60) = t * func_00417D50(2.0f, (f32)k) / 2.0f;
    *(f32 *)(s + 0) += *(f32 *)(a + 0x5C);
    *(f32 *)(s + 4) += *(f32 *)(a + 0x60);
    *(f32 *)(a + 0x34) = *(f32 *)(s + 0) + *(f32 *)(b + 0x34);
    *(f32 *)(a + 0x38) = *(f32 *)(s + 4) + *(f32 *)(b + 0x38);
}

void func_003BAD60(u8 *p) {
    extern s8 func_00175700();
    extern void func_001757E0();
    extern void func_001E7F60();
    u8 *s = *(u8 **)(p + 0x18);
    f32 m, v;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    m = *(f32 *)(s + 0x430);
    if (!(m <= *(f32 *)(p + 0x38))) {
        *(f32 *)(p + 0x38) = m;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x6C) = 0;
    }
    if (func_00175700(p) < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 0x19, 1);
        *(u32 *)(p + 0x6C) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0xC0092492;
        v = 6.6666665077209473f;
        if (s[0x1E6] == 0) v = -v;
        *(f32 *)(p + 0x5C) = v;
    }
    func_001E7F60(p);
}

void func_001927D0(u8 *o, s32 a1, u8 a2) {
    extern f32 func_00417500(s32);
    extern f32 func_00417440(s32);
    f32 t = 256.0f * (f32)a1;
    s16 ang = ((0x28 - a2) & 0x1F) << 11;
    *(f32 *)(o + 0x34) += 1.6666666269302368f * (t * (1000.0f * func_00417500(ang)) / 100000.0f / 256.0f);
    *(f32 *)(o + 0x38) += 2.1428570747375488f * (t * (1000.0f * func_00417440(ang)) / 125000.0f / 256.0f);
}

extern s16 D_00464B40[];
void func_00389230(u8 *o, u8 *a) {
    s32 t = a[7];
    if (t < 3 || t >= 6) {
        s16 v;
        *(f32 *)(o + 0x38) -= 2.1428570747375488f * (f32)D_00464B40[*(s16 *)(o + 0x1C)];
        v = *(s16 *)(o + 0x1C) - 1;
        *(s16 *)(o + 0x1C) = v;
        if (v < 0) *(s16 *)(o + 0x1C) = 15;
    } else {
        s32 w = a[0x2D0];
        if (w <= 1 || w > 3) {
            *(f32 *)(o + 0x38) -= 10.714284896850586f;
        }
    }
}
