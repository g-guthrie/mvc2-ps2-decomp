typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;


static void func_0014E770(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    if (*(s32 *)(q + 0xDC) != 0) {
        *(s16 *)(p + 0x1E) = *(s16 *)(q + 0x1E);
    }
}
void func_0014FD80(u8 *p) {
    func_0014E770(p);
    *(s8 *)(p + 0x13C) = *(s8 *)(*(u8 **)(p + 0x18) + 0x13C);
    *(f32 *)(p + 0x74) = *(f32 *)(*(u8 **)(p + 0x18) + 0x74);
}

extern u8 D_004B6A50[];
static u8 func_001E3940(u8 *p, s32 x) {
    u32 c = x & 0xFF;
    u32 f;
    if (p[1] == 0x14) return 0;
    if (c == 0x10) return 0;
    if (c == 0xF || c == 0xE || c == 6 || c == 5 || c == 4) return 0;
    f = *(u32 *)(p + 0x428);
    if (((f & 0x1018000) | (*(u32 *)(p + 0x42C) & 0x184000)) != 0) {
        x = D_004B6A50[c];
    }
    if (p[0x216] & 0x80) {
        x = D_004B6A50[x & 0xFF];
        return x;
    }
    return x;
}
extern void func_001E3710(void *, s32);
void func_001E3B70(u8 *p, s32 x) {
    u8 r = func_001E3940(p, x);
    if (r != 0) {
        x = r & 0xFF;
    }
    func_001E3710(p, x);
}

extern s32 func_00175670(void *);
void func_001B5C90(u8 *p) {
    s8 r = func_00175670(p);
    if (r < 0) {
        p[4] = 2;
        return;
    }
}

extern s32 func_00175700(void *);
extern void func_00183920(void *, void *, s32);
void func_0030EFE0(u8 *p) {
    u32 v[4];
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6];
        t += 1;
        p[6] = t;
        p[0x151] = 0;
        v[0] = 0x423AAAAA;
        v[1] = 0x4211B6DB;
        func_00183920(p, v, t);
    }
}

extern void func_00184540(void *);
extern void func_002DC1B0(void *);
void func_002DB060(u8 *p) {
    s8 r;
    *(s32 *)(p + 0x2C0) = 0x10;
    r = func_00175700(p);
    if (r < 0) {
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        if (p[0x20D] == 2) {
            func_00184540(p);
        } else {
            func_002DC1B0(p);
        }
    }
}

extern void func_001757E0(void *, s32, s32);
void func_0025F310(u8 *p) {
    if (*(s8 *)(p + 0x153) < 0) {
        if (p[0x23] > 0 && *(s16 *)(p + 0x1C) == 0) {
            u32 t = p[6];
            p[6] = t + 1;
            func_001757E0(p, 0x15, 0x1A);
        } else {
            p[6] = 5;
            func_001757E0(p, 0x15, 0x1D);
        }
    } else {
        func_00175700(p);
    }
}

extern void func_001843A0(void *);
extern s32 func_00185980(void *);
extern void func_00185640(void *, s32);
extern void func_003A15E0(void *, s32);
void func_002504A0(u8 *p) {
    s8 r = func_00175700(p);
    if (r < 0) {
        func_001843A0(p);
    } else if (*(s16 *)(p + 0x1C) == 0 && *(s8 *)(p + 0x1B2) != 0) {
        *(s16 *)(p + 0x1C) = 1;
        if (func_00185980(p) != 0) {
            p[6] = 0;
            p[0x20B] = 0xC2;
            func_00185640(p, *(s32 *)(p + 0x1C4));
        }
    }
}

void func_002E18F0(u8 *p) {
    s8 r;
    if (p[0x1FC] == 1) {
        r = func_00175700(p);
        if (r < 0) {
            func_001843A0(p);
        } else if (*(s8 *)(p + 0x151) != 0) {
            p[0x151] = 0;
            func_003A15E0(p, 1);
        }
    } else {
        r = func_00175700(p);
        if (r < 0) {
            func_001843A0(p);
        }
    }
}

extern s32 func_00174170();
extern void func_001E7F60(void *);
extern void func_003A9270(void *);
void func_003A91C0(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    s16 v;
    *(s8 *)(p + 0x13C) ^= 1;
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v >= 0 && *(u32 *)(p + 0xD0) == *(u16 *)(q + 0x168)) {
        func_00175700(p);
        if (p[0x21] == 0) {
            s32 r = func_00174170();
            if ((r & 7) != 0) {
                return;
            }
        }
        func_001E7F60(p);
    } else {
        func_003A9270(p);
    }
}

extern void func_001830D0(void *, void *, s32);
void func_00252300(u8 *p) {
    u32 v[4];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        p[0x404] = 0;
        p[0x405] = 0;
        v[0] = 0xC2820000;
        v[1] = 0;
        v[2] = 0;
        func_001830D0(p, v, 1);
    }
}

void func_002FEB80(u8 *p) {
    u32 v[4];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6];
        t += 1;
        p[6] = t;
        v[0] = 0xC1AD5555;
        v[1] = 0x435EDB6D;
        v[2] = 0;
        p[0x404] = 0;
        p[0x405] = 0;
        func_001830D0(p, v, 1);
    }
}

extern void func_001975C0(void *, void *);
void func_00196D90(u8 *p, u8 *q) {
    u8 *a = p + 0x88;
    u8 *b = q + 0x2B8;
    if (q[5] == 0 && q[0x1E4] == 0x1D && q[0x1FD] == 9) {
        if (*(s8 *)(q + 0x161) != 0) {
            *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
            *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
            *(s16 *)(p + 0x140) = *(s16 *)(q + 0x140);
            func_00175670(p);
            func_001975C0(p, q);
        }
    } else {
        b[0xC] = 0;
        a[0] = 0;
    }
}

extern void func_00378620();
void func_002722E0(u8 *p) {
    s8 r;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (*(s8 *)(p + 0x151) != 0) {
        func_00378620();
        p[0x151] = 0;
    }
    r = func_00175700(p);
    if (r < 0) {
        u32 t;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        t = p[7];
        p[7] = t + 1;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        func_001757E0(p, 1, 9);
    }
}
