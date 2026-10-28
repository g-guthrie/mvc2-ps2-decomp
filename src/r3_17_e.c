typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern V3 D_0043E2B0[];
extern f32 D_0043E314, D_0043E318, D_0043E31C;
extern f32 D_0043E324, D_0043E328, D_0043E32C;
extern s8 D_004D18D6[];

void func_00133510(u8 *p) {
    extern f32 func_00417500(s32);
    u8 *s;
    u8 t;
    s32 c;
    s32 i;
    s = *(u8 **)(p + 0x18);
    t = s[0x425];
    if (p[0x21] != t) {
        i = s[2];
        i = (t << 1) + i;
        *(V3 *)(p + 0x5C) = D_0043E2B0[i];
        p[0x21] = t;
        *(s16 *)(p + 0x1C) = 0x20;
        *(s16 *)(p + 0x1E) = 0;
    }
    c = *(s16 *)(p + 0x1C);
    if (c != 0) {
        if (((c << 16) >> 16) == 0x10) {
            *(s16 *)(p + 0x1E) += -0x8000;
            *(V3 *)(p + 0x34) = *(V3 *)(p + 0x5C);
        }
        *(f32 *)(p + 0x50) = func_00417500(*(s16 *)(p + 0x1E));
        *(s16 *)(p + 0x1C) -= 1;
        *(s16 *)(p + 0x1E) += 0x400;
    }
    *(f32 *)(p + 0x78) = D_0043E314;
    *(f32 *)(p + 0x7C) = D_0043E318;
    *(f32 *)(p + 0x80) = D_0043E31C;
    if (*(s16 *)(s + 0x2B4) != 0) {
        *(f32 *)(p + 0x78) = D_0043E324;
        *(f32 *)(p + 0x7C) = D_0043E328;
        *(f32 *)(p + 0x80) = D_0043E32C;
    }
    if (s[0x1F0] == 0 && *(s16 *)(s + 0x434) <= 0) p[0x13C] = 0;
    if (*(s8 *)(p + 0x13C) != 0) {
        if (s[0x1F0] != 0 && s[0] == 0) {
            if (D_004D18D6[s[2]] >= 3 && s[0x425] == 0) {
                *(u32 *)(p + 0x74) = 0x3F800000;
            } else {
                f32 z = 0.0f;
                f32 v;
                *(f32 *)(p + 0x74) -= 0.03125f;
                v = *(f32 *)(p + 0x74);
                if (v < z) {
                    p[0x13C] = 0;
                    *(f32 *)(p + 0x74) = z;
                }
            }
        }
    } else if (s[0x1F0] == 0 && *(s16 *)(s + 0x434) > 0) {
        p[0x13C] = 1;
        *(u32 *)(p + 0x74) = 0x3F800000;
    }
}
