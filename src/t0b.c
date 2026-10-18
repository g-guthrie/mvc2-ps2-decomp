typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_003742B0(u8 *p) {
    s16 v;
    u32 t;
    *(f32 *)(p + 0x50) += 0.012000000104308128f;
    *(f32 *)(p + 0x54) -= 0.017999999225139618f;
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v <= 0) {
        t = p[6];
        p[6] = t + 1;
        *(s16 *)(p + 0x1C) = 5;
    }
}
extern int func_00175700(u8 *p);
extern void func_001757E0(u8 *p, s32 a, s32 b);
extern void func_003589A0(u8 *p, s32 a, f32 b, f32 c);
extern void func_001E3210(u8 *p, u8 a);
void func_0022BFB0(u8 *p) {
    u32 t;
    s16 v;
    s32 k;
    func_00175700(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 0xF, 1);
    } else {
        if (*(s8 *)(p + 0x150) != 0) {
            p[0x150] = 0;
            func_003589A0(p, 2, 29.0f, 100.0f);
        }
        if (*(s8 *)(p + 0x151) != 0) {
            p[0x151] = 0;
            k = 0x14;
            if (*(u32 *)(p + 0x2D0) != 0) k = 0x16;
            func_001E3210(p, k);
        }
    }
}
s32 func_00165180(u8 *p) {
    f32 z = 0.0f;
    f32 d;
    s32 m;
    if (p[0x1E4] == *(u32 *)(p + 0x468)) {
        if (p[0x454] == 0x13 || (m = *(s8 *)(p + 0x211)) == 0 || (m & (1 << p[0x1E6])) == 0) {
            d = *(f32 *)(p + 0x34) - *(f32 *)(p + 0x464);
            if (d < z) d = -d;
            *(f32 *)(p + 0x460) -= d;
            if (*(f32 *)(p + 0x460) > z) {
                *(f32 *)(p + 0x464) = *(f32 *)(p + 0x34);
                *(s16 *)(p + 0x4F0) = *(s16 *)(p + 0x46C);
                p[0x1E7] = 1;
                return 0;
            }
        }
    }
    p[0x451]--;
    *(s16 *)(p + 0x4F0) = 0;
    return 1;
}
