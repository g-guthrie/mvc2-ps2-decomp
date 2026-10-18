typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_00359B30(u8 *p);
extern s8 D_004F8010;
extern s8 D_004F8014;
extern void func_0014E770(u8 *p);
extern void func_001391E0(u8 *p);
extern float D_004C9F50;
extern float D_004F1FEC;
extern float D_004F1F4C;
extern void func_00178F20(u8 *p);

void func_00126280(s32 unused, s32 n) {
    float a = D_004C9F50;
    float v = a + (D_004F1FEC - a) / (float)n;
    D_004F1F4C = v;
    D_004C9F50 = v;
}

s32 func_0018A1F0(s32 a0, u8 *q, u8 *r, u32 mask) {
    if (((mask & 0xFFFF) & *(u16 *)(q + 8)) == 0) {
        return r[0] = 0;
    }
    r[1] = *(s8 *)q;
    r[0]++;
    return 0;
}

extern void func_001757E0();
extern s32 func_0028D8B0();
extern void func_001C5390();
extern s32 func_00175700();
extern void func_0011D8F8();
extern void func_00414AA0();
extern void func_0016F090();
extern void func_0016F0C0(float);
extern u8 D_004F1CA0[];
extern u8 D_00446800[];
extern void func_00334E20();
extern void func_00126970();
extern void func_00126340();
extern float D_004F1FF8;
extern u8 D_00583B92[];
extern u8 D_004AC701[];
extern void func_003DAA40();
extern s32 func_001315F0();
extern void func_0012F710();
extern void func_0012A210();
extern void func_001E41B0();
extern void func_001E41C0();
extern void func_001E46D0();
extern void func_00185490();
extern void func_001E3210();
extern s32 func_001891F0();
extern void func_00186A60();
extern s32 func_003D90A0();
extern void func_001555A0();

void func_003670B0(u8 *p) {
    float v;
    *(s32 *)(p + 0x5C) = 0;
    *(s32 *)(p + 0x60) = 0;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6C) = 0;
    if (*(s16 *)(p + 0x140) != 0) v = 2.5f;
    else v = -2.5f;
    *(float *)(p + 0x5C) = v;
    func_001757E0(p, 0x17, 9);
}

s32 func_00197810(u8 *a, u8 *b) {
    u8 *c = b + 0x2B8;
    u8 *d = a + 0x88;
    if (b[0x1E4] == 0x15) {
        s32 v = *(s8 *)(c + 0xC);
        if (v != 0) {
            if ((s8)v == *(s8 *)d) goto z;
            return 1;
        }
    }
z:
    return 0;
}

void func_0013A2D0(u8 *p) {
    if (D_00583B92[p[0x20]] & (0x10 << p[0x21])) {
        p[4]++;
        *(s16 *)(p + 0x1C) = 10;
    }
}

void func_00288E80(u8 *p) {
    if (func_0028D8B0(p) == 0) {
        p[7]++;
        func_001C5390(p);
        func_00175700(p);
    }
}

void func_0016F040(void) {
    func_0011D8F8(D_004F1CA0, 0, 0x10);
    func_00414AA0();
    func_0016F090(D_00446800);
    func_0016F0C0(1.0f);
}

s32 func_00334DD0(u8 *p) {
    if (*(float *)(p + 0x74) == 0.0f) *(float *)(p + 0x74) = 1.0f;
    *(float *)(p + 0x50) = 1.0f;
    p[6] = 1;
    p[7] = 0;
    func_00334E20(p);
    return 0;
}

void func_00125EF0(void) {
    func_00126970(&D_004F1FEC, &D_004F1FF8);
    D_004F1FF8 = D_004F1FEC;
    func_00126280(0, 8);
    func_00126340(0, 8);
}

void func_0012A290(u8 *p) {
    if (func_001315F0()) {
        func_0012F710(1);
        func_0012A210(p);
        func_001E41B0(0x38);
        func_001E41C0(0x38);
        func_001E46D0(0xF5);
    }
}

void func_001CF640(u8 *p) {
    s8 r = func_00175700(p);
    if (r < 0) p[4]++;
    else if (*(s8 *)(p + 0x151) != 0) *(s8 *)(p + 0x151) = 0;
}

void func_002BD2D0(u8 *p) {
    float v;
    p[6] = 0xC;
    if (p[0x1E6] != 0) v = -2.5f;
    else v = 2.5f;
    *(float *)(p + 0x5C) = v;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x60) = 0x41892492;
    *(s32 *)(p + 0x6C) = 0xBF4DB6DB;
    func_001757E0(p, 0x16, 0xD);
}

void func_003B0C70(u8 *p, u8 *q) {
    s16 t = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = t - 1;
    if (t == 0) {
        p[5]++;
        func_001E3210(q, 0x21);
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
    }
}

extern void (*D_0044A838[])(u8 *, u8 *);
void func_0019ACC0(u8 *p, u8 *q) {
    if (q[0x169] != 0x13) {
        p[4]++;
        p[0x13C] = 0;
    } else {
        D_0044A838[p[5]](p, q);
    }
}

void func_00155540(u8 *p) {
    func_001555A0(p, 8, 5, 0);
    func_001555A0(p, 8, 5, 1);
    func_001555A0(p, 8, 5, 2);
}

s32 func_00128CA0(void) {
    if (D_004F8010 == 1) {
        if (D_004F8014 == 1) goto z;
    }
    return 1;
z:
    return 0;
}
