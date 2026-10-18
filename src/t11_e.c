typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct V3 { f32 x, y, z; } V3;
extern s32 func_0018AA50();
extern s32 func_0018A580();

extern u8 D_00455C10[];
extern u8 D_00450E30[];
extern u8 D_00454110[];
extern u8 D_004511B0[];
extern s32 func_00169CE0();
extern void func_00169C90();
extern s32 func_00189310();
extern void func_0018A990();
extern void func_00186A60();
extern void func_002918A0();
extern void func_001757E0();
extern void func_00292420();
extern void func_0015B200();
extern void func_001E3710();
extern void func_003B54E0();
extern void func_003B5530();

s32 func_00286440(u8 *p) {
    if (func_00189310(p, D_00455C10, p + 0x380) == 0) return 0;
    if (p[0x20D] == 2) {
        if (*(s8 *)(p + 0x1E8) != 0 && p[0x210] == 0) return 0;
        *(s8 *)(p + 0x1E8) += 1;
    }
    func_0018A990(p, p + 0x380);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 2;
    func_00186A60(p, 0x15);
    return 1;
}

static s32 func_00291800(u8 *p) {
    u8 f = p[0x1E6];
    u8 *o = *(u8 **)(p + 0x220);
    if (f == 0 && *(f32 *)(p + 0x34) < *(f32 *)(o + 0x34)) return 1;
    if (f != 0 && *(f32 *)(p + 0x34) <= *(f32 *)(o + 0x34)) return 1;
    return 0;
}

void func_00291970(u8 *p, u8 *q) {
    if (func_00291800(p) != 0) {
        p[7] = 6;
        q[0x18] = 0;
        func_002918A0(p);
    } else {
        if (q[0x18] == 0) {
            u32 t = q[0x18];
            q[0x18] = t + 1;
            q[0x19] = 0;
            func_001757E0(p, 0x16, 8);
        }
        if (p[0x1E6] == 0) {
            *(f32 *)(p + 0x34) += -5.0f;
        } else {
            *(f32 *)(p + 0x34) += 5.0f;
        }
        func_00292420(p);
    }
}

s32 func_002161C0(u8 *p) {
    if (func_00189310(p, D_00450E30, p + 0x3B0) == 0) return 0;
    if (**(s8 **)(p + 0x420) == 0) return 0;
    if (p[0x20D] == 2) {
        if (p[0x210] == 0 && *(s8 *)(p + 0x1E8) != 0) return 0;
    }
    func_0018A990(p, p + 0x3B0);
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[0x1FD] = 6;
    func_00186A60(p, 0x1D);
    return 1;
}

s32 func_001EE130(u8 *p) {
    u8 *s = p + 0x2B8;
    u16 loc[8];
    u32 v;
    if (func_0018AA50(p, 0x60, &loc[7], 1) == 0) return 0;
    if (func_0018A580(p) == 0) return 0;
    if (p[0x20D] == 2) return 0;
    v = *(u16 *)(p + 0x20E);
    if (v & 0x2000) return 0;
    *(u16 *)s = v;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 1;
    func_00186A60(p, 0x15);
    return 1;
}

s32 func_00262770(u8 *p) {
    if (func_00189310(p, D_00454110, p + 0x3A8) == 0) return 0;
    if (**(s8 **)(p + 0x420) == 0) return 0;
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            s32 t = *(s8 *)(p + 0x1E8);
            if (t != 0) return 0;
            p[0x1E8] = t + 1;
        }
    }
    func_0018A990(p, p + 0x3A8);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 6;
    func_00186A60(p, 0x1D);
    return 1;
}

s32 func_0021CB10(u8 *p) {
    if (func_00189310(p, D_004511B0, p + 0x390) == 0) return 0;
    if (**(s8 **)(p + 0x420) == 0) return 0;
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            s32 t = *(s8 *)(p + 0x1E8);
            if (t != 0) return 0;
            p[0x1E8] = t + 1;
        }
    }
    p[0x1B7] = 1;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 2;
    func_00186A60(p, 0x1D);
    return 1;
}

s32 func_0016A130(u8 *p, s32 i, u8 b) {
    u32 m;
    if (p[0x450] == i) return 1;
    m = *(u32 *)(p + 0x4C4);
    if (m & (1 << i)) return 1;
    ((u32 *)p)[0x4C4 / 4] = m | (1 << i);
    if (p[0x450] < 2) {
        if (func_00169CE0(p, i, 2) == 0) return 1;
    }
    p[0x450] = i;
    p[0x451] = 0;
    p[0x452] = 0;
    func_00169C90(p);
    p[0x4A8] = b;
    return 0;
}
