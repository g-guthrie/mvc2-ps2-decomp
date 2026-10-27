typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u8 D_004F1F45, D_004F1F46;
extern u8 D_004F1F45, D_004F1F46;
void func_002CFDB0(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_002CFA20(u8 *);
    extern void func_001CFE00(u8 *, s32);
    extern void func_002D0130(u8 *);
    s16 h, g;
    u32 t;
    s32 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        h = *(s16 *)(p + 0x1E) - 1;
        *(s16 *)(p + 0x1E) = h;
        if (h < 0) {
            g = *(s16 *)(p + 0x1C);
            *(s16 *)(p + 0x1E) = g;
            if (g != 0) {
                *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
                *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
                *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
                *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
                *(s16 *)(p + 0x1C) = 0;
                *(u32 *)(p + 0x60) = 0;
                *(u32 *)(p + 0x6C) = 0;
                *(u32 *)(p + 0x5C) = 0;
                *(u32 *)(p + 0x68) = 0;
                func_001757E0(p, 0x16, 0xC);
                return;
            }
            t = p[6];
            p[6] = t + 1;
            func_001757E0(p, 0x16, 8);
            func_002CFA20(p);
            return;
        }
    }
    v = *(s8 *)(p + 0x150);
    if (v != 0) {
        if (*(s16 *)(p + 0x1E) != 0) {
            func_001CFE00(p, (u8)((s8)v - 1));
            p[0x150] = 0;
        }
    }
    func_002D0130(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_002CFA20(p);
}
extern f32 D_0045E86C[];
void func_00330CE0(u8 *p) {
    extern void func_00330EF0(u8 *);
    extern void func_00330EB0(u8 *);
    extern void func_00330E70(u8 *);
    extern s32 func_003D90A0(s32);
    s16 h;
    u32 t;
    f32 x, y, z;
    func_00330EF0(p);
    switch (p[4]) {
    case 0:
        h = *(s16 *)(p + 0x1E) - 1;
        *(s16 *)(p + 0x1E) = h;
        if (h < 0) {
            *(s16 *)(p + 0x1E) = 0;
        } else {
            func_00330EB0(p);
        }
        if (func_003D90A0(0) != 0) {
            t = p[4];
            p[4] = t + 1;
            *(s16 *)(p + 0x1E) = 0;
        }
        break;
    case 1:
        x = 0.5f * (f32)*(s16 *)(p + 0x1E);
        *(f32 *)(p + 0x38) = D_0045E86C[0] + (10.0f - 0.5f * x) * x;
        h = *(s16 *)(p + 0x1E) + 1;
        *(s16 *)(p + 0x1E) = h;
        if (h >= 0x14) {
            t = p[4];
            p[4] = t + 1;
            *(s16 *)(p + 0x1E) = 0;
        }
        break;
    case 2:
        func_00330E70(p);
        x = 0.5f * (f32)*(s16 *)(p + 0x1E);
        y = 50.0f + D_0045E86C[0];
        z = -0.5f * x;
        z = z * x;
        *(f32 *)(p + 0x38) = y + z;
        h = *(s16 *)(p + 0x1E) + 1;
        *(s16 *)(p + 0x1E) = h;
        if (h >= 0x14) {
            p[4] = 0;
            *(f32 *)(p + 0x38) = D_0045E86C[0];
        }
        break;
    }
}
