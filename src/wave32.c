typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u8 *func_003DA750(int, int, int);
extern void func_00351060(void);

void func_00350FF0(u32 a) {
    int i;
    i = 0;
    do {
        u8 *p = func_003DA750(0, 1, 0);
        if (p) {
            *(void **)(p + 0x10) = func_00351060;
            *(u32 *)(p + 0x18) = a;
            p[0x20] = i;
            *(s16 *)(p + 0x26) = 0x504;
        }
        i++;
    } while (i < 4);
}
extern void func_003636B0(void);

void func_00363640(u8 *a, u8 b, u8 c) {
    u32 t;
    u8 *p = func_003DA750(0, 1, 0);
    if (p) {
        *(void **)(p + 0x10) = func_003636B0;
        *(u8 **)(p + 0x18) = a;
        p[0x20] = b;
        p[0x23] = c;
        t = a[0x2BF]; a[0x2BF] = t + 1;
    }
}

extern void func_001EAFD0(u8 *);
extern int func_00100240(double, int);
extern int func_00175700(u8 *);

void func_001EB330(u8 *p) {
    f32 v;
    func_001EAFD0(p);
    v = *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x34) = *(f32 *)(p + 0x34) + v;
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if (func_00100240(*(f32 *)(p + 0x5C) * v, 0)) {
        u32 t = p[6]; p[6] = t + 1;
    }
    func_00175700(p);
}

extern void func_001843A0(u8 *);
extern void func_001266A0(u8 *, int, int);

void func_001F6DF0(u8 *p) {
    u8 *q;
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        func_001266A0(p, 0, 0);
        q = *(u8 **)(p + 0x1DC);
        q[0x20A] = 2;
        q[0x1B5] = 0x20;
        p[0x1B5] = 0x20;
    }
}

extern u8 D_0045A670[];
extern int func_00189310(u8 *, u8 *, u8 *);
extern void func_0018A990(u8 *, u8 *);
extern void func_0018C4B0(u8 *, int);
extern void func_00186A60(u8 *, int);

int func_002D6340(u8 *p) {
    if (!func_00189310(p, D_0045A670, p + 0x398)) return 0;
    func_0018A990(p, p + 0x398);
    func_0018C4B0(p, 10);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 3;
    func_00186A60(p, 0x15);
    return 1;
}

void func_002D6E50(u8 *p) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        u32 t = p[6]; p[6] = t + 1;
        p[0x151] = 0;
    }
}

extern int func_0016A130(u8 *, int, int);
extern int func_0016A1F0(u8 *, int);

int func_00169380(u8 *a, int b) {
    u8 *c = *(u8 **)(a + 0x220);
    if (b > 3) return 0;
    if (a[0x215] == 0 && a[0x20D] != 2 && (c[0x215] != 0 || c[0x1E4] == 14)) {
        return func_0016A130(a, 11, 3);
    }
    return func_0016A1F0(a, 11);
}

extern u8 D_004F20CE[];
extern u8 D_00583B92[];
extern u8 D_00583BC6;

void func_00138800(u8 *p) {
    u32 i = p[0x20];
    if (*(s16 *)(D_004F20CE + i * 0x5B8) == 2 && (D_00583B92[i] & 0x40)) {
        u32 t = p[5]; p[5] = t + 1;
        p[0x22] = 0;
        D_00583BC6 |= (u8)(1 << (s8)p[0x20]);
    }
}

extern void func_001E3710(u8 *, int);
extern void func_0015B200(u8 *, f32 *, int, int);

void func_00194990(u8 *a, u8 *b) {
    f32 v[4];
    u8 *c = *(u8 **)(b + 0x1DC);
    *(s8 *)(b + 0x2D3) = -1;
    func_001E3710(a, 0x49);
    *(u8 **)(c + 0x1C8) = b;
    c[0x20A] = 1;
    c[0x20D] = 2;
    c[0x1B5] = 0x23;
    v[0] = *(f32 *)(c + 0x34);
    v[1] = *(f32 *)(a + 0x38);
    func_0015B200(c, v, 1, 0x89);
}

extern void func_00183DF0(u8 *, int);
extern int func_001757E0(u8 *, int, int);

void func_00209F70(u8 *p) {
    if (*(s8 *)(p + 0x151) != 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        func_00183DF0(p, 3);
    }
    if ((s8)func_00175700(p) < 0) func_001843A0(p);
}

void func_002DA260(u8 *p) {
    s16 x;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    x = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = x;
    if (x < 0) {
        u32 t = p[6]; p[6] = t + 1;
        func_001757E0(p, 2, 3);
    }
}

extern void func_0035A340(u8 *, u8 *);

void func_0035A440(u8 *a, u8 *b) {
    u8 *q = *(u8 **)(a + 0x18);
    u32 t = a[5]; a[5] = t + 1;
    a[6] = 0;
    *(u16 *)(b + 8) = *(u16 *)(q + 0x160);
    *(u16 *)(a + 0x1C) = 8;
    *(u32 *)(a + 0x5C) = 0;
    *(u32 *)(a + 0x68) = 0;
    *(u32 *)(a + 0x60) = 0x41892492;
    *(u32 *)(a + 0x6C) = 0xBF892492;
    a[0x169] = 0x17;
    a[0x168] = 7;
    func_001757E0(a, a[0x169], a[0x168]);
    func_0035A340(a, b);
}
