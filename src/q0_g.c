typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s8 *D_004C29D4;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G351540;
extern G351540 *D_004C2794;
extern void (*D_0045B220[])();
extern u8 *D_004C28DC;

void func_00393000(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_00179160(u8 *, u8 *);
    extern s32 func_00393390(u8 *);
    extern void func_003933A0(u8 *);
    u8 *s = *(u8 **)(p + 0x1DC);
    func_00175700(p);
    func_00179160(p, s);
    *(u8 *)(*(u8 **)(p + 0x18) + 0x1FE) = 1;
    *(u8 *)(*(u8 **)(p + 0x18) + 0x201) = 2;
    *(u8 *)(*(u8 **)(p + 0x18) + 0x209) = 2;
    if (func_00393390(p)) {
        func_003933A0(p);
    } else if (D_004C29D4[9]) {
        p[5]++;
        *(s16 *)(p + 0x1C) = 2;
        *(s16 *)(p + 0x1E) = 0;
    }
}

void func_002ACEA0(u8 *p) {
    extern void func_00175700();
    extern void func_00183D90();
    f32 *a, *b, *c, *d;
    d = (f32 *)(p + 0x6C);
    c = (f32 *)(p + 0x68);
    b = (f32 *)(p + 0x60);
    a = (f32 *)(p + 0x5C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        p[6]++;
        *a = 0;
        *b = 0;
        *c = 0;
        *d = 0;
    }
    func_00183D90(p);
}

void func_00241F20(u8 *p) {
    extern s8 func_00175700();
    extern void func_001843A0();
    extern void func_00183d50();
    extern void func_001757E0();
    if (p[7] == 0) {
        if (func_00175700() >= 0) return;
        func_001843A0(p);
        return;
    }
    func_00175700();
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        p[7]--;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        func_00183d50(p);
        func_001757E0(p, 0x16, 5);
    }
}

void func_00351540(u8 *p) {
    extern s8 func_00175700();
    extern void func_00351870();
    extern void func_00351760();
    extern void func_001757E0(u8 *, s32, u8);
    s16 v;
    p[0x13C] = 1;
    if (func_00175700() >= 0) return;
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v >= 0) return;
    v = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = v;
    if (v != 0) {
        p[5] = 2;
        func_00351870(p);
        return;
    }
    p[5]++;
    *(s16 *)(p + 0x1C) = 0x10;
    p[0x1B5] = 0x4A;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_00351760(p);
    func_001757E0(p, 0x15, p[0x20] + 0x25);
}

void func_00374500(u8 *p) {
    extern void func_0018FDB0(u8 *);
    extern void func_00154470(u8 *, s32, s32, f32, f32);
    extern void func_001757E0(u8 *, s32, u8);
    u8 *q = *(u8 **)(p + 0x18);
    s16 a, b;
    f32 f;
    q[0x1FE] = 1;
    a = *(s16 *)(p + 0x1C);
    b = *(s16 *)(p + 0x1E);
    if (a == b) return;
    if (a <= 0) {
        p[5]++;
        p[0x13C] = 0;
        (*(u8 **)(p + 0x1C4))[0x1B5] = 0x40;
        func_0018FDB0(q);
        f = 4.0f;
        func_00154470(p, 0, 0x90, f, f);
        f = 4.0f;
        func_00154470(p, 0x10, 0x90, f, f);
        f = 4.0f;
        func_00154470(p, 0xF0, 0x90, f, f);
        p[0] = 0;
    } else {
        *(s16 *)(p + 0x1E) = a;
        func_001757E0(p, 0x16, p[0x20] + *(s16 *)(p + 0x1C));
        (*(u8 **)(p + 0x1C4))[0x1B5] = 0x40;
        func_0018FDB0(q);
    }
}

void func_0023CB30(u8 *p) {
    extern void func_00175700();
    extern void func_001757E0(u8 *, s32, s32);
    s16 h;
    s16 v;
    f32 d;
    func_00175700();
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    h = *(s16 *)(p + 0x1E);
    if (h == 0) {
        if (p[0x23] != 0) {
            p[6]++;
            p[7] = 0;
            return;
        }
    } else {
        *(s16 *)(p + 0x1E) = h - 1;
    }
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v != 0) return;
    p[7]++;
    p[0x169] = 0x15;
    p[0x168] = 0xA;
    func_001757E0(p, p[0x169], p[0x168]);
    d = 4.0f;
    *(f32 *)(p + 0x5C) /= d;
    *(f32 *)(p + 0x68) /= d;
}

