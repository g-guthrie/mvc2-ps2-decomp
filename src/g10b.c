typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s8 func_00175700();
extern void func_00175C00();
extern void func_001757E0();

void func_002350F0(u8 *p) {
    s8 r = func_00175700(p);
    if (r < 0) {
        u32 t = p[5];
        p[5] = t + 1;
        p[6] = 0;
        p[7] = 0;
        p[0x20] = 0;
        func_00175C00(p, 1);
        func_001757E0(p, 0, 0);
    }
}

void func_0020B900(u8 *p) {
    s16 v;
    func_00175700(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 0x15, (u8)(p[0x1B7] * 2 + 10));
    }
}

void func_00265F80(u8 *p) {
    s8 r;
    u8 x = 2;
    p[0x40C] = x;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? x : 0;
    r = func_00175700(p);
    if (r < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        *(s16 *)(p + 0x1C) = 0xB4;
    }
}
extern void func_001843A0();
extern void func_00183920();

void func_002AABA0(u8 *p) {
    u32 v[3];
    s8 r = func_00175700(p);
    if (r < 0) {
        func_001843A0(p);
    } else if (*(s8 *)(p + 0x151) & 1) {
        p[0x151] = 0;
        v[0] = 0x41C80000;
        v[1] = 0x433C9249;
        v[2] = 0;
        func_00183920(p, v);
    }
}
extern void func_00184540();
extern void func_001E3240();

void func_001ACA90(u8 *p, void *owner) {
    s16 v;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    v = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = v;
    if (v == 0) {
        u32 t = p[5];
        p[5] = t + 1;
        func_001757E0(p, 0x17, 0x15);
    }
}

void func_00212D20(u8 *p) {
    s8 r = func_00175700(p);
    if (r < 0) {
        func_001E3240(p, 0x1F);
        func_001E3240(p, 0x20);
        func_00175C00(p, 0);
        if (p[0x20D] == 2) {
            func_00184540(p);
        } else {
            func_001843A0(p);
        }
    }
}
typedef struct { f32 x, y, z; } V3;
extern void func_00376A50();
extern void func_003A8D10();
extern void func_0036C0B0();

void func_0026CDF0(u8 *p) {
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        if (p[0x1FD] == 0) {
            func_00376A50(p, 0);
        } else {
            func_00376A50(p, 1);
        }
    }
}

void func_003A8C90(u8 *d, u8 *s) {
    func_00175700(d);
    *(s8 *)(d + 0x24) = *(s8 *)(s + 0x24);
    *(V3 *)(d + 0x34) = *(V3 *)(s + 0x34);
    if (*(u32 *)(d + 0xD0) != *(u16 *)(s + 0x168)) {
        func_003A8D10(d, s);
    }
}

void func_0036D840(u8 *p) {
    if (*(u8 *)(*(u8 **)(p + 0x18) + 5) != 0) {
        p[5] = 2;
        *(s16 *)(p + 0x1C) = 10;
    } else {
        func_00175700(p);
        if (*(s8 *)(p + 0x151) != 0) {
            u32 t = p[5];
            p[5] = t + 1;
            func_0036C0B0(p, 1, 0);
        }
    }
}
extern u8 *func_003DA750();
extern void func_0038EEB0();

void func_0038EE40(u8 *p) {
    u8 *o = func_003DA750(0, 1, 1);
    if (o != 0) {
        *(void **)(o + 0x10) = func_0038EEB0;
        o[0x20] = 1;
        *(u32 *)(o + 0x18) = *(u32 *)(p + 0x18);
        o[1] = p[1];
        *(s16 *)(o + 0x26) = 0x1E02;
        *(u8 **)(o + 0x14) = p;
    }
}

void func_0036AE20(u8 *p) {
    p[0x13C] = 1;
    p[0x24] = 7;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(*(u8 **)(p + 0x18) + 0x3C);
    *(f32 *)(p + 0x38) += 120.0f;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(f32 *)(p + 0x118) = 1.0f;
    func_001757E0(p, 0x17, 2);
}
extern f32 D_00463A80[];

void func_0036AF80(u8 *p) {
    p[0x13C] = 1;
    p[0x24] = 0;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x14) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x14) + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(*(u8 **)(p + 0x14) + 0x3C);
    *(f32 *)(p + 0x34) += D_00463A80[p[0x23]];
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    func_001757E0(p, 0x17, 4);
}
extern void func_001E2490();
extern void func_003DAA40();

void func_003C9EC0(u8 *a) {
    u8 *q = *(u8 **)(a + 0xC);
    q[4] = 1;
    q = *(u8 **)(q + 0xC);
    q[4] = 1;
    q = *(u8 **)(q + 0xC);
    q[4] = 1;
    q = *(u8 **)(q + 0xC);
    q[4] = 1;
    q = *(u8 **)(q + 0xC);
    q[4] = 1;
    q = *(u8 **)(q + 0xC);
    q[4] = 1;
    q = *(u8 **)(q + 0xC);
    q[4] = 1;
    func_001E2490(6, 0x48);
    func_003DAA40(a);
}
extern void (*D_0044C240[])(u8 *, u8 *);

void func_001BD0C0(u8 *p, void *q_context) {
    u8 *q = (u8 *)q_context;
    u32 v = q[0x1E4];
    if (v != 0x15 || (v = q[0x1FD]) != 5) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    } else {
        D_0044C240[p[5]](p, q);
    }
}
extern void func_002E16D0();

void func_002E1850(u8 *p) {
    if (p[0x215] != 0) {
        func_002E16D0(p);
    } else if (p[0x212] == 0) {
        if ((*(s8 *)(p + 0x1EA) & 0xF) != 0) {
            func_002E16D0(p);
        }
    } else {
        if ((*(s8 *)(p + 0x1EA) & 0xF0) != 0) {
            func_002E16D0(p);
        }
    }
}
extern u16 D_00584BCA[], D_00584C40[], D_00584D2C[], D_00584DA2[], D_00584CB6[];

u32 func_00131870(s16 i) {
    return D_00584BCA[i] + D_00584C40[i] + D_00584D2C[i] + D_00584DA2[i] + D_00584CB6[i];
}
extern u32 D_00583BA0, D_00583BA4, D_00583BA8, D_00583BAC;

void func_00137860(u8 *p, s8 *o1, u32 *o2) {
    if (p[0x21] >= 0x20) {
        *o2 = D_00583BA4 | D_00583BAC;
        *o1 = *(s8 *)(p + 0x21) - 0x20;
    } else {
        *o2 = D_00583BA0 | D_00583BA8;
        *o1 = p[0x21];
    }
}
extern u8 D_004CAB33, D_004CAB34;
extern s32 D_004CA610[][3];

void func_0012E640(s32 a, s32 b, s32 c) {
    u32 t;
    s32 *e;
    u32 u;
    u = D_004CAB34;
    D_004CAB34 = u + 1;
    t = D_004CAB33;
    D_004CAB33 = t + 1;
    e = D_004CA610[t];
    u = D_004CAB33;
    D_004CAB33 = u & 7;
    e[0] = a;
    e[1] = b;
    e[2] = c;
}
