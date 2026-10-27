struct Object;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *func_003DA750(s32 a, s32 b, s32 c);
extern void func_00348520(void);
void *func_003484A0(u8 *p, s32 a, s32 b) {
    u8 *o;
    if ((o = func_003DA750(0, 1, 1)) != 0) {
        *(void **)(o + 0x10) = (void *)func_00348520;
        *(u8 **)(o + 0x18) = p;
        o[1] = p[1];
        o[0x20] = a;
        o[0x21] = b;
        *(s16 *)(o + 0x26) = 0x300;
    }
    return o;
}
extern int func_00175700(u8 *p);
extern s32 func_001864a0(u8 *p);
extern void func_001757E0(u8 *p, s32 a, s32 b);
extern void func_00183d50(u8 *p);
extern void func_001DD8A0(u8 *p, s32 a, s32 b);
void func_00312840(u8 *p) {
    u32 t;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_001864a0(p) != 0) {
        t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 0x14, 1);
        func_00183d50(p);
        func_001DD8A0(p, 5, 0);
    }
}
extern int func_00175700(u8 *p);
extern void func_001757E0(u8 *p, s32 a, s32 b);
void func_0028F450(u8 *p) {
    u32 t;
    u32 *v;
    u32 *w;
    func_00175700(p);
    v = (u32 *)(p + 0x60);
    w = (u32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (!(*(f32 *)(p + 0x430) < *(f32 *)(p + 0x38))) {
        t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        *v = 0;
        *w = 0;
        p[0x20D] = 0;
        func_001757E0(p, 2, 2);
    }
}
extern int func_00175700(u8 *p);
extern void func_0031AF50(u8 *p);
void func_0031ABD0(u8 *p, u8 *q) {
    u32 t;
    if (p[6] == 0) {
        func_00175700(p);
        if (p[0x15B] != 0) {
            p[0x15B] = 0;
            t = p[6];
            p[6] = t + 1;
            *(u8 **)(q + 0x1C8) = p;
            q[0x1B5] = 0x21;
            q[0x20A] = 1;
            *(s16 *)(q + 0x140) = *(s16 *)(q + 0x140) ^ 1;
        }
    } else if ((s8)func_00175700(p) < 0) {
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        func_0031AF50(p);
    }
}
extern int func_00175700(u8 *p);
extern void func_001757E0(u8 *p, s32 a, s32 b);
extern void func_001E3210(u8 *p, s32 a);
void func_0024A620(u8 *p) {
    u32 t;
    s16 v;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v <= 0) {
        t = p[6];
        p[6] = t + 1;
        if ((p[0x1B8] & 1) == 0) {
            *(u32 *)(p + 0x68) = 0xBED55555;
        } else {
            *(u32 *)(p + 0x68) = 0x3ED55555;
        }
        func_001757E0(p, 0x12, 1);
        func_001E3210(p, 0xA);
    }
    func_00175700(p);
}
typedef struct { f32 x, y, z; } V3;
void func_001A4340(u8 *p, u8 *q) {
    s16 v;
    u8 *r;
    u32 n;
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    r = q + 0x2B8;
    if (v == 0) {
        p[4] = 2;
        p[0x13C] = 0;
        *(s8 *)r = -1;
    } else {
        n = p[0x21];
        *(f32 *)(p + 0x60) = *(f32 *)(p + 0x5C) / (f32)n;
    }
}
extern int func_00175700(u8 *p);
extern void func_001E3210(u8 *p, s32 a);
extern void func_001830D0(u8 *p, u32 *v, s32 a);
void func_0021FDF0(u8 *p) {
    u32 v[3];
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    if (*(s8 *)(p + 0x151) != 0) {
        t = p[6];
        p[6] = t + 1;
        p[0x404] = 0;
        p[0x405] = 0;
        p[0x151] = 0;
        func_001E3210(p, 0x17);
        v[0] = 0xC1555555;
        v[1] = 0x435EDB6D;
        v[2] = 0;
        func_001830D0(p, v, 1);
    }
    func_00175700(p);
}
extern int func_00175700(u8 *p);
extern void func_001757E0(u8 *p, s32 a, s32 b);
extern void func_00185490(u8 *p);
extern void func_001843A0(u8 *p);
extern void func_001D0500(u8 *p, s32 a);
void func_002D8540(u8 *p) {
    u32 t;
    s16 v;
    t = p[6];
    if (t == 0) {
        p[6] = t + 1;
        *(s16 *)(p + 0x1C) = 0x3C;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_00185490(p);
        func_001757E0(p, 0x15, 0x11);
    } else {
        func_00175700(p);
        v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v != 0) {
            if (*(s8 *)(p + 0x151) != 0) {
                p[0x151] = 0;
                func_001D0500(p, 7);
            }
        } else {
            func_001843A0(p);
        }
    }
}
extern int func_00175700(u8 *p);
extern void func_001757E0(u8 *p, s32 a, s32 b);
void func_0029FFE0(u8 *p) {
    u32 t;
    s16 v;
    func_00175700(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v != 0) {
        p[0x209] = 2;
        if (*(s8 *)(p + 0x151) == 0) {
            *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
            *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
            *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        }
        return;
    } else {
        t = p[6];
        p[6] = t + 1;
        p[0x20D] = 0;
        func_001757E0(p, 0x15, 0xC);
    }
}
extern int func_00175700(u8 *p);
extern void func_001757E0(u8 *p, s32 a, s32 b);
extern u8 *func_00383B80(void *, u8, u8);
void func_00283DF0(u8 *p, u8 *q) {
    u32 t;
    u8 *r;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 0x161) & 1) {
        t = p[6];
        p[6] = t + 1;
        q[1] = 0;
        func_00383B80(p, 0xB, 0);
        r = func_00383B80(p, 1, 0);
        *(u8 **)(p + 0x14) = r;
        if (r == 0) {
            p[6] = 4;
            func_001757E0(p, 0x16, 4);
        } else {
            q[2] = 8;
            func_001757E0(p, 0x16, 3);
        }
    }
}
extern f32 D_004B40C0[];
extern f32 D_004B4100[];
extern f32 D_004B4140[];
extern s8 D_004D1900;
extern void func_003DAA40(struct Object *);
void func_00162D20(u8 *p) {
    f32 *a = D_004B40C0;
    f32 *b = D_004B4100;
    f32 *c = D_004B4140;
    s16 i = *(s16 *)(p + 0x1C);
    if (i >= 0xC) {
        func_003DAA40((struct Object *)p);
        D_004D1900 = D_004D1900 - 1;
    } else {
        *(f32 *)(p + 0x50) = a[i];
        *(f32 *)(p + 0x54) = b[*(s16 *)(p + 0x1C)];
        *(f32 *)(p + 0x78) = c[*(s16 *)(p + 0x1C)];
        *(f32 *)(p + 0x7C) = c[*(s16 *)(p + 0x1C)];
        *(f32 *)(p + 0x80) = c[*(s16 *)(p + 0x1C)];
        *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
    }
}
extern s32 func_00174240(u8 *p);
extern void func_001E7F60(u8 *p);
void func_0037FF60(u8 *p) {
    u32 t;
    if (*(*(u8 **)(p + 0x18) + 4) >= 2) {
        t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    } else {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        if (func_00174240(p) == 0) {
            t = p[4];
            p[4] = t + 1;
            p[0x13C] = 0;
        } else {
            func_001E7F60(p);
        }
    }
}
