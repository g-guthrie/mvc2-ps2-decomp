typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef long long s64;

extern void func_001E3710(u8 *p, u8 a);
void func_001E3A10(u8 *p) {
    u8 a;
    s32 y = p[0x21B];
    if (p[0x216] & 0x80) goto L1;
    a = 0x30;
    if (y < 5) goto L2;
L1: a = 0x31;
L2:
    func_001E3710(p, a);
}

extern void func_00123090(u32 a);
extern void func_00151A20(u8 a);
extern void func_001520E0(u8 a);
void func_00153710(u32 a) {
    func_00123090(a);
    func_00151A20(a);
    func_001520E0(a);
}

void func_0013DD80(u8 *p) {
    s16 v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        p[5] += 1;
        p[0x13C] = 1;
        *(s16 *)(p + 0x1C) = 0;
    }
}

void func_003DAC00(void) {
    extern u8 D_004D1960[];
    s32 i = 0;
    do {
        u8 *q = D_004D1960 + i;
        q[0] = 0; i += 8; q[1] = 0; q[2] = 0; q[3] = 0;
        q[4] = 0; q[5] = 0; q[6] = 0; q[7] = 0;
    } while (i < 16);
}

extern u8 func_001748C0(u8 *a, u8 *b);
u32 func_00292E80(u8 *p) {
    u8 *q = *(u8 **)(p + 0x220);
    u8 t;
    p[0x2C4] = 0xFF;
    t = func_001748C0(p + 0x34, q + 0x34) >> 3;
    return ((s8)t - 16) & 0x1F;
}

extern void func_00175700(u8 *p);
extern void func_00175910(u8 *a, s32 b, s32 c, s32 d);
extern void func_00176160(u8 *a, s32 b, s32 c, s32 d);
extern s32 func_001891F0(u8 *a, s32 b);
extern void func_00186A60(u8 *a, s32 b);
extern void func_003870A0(u8 *a);
extern void func_00334FA0(u8 *a);

void func_0017C3F0(u8 *p) {
    s16 v;
    func_00175700(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v < 0) {
        p[6] += 1;
        p[0x268] = 1;
    }
}

void func_00386E40(u8 *p, u8 *q) {
    u8 *r = *(u8 **)(p + 0x14);
    if (q[4] >= 2) goto A;
    if (r[4] < 2) goto B;
A:  p[4] += 1;
    p[0x13C] = 0;
    goto E;
B:  func_003870A0(p);
E:  ;
}

void func_001D9B90(u8 *p, u8 *q) {
    *(float *)(p + 0x34) = *(float *)(q + 0x34);
    *(float *)(p + 0x38) = *(float *)(q + 0x38);
    if (*(s8 *)(q + 0x150) == 0) {
        p[0x13C] = 0;
    } else {
        p[0x13C] = 1;
        func_00175910(p, 0xF, 5, *(s8 *)(q + 0x150) - 16);
    }
}

void func_002DB480(u8 *p) {
    s16 v;
    *(s8 *)(p + 0x40C) = 2;
    *(s8 *)(p + 0x33C) = 5;
    *(s32 *)(p + 0x2F8) = 0x60;
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        p[6] += 1;
        *(s16 *)(p + 0x1C) = 0x20;
        *(s16 *)(p + 0x1E) = 0x10;
    }
    func_00175700(p);
}

void func_003BB890(u8 *p) {
    u8 *t = p + 0xD0;
    u8 *r;
    u8 *s;
    p[5] += 1;
    p[6] = 0;
    *(s32 *)t = *(s32 *)(p + 0x1C4);
    t[9] = 0xFF;
    r = *(u8 **)(p + 0x18);
    s = r + 0x2B8;
    if (r[0x2BA] == 0) s[3] = 0x78;
    t[7] = s[2];
    t[0xA] = 0;
    s[2] += 1;
}

u8 func_0032D620(u32 *p, s8 n) {
    s8 t = n >= 32 ? 1 : 0;
    *p = 1 << (n - (s8)t * 32);
    return t;
}

extern s32 func_00118FA8(float f);
void func_001DEEB0(u8 *p) {
    s16 *q = (s16 *)(p + 0xD8);
    *q = func_00118FA8((float)*q + *(float *)(p + 0x5C));
}

extern void func_0020D2A0(u8 *p, u8 *q);
void func_0020D250(u8 *p, u8 *q, u8 a) {
    if (q[9] || !q[0xB]) {
        func_0020D2A0(p, q);
    } else {
        *(s16 *)(p + 0x1E) = a;
        p[7] = 0;
    }
}

s32 func_00334F50(u8 *p) {
    if (*(float *)(p + 0x74) == 0.0f) *(u32 *)(p + 0x74) = 0x3F800000;
    *(u32 *)(p + 0x50) = 0x3F800000;
    p[6] = 1;
    p[7] = 0;
    func_00334FA0(p);
    return 0;
}

extern u8 D_00463F20[];
void func_00374C70(u8 *p) {
    ((void (**)(u8 *))D_00463F20)[p[5]](p);
    if (p[0xD1] != (*(u8 **)(p + 0x18))[0x169]) p[4] = 2;
}

extern u8 D_0044AD30[];
void func_0019F310(u8 *p, s32 x) {
    if ((*(u8 **)(p + 0x18))[1] != p[1]) {
        p[4] += 1;
    } else {
        ((void (**)(u8 *, s32))D_0044AD30)[p[0x20]](p, x);
    }
}
