typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s32 func_001853E0(u8 *p) {
    extern void func_00186CE0();
    f32 c = -23.33333206f;
    f32 x, y;
    s32 t;
    *(s16 *)(p + 0x140) = p[0x1E6];
    t = p[0x1E6];
    if (t != 0) c = -c;
    x = *(f32 *)(*(u8 **)(p + 0x220) + 0x34);
    x += c;
    y = *(f32 *)(p + 0x34);
    if (!(x < y) && t != 0) return 0;
    if (x < y && t == 0) return 0;
    if (p[0x20D] == 0) {
        func_00186CE0(p, 8);
        return 1;
    }
    func_00186CE0(p, 9);
    return 1;
}

void func_001EC4F0(u8 *p) {
    extern void func_00175700();
    extern void func_00193090();
    extern void func_001757E0();
    f32 z = 0.0f;
    f32 o;
    p[0x40C] = 2;
    p[0x33C] = 5;
    o = *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (!(o * *(f32 *)(p + 0x60) <= z)) {
        func_00175700(p);
        return;
    }
    {
        u32 t = p[6];
        p[6] = t + 1;
        *(s16 *)(p + 0x1C) = 8;
        func_00193090(p);
        func_001757E0(p, 0x16, 1);
    }
}

void func_0020AD00(u8 *p) {
    extern void func_00175700();
    extern void func_0034FA80();
    extern void func_001757E0();
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (1225.7142333984375f + *(f32 *)(p + 0x430) <= *(f32 *)(p + 0x38)) {
        u32 t = p[7];
        p[7] = t + 1;
        *(s32 *)(p + 0x48) = (*(s32 *)(p + 0x48) + 0x8000) & 0xFFFF;
        *(f32 *)(p + 0x38) = 1032.8570556640625f + *(f32 *)(p + 0x430);
        func_0034FA80(p, 5);
        func_001757E0(p, 0x13, 5);
    }
}

void func_00279370(u8 *p) {
    extern void func_00175700();
    extern void func_0037EA30();
    u32 a;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_0037EA30(p, p, p[0x1B7]);
    }
    a = *(u16 *)(p + 0x160);
    if (a != 0) {
        if (*(s16 *)(p + 0x140) == 0) {
            *(f32 *)(p + 0x34) += 1.6666666269302368f * (f32)(s16)a;
        } else {
            *(f32 *)(p + 0x34) -= 1.6666666269302368f * (f32)(s16)a;
        }
        *(s16 *)(p + 0x160) = 0;
    }
}

void func_00396510(u8 *a, u8 *b) {
    extern void func_00175700();
    f32 c = 182.14285278320312f;
    u32 t;
    func_00175700(a);
    *(f32 *)(a + 0x34) += *(f32 *)(a + 0x5C);
    *(f32 *)(a + 0x5C) += *(f32 *)(a + 0x68);
    *(f32 *)(a + 0x38) += *(f32 *)(a + 0x60);
    *(f32 *)(a + 0x60) += *(f32 *)(a + 0x6C);
    if (!(c + *(f32 *)(b + 0x430) <= *(f32 *)(a + 0x38))) {
        t = a[5];
        a[5] = t + 1;
        *(f32 *)(a + 0x38) = c + *(f32 *)(b + 0x430);
        *(f32 *)(a + 0x5C) = *(f32 *)(a + 0x5C) / 2.0f;
        *(u32 *)(a + 0x60) = 0x40092492;
    }
}

void func_001563A0(u8 *p) {
    extern void func_00156480();
    f32 c = 0.125f;
    func_00156480(p);
    *(f32 *)(p + 0x50) += c;
    *(f32 *)(p + 0x54) += c;
    if (p[5] == 0) {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v < 0) {
            u32 t = p[5];
            p[5] = t + 1;
        }
    } else {
        f32 d = 0.05000000074505806f;
        f32 z = 0.0f;
        f32 x;
        *(f32 *)(p + 0x78) -= d;
        *(f32 *)(p + 0x7C) -= d;
        x = *(f32 *)(p + 0x80) - d;
        *(f32 *)(p + 0x80) = x;
        if (x < z) {
            u32 t = p[4];
            p[4] = t + 1;
            p[0x13C] = 0;
        }
    }
}
