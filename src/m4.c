typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s32 func_0018BF90(void *p);
extern void func_0018D660(void *p, s32 q);
s32 func_0018BF30(u8 *p, s32 q) {
    if (*(s8 *)(p + 0x203) == 0) return 0;
    if (func_0018BF90(p) != 0) return 0;
    func_0018D660(p, q);
    return 1;
}

extern s16 D_004B7EC0[][5];
extern void func_00334AD0(void *p);
void func_00334A60(u8 *p) {
    s32 i = *(s32 *)(p + 0xD4);
    s32 v;
    u8 *t = (u8 *)D_004B7EC0;
    p[0x13C] = 0;
    t += i * 10;
    t += p[0x23] * 2;
    v = *(s16 *)t;
    if (v != 0) {
        *(s32 *)(p + 0xD8) = (s16)v;
        p[4] = 1;
        func_00334AD0(p);
    }
}

extern void func_003DA650(s32 n);
extern u8 *D_004C2840;
void func_003D8EE0(u8 *p) {
    s16 v = *(s16 *)(p + 0x12) - 1;
    *(s16 *)(p + 0x12) = v;
    if (v <= 0) {
        p[0x32] = 0;
        p[0x31] = 0;
        p[0x30] = 0;
        *(s16 *)(p + 0x12) = 0;
        p[0] = 9;
        if (*(s8 *)(D_004C2840 + 0x8C) != 0) {
            *(s16 *)(p + 0x12) = 0x186;
            func_003DA650(0xD);
            func_003DA650(0xE);
            func_003DA650(0xF);
        }
    }
}

extern u8 D_004F20B0[];
extern void func_00418040(s32 v);
extern void func_00174F40(void *p);
extern void func_003DAB30(void *p);
void func_00326AF0(void) {
    s32 i;
    u8 *e;
    s32 off;
    func_00418040(0x777777);
    i = 0;
    off = 0;
    do {
        e = D_004F20B0 + off;
        if (*(s8 *)(e + 0x13C) != 0) {
            func_00174F40(e);
            func_003DAB30(e);
        }
        i++;
        off += 0x5B8;
    } while (i < 6);
}


extern s32 func_00175700(void *p);
extern void func_00184540(void *p);
extern void func_00385A20(void *p);
extern void func_001C09A0(void *p, s32 n);


extern void func_001843A0(void *p);
extern void func_00183920(void *p, u32 *v);
void func_0023E7E0(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        u32 v[3];
        p[0x151] = 0;
        v[0] = 0xC2DF5555;
        v[1] = 0x437CDB6D;
        v[2] = 0;
        func_00183920(p, v);
    }
}


typedef float f32;
extern s16 D_004B5770[];
extern s16 D_004B5772[];


extern u8 D_0058C020[];
s32 func_0038CA90(void) {
    u8 *p = D_0058C020;
    u32 i = 0;
    u16 s = 0;
    do {
        s += p[0]; s += p[1]; s += p[2]; s += p[3];
        s += p[4]; s += p[5]; s += p[6]; s += p[7];
        p += 8;
        i += 8;
    } while (i < 0x750);
    return s;
}

typedef struct { f32 x, y, z; } V3;
extern u8 *func_003DA750(s32 a, s32 b, s32 c);
extern void func_0037FCA0(void);
void func_00380160(void *owner, V3 *pos, s32 a, s32 b) {
    u8 *o = func_003DA750(0, 1, 0);
    if (o != 0) {
        *(void **)(o + 0x18) = owner;
        *(void **)(o + 0x10) = (void *)func_0037FCA0;
        *(V3 *)(o + 0x34) = *pos;
        o[0x20] = a;
        o[0x21] = b;
    }
}

void func_001AD0B0(u8 *p) {
    s16 v;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        u32 t = p[4];
        p[4] = t + 1;
    }
    v = *(s16 *)(p + 0x1C);
    if (v < 11) p[0x13C] = v & 1;
}

extern s32 func_00175700(void *p);
extern void func_00179150(void *p, s32 q);
void func_00326190(u8 *p) {
    s16 v;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v <= 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_00175700(p);
        func_00179150(p, *(s32 *)(p + 0x1DC));
    }
}

typedef struct { s16 x, y, z; } T3;
extern T3 D_00464930[];
void func_003879F0(u8 *a, u8 *b) {
    u32 t = a[5];
    if (t == 0) {
        T3 *e;
        a[5] = t + 1;
        e = &D_00464930[a[0x20]];
        *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34);
        *(f32 *)(a + 0x38) = *(f32 *)(b + 0x38) + (f32)e->y;
    }
    if (b[4] >= 2) {
        u32 u = a[4];
        a[4] = u + 1;
        a[0x13C] = 0;
    } else {
        func_00175700(a);
    }
}

extern void func_0030C470(void *p);
extern void func_003BA230(void *p, s32 a, s32 b);
void func_0030A0E0(u8 *p) {
    if (p[0x1FC] == 2) {
        if (*(s8 *)(p + 0x151) != 0) {
            s32 i;
            p[0x151] = 0;
            func_0030C470(p);
            for (i = 0; (u8)i < 5; i = (u8)(i + 1)) {
                func_003BA230(p, 5, i);
            }
        }
    }
    if ((s8)func_00175700(p) < 0) {
        func_00184540(p);
    }
}

extern u8 D_0058C020[];
extern u8 D_00583D00[];
u8 *func_0038D1B0(s32 n) {
    u8 *r;
    switch (n) {
    case 0:
        r = 0;
        break;
    case 1:
        r = D_0058C020;
        break;
    case 2:
        r = 0;
        break;
    case 3:
        r = 0;
        break;
    case 4:
        r = D_00583D00;
        break;
    default:
        r = 0;
        break;
    }
    return r;
}

extern s32 func_00185980(void *p);
extern void func_002E7850(void *p);
extern s32 func_00175700(void *p);
extern void func_001843A0(void *p);
void func_002E7740(u8 *p) {
    if (*(s8 *)(p + 0x151) != 0) {
        if (func_00185980(p) != 0) {
            func_002E7850(p);
            return;
        }
    }
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
    }
}

extern void func_001757E0(void *p, s32 a, s32 b);
extern void func_0015D010(void *p, u32 *v);
extern void func_0018C6E0(void *p);
void func_0023EA60(u8 *p) {
    u32 v[3];
    func_001757E0(p, 0xF, 1);
    *(s32 *)(p + 0x5C) = 0;
    *(s32 *)(p + 0x60) = 0;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6C) = 0;
    v[0] = 0xC3145555;
    v[1] = 0x4385EDB7;
    v[2] = 0;
    func_0015D010(p, v);
    func_0018C6E0(p);
}

extern u8 *func_003DA750(s32 a, s32 b, s32 c);
extern void func_0034C0A0(void);
void func_0034C020(u8 *a, s32 b, s32 c) {
    u8 *o = func_003DA750(0, 1, 1);
    if (o != 0) {
        *(void **)(o + 0x10) = (void *)func_0034C0A0;
        *(s32 *)(o + 0x18) = *(s32 *)(a + 0x18);
        *(u8 **)(o + 0x14) = a;
        o[0x20] = b;
        o[0x22] = c;
        *(s16 *)(o + 0x26) = 0x403;
    }
}
