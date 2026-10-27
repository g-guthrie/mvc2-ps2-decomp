struct Object;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s16 func_0012B8D0(s16 a, s16 b) {
    if (b >= 3) return 4;
    return (a + b + 4) % 4;
}

void func_002BE9E0(u8 *p) {
    extern void func_0018C6E0(void *);
    extern void func_0015D010(u8 *, u32 *);
    extern void func_001757E0(u8 *, s32, s32);
    u32 v[3];
    s16 t;
    s16 t2;
    func_0018C6E0(p);
    v[0] = 0xC2A00000;
    v[1] = 0x43384924;
    v[2] = 0;
    func_0015D010(p, v);
    p[0x1B4] = 10;
    t = p[0x1E6] ^ 1;
    *(s16 *)(p + 0x140) = t;
    p[0x1E6] = t;
    t2 = p[0x1E6] ^ 1;
    *(s16 *)(*(u8 **)(p + 0x1DC) + 0x140) = t2;
    (*(u8 **)(p + 0x1DC))[0x1E6] = t2;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    func_001757E0(p, 15, 3);
}

void func_001AC210(u8 *p, u8 *q) {
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00175700(u8 *);
    f32 c = -19.28571319580078f;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x60) <= c) *(f32 *)(p + 0x6C) = 0;
    if (*(f32 *)(p + 0x38) <= *(f32 *)(q + 0x430)) {
        u32 t = p[7];
        p[7] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
        func_001757E0(p, 0x17, (u8)(*(s8 *)(q + 0x1E7) + 10));
    }
    func_00175700(p);
}

void func_002DAF80(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_002DC1B0(u8 *);
    extern void func_00184540(u8 *);
    s16 v;
    f32 g;
    f32 c = 34.28571319580078f;
    *(s32 *)(p + 0x2C0) = 0x10;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    g = *(f32 *)(p + 0x430);
    if (*(f32 *)(p + 0x38) <= g - c) {
        *(f32 *)(p + 0x38) = g;
        p[0x20D] = 0;
        func_002DC1B0(p);
    } else {
        v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v <= 0) func_00184540(p);
    }
}

void func_0021C330(u8 *p, u8 *q) {
    extern void func_001266A0(u8 *, s32, s32);
    extern void func_0015D010(u8 *, u32 *);
    extern void func_001E3210(u8 *, s32);
    u32 v[3];
    p[0x24] = *(s8 *)(q + 0x24) - 1;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        p[0x152] = 1;
        if (*(s8 *)(p + 0x151) == 0xC) {
            func_001266A0(p, 1, 1);
            v[0] = 0;
            v[1] = 0;
            func_0015D010(p, v);
            p[0x1B4] = 10;
            func_001E3210(p, 3);
        }
    }
}

extern u16 D_004D18DC;
extern u8 D_004D18DB;

void func_001A6DC0(u8 *p, u8 *q) {
    extern s32 func_00175700(u8 *);
    f32 *r5c, *r60, *r68, *r6c;
    if ((D_004D18DC & (1 << D_004D18DB)) == 0) {
        if ((s8)func_00175700(p) < 0) {
            p[4] = 2;
            p[0x13C] = 0;
        } else {
            r5c = (f32 *)(p + 0x5C);
            r68 = (f32 *)(p + 0x68);
            r60 = (f32 *)(p + 0x60);
            r6c = (f32 *)(p + 0x6C);
            *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
            *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
            *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
            if (*(f32 *)(p + 0x38) < *(f32 *)(q + 0x430)) {
                *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
                *r5c = 0;
                *r60 = 0;
                *r68 = 0;
                *r6c = 0;
            }
        }
    }
}

void func_00194850(u8 *p) {
    u8 *q = *(u8 **)(p + 0x14);
    f32 z = 0.0f;
    s32 a;
    *(f32 *)(p + 0x34) -= *(f32 *)(p + 0x5C);
    if (*(f32 *)(p + 0x5C) > z) {
        *(f32 *)(p + 0x68) -= *(f32 *)(p + 0x5C);
    } else {
        *(f32 *)(p + 0x68) += *(f32 *)(p + 0x5C);
    }
    if (*(f32 *)(p + 0x68) < 0.0f) {
        p[4]++;
        p[0x13C] = 0;
        q[0x21] |= 0x80;
    } else {
        a = 0;
        if (q[0x21] != 0) a = 0x2000;
        if (*(s16 *)(q + 0x140) == 0) a = (s16)-a;
        *(f32 *)(q + 0x34) = *(f32 *)(p + 0x34) + 1.6666666269302368f * a / 256.0f;
    }
}

void func_003BEB70(u8 *p, void *owner) {
    extern void func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E7F60(u8 *);
    f32 z = 0.0f;
    f32 d;
    s16 v;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    v = *(s16 *)(p + 0x1E) + 0x2000;
    *(s16 *)(p + 0x1E) = v;
    if (v == 0) p[0x1B2] = 0;
    d = *(f32 *)(p + 0x34) - (f32)*(s32 *)(p + 0xD0);
    if (d < z) d = -d;
    if (d < 40.0f) {
        p[5]++;
        func_001757E0(p, 0x16, 2);
    }
    func_001E7F60(p);
}