void func_002E54F0(u8 *p) {
    extern s8 func_00175700();
    extern void func_00184540(u8 *);
    extern s32 func_001864a0();
    extern void func_001865B0(u8 *);
    u8 *q = p + 0x2B8;
    switch (p[0x1FC]) {
    case 0:
    case 1:
        if (func_00175700(p) < 0) {
            func_00184540(p);
        } else if (func_001864a0(p) != 0) {
            func_001865B0(p);
        }
        break;
    case 2:
        if (*(s8 *)(q + 0x10) != 0) {
            D_0045B220[p[6]](p, p[0x1FC], q);
        } else {
            if (func_00175700(p) < 0) {
                func_00184540(p);
            } else if (func_001864a0(p) != 0) {
                func_001865B0(p);
            }
        }
        break;
    }
}

void func_002F9740(u8 *p, u8 *q) {
    extern void func_00185490();
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_002F8DE0(u8 *);
    extern s8 func_00175700();
    extern void func_002F8EB0(u8 *);
    extern void func_00183210(u8 *, u32 *, s32);
    extern void func_00175C00(u8 *, s32);
    extern void func_00131AB0(u8 *, u8 *, s32);
    extern void func_002F8E40(u8 *);
    u32 v[4];
    u8 *r;
    if (p[7] == 0) {
        p[7]++;
        func_00185490(p);
        func_001757E0(p, 0x15, 6);
        func_002F8DE0(p);
        return;
    }
    if (func_00175700() < 0) {
        func_002F8EB0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        v[0] = 0xC1AD5555;
        v[1] = 0x4331DB6D;
        func_00183210(p, v, 1);
        func_00175C00(p, 0);
        r = q + 0xE;
        *(s16 *)r = 0x258;
        q[0xD] = 2;
        q[0x14] = 0;
        q[0x15] = 0;
        *(s16 *)(p + 0x3FE) = *(s16 *)r;
        func_00131AB0(p, r, 2);
        *(s16 *)(p + 0x3FA) = 0;
        p[0x402] = 0;
    }
    func_002F8E40(p);
}

void func_003A4D10(u8 *p, u8 *q) {
    extern void func_003A4E90();
    extern void func_001E7F60();
    u8 *r = q + 0x2B8;
    s16 v;
    if (q[5] != 0 || q[0x1FD] != 1 || q[0x169] != 0x15) {
        p[4] = 2;
        p[0x13C] = 0;
        return;
    }
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    *(s8 *)(p + 0x31) = *(s8 *)(p + 0x20) + 1;
    p[0x13D] = 1;
    if (q[2] != 0) *(s16 *)(p + 0x13E) = *(s16 *)(q + 0x13E) + 9;
    else *(s16 *)(p + 0x13E) = *(s16 *)(q + 0x13E) + 1;
    if (p[5] == 0) {
        if (*(s8 *)(r + 5) < 0) {
            p[5]++;
            *(s16 *)(p + 0x1C) = 4 - q[0x20];
            return;
        }
        func_003A4E90(p);
        if (*(s8 *)(p + 0x1B2) != 0) return;
        func_001E7F60(p);
        return;
    }
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        p[4] = 2;
        p[0x13C] = 0;
    } else {
        func_003A4E90(p);
    }
}

void func_0030AF90(u8 *p) {
    extern void func_00175700();
    extern void func_00176160(u8 *, s32, s32, s32);
    extern void func_001757E0(u8 *, s32, s32);
    f32 *a, *b, *c, *d;
    s16 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x33C] = 5;
    func_00175700();
    a = (f32 *)(p + 0x5C);
    c = (f32 *)(p + 0x68);
    b = (f32 *)(p + 0x60);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    d = (f32 *)(p + 0x6C);
    if (v == 0) {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        p[6]++;
        *D_004C28DC = 0xFF;
        func_00176160(p, 2, 0x13, 1);
        *a = 0;
        *b = 0;
        *c = 0;
        *d = 0;
        *(u32 *)(p + 0x6C) = 0xBEF00000;
        func_001757E0(p, 1, 9);
    }
}
