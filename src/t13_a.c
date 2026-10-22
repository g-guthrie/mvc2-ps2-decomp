typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s32 func_00178990(u8 *p) {
    extern void func_0018F320(u8 *);
    extern void func_00175700(void *);
    extern void func_001E3A10(void *);
    extern void func_00163D70(void *);
    extern s32 func_001864a0(void *);
    extern void func_00178D80(void *, s32);
    extern s32 func_00191210(void *);
    func_0018F320(p);
    func_00175700(p);
    if (*(s8 *)(p + 0x211) != 0) {
        if (p[0x24C] == 0) {
            p[0x24C] = 1;
            func_001E3A10(p);
            func_00163D70(p);
        }
    }
    if (*(f32 *)(p + 0x60) < 0.0f) {
        if (func_001864a0(p) != 0) {
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
            func_00178D80(p, 1);
            return func_00191210(p);
        }
    }
}

void func_0031D470(f32 *p) {
    extern s32 func_00175700(void *);
    extern void func_001757E0(void *, s32, s32);
    extern s32 func_001864a0(void *);
    p[0x34 / 4] += p[0x5C / 4];
    p[0x5C / 4] += p[0x68 / 4];
    p[0x38 / 4] += p[0x60 / 4];
    p[0x60 / 4] += p[0x6C / 4];
    func_00175700(p);
    if (func_001864a0(p) != 0) {
        u8 *q = (u8 *)p;
        u32 t = q[6];
        q[6] = t + 1;
        q[7] = 0;
        p[0x34 / 4] -= p[0x5C / 4];
        q[0x20D] = 0;
        func_001757E0(p, 0x12, 2);
    }
}

extern void (*D_00472480[])(void *, void *);

void func_003966A0(u8 *p, u8 *q) {
    extern void func_003DAA40(void *, void *);
    extern void func_001E7F60(void *);
    if (*(s32 *)(p + 0xD0) != *(u16 *)(q + 0x168)) {
        func_003DAA40(p, q);
        return;
    }
    D_00472480[p[5]](p, q);
    func_001E7F60(p);
}

extern f32 D_0045A7E0[];
extern f32 D_0045A7E4[];

void func_002D8300(u8 *p) {
    extern s32 func_00175700(void *);
    extern void func_00186A20(void *);
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_00186A20(p);
        *(f32 *)(p + 0x60) = *(f32 *)((u8 *)D_0045A7E4 + (p[0x1B7] << 3));
        *(u32 *)(p + 0x6C) = 0xC0092492;
        *(f32 *)(p + 0x5C) = *(f32 *)((u8 *)D_0045A7E0 + (p[0x1B7] << 3));
        *(u32 *)(p + 0x68) = 0xBC092492;
        if (p[0x1E6] == 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
    }
}

extern u8 D_004F1F45;
extern u8 D_004F1F46;

void func_001F2610(f32 *p) {
    extern s32 func_00175700(void *);
    extern s32 func_001864a0(void *);
    extern void func_001F72E0(void *);
    extern void func_001757E0(void *, s32, s32);
    ((u8 *)p)[0x206] = 3;
    p[0x34 / 4] += p[0x5C / 4];
    p[0x5C / 4] += p[0x68 / 4];
    p[0x38 / 4] += p[0x60 / 4];
    p[0x60 / 4] += p[0x6C / 4];
    func_00175700(p);
    if (func_001864a0(p) != 0) {
        u32 t = ((u8 *)p)[7];
        ((u8 *)p)[7] = t + 1;
        D_004F1F45 = 2;
        D_004F1F46 = 1;
        func_001F72E0(p);
        func_001757E0(p, 0xF, 0x1B);
    }
}

extern s8 D_004F7FC8[];
extern s8 D_00448FE0[];

void func_0018A920(u8 *p, u8 *q) {
    extern s32 func_00174170(void *);
    q[1] = D_004F7FC8[p[2]] * 10 + D_00448FE0[func_00174170(p) & 0x1F];
}

void func_00243210(u8 *p) {
    extern s32 func_00175700(void *);
    extern void func_00126400();
    extern void func_00158C70(void *, s32);
    extern void func_001E3A40(void *);
    f32 v[4];
    u8 *s;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        s = *(u8 **)(p + 0x1DC);
        *(u8 **)(s + 0x1C8) = p;
        s[0x20A] = 0xB;
        s[0x1E6] = p[0x1E6];
        *(s16 *)(s + 0x140) = *(s16 *)(p + 0x140);
        s[0x20D] = 2;
        s[0x1B5] = 0x21;
        func_00126400();
        v[0] = *(f32 *)(s + 0x34);
        v[1] = *(f32 *)(s + 0x430);
        func_00158C70(v, s[2]);
        func_001E3A40(p);
        D_004F1F45 = 1;
        D_004F1F46 = 1;
    }
}