void func_003CCBF0(u8 *p, u8 *q) {
    extern s32 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_003CDB90(u8 *, s32);
    extern void func_003CAB20(u8 *, u8 *, unsigned int);
    if (p[6] == 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        func_00175700(p);
        if (*(f32 *)(p + 0x38) < *(f32 *)(q + 0x430)) {
            p[6]++;
            *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
            func_001757E0(p, 0x17, 0x33);
            func_003CDB90(p, 0);
        }
    } else {
        if ((s8)func_00175700(p) < 0) func_003CAB20(p, q, p[7]);
    }
}

void func_00224330(u8 *p) {
    extern s32 func_00175700(u8 *);
    extern void func_00183D50(u8 *);
    extern void func_00224420(u8 *);
    f32 *a, *b;
    f32 v;
    a = (f32 *)(p + 0x60);
    b = (f32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        p[6]++;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_00183D50(p);
        if (p[0x1E6] != 0) v = -6.666666507720947f;
        else v = 6.666666507720947f;
        *(f32 *)(p + 0x5C) = v;
        *(f32 *)(p + 0x68) = 0;
        *a = 0;
        *b = 0;
        func_00224420(p);
    }
}

void func_0036CE80(u8 *p) {
    extern void func_00176160(u8 *, s32, s32, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_0015E630(u8 *);
    f32 c;
    s32 t;
    p[0x13C] = 1;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(*(u8 **)(p + 0x18) + 0x3C);
    if (*(s16 *)(*(u8 **)(p + 0x18) + 0x140) != 0) c = 433.3333435058594f;
    else c = -433.3333435058594f;
    *(f32 *)(p + 0x34) += c;
    t = (*(s16 *)(*(u8 **)(p + 0x18) + 0x140) != 0) ? 0x30 : -0x30;
    *(f32 *)(p + 0x34) += (f32)t;
    p[0x24] = 9;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6C) = 0;
    func_00176160(p, 4, 4, 1);
    func_001757E0(p, 0x17, 0x2D);
    func_0015E630(p);
    p[0] = 1;
}

void func_003BF1E0(u8 *p, u8 *q) {
    extern s32 func_00174170();
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_003BEFE0(u8 *, s32);
    u32 r;
    s16 a;
    p[0x24] = 0;
    r = (u8)func_00174170();
    a = (r * 3) >> 2;
    a -= 0x60;
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + 1.6666666269302368f * (f32)a;
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(q + 0x18) + 0x430);
    *(f32 *)(p + 0x5C) = (*(f32 *)(q + 0x34) - *(f32 *)(p + 0x34)) / 24.0f;
    *(f32 *)(p + 0x60) = (*(f32 *)(q + 0x38) - *(f32 *)(p + 0x38)) / 24.0f;
    *(s32 *)(p + 0x6C) = 0;
    *(s32 *)(p + 0x68) = 0;
    *(s16 *)(p + 0x1C) = 0x18;
    func_001757E0(p, 0x16, (u8)(p[0x22] + 0x3B + (func_00174170() & 3)));
    func_003BEFE0(p, 0x200);
}

u8 *func_003BE5F0(u8 *p) {
    extern u8 *func_003DA750(s32, s32, s32);
    extern s32 func_00118FA8(f32);
    extern void func_003BE6F0();
    u8 *o;
    u8 i;
    s32 d;
    d = -0xE0;
    if (*(s16 *)(p + 0x140) != 0) d = 0xE0;
    for (i = 0; i < 2; i++) {
        if ((o = func_003DA750(0, 1, 0)) != 0) {
            f32 v;
            *(void **)(o + 0x10) = func_003BE6F0;
            *(u8 **)(o + 0x18) = p;
            o[1] = p[1];
            *(s16 *)(o + 0x26) = 0x3601;
            o[0x20] = i;
            o[0x21] = *(s8 *)(p + 0x140) ^ i;
            v = *(f32 *)(p + 0x34) + 1.6666666269302368f * (f32)d;
            *(f32 *)(o + 0x34) = v;
            *(s32 *)(o + 0xD0) = func_00118FA8(v);
            *(f32 *)(o + 0x38) = *(f32 *)(p + 0x430);
        }
    }
    return o;
}

void func_00222630(u8 *p) {
    extern s32 func_00175700(u8 *);
    extern void func_001843A0(u8 *);
    extern void func_00126400();
    u32 t;
    s32 x;
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        *(s8 *)(p + 0x151) = 0;
        t = p[6];
        p[6] = t + 1;
        *(u8 **)(*(u8 **)(p + 0x220) + 0x1C8) = p;
        (*(u8 **)(p + 0x220))[0x20A] = 1;
        x = *(s8 *)(p + 0x1E6) ^ 1;
        (*(u8 **)(p + 0x220))[0x1E6] = x;
        (*(u8 **)(p + 0x220))[0x1B5] = 0x22;
        func_00126400(x);
        (*(u8 **)(p + 0x220))[0x1B4] = 8;
        p[0x1B4] = 8;
        if (p[0x1E6] != 0) {
            *(u32 *)(p + 0x5C) = 0x40A00000;
            *(u32 *)(p + 0x68) = 0x3DD55555;
        } else {
            *(u32 *)(p + 0x5C) = 0xC0A00000;
            *(u32 *)(p + 0x68) = 0xBDD55555;
        }
        *(u32 *)(p + 0x60) = 0x412B6DB6;
        *(u32 *)(p + 0x6C) = 0xBF009249;
        p[0x20D] = 2;
    }
}

