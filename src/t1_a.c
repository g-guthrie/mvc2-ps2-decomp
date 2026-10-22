typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { f32 x, y, z, w; } V4;

extern f32 func_00417440(s32 a);
extern f32 D_00460560[];

void func_00341C60(u8 *p) {
    f32 r = func_00417440(*(s32 *)(*(s32 *)(p + 0x14) + 0x44));
    f32 v = 16000.0f; v *= r; *(f32 *)(p + 0x34) = D_00460560[p[0x20] * 3] - v;
}

extern void func_00175700(u8 *p);

void func_00211DB0(u8 *p) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
    }
}

extern void func_001757E0(u8 *p, s32 a, s32 b);

void func_002B9EC0(u8 *p) {
    u8 *q;
    s16 v;
    p[0x33A] = 0xFF;
    v = *(s16 *)(p + 0x1E);
    q = p + 0x2B8;
    if (v != 0) {
        v = v - 1;
        *(s16 *)(p + 0x1E) = v;
        if (v == 0) {
            if (*(s8 *)(q + 0xF) != 0) {
                p[0x168] = (p[0x20] == 0) ? 1 : 4;
                func_001757E0(p, 0x13, p[0x168]);
                return;
            }
        }
    }
    func_00175700(p);
}

void func_00155F00(u8 *d) {
    u8 *s = *(u8 **)(d + 8);
    u8 t;
    s8 u;
    d[0x13C] = 0;
    t = s[4];
    d[4] = t;
    if (t < 2) {
        u = *(s8 *)(s + 0x13C);
        *(s8 *)(d + 0x13C) = u;
        if (u != 0) {
            *(V3 *)(d + 0x34) = *(V3 *)(s + 0x34);
            *(V4 *)(d + 0x74) = *(V4 *)(s + 0x74);
            *(V3 *)(d + 0x50) = *(V3 *)(s + 0x50);
            *(s32 *)(d + 0x40) = *(s32 *)(s + 0x40);
            *(s32 *)(d + 0x44) = *(s32 *)(s + 0x44);
            *(s32 *)(d + 0x48) = *(s32 *)(s + 0x48);
        }
    }
}

extern void func_0018C6E0(void *);
extern void func_0015D010(u8 *p, void *v);

void func_002FB580(u8 *p) {
    u32 v[3];
    if (p[0x22] & 1) {
        { u32 t = p[0x1E6]; p[0x1E6] = t ^ 1; }
        *(s16 *)(p + 0x140) = p[0x1E6];
    }
    p[0x1B4] = 10;
    func_0018C6E0(p);
    func_001757E0(p, 0xF, 5);
    v[0] = 0xC2AA0000;
    v[1] = 0x42564924;
    v[2] = 0;
    func_0015D010(p, v);
    *(s32 *)(p + 0x5C) = 0;
    *(s32 *)(p + 0x60) = 0;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6C) = 0;
}

extern void func_00230020(u8 *p, u8 *q);

extern void func_001266A0(u8 *p, s32 a, s32 b);

void func_002419D0(u8 *p, u8 *q) {
    s8 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    v = q[2];
    if (v < 0) {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        {
            u32 t = p[6];
            p[6] = t + 1;
        }
        p[7] = 1;
        q[3] = 0;
        func_001266A0(p, 0, 0xD);
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        *(u32 *)(p + 0x6C) = 0xBF700000;
        func_001757E0(p, 0x16, 6);
    } else if (v > 0) {
        u32 t = p[7];
        p[7] = t + 1;
    }
}

extern void func_001830D0(u8 *p, void *v, s32 a);

void func_002066E0(u8 *p) {
    u32 v[3];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        p[0x22] = 0;
        *(s16 *)(p + 0x1E) = 0;
        p[0x404] = 0;
        p[0x405] = 0;
        v[0] = 0xC2555555;
        v[1] = 0x43700000;
        v[2] = 0;
        func_001830D0(p, v, 1);
    }
}

extern s32 D_004D18B8[];
extern void func_00326DE0(u8 *p);
extern void func_00180D20(u8 *a, u8 *b);
extern void func_00180E20(u8 *a);

void func_00327690(u8 *p) {
    u8 *o;
    u8 *row;
    u8 i;
    if (p[0x425] == 0) {
        row = (u8 *)D_004D18B8 + p[2] * 12;
        o = *(u8 **)(row + (i = p[0x26B]) * 4);
        if (*(s16 *)(o + 0x434) == 0) {
            o = *(u8 **)(row + (i ^ 3) * 4);
            if (*(s16 *)(o + 0x434) == 0) return;
        }
        p[0x425] = o[0x425];
        o[0x425] = 0;
        p[0x13C] = 0;
        p[0] = 0;
        func_00326DE0(o);
        func_00180D20(o, p);
        func_00180E20(p);
    }
}

extern s32 func_00175670(u8 *p);
extern void func_001AD1E0(u8 *p, s32 a, s32 b);
extern s32 func_001745B0(u8 *p);

extern s32 func_001AFC90(u8 *p);
s32 func_001AE9E0(u8 *p) {
    func_00175670(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v == 0) {
            *(s16 *)(p + 0x1C) = 2;
            func_001AD1E0(p, 4, 0);
        }
    }
    if (func_001745B0(p) == 0) {
        return func_001AFC90(p);
    }
}

extern s32 func_00174170(void);

void func_00260FA0(u8 *p) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[7] = func_00174170();
    p[7] &= 1;
    *(s16 *)(p + 0x1C) = 0x78;
    if (*(s16 *)(p + 0x1E) < 3) {
        p[6] = 4;
        *(s16 *)(p + 0x1E) += 1;
        if (*(s16 *)(p + 0x1E) == 3) {
            func_001757E0(p, 0x16, 0xC);
        } else {
            func_001757E0(p, 0x16, 0xB);
        }
    } else {
        u32 t = p[6];
        p[6] = t + 1;
    }
}
