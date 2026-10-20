typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004F1FF0;
extern f32 D_004F1FFC;
extern u8 D_004F1FEC[];
extern u8 D_004F1FF8[];
void func_001269F0(void *a, void *b);
void func_001262C0(s32 a, s32 b);
void func_00126380(s32 a, s32 b);

void func_00125DC0(void) {
    D_004F1FF0 = 95.0f;
    func_001269F0(D_004F1FEC, D_004F1FF8);
    D_004F1FFC = D_004F1FF0;
    func_001262C0(0, 4);
    func_00126380(0, 4);
}

typedef struct S27B9F0 {
    u8 pad0[7];
    u8 b7;
    u8 pad1[0x16];
    s16 h1E;
} S27B9F0;
void func_001BE890(void *p, s32 n);

void func_0027B9F0(S27B9F0 *p) {
    s16 v = p->h1E - 1;
    p->h1E = v;
    if (v <= 0) {
        u32 t = p->b7;
        p->b7 = t + 1;
        p->h1E = 30;
        func_001BE890(p, 14);
        func_001BE890(p, 15);
    }
}

typedef struct S1C4220 {
    u8 pad0[7];
    u8 b7;
    u8 pad1[0x30];
    f32 f38;
    u8 pad2[0x24];
    f32 f60;
    u8 pad3[8];
    f32 f6C;
} S1C4220;
typedef struct S1C4220b {
    u8 pad[0x430];
    f32 f430;
} S1C4220b;
s8 func_00175700(void *p);

void func_001C4220(S1C4220 *a, S1C4220b *b) {
    a->f38 += a->f60;
    a->f60 += a->f6C;
    if (!(b->f430 < a->f38)) {
        u32 t = a->b7;
        a->b7 = t + 1;
        a->f38 = b->f430;
        func_00175700(a);
    }
}

typedef struct S37A810 {
    u8 pad0[0x140];
    s16 h140;
} S37A810;
typedef struct S37A810n {
    u8 pad0[0x10];
    void *fn10;
    u8 pad1[4];
    void *p18;
    u8 pad2[4];
    u8 b20;
    u8 pad3[5];
    s16 h26;
    u8 pad4[0x118];
    s16 h140;
} S37A810n;
void *func_003DA750(s32 a, s32 b, s32 c);
void func_0037A880(void);

void func_0037A810(S37A810 *a, u8 b) {
    S37A810n *n = (S37A810n *)func_003DA750(0, 1, 1);
    if (n != 0) {
        n->fn10 = func_0037A880;
        n->p18 = a;
        n->b20 = b;
        n->h26 = 0x1701;
        n->h140 = a->h140;
    }
}

typedef struct S27F330q {
    u8 pad0[5];
    u8 b5;
    u8 pad1[0x5A];
    f32 f60;
} S27F330q;
typedef struct S27F330 {
    u8 pad0[6];
    u8 b6;
    u8 b7;
    u8 pad1[0x1F6];
    u8 b1FE;
    u8 pad2[0x21];
    S27F330q *q;
} S27F330;
void func_00280340(void);

void func_0027F330(S27F330 *a) {
    S27F330q *q;
    a->b1FE = 1;
    q = a->q;
    if (q->b5 != 2) {
        func_00280340();
    } else if (q->f60 < 0.0f) {
        u32 t = a->b6;
        a->b6 = t + 1;
        a->b7 = 0;
    }
}

typedef struct S2F8BF0 {
    u8 pad0[6];
    u8 b6;
    u8 pad1[0x14A];
    s8 b151;
} S2F8BF0;
void func_001757E0(void *p, s32 a, s32 b);
void func_002F8D80(void *p);
void func_001D8A30(void *p, s32 a, s32 b);

void func_002F8BF0(S2F8BF0 *p) {
    if (p->b6 == 0) {
        u32 t = p->b6;
        p->b6 = t + 1;
        func_001757E0(p, 0x13, 0);
        func_002F8D80(p);
    } else {
        func_00175700(p);
        if (p->b151 != 0) {
            p->b151 = 0;
            func_001D8A30(p, 1, 0);
        }
    }
}

#define B(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define H(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define UH(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define W(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))

typedef struct E43F490 { u32 a[3]; } E43F490;
extern E43F490 D_0043F490[];
extern s32 func_00416AE0(const void *);
void func_00416F80(void *p);
void func_004171E0(void);
void func_001227F0(void *a, void *b, u32 c);
extern void *func_00416D40(void *);
extern s32 func_00416CC0(s32);

void func_00137DF0(u8 *p) {
    func_00416AE0(0);
    func_00416F80(p + 0x88);
    func_004171E0();
    func_001227F0(p + 0x34, &D_0043F490[p[1]], W(p, 0x48));
    func_00416D40(p + 0x88);
    func_00416CC0(1);
}

void func_003A6760(void *a, void *b);

void func_003A6440(u8 *a, u8 *b) {
    u8 *s0 = b + 0x2B8;
    if (func_00175700(a) < 0) {
        u32 t = a[4];
        a[4] = t + 1;
        t = s0[2];
        s0[2] = t - 1;
        func_003A6760(a, b);
    }
}