void func_002CD390(u8 *p) {
    extern void func_00175700(void *);
    u32 *a = (u32 *)(p + 0x60);
    u32 *b = (u32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        u32 t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        *a = 0;
        *b = 0;
    }
}

extern u16 D_004D18DC[];
extern u8 D_004D18DB[];

void func_00390AF0(u8 *p) {
    extern int func_00174470(const void *);
    extern void func_00175700(void *);
    extern void func_001E7F60(void *);
    if ((D_004D18DC[0] & (1 << D_004D18DB[0])) == 0) {
        *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
        if (p[5] == 0) {
            if (func_00174470(p) == 0) {
                p[4] = 2;
            } else if (*(s8 *)(p + 0x1B2) != 0) {
                u32 t = p[4];
                p[4] = t + 1;
            } else {
                *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
                *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
                func_00175700(p);
                func_001E7F60(p);
            }
        }
    }
}

extern u8 D_004D18A0;

void func_00187780(u8 *p) {
    extern void func_00191210(void *);
    extern void func_001757E0(void *, s32, s32);
    p[0x20D] = 3;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(s8 *)(p + 0x1B1) = -0x80;
    p[0x201] = 0;
    if (D_004D18A0 < 5) {
        if (p[0x1F0] == 0) {
            p[0x201] = 2;
            p[0x1B1] = 0;
        }
    }
    if (*(s16 *)(p + 0x1FA) == 0) {
        *(s16 *)(p + 0x1FA) = *(s16 *)(p + 0x240);
        if (*(s8 *)(p + 0x1F7) == 0) {
            p[0x1F7] = 0xA;
        }
    }
    if (*(s8 *)(p + 0x1EE) < 0) {
        *(s16 *)(p + 0x1FA) = 0;
    }
    if (*(s16 *)(p + 0x434) == 0) {
        func_00191210(p);
    }
    func_001757E0(p, 0xD, 0x1F);
}

void func_00306DC0(u8 *p, u8 *q) {
    extern void func_001757E0(void *, s32, s32);
    extern void func_00175700(void *);
    if (q[4] != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        if (p[7] == 0) {
            func_001757E0(p, 0x15, 1);
        } else {
            func_001757E0(p, 0x15, 0xF);
        }
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    }
    func_00175700(p);
}

void func_001F57C0(u8 *p) {
    extern s32 func_00175700(void *);
    extern void func_00175C00(void *, s32);
    extern void func_001757E0(void *, s32, s32);
    extern void func_001830D0(void *, void *, s32);
    u32 v[4];
    s8 r = func_00175700(p);
    if (r < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        if (p[0x216] == 0) {
            p[0x216] = 0x80;
        } else {
            p[0x216] = 0;
        }
        func_00175C00(p, 0);
        func_001757E0(p, 0x15, 0xF);
        v[0] = 0xC2D55555;
        v[1] = 0x432B6DB6;
        func_001830D0(p, v, 1);
    }
}

typedef struct {
    s32 n;
    s32 tot;
    f32 dx;
    f32 dy;
    s32 pad0;
    f32 o0, o1, o2, o3;
    s32 pad[2];
    u8 a, b;
} S32D;

void func_0032D390(u8 *p, s32 n, u8 a, u8 b, f32 x, f32 y) {
    extern void func_0032D230(S32D *);
    extern void func_0032D290(S32D *);
    S32D s;
    s.n = n;
    s.tot = s.n + s.n * (s.n - 1) / 2;
    s.dx = x - *(f32 *)(p + 0x34);
    s.dy = y - *(f32 *)(p + 0x38);
    s.a = a;
    s.b = b;
    if (s.n == 0) {
        s.o3 = 0;
        s.o2 = 0;
        s.o1 = 0;
        s.o0 = 0;
    } else {
        func_0032D230(&s);
        func_0032D290(&s);
    }
    *(f32 *)(p + 0x5C) = s.o0;
    *(f32 *)(p + 0x68) = s.o1;
    *(f32 *)(p + 0x60) = s.o2;
    *(f32 *)(p + 0x6C) = s.o3;
}

void func_0025A760(u8 *p) {
    extern void func_002555E0(void *);
    extern void func_001548D0(void *, void *, s32);
    extern void func_001E3710(void *, s32);
    extern void func_0018FC10(void *, s32);
    extern void func_0016CED0();
    extern void func_00175700(void *);
    u8 *s;
    u32 v[4];
    p[0x1FE] = 1;
    p[0x201] = 2;
    p[0x209] = 2;
    func_002555E0(p);
    s = *(u8 **)(p + 0x1DC);
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        v[1] = 0x42F00000;
        v[0] = 0;
        func_001548D0(s, v, 0xD);
        func_001E3710(p, 6);
        func_0018FC10(s, -1);
    }
    if (*(s8 *)(p + 0x153) < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        *(s16 *)(p + 0x1C) = 100;
        func_0016CED0();
    } else {
        func_00175700(p);
    }
}
