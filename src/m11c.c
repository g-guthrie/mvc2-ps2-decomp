typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_003D7D50(u8 *a, u8 *b, u8 *c) {
    f32 k;
    if (*(u32 *)(a + 0xD0) != 0) {
        if (c[0x20] == 0) k = -33.33333206f; else k = -53.33333206f;
    } else {
        if (c[0x20] == 0) k = -83.33332825f; else k = -53.33333206f;
    }
    if (*(s16 *)(b + 0x140) == 0) {
        *(f32 *)(a + 0x34) = *(f32 *)(c + 0x34) + k;
    } else {
        *(f32 *)(a + 0x34) = *(f32 *)(c + 0x34) - k;
    }
    *(f32 *)(a + 0x38) = *(f32 *)(c + 0x38);
}

extern s32 func_001E1B70();
extern s32 func_00175670();
extern void func_001E1FC0();

void func_001E1A60(u8 *a, u8 *b) {
    if (func_001E1B70(a, b) == 0) {
        f32 v = *(f32 *)(a + 0x64);
        *(f32 *)(a + 0x64) = 15.0f * v / 16.0f;
        if (*(s16 *)(b + 0x140) != 0) v = -v;
        *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34) + v;
        func_00175670(a);
        a[0x159] = 0;
        if (*(s8 *)(b + 0x150) < 0) func_001E1FC0(a, b);
    }
}

extern s32 func_00175700();

void func_0022E2B0(u8 *p) {
    s32 v;
    func_00175700(p);
    v = (s8)p[0x151];
    if (v != 0) {
        f32 k = (p[0x1E6] != 0) ? -133.33332825f : 133.33332825f;
        if ((s8)v < 0) {
            u32 t = p[6];
            p[6] = t + 1;
            k = (p[0x1E6] != 0) ? -80.0f : 80.0f;
        }
        p[0x151] = 0;
        *(f32 *)(p + 0x34) += k;
    }
}
