typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
s32 func_00178EB0(u8 *p) {
    *(s16*)(p+0x4E) = 0;
    if (*(s32*)(p+0x48) != 0) {
        u8 *a = *(u8**)(p+0x178);
        u8 *t = *(u8**)(p+0x17C);
        u8 *q = *(u8**)(a + *(u16*)(p+0x142) + 0x40);
        u8 *r;
        s32 x;
        q = q + (u32)a;
        r = *(u8**)(q + (*(u8*)(p+0x168) << 2));
        x = *(u8*)(a + (u32)r + 0x12);
        x = *(u8*)(t + (x << 4) + 0xE);
        *(s16*)(p+0x4E) = (-x) / 2;
    }
    return;
}

void func_00385130(s8 *p) {
    extern s32 func_00417A40();
    extern void func_00383BF0();
    s16 v;
    *(s16*)(p+0x1C) = 2;
    v = *(s16*)(p+0x1E) - 1;
    *(s16*)(p+0x1E) = v;
    if (v < 0) {
        { u32 t = p[5]; p[5] = t + 1; }
        *(s16*)(p+0x1C) = 0x168;
        *(s16*)(p+0x1E) = 0x8A;
        if ((func_00417A40() & 7) != 0) {
            func_00383BF0(p, 10, 7);
        } else {
            func_00383BF0(p, 10, 8);
        }
        func_00383BF0(p, 9, 5);
    }
}

void func_002C7250(u8 *p) {
    extern void func_00183D90();
    extern void func_00175700();
    extern void func_001757E0();
    s16 v;
    func_00183D90(p);
    *(f32*)(p+0x34) += *(f32*)(p+0x5C);
    *(f32*)(p+0x5C) += *(f32*)(p+0x68);
    *(f32*)(p+0x38) += *(f32*)(p+0x60);
    *(f32*)(p+0x60) += *(f32*)(p+0x6C);
    func_00175700(p);
    v = *(s16*)(p+0x1C) - 1;
    *(s16*)(p+0x1C) = v;
    if (v < 0) {
        { u32 t = p[6]; p[6] = t + 1; }
        func_001757E0(p, 2, 3);
    }
}

void func_002EBCE0(u8 *p, s8 *q) {
    extern void func_00175700();
    extern void func_003A6DC0();
    extern void func_001757E0();
    s16 v;
    s16 w;
    func_00175700(p);
    if (q[8] != 0) {
        v = *(s16*)(p + 0x1C);
        *(s16*)(p + 0x1C) = v - 1;
        if (v == 0) {
            *(s16*)(p + 0x1C) = 3;
            func_003A6DC0(p, 2, 2);
            q[8] = q[8] - 1;
        }
    }
    w = *(s16*)(p + 0x1E) - 1;
    *(s16*)(p + 0x1E) = w;
    if (w == 0) {
        { u32 t = p[6]; p[6] = t + 1; }
        func_001757E0(p, 0x15, (u8)(p[0x1B7] + 10));
    }
}

void func_00304660(u8 *p) {
    extern void func_00175700();
    extern void func_001843A0();
    extern void func_003B38F0();
    s16 v;
    s32 a;
    u8 *o;
    func_00175700(p);
    v = *(s16*)(p + 0x1C) - 1;
    *(s16*)(p + 0x1C) = v;
    if (v == 0) {
        func_001843A0(p);
        return;
    }
    a = *(s8*)(p + 0x151);
    if (a & 1) {
        *(s8*)(p + 0x151) = a & ~1;
        func_003B38F0(p, 1, 9);
    }
    a = *(s8*)(p + 0x151);
    if (a & 2) {
        *(s8*)(p + 0x151) = a & ~2;
        o = *(u8**)(p + 0x1DC);
        o[0x20A] = 1;
        o[0x20D] = 2;
        o[0x1B5] = 0x20;
        p[0x1B5] = 0x20;
        o[0x1E6] = p[0x1E6];
        { u32 t = o[0x1E6]; o[0x1E6] = t ^ 1; }
    }
}

s32 func_00163FD0(u8 *p, s32 b) {
    extern s32 func_0016B240();
    extern void func_0016B0C0();
    extern void func_00186CE0();
    extern s32 func_001640A0();
    if (func_0016B240(p, 0) == 0) return 0;
    func_0016B0C0(p, b, 0);
    func_0016B0C0(p, b, 3);
    { u32 t = p[0x451]; p[0x451] = t + 1; }

    *(f32*)(p + 0x460) = *(f32*)(p + 0x4C8);
    *(f32*)(p + 0x464) = *(f32*)(p + 0x34);
    *(s32*)(p + 0x468) = 1;
    *(s32*)(p + 0x46C) = ((p[0x1E6] * 3) << 10) ^ 0x800;
    *(f32*)(p + 0x38) = *(f32*)(p + 0x430);
    p[0x1E7] = 0;
    *(s16*)(p + 0x4F0) = *(s16*)(p + 0x46C);
    *(s16*)(p + 0x35E) = 0x800;
    func_00186CE0(p, 1);
    *(s16*)(p + 0x35E) = 0;
    return func_001640A0(p, b);
}

