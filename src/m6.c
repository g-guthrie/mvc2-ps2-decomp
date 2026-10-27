typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern void func_003C1CF0(void *, s32);
void func_003C1CB0(u8 *p, s32 q) {
    s16 v = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = v - 1;
    if (v == 0) {
        u32 t = p[5];
        p[5] = t + 1;
        p[0x13C] = 1;
        func_003C1CF0(p, q);
    }
}

extern void func_00169E50(void *, s32, s32);
extern void func_00169C90(void *);
void func_00169C30(u8 *p) {
    p[0x450] = 0;
    p[0x452] = 0;
    p[0x497] = 0;
    p[0x470] = 0;
    p[0x4A8] = 0;
    p[0x4B9] = 0;
    p[0x4B4] = 0xFF;
    *(s8 *)(p + 0x4BC) = -1;
    func_00169E50(p, 0, 0);
    func_00169C90(p);
}

extern void *func_003DA750(void *, s32, s32);
extern void func_0039B840(void);
void func_0039B7E0(u8 *p, u8 b) {
    u8 *r = func_003DA750(0, 1, 0);
    if (r) {
        *(void **)(r + 0x10) = func_0039B840;
        *(void **)(r + 0x18) = p;
        r[0x20] = b;
        *(s16 *)(r + 0x26) = 0x2602;
        *(void **)(p + 0x14) = r;
    }
}

extern void func_001555A0(void *, s32, s32, s32);
void func_00155420(void *p) {
    func_001555A0(p, 8, 0, 0);
    func_001555A0(p, 8, 1, 0);
    func_001555A0(p, 7, 0, 1);
    func_001555A0(p, 7, 1, 1);
}

extern void func_001757E0(void *, s32, s32);
void func_0036B360(u8 *p) {
    p[0x13C] = 1;
    p[0x24] = 0;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x14) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x14) + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(*(u8 **)(p + 0x14) + 0x3C);
    *(f32 *)(p + 0x34) -= (f32)(p[0x23] * 80);
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    func_001757E0(p, 0x17, 10);
}

extern void func_0013B6A0(void *);
extern void func_0013B770(void *);
void func_0013B560(u8 *p) {
    switch (p[6]) {
    case 0:
        p[6] = p[6] + 1;
        *(s32 *)(p + 0xD4) = 3;
        *(u32 *)(p + 0x5C) = 0x3D23D70A;
    case 1:
        func_0013B6A0(p);
        func_0013B770(p);
    }
}

extern void func_00390CB0(void *);
extern void func_003DAA40(void *);
extern void (*D_00471B48[])(void *);
void func_00391020(u8 *p, u8 *q) {
    if (q[0x425] != 0 && p[4] < 2) {
        func_00390CB0(p);
        func_003DAA40(p);
    } else {
        D_00471B48[p[5]](p);
    }
}

extern s32 func_00175700(void *);
extern s32 func_00174240(void *);
void func_003B6380(u8 *p) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (func_00174240(p) == 0) {
        p[4] = 3;
    }
}

extern void func_00299010(void *);
extern void func_00186A20();
/* Provisional: func_00186A20 still lacks its actor argument. */
void func_00299400(u8 *p) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    func_00175700(p);
    func_00299010(p);
    if (*(s8 *)(p + 0x151) == 0) {
        { u32 t = p[6]; p[6] = t + 1; }
        func_00186A20();
    }
}

extern u8 D_0045A690[];
extern s32 func_00189310(void *, void *, void *);
extern void func_0018A990(void *, void *);
extern void func_0018C4B0(void *, s32);
extern void func_00186A60(void *, s32);
s32 func_002D63C0(u8 *p) {
    if (func_00189310(p, D_0045A690, p + 0x3A0) == 0) {
        return 0;
    }
    func_0018A990(p, p + 0x3A0);
    func_0018C4B0(p, 10);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 7;
    func_00186A60(p, 0x15);
    return 1;
}

extern void func_0035F010(void);
u8 *func_0035EF90(u8 *p, s32 b, void *c) {
    u8 *r = func_003DA750(0, 1, 1);
    if (r) {
        *(s16 *)(r + 0x26) = 0xE02;
        r[0x20] = b;
        *(V3 *)(r + 0x34) = *(V3 *)(p + 0x34);
        *(void **)(r + 0x18) = c;
        *(void **)(r + 0x10) = func_0035F010;
    }
    return r;
}

extern void func_0039ACD0(void *);
extern int func_00174470(const void *);
extern void (*D_00472690[])(void *);
void func_0039A9C0(u8 *p) {
    if ((*(u8 **)(p + 0x18))[0x169] != 0x16) {
        func_0039ACD0(p);
    } else if (func_00174470(p) == 0) {
        func_0039ACD0(p);
    } else {
        D_00472690[p[5]](p);
    }
}

typedef struct { u16 f; u8 pad[18]; } E;
extern E D_004F4484[];
extern void func_00173C30(void);
s32 func_001733E0(u8 *p) {
    if (D_004F4484[*(s8 *)(p + 0x538) & 1].f & 0x8000) {
        *(s16 *)(p + 0x4D6) = 1;
        *(s16 *)(p + 0x4D4) = 1;
    }
    *(s16 *)(p + 0x4D4) -= 1;
    *(s16 *)(p + 0x4D6) -= 1;
    if (*(s16 *)(p + 0x4D4) <= 0 || *(s16 *)(p + 0x4D6) <= 0) {
        func_00173C30();
        return 1;
    }
    return 0;
}

extern void func_0018F4C0(void *);
extern void func_0018E810(void *);
extern void func_0018E6C0(void *);
extern void func_0018E790(void *);
void func_0018E470(u8 *p) {
    p[0x247] = 0x13;
    p[0x248] = 0;
    if (*(s16 *)(p + 0x434) == 0) {
        func_0018F4C0(p);
    } else {
        func_0018E810(p);
        if (p[0x20D] != 2) {
            func_0018E6C0(p);
        } else {
            func_0018E790(p);
            p[0x20D] = 2;
        }
        p[0x24D] = *(s8 *)(p + 0x246);
    }
}

extern void func_001843A0(void *);
void func_0025D5C0(u8 *p) {
    s8 r;
    switch (p[0x1FC]) {
    case 0:
    case 1:
    case 2:
        r = func_00175700(p);
        if (r < 0) {
            func_001843A0(p);
        }
        break;
    default:
        p[0x1FC] = 2;
        r = func_00175700(p);
        if (r < 0) {
            func_001843A0(p);
        }
        break;
    }
}

typedef struct { u8 pad[0x160]; s8 b[8]; } S_002C6BB0;
extern void func_00183D90(void *);
void func_002C6BB0(S_002C6BB0 *a) {
    s8 r;
    s8 *p;
    s8 f;
    s8 *q;
    func_00183D90(a);
    p = a->b;
    f = p[1];
    q = p + 1;
    if (f == 2) {
        *q = 0;
        *(u32 *)((u8 *)a + 0x5C) = 0;
        *(u32 *)((u8 *)a + 0x68) = 0;
    }
    r = func_00175700(a);
    if (r < 0) {
        func_001843A0(a);
    }
}

typedef struct { u8 pad[0x160]; s8 b[8]; } S_002CADC0;
extern void func_00399720(void *, s32);
void func_002CADC0(S_002CADC0 *a) {
    s8 r = func_00175700(a);
    if (r < 0) {
        func_001843A0(a);
    } else {
        s8 *p = a->b;
        s8 f = p[1];
        s8 *q = p + 1;
        if (f != 0) {
            *q = 0;
            func_00399720(a, 0);
        }
    }
}
