typedef unsigned char u8; typedef signed char s8; typedef unsigned short u16; typedef signed short s16; typedef unsigned int u32; typedef signed int s32; typedef float f32;

extern u8 D_004D1820[];
void func_00170B30(u8 *p) {
    s32 i = 0; u8 *q = *(u8 **)(p + 4); s32 o = 0;
    do {
        *(s32 *)(D_004D1820 + o) = *(s32 *)(q + 0x44);
        i++;
        o += 0x10;
        q += 0x4C;
    } while (i <= 3);
}

typedef struct { u8 p0[0x34]; f32 f34, f38; u8 p3c[0x20]; f32 f5c, f60; u8 p64[4]; f32 f68, f6c; u8 p70[0x3C0]; f32 f430; } S_4BB0;
void func_00224BB0(S_4BB0 *p) {
    f32 *v1, *a1, *a2, *a3;
    p->f34 += p->f5c;
    v1 = &p->f5c;
    a2 = &p->f68;
    a1 = &p->f60;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    a3 = &p->f6c;
    if (p->f38 <= p->f430) {
        p->f38 = p->f430;
        *v1 = 0; *a1 = 0; *a2 = 0; *a3 = 0;
    }
}

typedef struct { u8 p0[0x34]; f32 f34, f38; u8 p3c[0x20]; f32 f5c, f60; u8 p64[4]; f32 f68, f6c; } T_DC90;
typedef struct { u8 p0[7]; u8 b7; u8 p8[0x14]; s16 h1c; u8 p1e[0x1BE]; T_DC90 *t1dc; u8 p1e0[0x15C]; u8 b33c; u8 p33d[0xCF]; u8 b40c; } S_DC90;
void func_0026DC90(S_DC90 *p) {
    extern void func_001266A0();
    p->b40c = 2;
    p->b33c = 5;
    p->t1dc->f34 += p->t1dc->f5c;
    p->t1dc->f5c += p->t1dc->f68;
    p->t1dc->f38 += p->t1dc->f60;
    p->t1dc->f60 += p->t1dc->f6c;
    {
        s16 v = p->h1c - 1;
        p->h1c = v;
        if (v <= 0) {
            { u32 t = p->b7; p->b7 = t + 1; }
            func_001266A0(p, 5, 5);
        }
    }
}

void func_002F4110(u8 *p) {
    extern void func_00175700();
    extern s32 func_003AA280();
    extern void func_001E3210();
    *(u16 *)(p + 0x366) |= (*(s16 *)(p + 0x362) & 0x360);
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        if (func_003AA280(p) == 0) {
            p[6] = 3;
        } else {
            u32 t = p[6];
            p[6] = t + 1;
            func_001E3210(p, 0x20);
        }
    }
}

extern f32 D_00459A20[];
extern f32 D_00459A24[];
typedef struct { u8 p0[7]; u8 b7; u8 p8[0x54]; f32 f5c; u8 p60[8]; f32 f68; u8 p6c[0xE5]; s8 b151; u8 p152[0x65]; u8 b1b7; u8 p1b8[0x2E]; u8 b1e6; } S_14E0;
void func_002C14E0(S_14E0 *p) {
    extern void func_00175700();
    func_00175700(p);
    if (p->b151 != 0) {
        u32 t = p->b7;
        p->b7 = t + 1;
        p->f5c = *(f32 *)((u8 *)D_00459A20 + (p->b1b7 << 3));
        p->f68 = *(f32 *)((u8 *)D_00459A24 + (p->b1b7 << 3));
        if (p->b1e6 != 0) {
            p->f5c = -p->f5c;
            p->f68 = -p->f68;
        }
    }
}

typedef struct { u8 p0[0x34]; f32 f34, f38; u8 p3c[0x20]; f32 f5c, f60; u8 p64[4]; f32 f68, f6c; u8 p70[0x3C0]; f32 f430; } S_FBE0;
typedef struct { u8 p0[0x18]; S_FBE0 *s18; } T_FBE0;
s32 func_001AFBE0(S_FBE0 *p) {
    extern void func_00175670();
    extern s32 func_00174240();
    extern s32 func_001AFC90();
    S_FBE0 *q = *(S_FBE0 **)((u8 *)p + 0x18);
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    func_00175670(p);
    if (func_00174240(p) == 0) {
        return func_001AFC90(p);
    }
    if (p->f38 <= q->f430) {
        return func_001AFC90(p);
    }
}

typedef struct { u8 p0[4]; s16 h4, h6; u8 p8[0x14]; s16 h1c; u8 p1e[0x16]; f32 f34; u8 p38[4]; f32 f3c; u8 p40[0x10]; f32 f50, f54, f58; f32 f5c; u8 p60[4]; f32 f64; u8 p68[0x10]; f32 f78, f7c, f80; } S_9CD0;
extern u8 D_00444EB0[], D_00444EC0[];
void func_00159CD0(S_9CD0 *p) {
    extern void func_003DAA40();
    extern f32 func_00154710();
    f32 v;
    if (p->h1c >= 0xC) {
        func_003DAA40();
        return;
    }
    p->f34 += p->f5c;
    p->f3c += p->f64;
    v = func_00154710(D_00444EB0, &p->h4, p->h1c);
    p->f50 = v;
    p->f54 = v;
    p->f58 = p->f50;
    v = func_00154710(D_00444EC0, &p->h6, p->h1c);
    p->f78 = v;
    p->f7c = v;
    p->f80 = p->f78;
    p->h1c = p->h1c + 1;
}

