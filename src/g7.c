typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern int func_00175700(u8 *);
extern void func_00178F20();
extern void func_001C88F0();
extern void func_001C8AE0();

void func_00258990(u8 *p) {
    *(float *)(p + 0x38) += *(float *)(p + 0x60);
    *(float *)(p + 0x60) += *(float *)(p + 0x6C);
    func_00175700(p);
    {
        s16 o = *(s16 *)(p + 0x1C);
        *(s16 *)(p + 0x1C) = o - 1;
        if (o == 0) {
            u32 t = p[7];
            p[7] = t + 1;
        }
    }
}

extern void func_00197620();
typedef void (*OwnerStateCallback)(u8 *, u8 *);
extern OwnerStateCallback D_0044A2A0[];

void func_00195920(u8 *a0, u8 *a1) {
    u8 *a2 = a0 + 0x88;
    if (a1[0x169] != 0x12) {
        a0[7] = 0;
        a0[6] = 0;
        a0[5] = 0;
        *a2 = 1;
        func_00197620(a0, a1, a2);
    } else {
        D_0044A2A0[a0[6]](a0, a1);
    }
}

typedef struct V3 { float x, y, z; } V3;
typedef struct E32 { u8 b[32]; } E32;
extern V3 D_00442A20[];
extern E32 D_004429B0[];
extern void func_00146F50();

void func_001472B0(u8 *p) {
    u32 t = p[4];
    p[4] = t + 1;
    p[0x13C] = 1;
    {
        *(V3 *)(p + 0x34) = D_00442A20[p[0x20]];
    }
    *(E32 **)(p + 0xD8) = &D_004429B0[p[0x20]];
    func_00146F50();
}

extern u8 *func_003DA750();
extern void func_00385F50();

void func_00385EE0(u8 *a0, s32 a1) {
    u8 *q = a0 + 0x2B8;
    u8 *r = func_003DA750(0, 1, 0);
    if (r != 0) {
        *(void **)(r + 0x10) = func_00385F50;
        *(u8 **)(r + 0x18) = a0;
        r[0x20] = a1;
        *(u32 *)(r + 0xD0) = q[2];
    }
}

extern int func_00174470(const void *);
extern void func_0034FA60();
extern void func_001E7F60();

void func_0034F890(u8 *p) {
    *(float *)(p + 0x34) += *(float *)(p + 0x5C);
    *(float *)(p + 0x5C) += *(float *)(p + 0x68);
    func_00175700(p);
    if (func_00174470(p) == 0) {
        func_0034FA60(p);
    } else {
        func_001E7F60(p);
    }
}

extern void func_00179160();
extern s32 func_00393390();
extern void func_003933A0();

extern void func_003992C0();

void *func_00399240(u8 *a0, s32 a1, s32 a2) {
    u8 *r = func_003DA750(0, 1, 0);
    if (r != 0) {
        *(void **)(r + 0x10) = func_003992C0;
        *(u8 **)(r + 0x18) = a0;
        *(s16 *)(r + 0x26) = 0x2504;
        r[0xD2] = a2;
        r[0xD3] = a1;
        *(u16 *)(r + 0xD0) = *(u16 *)(a0 + 0x168);
    }
    return r;
}

extern s32 func_001341B0();
extern s32 func_00134230();
extern s32 func_001342D0();
extern s32 func_00134370(u8 *, u8 *);
extern s32 func_001343E0();

void func_00133B20(u8 *p, u8 *b) {
    *(s16 *)(p + 0x140) = 0;
    if (func_001341B0(p, b) && func_00134230(p, b) && func_001342D0(p, b) && func_00134370(p, b)) {
        func_001343E0(p, b);
    }
}

extern u8 *func_001E7FD0(u8 *);
extern s32 func_0016A130();
extern s32 func_0016A1F0();

s32 func_00168F00(u8 *p, s32 n) {
    if (n > 2) return 0;
    if (p[0x215] == 0) {
        if (func_001E7FD0(p)) return func_0016A130(p, 2, 2);
    }
    return func_0016A1F0(p, 2);
}

void func_001921F0(u8 *p) {
    u32 t = p[6];
    p[6] = t + 1;
    p[0x206] = 10;
    p[0x207] = 10;
    *(s16 *)(p + 0x1C) = 0x10;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x5C) = 0xC17D5555;
    *(u32 *)(p + 0x68) = 0x3EA00000;
    if (p[0x1E6] != 0) {
        *(float *)(p + 0x5C) = -*(float *)(p + 0x5C);
        *(float *)(p + 0x68) = -*(float *)(p + 0x68);
    }
    func_001757E0(p, 2, 4);
}

extern void func_003C80A0();

void func_003C7130(u8 *a0, u8 *a1) {
    u8 *a2 = *(u8 **)(a0 + 0x14);
    if (a2[4] >= 2 || a2[0x169] != 0x15 || a2[0x168] != 0x1A) {
        func_003C80A0(a0, a1);
    } else {
        *(float *)(a0 + 0x34) = *(float *)(a2 + 0x34);
        *(float *)(a0 + 0x38) = *(float *)(a2 + 0x38);
        *(s8 *)(a0 + 0x24) = *(s8 *)(a2 + 0x24);
        *(s8 *)(a0 + 0x31) = *(s8 *)(a2 + 0x31);
        func_00175700(a0);
    }
}

