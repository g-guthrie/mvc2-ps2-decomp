typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern f32 D_004F1F58[];
extern void func_001757E0(u8 *, s32, s32);
extern s8 func_00175700(u8 *);
extern void func_00186A60(u8 *, s32);
extern void func_00175910(u8 *, s32, s32, s32);
void func_0017C000(u8 *p) {
    u32 v;
    s32 a3;
    f32 g, t, z;
    u32 m;
    switch (p[1]) {
    case 0x20:
        (**(void (**)(u8 *))(*(u8 **)(p + 0x43C) + 0x58))(p);
        return;
    default:
        break;
    }
    v = p[6];
    if (v == 0) {
        p[6] = v + 1;
        a3 = *(s8 *)(p + 0x1E9);
        a3 = a3 + 1;
        p[0x1E9] = a3;
        p[0x1E8] = 0;
        p[0x1EA] = 0x11;
        p[0x20D] = 2;
        func_001757E0(p, 1, 0xC);
        return;
    }
    g = D_004F1F58[0];
    *(f32 *)(p + 0x34) -= g - g;
    if (func_00175700(p) >= 0) {
        t = *(s8 *)(p + 0x151);
        z = 0.0f;
        if (t == z) return;
        if (p[0x1E6] != 0) t = -t;
        *(f32 *)(p + 0x34) += 1.6666666269302368f * t;
        p[0x151] = 0;
    } else {
        func_00186A60(p, 2);
        p[6] = 1;
        p[0x20D] = 2;
        *(u16 *)(p + 0x140) = p[0x1E6];
        m = (*(u32 *)(p + 0x428) & 0x80) | (*(u32 *)(p + 0x42C) & 0x2000000);
        if (m != 0) func_00175910(p, 1, 1, 2);
        else func_001757E0(p, 1, 9);
    }
}

#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))
static void func_002555E0(u8 *p) {
    if (S(p, 696) > 0) {
        p[1037] = 0;
        p[1036] = 0;
        p[828] = 5;
    } else {
        p[1036] = 2;
        p[828] = 5;
    }
}
extern void func_001830D0(u8 *, f32 *, s32);
extern s32 func_00185980(u8 *);
extern void func_00185770(u8 *, s32);
extern void func_001757E0(u8 *, s32, s32);
extern void func_0025A760(u8 *);
void func_0025A5C0(u8 *p) {
    extern void func_00175700(u8 *);
    s16 *q;
    f32 v[4];
    f32 c;
    u32 t;
    q = (s16 *)(p + 0x2B8);
    func_002555E0(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(s8 *)(p + 0x151) == 1) {
        p[0x151] = 0;
        v[0] = 13.333333015441895f;
        v[1] = 120.0f;
        if (*q == 0) func_001830D0(p, v, 3);
        else func_001830D0(p, v, 0);
        if (p[0x1E6] != 0) c = 20.0f; else c = -20.0f;
        *(f32 *)(p + 0x5C) = c;
        if (p[0x1E6] != 0) c = -0.625f; else c = 0.625f;
        *(f32 *)(p + 0x68) = c;
    }
    if (*(s8 *)(p + 0x1B2) != 0 && func_00185980(p) != 0) {
        t = p[6];
        p[6] = t + 1;
        p[0x20B] = 0xC4;
        func_00185770(p, *(s32 *)(p + 0x1C4));
        p[0x1FE] = 1;
        p[0x201] = 2;
        p[0x209] = 2;
        func_001757E0(p, 0x16, 7);
        func_0025A760(p);
        return;
    }
    if (*(s8 *)(p + 0x153) < 0) {
        p[6] = 7;
        func_001757E0(p, 0x16, 0xA);
    }
    func_00175700(p);
}
