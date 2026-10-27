typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_003DAA40(u8 *, u8 *);
extern void func_001D3F00(u8 *, u8 *);
extern void func_001D4400(u8 *, u8 *);
extern void func_001D40F0(u8 *, u8 *);
void func_001D3E60(u8 *p) {
    u8 *g = *(u8 **)(p + 0x18);
    if (*(u8 *)(*(u8 **)(g + 0x1DC) + 1) != 0x2C) {
        func_003DAA40(p, g);
    } else if (p[4] >= 2) {
        func_003DAA40(p, g);
    } else if (p[0x20] == 0) {
        func_001D3F00(p, g);
    } else if ((u8)p[0x20] & 0x80) {
        func_001D4400(p, g);
    } else {
        func_001D40F0(p, g);
    }
}

extern s8 func_00175700();
extern void func_001843A0(u8 *);
void func_0024D3E0(u8 *p) {
    if (func_00175700(p) < 0) {
        func_001843A0(p);
    } else if (*(s8 *)(p + 0x151) != 0) {
        u8 *q;
        p[0x151] = 0;
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        *(s8 *)(q + 0x1E6) = *(s8 *)(p + 0x1E6) ^ 1;
        q[0x20D] = 2;
        q[0x1B5] = 0x22;
        q[0x20A] = 1;
    }
}

extern void func_0015D010(u8 *, u32 *);
extern void func_001266A0(u8 *, s32, s32);
extern void func_0018C6E0(void *);
extern void func_001757E0(u8 *, s32, s32);
void func_0025B620(u8 *p) {
    u32 v[4];
    if (*(u16 *)(p + 0x20E) & 0x400) {
        *(s8 *)(p + 0x1E6) = *(s8 *)(p + 0x1E6) ^ 1;
        *(s16 *)(p + 0x140) = *(s16 *)(p + 0x140) ^ 1;
    }
    v[0] = 0xC2A6AAAA;
    v[1] = 0x431E9249;
    func_0015D010(p, v);
    p[0x1B4] = 10;
    func_001266A0(p, 5, 5);
    func_0018C6E0(p);
    func_001757E0(p, 0xF, 1);
}

extern s32 func_00280AE0(u8 *, s32);
extern void (*D_00455470[])(u8 *);
void func_002806C0(u8 *p) {
    switch (p[0x451]) {
    case 0:
        p[0x451] = p[0x451] + 1;
    case 1:
        p[0x451]++;
        *(s32 *)(p + 0x484) = func_00280AE0(p, *(s32 *)(p + 0x484));
        break;
    case 2:
        D_00455470[p[0x454]](p);
        break;
    }
}

extern void func_00289E30(u8 *);
extern s32 func_00118FA8(f32);
void func_00289980(u8 *p) {
    s32 a, b;
    func_00175700(p);
    func_00289E30(p);
    a = func_00118FA8(*(f32 *)(p + 0x5C));
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    b = func_00118FA8(*(f32 *)(p + 0x5C));
    if ((a ^ b) < 0) {
        p[7]++;
    }
}



extern void func_001843A0(u8 *);
void func_002ACF70(u8 *p) {
    if (*(s32 *)(p + 0xD0) == 0) {
        if (*(s8 *)(p + 0x151) == 0) {
            *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        }
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    }
    if (func_00175700(p) < 0) {
        func_001843A0(p);
    }
}

void func_00313B00(u8 *p, u8 *q) {
    s32 t = *(s8 *)(p + 0x1B2);
    if (t != 0) {
        s8 f = t;
        if (!(f & 1) && !(f & 0x10)) {
            u8 *r = *(u8 **)(p + 0x1C4);
            if (r[3] == 0 && r[0x425] == 0 && !(*(u32 *)(r + 0x428) & 0x7000000) && r[5] == 3) {
                q[0xD] = 1;
                p[7] = 0;
                q[0xF] = 1;
                *(s16 *)(p + 0x1C) = 100;
            }
        }
    }
}

extern void func_0035D340(u8 *);
void func_0035CFE0(u8 *p, u8 *owner_unused) {
    s16 v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        p[4]++;
        func_0035D340(p);
    } else {
        func_00175700(p);
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    }
}

extern s8 func_00175670(u8 *);
extern void func_00381EC0(u8 *, s32);
void func_00382420(u8 *p) {
    u8 *g = *(u8 **)(p + 0x18);
    p[0x13C] = 0;
    if (*(u16 *)(g + 0x168) != *(u16 *)(p + 0x1E)) {
        p[4] = 2;
    } else if (func_00175670(p) < 0) {
        p[4]++;
    } else {
        if (p[0x20] == 1) {
            if (*(s8 *)(p + 0x151) != 0) {
                p[0x151] = 0;
                func_00381EC0(p, 3);
            }
        }
        p[0x13C] = 1;
    }
}

extern void func_001E3710(u8 *, s32);
extern s32 func_00174240(u8 *);
void func_003A2CE0(u8 *p, u8 *q) {
    if (func_00175700(p) < 0) {
        p[4] += 2;
        p[0x13C] = 0;
        func_001E3710(q, 0x3A);
    } else if (func_00174240(p)) {
        p[0x13C] = 1;
    } else {
        p[0x13C] = 0;
    }
}
