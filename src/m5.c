typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern volatile u32 D_0061BEE0[];

void func_003DE640(u32 *dst, s32 idx) {
    s32 i;
    u32 b;
    u32 a;
    volatile u32 *src;
    src = D_0061BEE0 + idx * 16;
    i = 8;
    do {
        a = src[0];
        i--;
        b = src[1];
        dst[0] = a;
        src += 2;
        dst[1] = b;
        dst += 2;
    } while (i > 0);
}

extern void func_00176160(void *p, s32 a, s32 b, s32 c);
void func_00212080(u8 *p) {
    s32 v = *(s8 *)(p + 0x2BE);
    u8 *q = p + 0x2B8;
    if (v < 8) {
        s32 n = p[0x25];
        q[6] = v + 1;
        func_00176160(p, 0, n * 8 + 0x27 - v, 1);
    }
}

extern f32 *D_004C26D0;
static void func_00192E30(u8 *p) {
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    if (*(s16 *)(p + 0x140) != 0) {
        *(f32 *)(p + 0x34) += D_004C26D0[0];
    } else {
        *(f32 *)(p + 0x34) -= D_004C26D0[0];
    }
    *(f32 *)(p + 0x38) += D_004C26D0[1];
}
extern void func_00193060(void *p);
extern s8 func_00175700(void *p);
void func_00193010(u8 *p) {
    s32 t;
    func_00192E30(p);
    t = *(s8 *)(*(u8 **)(p + 0x18) + 0x161);
    if (t != 5 && t != 8) {
        func_00193060(p);
    } else {
        func_00175700(p);
    }
}

extern void func_0022C700(void *p);
extern void func_001757E0(void *p, s32 a, s32 b);
extern void func_0022C6B0(void *p);
void func_00226E60(u8 *p) {
    func_00175700(p);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        u32 t = p[7];
        p[7] = t + 1;
        func_0022C700(p);
        func_001757E0(p, 1, 3);
        func_0022C6B0(p);
    }
}

extern s32 func_0016A1F0(void *p, s32 a);
extern s32 func_0016A130(void *p, s32 a, s32 b);
extern s32 func_003D92F0(void *p);
extern void func_001E3240(void *p, s32 a);
extern void func_001843A0(void *p);
extern void (*D_00450BB0[])(void *);
void func_002120D0(u8 *p) {
    if (func_003D92F0(p) != 0) {
        func_001E3240(p, 0x1F);
        func_001E3240(p, 0x20);
        func_001843A0(p);
    } else {
        D_00450BB0[p[0x20]](p);
    }
}

extern s32 func_00189EE0(void *p, void *a, void *b);
extern void func_0018A990(void *p, void *a);
extern void func_00186A60(void *p, s32 a);
extern u8 D_00451220[];
s32 func_0021CFD0(u8 *p) {
    if (func_00189EE0(p, D_00451220, p + 0x3B0) == 0) {
        return 0;
    }
    func_0018A990(p, p + 0x3B0);
    p[0x1B7] = 1;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 7;
    func_00186A60(p, 0x15);
    return 1;
}

extern void func_003C1530(void *p);
extern void func_003C15F0(u8 *p, u8 *a);
void func_003C1930(u8 *p, u8 *x) {
    s16 v;
    func_003C1530(p);
    func_003C15F0(p, x);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        u32 t = p[5];
        p[5] = t + 1;
        *(u32 *)(p + 0x5C) = 0xC1555555;
        *(s16 *)(p + 0x1C) = 0xE;
    }
}

extern s32 func_0035AB80(void *p, s32 x);
extern void func_0035AE70(void *p, s32 x);
extern void func_001E3210(void *p, s32 a);
void func_0035ACA0(u8 *p, s32 x) {
    if (func_0035AB80(p, x) != 0) {
        if (func_0035AB80(p, x) < 0) {
            p[0x21] = 10;
            func_0035AE70(p, x);
        } else {
            p[0x20] = 0;
            func_0035AE70(p, x);
            func_001E3210(p, 0x1F);
        }
    }
}

extern void func_00209960(void *p);
void func_002098E0(u8 *p) {
    switch (p[0x1FC]) {
    case 2:
        if (p[0x22] != 0) {
            func_00209960(p);
            break;
        }
    case 0:
    case 1:
        if (func_00175700(p) < 0) {
            func_001843A0(p);
        }
    }
}

void func_00228400(u8 *p) {
    f32 a = *(f32 *)(p + 0x5C);
    if (a * *(f32 *)(p + 0x68) < 0.0f) {
        *(f32 *)(p + 0x34) += a;
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    }
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x60) < 0.0f) {
        *(u32 *)(p + 0x6C) = 0xC0092492;
    }
}

extern s32 func_0016A1F0(void *p, s32 a);
extern s32 func_0016A130(void *p, s32 a, s32 b);
s32 func_00169210(u8 *p, s32 n) {
    if (n > 3) {
        return 0;
    }
    if (p[0x215] != 0) {
        return func_0016A1F0(p, 7);
    }
    if (p[5] == p[0x497]) {
        return 1;
    }
    if (p[0x497] == 3 && p[0x20D] == 2) {
        return func_0016A130(p, 7, 3);
    }
    return func_0016A1F0(p, 7);
}

extern void func_00176160(void *p, s32 a, s32 b, s32 c);
extern void func_00176090(void *p, s32 a, s32 b, s32 c);
void func_0027C4D0(u8 *p) {
    u32 t;
    if (func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    t = p[7];
    p[7] = t + 1;
    if (p[7] == 2) {
        func_00176160(p, 5, 0, 1);
    }
    if (p[7] == 4) {
        p[7] = 0;
        func_00176090(p, 5, 5, 1);
    }
}

extern void func_002BD610(void *p);
s32 func_002BD580(u8 *p, u8 *q) {
    s16 v;
    if (p[0x22] == 0) {
        return 0;
    }
    if ((*(s8 *)(p + 0x211) & 1) == 0) {
        return 0;
    }
    p[7] = 3;
    func_002BD610(p);
    *(u32 *)(q + 4) = 0xC3A00000;
    v = p[0x1E6] ^ 1;
    *(s16 *)(p + 0x140) = v;
    p[0x1E6] = v;
    func_001757E0(p, 0x16, 2);
    return 1;
}

extern void func_003DAA40(void);
extern f32 func_00154710(void *a, void *b, s32 c);
extern u8 D_00444E80[], D_00444E90[];
void func_00159BA0(u8 *p) {
    f32 r;
    if (*(s16 *)(p + 0x1C) >= 0xC) {
        func_003DAA40();
        return;
    }
    *(u32 *)(p + 0x50) = 0x3F800000;
    r = func_00154710(D_00444E80, p + 4, *(s16 *)(p + 0x1C));
    *(f32 *)(p + 0x54) = r;
    *(f32 *)(p + 0x58) = r;
    r = func_00154710(D_00444E90, p + 6, *(s16 *)(p + 0x1C));
    *(f32 *)(p + 0x78) = r;
    *(f32 *)(p + 0x7C) = r;
    *(f32 *)(p + 0x80) = *(f32 *)(p + 0x78);
    *(s16 *)(p + 0x1C) += 1;
}
