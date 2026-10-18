typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_001830D0(u8 *, u32 *, int, int);
extern void func_00183d50(u8 *);
extern void func_001843A0(u8 *);

/* 0x002795E0 */
void func_002795E0(u8 *p) {
    u32 v[3];
    func_00175700(p);
    if ((s8)p[0x151] != 0) {
        u32 t = p[6] + 1;
        p[6] = t;
        p[0x151] = 0;
        v[0] = 0xC2CEAAAA;
        v[1] = 0x43D86DB6;
        v[2] = 0;
        func_001830D0(p, v, 1, t);
    }
}

/* 0x0026A410 */
void func_0026A410(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if (p[0x15B] != 0) {
        u8 *q;
        p[0x15B] = 0;
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x1E6] = p[0x1E6];
        q[0x1B5] = 0x21;
        q[0x20A] = 0x10;
    }
}

/* 0x00365FC0 */
extern u8 *func_003DA750(u8 *, int, int);
extern void func_00366090();
void func_00365FC0(u8 *p) {
    u8 *v = func_003DA750(p, 1, 2);
    if (v != 0) {
        *(void **)(v + 0x10) = func_00366090;
        *(u32 *)(v + 0x18) = *(u32 *)(p + 0x18);
        *(u8 **)(v + 0x14) = p;
        *(u8 **)(p + 0x14) = v;
        v[0x20] = 1;
        *(s16 *)(v + 0x26) = 0x1101;
    }
}

/* 0x00289A00 */
extern void func_00289E30(u8 *);
void func_00289A00(u8 *p) {
    func_00175700(p);
    func_00289E30(p);
    if (!(*(f32 *)(p + 0x430) < *(f32 *)(p + 0x38))) {
        p[7]++;
        p[0x20D] = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_00183d50(p);
        func_001757E0(p, 0x15, (u8)(p[0x1B7] + 6));
    }
}

/* 0x00386EC0 */
extern void func_00386600();
void func_00386EC0(u8 *p, u32 x) {
    u8 *v = func_003DA750(0, 1, 0);
    if (v != 0) {
        *(void **)(v + 0x10) = func_00386600;
        *(u32 *)(v + 0x18) = x;
        *(s8 *)(v + 0x20) = *(s8 *)(p + 0x20) + 1;
        *(u8 **)(v + 0x14) = p;
        *(s8 *)(v + 0x31) = *(s8 *)(p + 0x31) + 1;
        *(s16 *)(p + 0x1E) = 0;
    }
}

/* 0x003BA230 */
extern void func_003BA360();
void func_003BA230(u8 *p, u32 a, u32 b) {
    u8 *v = func_003DA750(0, 1, 1);
    if (v != 0) {
        *(void **)(v + 0x10) = func_003BA360;
        *(f32 *)(v + 0x34) = *(f32 *)(p + 0x34);
        *(f32 *)(v + 0x38) = *(f32 *)(p + 0x38);
        *(u8 **)(v + 0x18) = p;
        v[1] = p[1];
        *(s16 *)(v + 0x26) = 0x3504;
        v[0x20] = a;
        v[0x21] = b;
        *(u32 *)(v + 0xD0) = *(u32 *)(p + 0x220);
    }
}

/* 0x0024D0C0 */
extern void func_0018C6E0(u8 *);
void func_0024D0C0(u8 *p) {
    if (p[0x22] & 1) {
        p[0x1E6] ^= 1;
        *(s16 *)(p + 0x140) = p[0x1E6];
    }
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(f32 *)(p + 0x60) /= 2.0f;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    func_0018C6E0(p);
    func_001757E0(p, 0xF, 1);
}

/* 0x001EF8E0 */
typedef struct { u8 pad[0x160]; s8 b[8]; } S160;
void func_001EF8E0(u8 *p) {
    S160 *a = (S160 *)p;
    s8 *r;
    s8 *q;
    func_00175700(p);
    r = a->b;
    q = r + 1;
    if (r[1] != 0) {
        u32 t = p[7];
        p[7] = t + 1;
        *q = 0;
        *(u32 *)(p + 0x5C) = 0x4162AAAA;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0xC1892492;
        *(u32 *)(p + 0x6C) = 0xBF092492;
        if (p[0x1E6] == 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        }
    }
}

