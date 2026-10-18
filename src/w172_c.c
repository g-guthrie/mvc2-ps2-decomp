typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x160]; s8 b[8]; } S;
typedef struct { f32 x, y, z; } V3;

extern s16 D_0044F784[][2];
extern s32 D_0044F8A0[][4], D_0044F8A4[][4], D_0044F8A8[][4], D_0044F8AC[][4];

void func_001F0D50(u8 *a) {
    extern s8 func_00175700(void *);
    extern void func_001843A0(void *);
    extern void func_003467C0(void *);
    s8 *p, *s0;
    s32 v;
    *(f32 *)(a + 0x34) += *(f32 *)(a + 0x5C);
    *(f32 *)(a + 0x5C) += *(f32 *)(a + 0x68);
    *(f32 *)(a + 0x38) += *(f32 *)(a + 0x60);
    *(f32 *)(a + 0x60) += *(f32 *)(a + 0x6C);
    if (func_00175700(a) < 0) {
        p = ((S *)a)->b;
        func_001843A0(a);
        return;
    }
    p = ((S *)a)->b;
    *(u32 *)(a + 0x5C) = 0;
    s0 = p + 1;
    v = p[1];
    if (v != 0) {
        *(f32 *)(a + 0x5C) = 1.6666666f * (f32)D_0044F784[(s8)v][a[0x1B7]] / 256.0f;
        if (*(s16 *)(a + 0x140) == 0) {
            *(f32 *)(a + 0x5C) = -*(f32 *)(a + 0x5C);
        }
        if (*s0 == 2) {
            func_003467C0(a);
        }
        *s0 = 0;
    }
}

void func_001F2940(u8 *s0) {
    extern s8 func_00175700(void *);
    extern void func_001757E0(void *, s32, s32);
    u32 t;
    s0[0x206] = 3;
    if (func_00175700(s0) >= 0) return;
    t = s0[7];
    s0[7] = t + 1;
    *(f32 *)(s0 + 0x5C) = 1.6666666f * (f32)D_0044F8A0[s0[0x1B7]][0] / 65536.0f;
    *(f32 *)(s0 + 0x68) = 1.6666666f * (f32)D_0044F8A4[s0[0x1B7]][0] / 65536.0f;
    *(f32 *)(s0 + 0x60) = 2.1428571f * (f32)D_0044F8A8[s0[0x1B7]][0] / 65536.0f;
    *(f32 *)(s0 + 0x6C) = 2.1428571f * (f32)D_0044F8AC[s0[0x1B7]][0] / 65536.0f;
    if (s0[0x1E6] == 0) {
        *(f32 *)(s0 + 0x5C) = -*(f32 *)(s0 + 0x5C);
        *(f32 *)(s0 + 0x68) = -*(f32 *)(s0 + 0x68);
    }
    func_001757E0(s0, 0xF, 0x1F);
}

void func_00265900(u8 *s0) {
    extern s8 func_00175700(void *);
    extern void func_001757E0(void *, s32, s32);
    extern void func_001830D0(void *, void *, s32);
    V3 v;
    s0[0x405] = (s0[0x269] == 6) ? 2 : 0;
    if (func_00175700(s0) >= 0) {
        u32 t = s0[6];
        s0[6] = t + 1;
        s0[0x404] = 0;
        s0[0x405] = 0;
        v = *(V3 *)(s0 + 0x34);
        if (s0[0x20D] == 2) {
            func_001757E0(s0, 0x16, 0x41);
            v.x = 0.0f;
            v.y += 94.2857132f;
            func_001830D0(s0, &v, 1);
        } else {
            func_001757E0(s0, 0x16, 1);
            v.x = 0.0f;
            v.y += 51.4285698f;
            func_001830D0(s0, &v, 1);
        }
    }
}

void func_0031AAA0(u8 *a0, u8 *s0) {
    extern void func_001E3710(void *, s32);
    extern void func_0015B200(void *, f32 *, s32, s32);
    if (s0[5] == 2 && (*(u8 **)(s0 + 0x1C8))[1] == 0x38 && s0[0x20A] == 0x12
        && *(f32 *)(s0 + 0x38) > 411.4285583f) {
        f32 v[4];
        u32 t = a0[6];
        a0[6] = t + 1;
        *(u8 **)(s0 + 0x1C8) = a0;
        s0[0x1B5] = 0x45;
        s0[0x20A] = 9;
        s0[0x20B] = 3;
        s0[7] = 0;
        s0[6] = 0;
        s0[0x1B4] = 10;
        func_001E3710(a0, 0x49);
        v[0] = *(f32 *)(s0 + 0x34);
        v[1] = 34.28571319f + *(f32 *)(s0 + 0x38);
        func_0015B200(s0, v, 1, 0xF9);
    }
}

void func_003214F0(u8 *s0, u8 *s1) {
    extern void func_001266A0(void *, s32, s32);
    extern void func_00179160(void *, void *);
    extern u32 func_00119098(f32);
    V3 v;
    f32 fa, fb;
    func_001266A0(s0, 6, 6);
    v = *(V3 *)(s0 + 0x34);
    *(f32 *)(s1 + 0x38) = *(f32 *)(s1 + 0x430);
    func_00179160(s0, s1);
    fa = (*(f32 *)(s0 + 0x34) - v.x) / 2.0f;
    fb = (*(f32 *)(s0 + 0x38) - v.y) / 2.0f;
    if (func_00119098(1.0f + fa) > 2 || func_00119098(1.0f + fb) > 2) {
        *(f32 *)(s0 + 0x34) = v.x + fa;
        *(f32 *)(s0 + 0x38) = v.y + fb;
        s0[0x152] = 8;
    }
}