void func_003AD6E0(void);
void func_001D0580(void);
u8 *func_003DA750b(s32 a, s32 b, s32 c);

void func_003AD580(u8 *a, u8 *b, u32 c) {
    u8 *n = (u8 *)func_003DA750(0, 1, 1);
    if (n != 0) {
        W(n, 0x10) = (u32)func_003AD6E0;
        B(n, 0x20) = 5;
        W(n, 0x18) = (u32)a;
        W(n, 0x14) = (u32)b;
        W(n, 0xD0) = W(b, 0x18);
        W(n, 0xD4) = c;
        H(n, 0x26) = 0x3002;
    }
}

void func_001D0500(u8 *a, u8 b) {
    u8 *n = (u8 *)func_003DA750(0, 3, 1);
    if (n != 0) {
        W(n, 0x10) = (u32)func_001D0580;
        B(n, 0x20) = b;
        B(n, 0x21) = 0;
        W(n, 0x18) = (u32)a;
        B(n, 1) = B(a, 1);
        F(n, 0x34) = F(a, 0x34);
        F(n, 0x38) = F(a, 0x38);
        H(n, 0x26) = 0x2900;
        W(n, 0xD0) = UH(a, 0x168);
    }
}

void func_00357690(void *p, u8 a);
void func_001843A0(void *p);
void func_001C93F0(void *p);

void func_00224AC0(u8 *p) {
    s16 v = H(p, 0x1C) - 1;
    H(p, 0x1C) = v;
    if (v <= 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 0x15, (u8)(B(p, 0x1B7) + 10));
    } else {
        func_00175700(p);
        if (*(s8 *)(p + 0x151) != 0) {
            func_00357690(p, B(p, 0x1B7));
            *(s8 *)(p + 0x151) = 0;
        }
    }
}

void func_002CB140(u8 *p) {
    if (p[6] == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        H(p, 0x1C) = 0x3C;
        func_001757E0(p, 0x15, 0x1D);
    } else {
        s16 v;
        func_00175700(p);
        v = H(p, 0x1C) - 1;
        H(p, 0x1C) = v;
        if (v == 0) {
            W(p, 0x5C) = 0;
            W(p, 0x60) = 0;
            W(p, 0x68) = 0;
            W(p, 0x6C) = 0;
            func_001843A0(p);
        }
    }
}

s32 func_001745B0(void *p);

void func_003B6520(u8 *p) {
    if (func_001745B0(p) == 0) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    }
    F(p, 0x34) += F(p, 0x5C);
    F(p, 0x5C) += F(p, 0x68);
    F(p, 0x38) += F(p, 0x60);
    F(p, 0x60) += F(p, 0x6C);
    func_00175700(p);
}

typedef struct S1C9360 {
    u8 pad0[0x18];
    u8 *p18;
} S1C9360;

void func_001C9360(S1C9360 *p) {
    u8 *q;
    F(p, 0x34) = F(p->p18, 0x34);
    F(p, 0x38) = F(p->p18, 0x38);
    if (*(s8 *)((u8 *)p + 0x151) < 0) {
        B(p, 0x24) = 0;
    } else {
        B(p, 0x24) = 7;
    }
    q = p->p18;
    if (q[0x169] != 0x16 || q[0x168] != 0xA) {
        u32 t = B(p, 4);
        B(p, 4) = t + 1;
        func_001C93F0(p);
    } else {
        func_00175700(p);
    }
}

s32 func_001864A0(void *p);

void func_002B6D10(u8 *p) {
    F(p, 0x34) += F(p, 0x5C);
    F(p, 0x5C) += F(p, 0x68);
    F(p, 0x38) += F(p, 0x60);
    F(p, 0x60) += F(p, 0x6C);
    func_00175700(p);
    if (func_001864A0(p) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 0x15, 0x17);
    }
}

void func_001E3210(void *p, s32 a);
void func_0018C4B0(void *p, s32 a);
void func_00185490(void *p);
void func_0029B130(void *p);

void func_002A02F0(u8 *p) {
    if (p[6] == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        W(p, 0x5C) = 0;
        W(p, 0x60) = 0;
        W(p, 0x68) = 0;
        W(p, 0x6C) = 0;
        func_001E3210(p, 0x2B);
        func_0018C4B0(p, 5);
        func_00185490(p);
        func_001757E0(p, 0x14, 3);
    } else {
        if (func_00175700(p) < 0) {
            func_0029B130(p);
        }
    }
}

void func_001AA440(u8 *a, u8 *b) {
    u8 *s1 = b + 0x2B8;
    if (b[0x1E4] != 0x1D || b[0x1FD] != 5) {
        W(a, 0xD0) = a[6];
        W(a, 0xD4) = a[7];
        a[6] = 0x10;
        a[7] = 0;
    } else {
        func_00175700(a);
        if (s1[7] != 0) {
            u32 t = a[7];
            a[7] = t + 1;
            H(a, 0x1E) = 0;
            func_001757E0(a, 0x17, 0x41);
        }
    }
}