/* 0x00310BF0 */
void func_00310BF0(u8 *p) {
    func_00175700(p);
    if ((s8)p[0x151] != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        *(u32 *)(p + 0x5C) = 0xC1195555;
        *(u32 *)(p + 0x68) = 0x3DD55555;
        *(u32 *)(p + 0x60) = 0x413C9249;
        *(u32 *)(p + 0x6C) = 0xBF22DB6D;
        if (*(s16 *)(p + 0x140) != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
    }
}

/* 0x00229540 */
void func_00229540(u8 *p) {
    u32 v[3];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    if ((s8)func_00175700(p) < 0) {
        u32 t;
        p[0x404] = 0;
        p[0x405] = 0;
        t = p[6] + 1;
        p[6] = t;
        v[0] = 0xC1E2AAAA;
        v[1] = 0x432D9249;
        func_001830D0(p, v, 1, t);
    }
}

/* 0x00157140 */
extern s8 D_004D1900;
extern void func_00156F50(u8 *, int);
extern void func_00157080(u8 *, int);
extern void func_003DAA40(u8 *);
void func_00157140(u8 *p) {
    if (*(s16 *)(p + 0x1C) == 2) {
        func_00156F50(p, p[0x23]);
    }
    if (*(s16 *)(p + 0x1C) == 10) {
        func_00157080(p, p[0x23]);
    }
    if (*(s16 *)(p + 0x1C) >= 10) {
        D_004D1900--;
        func_003DAA40(p);
    } else {
        *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
    }
}

/* 0x0020D6B0 */
extern void func_0034E1C0(u8 *);
void func_0020D6B0(u8 *p) {
    s16 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v <= 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        *(s16 *)(p + 0x1C) = 0x28;
    } else if ((s8)p[0x151] != 0) {
        p[0x151] = 0;
        func_0034E1C0(p);
    }
}

/* 0x0019F050 */
void func_0019F050(u8 *p, u16 *q) {
    u8 *r = *(u8 **)(p + 0x18);
    p[0x13C] = 0;
    if (*(u16 *)(r + 0x168) != *q) {
        u32 t = p[4];
        p[4] = t + 1;
    } else if ((s8)r[0x151] != 0) {
        *(s16 *)(p + 0x140) = *(s16 *)(r + 0x140);
        *(s8 *)(p + 0x31) = -2;
        *(f32 *)(p + 0x34) = *(f32 *)(r + 0x34) + *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x38) = *(f32 *)(r + 0x38) + *(f32 *)(p + 0x60);
        func_00175700(p);
        if ((s8)p[0x150] == 0) {
            p[0x13C] = 1;
        }
    }
}

/* 0x0019E790 */
void func_0019E790(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        *(u32 *)(p + 0x6C) = 0;
        p[5]++;
        func_001757E0(p, 0x13, 9);
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
}

/* 0x0019CA20 */
static void func_0019C840(u8 *p) {
    p[0x1D] = 1;
}
extern void func_0019CAC0(u8 *);
extern void func_0019C7E0(u8 *);
void func_0019CA20(u8 *p) {
    u8 *q;
    func_00175700(p);
    func_0019C840(p);
    q = *(u8 **)(p + 0x18);
    if (q[0x169] != 0x13) {
        u32 t = p[4];
        p[4] = t + 1;
        func_0019CAC0(p);
    } else if (p[0x20] == 0 && p[5] == 0 && (s8)q[0x151] != 0) {
        u32 t = p[5];
        p[5] = t + 1;
        func_001757E0(p, 0x13, 7);
        func_0019C7E0(p);
    }
}

/* 0x002CF940 */
void func_002CF940(u8 *p) {
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        p[6]++;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        func_001757E0(p, 0x15, (u8)(p[0x1B7] + 0x17));
        func_00183d50(p);
    } else {
        func_00175700(p);
    }
}

/* 0x0034E090 */
extern int func_00174470(u8 *);
extern void func_001E7F60(u8 *);
void func_0034E090(u8 *p) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if ((s8)p[0x1B2] != 0 || func_00174470(p) == 0) {
        p[4]++;
    }
    func_001E7F60(p);
}

/* 0x00259D10 */
static void func_002555E0(u8 *p) {
    p[0x1D] = 1;
}
void func_00259D10(u8 *p) {
    func_002555E0(p);
    if ((s8)p[0x151] == 3) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
    }
    func_00175700(p);
}