typedef struct { f32 x, y, z; } V3;
extern V3 D_0043DD80[];

void func_00132950(u8 *p, u8 *q) {
    extern f32 func_00417440(s32);
    f32 z = 0.0f;
    u32 t;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x6C) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x3C) += *(f32 *)(p + 0x64);
    if (*(s16 *)(p + 0x1E) >= 0) {
        z = 20.0f * func_00417440(*(s16 *)(p + 0x1E));
        *(s16 *)(p + 0x1E) += 0x400;
    }
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x6C) + z;
    t = p[0x23] - 1;
    p[0x23] = t;
    if (((u8)t & 0x80) != 0) {
        p[4] = 0;
        *(V3 *)(p + 0x34) = D_0043DD80[(q[0x425] << 1) + q[2]];
    }
}

void func_002537F0(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_001266A0(u8 *, s32, s32);
    extern void func_001548D0(u8 *, u32 *, s32);
    extern void func_001E3710(u8 *, s32);
    u8 *q;
    u32 t;
    f32 c;
    u32 v[3];
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        t = p[6];
        p[6] = t + 1;
        *(s8 *)(p + 0x151) = 0;
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x20A] = 1;
        q[0x20D] = 2;
        func_001266A0(p, 0, 0);
        q[0x1B5] = ((p[0x20B] & 1) != 0) ? 0x21 : 0x20;
        if (p[0x1E6] != 0) c = -5.0f;
        else c = 5.0f;
        *(f32 *)(p + 0x5C) = c;
        *(u32 *)(p + 0x60) = 0x414DB6DB;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        v[2] = 0;
        v[0] = 0xC2FA0000;
        v[1] = 0x430D6DB7;
        func_001548D0(p, v, 0xC);
        func_001E3710(p, 5);
    }
}

void func_003A14D0(u8 *p) {
    extern s32 func_00175700(u8 *);
    extern void func_001D2390(u8 *, s32);
    extern void func_001E7F60(u8 *);
    u8 *q = *(u8 **)(p + 0x18);
    s32 t;
    if (q[5] != 0 || q[0x1E4] != 0x1D) {
        p[4] = 2;
        p[0x13C] = 0;
        return;
    }
    p[0x24] = *(s8 *)(q + 0x24);
    t = (p[0x20] != 0) ? 4 : -4;
    p[0x31] = *(s8 *)(p + 0x31) + (s8)t;
    if ((s8)func_00175700(p) < 0) {
        p[4]++;
        p[0x13C] = 0;
        return;
    }
    if (p[0x21] == 0 && *(s8 *)(p + 0x1B2) != 0) {
        func_001D2390(q, 0);
        func_001D2390(q, 1);
        p[0x21] = 1;
    }
    if (p[0x20] == 0 && p[0x21] == 0) func_001E7F60(p);
}

typedef struct { s16 x, y, z; } E3;
extern E3 D_0044B470[];

void func_001A8A10(u8 *p, u8 *q) {
    extern void func_00175670(u8 *);
    extern void func_001754A0(u8 *, s32, s32);
    E3 *e;
    func_00175670(p);
    if (*(s8 *)(q + 0x151) == 0) {
        p[5]++;
        func_001754A0(p, 0x1B, 0x23);
    }
    e = &D_0044B470[p[0x20]];
    if (*(s16 *)(p + 0x140) == 0) {
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + 1.6666666269302368f * (f32)e->x;
    } else {
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) - 1.6666666269302368f * (f32)e->x;
    }
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38) + 2.1428570747375488f * (f32)e->y;
}

extern u8 *D_004CAB90[];

void func_001331E0(u8 *p) {
    extern void func_003DAA40(struct Object *);
    u8 *a;
    u8 *q;
    u8 *o;
    q = *(u8 **)(p + 0x18);
    p[0x13C] = 1;
    if (q[0x425] != 0) p[0x13C] = 0;
    if (*(s16 *)(q + 0x434) > 0 && *(s16 *)(p + 0x1C) != 0) {
        a = *(u8 **)(p + 0xD4);
        *(f32 *)(p + 0x50) = (f32)*(s16 *)a / (f32)*(s16 *)(p + 0x1C);
        o = D_004CAB90[q[0x1B8]];
        if (o != 0 && p != o) {
            if (a == *(u8 **)(o + 0xD4)) goto reset;
            o[0x13C] = 0;
        }
        D_004CAB90[q[0x1B8]] = p;
        if (*(s16 *)a > 0) return;
    }
reset:
    *(s16 *)(p + 0x1C) = 0;
    p[0x13C] = 0;
    D_004CAB90[q[0x1B8]] = 0;
    func_003DAA40((struct Object *)p);
}
