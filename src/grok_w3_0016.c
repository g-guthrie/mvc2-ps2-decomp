typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef float f32;

typedef struct Vec3 {
    f32 x, y, z;
} Vec3;

extern s32 D_00446BF0;
extern s32 D_00446BF4;
extern s32 D_00446BF8;
extern s32 D_00446BFC;
extern s32 D_00446C00;
extern s32 D_00446C04;
extern Vec3 D_004F1CA0;

extern s32 func_0016B0C0(u8 *, s32, s32);
extern void func_00166DF0(u8 *);
extern void func_00167270(u8 *);
extern void func_003DF7A0(void);
extern void func_003DF850(s32, s32);
extern void func_00414C30(void);
extern s32 func_00169E50(u8 *, s32, s32);
extern void func_001688C0(u8 *, s32);
extern s32 func_0016B240(u8 *, s32);
extern s32 func_0016B250(u8 *, s32);
extern s32 func_00169CE0(u8 *, s32, s32);

void func_00176300(void) {
    D_00446BF0 = 0;
    D_00446BF4 = 0;
    D_00446BF8 = 0;
    D_00446BFC = 0;
    D_00446C00 = 0;
    D_00446C04 = 0;
}

s32 func_00166BE0(u8 *p, s32 a1) {
    func_0016B0C0(p, a1, 0);
    p[1193] = 0;
    return 1;
}

s32 func_00166C10(u8 *p, s32 a1) {
    func_0016B0C0(p, a1, 0);
    p[1194] = 0;
    return 1;
}

s32 func_00166C40(u8 *p, s32 a1) {
    func_0016B0C0(p, a1, 0);
    p[1195] = 0;
    p[533] = 0;
    return 1;
}

s32 func_001672B0(u8 *p, s32 a1) {
    func_0016B0C0(p, a1, 0);
    p[1174] = 1;
    return 1;
}

s32 func_001672E0(u8 *p, s32 a1) {
    func_0016B0C0(p, a1, 0);
    p[1174] = 0;
    return 1;
}

void func_00166DC0(u8 *p, s32 a1) {
    func_0016B0C0(p, a1, 0);
    func_00166DF0(p);
}

void func_00167240(u8 *p, s32 a1) {
    func_0016B0C0(p, a1, 0);
    func_00167270(p);
}

void func_00170D30(void) {
    func_003DF7A0();
    func_003DF850(93, 50);
    func_003DF850(98, 0);
}

void func_0016F090(Vec3 *p) {
    D_004F1CA0 = *p;
    func_00414C30();
}

s32 func_00166D80(u8 *p, s32 a1) {
    func_0016B0C0(p, a1, 0);
    func_00169E50(p, 0, 0);
    return 0;
}

s32 func_00167140(u8 *p, s32 a1) {
    func_0016B0C0(p, a1, 0);
    p[1172] = 0;
    p[1105] = 1;
    p[1106] = 0;
    p[1107] = 0;
    return 1;
}

void func_00166D20(u8 *p, s32 a1) {
    func_0016B0C0(p, a1, 0);
    func_001688C0(p, a1);
}

s32 func_00166E40(u8 *p, s32 a1) {
    func_0016B0C0(p, a1, 0);
    func_0016B0C0(p, a1, 1);
    p[1170] = *(s8 *)(p + 1224);
    p[1172] = 1;
    p[1105] = 0;
    p[1106] = 0;
    p[1107] = 0;
    return 1;
}

s32 func_00166AC0(u8 *p, s32 a1) {
    if (!func_0016B240(p, 4)) {
        return 0;
    }
    func_0016B0C0(p, a1, 0);
    p[1194] = 1;
    return 1;
}

s32 func_00166B80(u8 *p, s32 a1) {
    if (!func_0016B240(p, 4)) {
        return 0;
    }
    func_0016B0C0(p, a1, 0);
    p[1195] = 1;
    return 1;
}

s32 func_00166B20(u8 *p, s32 a1) {
    if (!func_0016B240(p, 4)) {
        return 0;
    }
    func_0016B0C0(p, a1, 0);
    *(s8 *)(p + 1194) = -128;
    return 1;
}

s32 func_001668B0(u8 *p, s32 a1) {
    if (!func_0016B250(p, 2)) {
        return 0;
    }
    func_0016B0C0(p, a1, 0);
    *(s8 *)(p + 1193) = -127;
    return 1;
}

s32 func_00166910(u8 *p, s32 a1) {
    if (!func_0016B250(p, 2)) {
        return 0;
    }
    func_0016B0C0(p, a1, 0);
    *(s8 *)(p + 1193) = -111;
    return 1;
}

void func_00167180(u8 *p, s32 a1) {
    func_0016B0C0(p, a1, 0);
    if (func_00169CE0(p, 0, 0)) {
        func_00167270(p);
    } else {
        func_00166DF0(p);
    }
}

void func_001671E0(u8 *p, s32 a1) {
    func_0016B0C0(p, a1, 0);
    if (func_00169CE0(p, 1, 1)) {
        func_00167270(p);
    } else {
        func_00166DF0(p);
    }
}

s32 func_00167A50(u8 *p, s32 a1) {
    s32 v;
    func_0016B0C0(p, a1, 0);
    func_0016B0C0(p, a1, 1);
    v = *(s32 *)(p + 1224);
    *(s32 *)(p + 1120) = v;
    p[1139] = (s8)p[1224] + 1;
    return 1;
}

s32 func_00167AB0(u8 *p, s32 a1) {
    s32 v;
    func_0016B0C0(p, a1, 0);
    func_0016B0C0(p, a1, 1);
    v = *(s32 *)(p + 1224);
    *(s32 *)(p + 1120) = v;
    p[1211] = (s8)p[1120] + 1;
    return 1;
}