extern void func_00362CA0();

void func_003630D0(u8 *p, s32 b) {
    u32 t = p[6];
    p[6] = t + 1;
    if (*(s16 *)(p + 0x140) == 0) {
        *(u32 *)(p + 0x5C) = 0xC0FD5555;
    } else {
        *(u32 *)(p + 0x5C) = 0x40FD5555;
    }
    *(u32 *)(p + 0x68) = 0;
    func_001757E0(p, 0x17, 0xD);
    func_00362CA0(p, b);
}

extern void func_003898C0();
extern void (*D_00464B80[])();

void func_00389590(u8 *a0, u8 *a1) {
    u8 *q = a1 + 0x2B8;
    if (*(s16 *)(a1 + 0x2D6) == 0) {
        u32 t = a0[5];
        a0[5] = t + 1;
        a0[6] = 0;
        a0[0x13C] = 1;
        func_003898C0(a0, a1);
    } else {
        a0[0x13C] = 1;
        if (q[0x19] != 0) a0[0x13C] = 0;
        D_00464B80[a0[0x20]](a0, a1);
    }
}

extern int func_00175670(u8 *);

void func_001C1080(u8 *a0, u8 *a1) {
    if ((s8)func_00175670(a0) < 0) {
        u32 t = a0[5];
        a0[5] = t + 1;
        if (*(s32 *)(a1 + 0xD0) == 0) {
            *(u32 *)(a0 + 0x5C) = 0xC0555555;
            *(u32 *)(a0 + 0x68) = 0xC0555555;
        } else {
            *(u32 *)(a0 + 0x5C) = 0x40555555;
            *(u32 *)(a0 + 0x68) = 0x40555555;
        }
    }
}

void func_001D9110(u8 *a0, u8 *a1) {
    if (*(u16 *)(a1 + 0x168) != *(u16 *)(a0 + 0xD0)) {
        u32 t = a0[4];
        a0[4] = t + 1;
        a0[0x13C] = 0;
    } else {
        *(s8 *)(a0 + 0x24) = *(s8 *)(a1 + 0x24);
        *(float *)(a0 + 0x34) = *(float *)(a1 + 0x34);
        *(float *)(a0 + 0x38) = *(float *)(a1 + 0x38);
        func_00175700(a0);
        {
            s16 o = *(s16 *)(a0 + 0x1C);
            *(s16 *)(a0 + 0x1C) = o - 1;
            if (o == 0) {
                u32 t = a0[4];
                a0[4] = t + 1;
                a0[0x13C] = 0;
            }
        }
    }
}

void func_001F0FF0(u8 *a0) {
    u8 *q = a0 + 0x2B8;
    a0[0x1FE] = 1;
    a0[0x201] = 2;
    a0[0x209] = 2;
    a0[0x206] = 3;
    if ((s8)func_00175700(a0) < 0) {
        u32 t = a0[7];
        a0[7] = t + 1;
        q[2] = 0;
        func_001757E0(a0, 0xF, 0xB);
    }
}

extern u8 D_0044C890[];
extern void func_001C1CA0();
extern void func_001754A0();
extern void func_001C19A0();

void func_001C1910(u8 *a0, u8 *a1) {
    u8 *a3 = a1 + 0x2B8;
    if (a1[0x378] != 0 && *(s8 *)(a1 + 0x379) < 0x41) {
        u32 t = a0[5];
        a0[5] = t + 1;
        a3[1] = 1;
        func_001C1CA0(a0, a1, D_0044C890);
        func_001754A0(a0, 0x1B, 6);
        func_001C19A0(a0, a1);
    }
}

void func_003259E0(u8 *p) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v <= 0) {
            u32 t;
            p[0x40D] = 0;
            p[0x40C] = 0;
            p[0x33B] = 0;
            p[0x33C] = 0;
            t = p[6];
            p[6] = t + 1;
            *(s16 *)(p + 0x1C) = 0xB4;
            func_001757E0(p, 0x16, 0x16);
        }
    }
}

extern s32 func_00169BC0();
extern s32 func_00169AE0();

s32 func_00169A50(u8 *a0) {
    u8 *t;
    u32 s = a0[0x451];
    switch (s) {
    case 0:
        a0[0x451] = s + 1;
        t = *(u8 **)(a0 + 0x1A8);
        *(u8 **)(a0 + 0x48C) = t + *(s32 *)(t + a0[0x492] * 4);
        *(s16 *)(a0 + 0x490) = 0;
        a0[0x493] = 0;
    case 1:
        return func_00169AE0(a0, 3);
    case 2:
        return func_00169BC0(a0, 3);
    }
    return 0;
}

extern s8 *D_004460E0[];
extern s8 *D_004460E4[];
extern s16 D_004D1802;
extern s32 func_00174170();

s32 func_00169DD0(s32 a0, s32 a1) {
    s8 *s0 = D_004460E0[a1];
    s8 *s1 = D_004460E4[a1];
    s32 r = s0[D_004D1802] + s1[func_00174170() & 0x1F];
    if (r < 0) r = 0;
    return r;
}
