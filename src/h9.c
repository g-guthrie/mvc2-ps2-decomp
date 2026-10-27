typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s32 func_00175670();
void func_001B5F00(u8 *p) {
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) += 0.5357142687f;
    if ((s8)func_00175670(p) < 0) p[4] = 2;
}
extern u8 *func_003DA750(s32, s32, s32);
extern void func_0038EEB0(void);
void func_0038EDE0(u8 *p) {
    u8 *o = func_003DA750(0, 1, 0);
    if (o) {
        *(void **)(o + 0x10) = func_0038EEB0;
        o[0x20] = 0;
        *(u8 **)(o + 0x18) = p;
        o[1] = p[1];
        *(u16 *)(o + 0x26) = 0x1E02;
        *(u16 *)(o + 0xD0) = *(u16 *)(p + 0x168);
    }
}
extern void (*D_004762B0[])();
extern void func_003C9EC0();
void func_003C9370(u8 *p) {
    u8 *o = *(u8 **)(p + 0x18);
    if (o[0x169] == 0x16 && o[0x168] == 0) {
        D_004762B0[p[4]]();
    } else {
        func_003C9EC0();
    }
}
extern s8 D_004D1926;
extern void func_0016B0C0(void *, void *, s32);
extern int func_00166C80(void *, void *, s32);
int func_00166A50(u8 *p, void *q) {
    func_0016B0C0(p, q, 0);
    func_0016B0C0(p, q, 1);
    return func_00166C80(p, q, *(s32 *)(p + 0x4C8) <= 99 - D_004D1926);
}
extern s32 func_00175700(void *);
extern void func_001843A0(void *);
extern u8 *func_00383B80(void *, u8, u8);
void func_00283480(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
    } else {
        u32 a = (u32)p + 0x160; if (*(s8 *)(a + 1) & 1) { a += 1; *(s8 *)a = 0; func_00383B80(p, 0, 0); }
    }
}
extern u16 D_004F4484;
extern u16 D_004F4498;
extern s32 func_001315E0(s32);
extern void func_001E3CE0(s32);
s32 func_001315F0(void) {
    u16 a = func_001315E0(0);
    u16 b = func_001315E0(1);
    if ((D_004F4484 & a) || (D_004F4498 & b)) {
        func_001E3CE0(2);
        return 1;
    }
    return 0;
}
void func_001FEAA0(u8 *p) {
    if (p[0x15B]) {
        if (*(f32 *)(p + 0x60) > 1.0714285373687744f) {
            *(f32 *)(p + 0x6C) = -*(f32 *)(p + 0x6C);
        }
        if (*(f32 *)(p + 0x60) < -1.0714285373687744f) {
            *(f32 *)(p + 0x6C) = -*(f32 *)(p + 0x6C);
        }
    }
    func_00175700(p);
}
extern void func_0015D010(void *, f32 *);
extern void func_001266A0(void *, s32, s32);
extern void func_0018C6E0(void *);
extern void func_001757E0(void *, s32, s32);
void func_00202500(u8 *p) {
    f32 v[4];
    p[0x1B4] = 10;
    p[6] = 0;
    v[0] = -53.33333206f;
    v[1] = 137.1428528f;
    func_0015D010(p, v);
    func_001266A0(p, 5, 5);
    func_0018C6E0(p);
    func_001757E0(p, 15, 8);
}
extern void func_001820A0(void *);
extern void func_001822B0(void *);
extern void func_00182300(void *);
extern s32 func_001864A0(void *);
extern void func_0017C7F0(void *);
void func_0017C710(u8 *p) {
    func_00175700(p);
    func_001820A0(p);
    func_001822B0(p);
    func_00182300(p);
    if (func_001864A0(p)) {
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        p[0x20D] = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[6] = 3;
        func_0017C7F0(p);
    }
}
extern void func_001BA090(void);
u8 *func_001BA010(u8 *p, s32 q) {
    u8 *o = func_003DA750(0, 4, 0);
    if (o) {
        *(void **)(o + 0x10) = func_001BA090;
        *(u8 **)(o + 0x18) = p;
        *(s16 *)(o + 0x140) = *(s16 *)(*(u8 **)(o + 0x18) + 0x140);
        *(u16 *)(o + 0x26) = 0x1700;
        o[0x20] = q;
        *(u16 *)(o + 0xD0) = *(u16 *)(*(u8 **)(o + 0x18) + 0x168);
        return o;
    }
    return 0;
}
extern void func_001DEE30(void *, void *);
extern void func_001DEEB0(void *, void *);
extern void func_001DEEF0(void *, void *);
void func_001DF190(u8 *p, void *q) {
    s16 t;
    if (*(s16 *)(p + 0xD8) <= 0) *(s16 *)(p + 0x1C) = 0;
    t = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = t - 1;
    if (t == 0) {
        u32 b = p[4];
        p[4] = b + 1;
        p[0x13C] = 0;
    } else {
        func_001DEE30(p, q);
        func_001DEEB0(p, q);
        func_001DEEF0(p, q);
    }
}
typedef struct { f32 x, y, z; } V3;
extern void func_001B7570(void *, void *);
void func_001B74E0(u8 *p, u8 *q) {
    u32 t = p[5];
    switch (t) {
    case 0:
        func_001B7570(p, q);
        break;
    case 1:
        *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
        *(s16 *)(p + 0x140) = *(s16 *)(q + 0x140);
        t = q[0x15B];
        if (t != p[0x21]) {
            p[5] = 0;
            p[0x13C] = 0;
            p[0x21] = 0;
            func_001B7570(p, q);
        }
        break;
    }
}
extern void func_0031B210(void *);
void func_003195C0(u8 *p) {
    s8 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    v = *(s8 *)(p + 0x2BA) - 1;
    *(s8 *)(p + 0x2BA) = v;
    if (v < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_0031B210(p);
    }
}
void func_0019C100(u8 *p) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if ((s8)func_00175700(p) < 0) {
        p[4] = 0;
        p[0x13C] = 0;
        *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) - 0x13;
    }
}
extern void func_00351870(void *);
void func_00351320(u8 *p) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if ((s8)func_00175700(p) < 0) {
        u32 t = p[5];
        p[5] = t + 1;
        func_00351870(p);
    }
}
extern s8 D_004F7F4C;
extern s8 D_004F7F32;
extern V3 D_004768A0[];
extern void func_003DAA40(void);
extern void func_0012AD00(void);
void func_003CECD0(u8 *p) {
    if (D_004F7F4C != 5) {
        func_003DAA40();
    } else {
        u32 t;
        *(V3 *)(p + 0x34) = D_004768A0[D_004F7F32];
        t = p[4];
        if (t == 0) {
            p[4] = t + 1;
            *(s16 *)(p + 0x1E) = 0;
        }
        func_0012AD00();
    }
}
extern void func_00178F20(void);
extern void func_0018FDB0(void *);
extern void func_001E3210(void *, s32);
extern void func_001E3710(void *, s32);
extern void func_001548D0(void *, f32 *, s32);
void func_00321CC0(u8 *p, u8 *q) {
    f32 v[4];
    p[0x151] = 0;
    p[0x2C4] = 1;
    func_00178F20();
    *(u8 **)(q + 0x1C8) = p;
    q[0x1B5] = 0x24;
    func_0018FDB0(p);
    func_001E3210(p, 3);
    func_001E3710(p, 2);
    v[0] = -80.0f;
    v[1] = 17.14285660f;
    func_001548D0(p, v, 2);
}
void func_001AB970(u8 *p, u8 *owner) {
    if ((s8)func_00175700(p) < 0) {
        u32 t = p[7];
        p[7] = t + 1;
        *(s16 *)(p + 0x140) ^= 1;
        if (*(s16 *)(p + 0x140) == 0) {
            *(u32 *)(p + 0x5C) = 0xC0D55555;
        } else {
            *(u32 *)(p + 0x5C) = 0x40D55555;
        }
        *(u32 *)(p + 0x68) = 0;
        *(s16 *)(p + 0x1C) = 1;
        func_001757E0(p, 0x17, 0x14);
    }
}
extern void func_003B11C0(void);
void func_003B1130(u8 *p, s32 a, s32 b, s32 c) {
    u8 *o = func_003DA750(0, 1, 1);
    if (o) {
        *(void **)(o + 0x10) = func_003B11C0;
        *(u16 *)(o + 0x26) = 0x3300;
        *(u32 *)(o + 0x18) = *(u32 *)(p + 0x18);
        *(u8 **)(o + 0x14) = p;
        o[1] = p[1];
        o[0x20] = a;
        o[0x21] = b;
        o[0x23] = c;
    }
}
void func_00317780(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
    } else if (*(s8 *)(p + 0x150)) {
        f32 v = -53.33333206f;
        *(s8 *)(p + 0x150) = 0;
        if (*(s16 *)(p + 0x140)) v = -v;
        *(f32 *)(p + 0x34) += v;
    }
}
extern void func_001BAD70(void *, void *);
void func_001BA970(u8 *p, u8 *q) {
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    if (p[1] != q[1]) {
        func_001BAD70(p, q);
    } else if ((s8)func_00175670(p, q) < 0) {
        p[4] = 2;
        p[0x13C] = 0;
    }
}
extern u8 D_00583B92[];
extern u8 D_00583B90[];
void func_00138210(u8 *p) {
    if ((D_00583B92[p[0x20]] & (0x10 << p[0x21])) && D_00583B90[p[0x20]] == 3) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    }
}