void func_002ED680(u8 *p) {
    extern void func_00175700();
    extern void func_001843A0();
    extern void func_003A6DC0();
    s16 v;
    func_00175700(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        func_001843A0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) & 1) {
        *(s8 *)(p + 0x151) &= ~1;
        func_003A6DC0(p, 1, 9);
    }
    if (*(s8 *)(p + 0x151) & 2) {
        u8 *q;
        *(s8 *)(p + 0x151) &= ~2;
        q = *(u8 **)(p + 0x1DC);
        q[0x20A] = 1;
        q[0x20D] = 2;
        q[0x1B5] = 0x22;
        p[0x1B5] = 0x22;
        q[0x1E6] = p[0x1E6];
        q[0x1E6] ^= 1;
    }
}

extern u8 D_0045BE30[];
void func_002F7460(u8 *a, u8 *p) {
    extern void func_00175C00();
    extern void func_00176160();
    s32 v = *(s16 *)(p + 0xE);
    if (v != 0) {
        u32 t;
        *(s16 *)(p + 0xE) = v - 1;
        t = p[0x14];
        p[0x14] = t - 1;
        if (t == 0) {
            u32 u;
            p[0x14] = 4;
            u = p[0x15];
            p[0x15] = u + 1;
            if (D_0045BE30[p[0x15]] == 0xFF) {
                p[0x15] = 2;
            }
            func_00176160(a, 0, D_0045BE30[p[0x15]] + 0x30 + a[0x25] * 28, 1);
        }
    } else {
        func_00175C00(a, 0);
        p[0xD] = 0;
        p[0x16] = 0;
    }
}

typedef struct { f32 x, y, z; } V_72B0;
typedef struct { u8 p0[4]; u8 b4; u8 p5[2]; u8 b7; u8 p8[0x14]; s16 h1c; u8 p1e[0x16]; V_72B0 v34; u8 p40[0x1C]; f32 f5c, f60, f64, f68, f6c, f70; } S_72B0;
extern V_72B0 D_0043F1C0[24];
extern u8 D_00583B9B;
void func_001372B0(S_72B0 *p) {
    V_72B0 *row;
    s16 t = p->h1c - 1;
    p->h1c = t;
    if (p->h1c < 0) {
        u32 u = p->b4;
        p->b4 = u + 1;
        row = (V_72B0 *)((u32)D_0043F1C0 + (u32)p->b7 * 12u);
        p->v34 = *row;
        D_00583B9B = 1;
    } else {
        p->v34.x += p->f5c;
        p->f5c += p->f68;
        p->v34.y += p->f60;
        p->f60 += p->f6c;
        p->v34.z += p->f64;
        p->f64 += p->f70;
    }
}

typedef struct { u8 p0[4]; u8 b4; u8 p5[0x17]; s16 h1c; u8 p1e[2]; u8 b20; u8 p21[0x13]; f32 f34, f38; } S_0970;
void func_00340970(S_0970 *p) {
    extern void func_00340A40();
    s32 h = p->h1c;
    if (h != 0) {
        p->h1c = h - 1;
        if (p->b20 < 4) {
            func_00340A40();
            return;
        }
        p->f34 += (f32)((p->h1c % 2) ? 2 : -2);
        p->f38 += (f32)((p->h1c % 2) ? 4 : -4);
    } else {
        u32 t = p->b4;
        p->b4 = t + 1;
        p->h1c = 0x1E;
    }
}

typedef struct { u8 p0[0x34]; f32 f34; } O_45F0;
s32 func_003245F0(u8 *p) {
    extern void func_001757E0();
    extern void func_00175700();
    s32 v1 = 0;
    s32 s1, s2;
    s32 a0;
    O_45F0 *o = *(O_45F0 **)(p + 0x220);
    if (*(f32 *)(p + 0x34) < o->f34) {
        v1 = 1;
    }
    if (p[0x1E6] != v1) {
    *(s16 *)(p + 0x140) = v1;
    p[0x1E6] = v1;
    {
        u32 t = *(u16 *)(p + 0x35E);
        s1 = *(s8 *)(p + 0x152);
        s2 = *(s8 *)(p + 0x150);
        a0 = 7;
        if (t & 0x800) a0 = 0xE;
    }
    func_001757E0(p, 0x16, (u8)a0);
    for (;;) {
        if (*(s8 *)(p + 0x150) == s2) {
            p[0x152] = s1;
            break;
        }
        p[0x152] = 1;
        func_00175700(p);
    }
    return 1;
    }
    return 0;
}

void func_001537D0(u32 a, u32 b, f32 x, f32 y) {
    extern void func_00153A40(s32, s32);
    extern void func_003DDAD0(f32 *, f32, f32, f32);
    extern void func_003DDDC0(f32 *, f32, f32, f32);
    extern void func_003DD260(f32 *);
    extern void func_003DF850(s32, f32 *);
    f32 m[16];
    if (b & 0x100) {
        func_00153A40((b >> 16) & 7, (b >> 19) & 7);
    } else {
        func_00153A40(1, 0);
    }
    if (b & 2) {
        f32 *q;
        if (a & 0x20000) {
            func_003DDAD0(m, x, y, 0.0f);
            func_003DDDC0(m, 0.0f, 0.0f, 0.0f);
            q = m;
        } else {
            func_003DD260(m);
            q = m;
        }
        func_003DF850(0x1A, q);
    }
}
