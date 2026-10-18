typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[0x34]; f32 f34; f32 f38; u8 pad1[0x20]; f32 f5c; f32 f60; u8 pad2[4]; f32 f68; f32 f6c; u8 pad3[0x3C0]; f32 f430; } F57;

void func_00257F00(u8 *p) {
    extern void func_00183D50();
    extern void func_00175700();
    F57 *q = (F57 *)p;
    f32 *v1, *a1, *a2, *a3;
    v1 = &q->f5c;
    a2 = &q->f68;
    a1 = &q->f60;
    a3 = &q->f6c;
    q->f34 += q->f5c;
    q->f5c += q->f68;
    q->f38 += q->f60;
    q->f60 += q->f6c;
    if (q->f38 < q->f430) {
        u32 t = p[7];
        p[7] = t + 1;
        p[0x20D] = 0;
        *v1 = 0;
        *a1 = 0;
        *a2 = 0;
        *a3 = 0;
        q->f38 = q->f430;
        func_00183D50(p);
    }
    func_00175700(p);
}

typedef struct { u8 pad0[0x34]; f32 f34; } F79;

void func_002797B0(u8 *p) {
    extern void func_00175700();
    extern void func_0037E4A0();
    u16 h;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        func_0037E4A0(p, 0);
    }
    h = *(u16 *)(p + 0x160);
    if (h != 0) {
        if (*(s16 *)(p + 0x140) == 0) {
            ((F79 *)p)->f34 += 1.6666666269302368f * (s16)h;
        } else {
            ((F79 *)p)->f34 -= 1.6666666269302368f * (s16)h;
        }
        *(u16 *)(p + 0x160) = 0;
    }
}

typedef struct { u8 pad0[0x34]; f32 f34; f32 f38; f32 f3c; } F6D;
extern f32 D_00463B80[];

void func_0036F6D0(u8 *p) {
    F6D *q = (F6D *)p;
    f32 x;
    f32 *tab = D_00463B80;
    u32 t = p[5];
    p[5] = t + 1;
    p[0x13C] = 1;
    p[0x24] = 0;
    q->f34 = (*(F6D **)(p + 0x18))->f34;
    q->f38 = (*(F6D **)(p + 0x18))->f38;
    q->f3c = (*(F6D **)(p + 0x18))->f3c;
    q->f34 += (f32)((*(s16 *)(*(u8 **)(p + 0x18) + 0x140) != 0) ? 0x92 : -0x92);
    q->f38 += 165.0f;
    if (*(s16 *)(*(u8 **)(p + 0x18) + 0x140) != 0) {
        x = tab[p[0x23]];
    } else {
        x = -tab[p[0x23]];
    }
    q->f34 += x;
}

typedef struct { u8 pad0[0x5C]; f32 f5c; f32 f60; f32 f64; f32 f68; f32 f6c; } F5B;
typedef struct { f32 a, b, c, d; } T4;
extern T4 D_004B7580[];

void func_002B5610(u8 *p) {
    extern void func_00175700();
    F5B *q = (F5B *)p;
    T4 *t;
    s32 flag;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) < 0) return;
    {
        u32 n = p[6];
        p[6] = n + 1;
    }
    t = &D_004B7580[p[0x1B7]];
    if (*(s8 *)(p + 0x1E7) < 0) {
        if (*(s16 *)(p + 0x140) != 0) flag = 1; else flag = 0;
    } else {
        flag = 0; if (q->f5c > 0.0f) flag = 1;
    }
    q->f5c = t->a;
    q->f68 = t->b;
    q->f60 = t->c;
    q->f6c = t->d;
    if (flag) {
        q->f5c = -q->f5c;
        q->f68 = -q->f68;
    }
}

void func_002BD9B0(u8 *p) {
    extern void func_00175700();
    extern void func_001757E0();
    F57 *q = (F57 *)p;
    f32 *v1, *a3, *t0, *t1;
    p[0x1FE] = 1;
    p[0x201] = 2;
    p[0x209] = 2;
    func_00175700(p);
    v1 = &q->f5c;
    t0 = &q->f68;
    a3 = &q->f60;
    q->f34 += q->f5c;
    q->f5c += q->f68;
    q->f38 += q->f60;
    q->f60 += q->f6c;
    t1 = &q->f6c;
    if (q->f38 <= q->f430) {
        u32 t = p[6];
        p[6] = t + 1;
        q->f38 = q->f430;
        p[0x20D] = 0;
        *v1 = 0;
        *a3 = 0;
        *t0 = 0;
        *t1 = 0;
        func_001757E0(p, 1, 5);
    }
}

void func_001F8A70(u8 *p) {
    extern void func_00175700();
    extern void func_00183D50();
    extern void func_001757E0();
    F57 *q = (F57 *)p;
    f32 *s0, *s1, *s2, *s3;
    s3 = &q->f6c;
    s2 = &q->f68;
    s1 = &q->f60;
    s0 = &q->f5c;
    q->f34 += q->f5c;
    q->f5c += q->f68;
    q->f38 += q->f60;
    q->f60 += q->f6c;
    func_00175700();
    if (q->f38 < q->f430) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x20D] = 0;
        q->f38 = q->f430;
        *s0 = 0;
        *s1 = 0;
        *s2 = 0;
        *s3 = 0;
        func_00183D50(p);
        func_001757E0(p, 8, 9);
    }
}
