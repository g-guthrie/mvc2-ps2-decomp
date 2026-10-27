typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[5]; u8 b5; u8 b6; u8 b7; u8 pad8[0x2C]; f32 f34; f32 f38; u8 pad3c[0x20]; f32 f5c; f32 f60; u8 pad64[4]; f32 f68; f32 f6c; u8 pad70[0x3C0]; f32 f430; } S22;
void func_0017CF00(S22 *p) {
    extern void func_00175700();
    extern void func_001757E0();
    extern void func_00186A60();
    extern void func_00183d50();
    f32 *x0, *x1, *x2, *x3;
    func_00175700(p);
    x0 = &p->f5c;
    x2 = &p->f68;
    x1 = &p->f60;
    x3 = &p->f6c;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (p->f38 <= p->f430) {
        p->f38 = p->f430;
        *(u8 *)((u8 *)p + 0x20D) = 0;
        *x0 = 0;
        *x1 = 0;
        *x2 = 0;
        *x3 = 0;
        func_001757E0(p, 0, 0);
        p->b5 = 0;
        p->b7 = 0;
        p->b6 = 0;
        *(u8 *)((u8 *)p + 0x1FD) = *(u8 *)((u8 *)p + 0x26C);
        func_00186A60(p, 0x1D);
        func_00183d50(p);
    }
}

typedef struct { u8 b0, b1, b2, b3, b4, b5; } E15;
typedef struct { f32 x, y, z; } V3;
extern E15 D_0044C0E0[];
void func_001BD4F0(u8 *p, void *q_context) {
    u8 *q = (u8 *)q_context;
    extern void func_00175580();
    E15 *e;
    if (q[0x1E4] != 0x15 || q[0x1FD] != 6 || *(u16 *)(q + 0x168) != 0x1507 || *(s8 *)(q + 0x150) == 0) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
        return;
    }
    *(u32 *)(p + 0x118) = 0x3F000000;
    *(s16 *)(p + 0x140) = *(s16 *)(q + 0x140);
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    *(s8 *)(p + 0x31) = -1;
    e = &D_0044C0E0[p[0x20]];
    func_00175580(p, 0x1B, e->b5, *(s8 *)(q + 0x150) & 0xF);
}

typedef struct { u8 pad0[6]; u8 b6; u8 pad7[0x2D]; f32 f34; f32 f38; u8 pad3c[0x20]; f32 f5c; f32 f60; u8 pad64[4]; f32 f68; f32 f6c; } S26;
void func_0025AFF0(S26 *p) {
    extern void func_00175700();
    extern s32 func_001864a0();
    extern void func_00183d50();
    extern void func_001757E0();
    f32 *x0, *x1, *x2, *x3;
    func_00175700(p);
    x0 = &p->f5c;
    x2 = &p->f68;
    x1 = &p->f60;
    x3 = &p->f6c;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (func_001864a0(p) != 0) {
        u32 t;
        func_00183d50(p);
        t = p->b6;
        p->b6 = t + 1;
        *x0 = 0;
        *x1 = 0;
        *x2 = 0;
        *x3 = 0;
        func_001757E0(p, 0x14, 1);
    }
}

typedef struct { u8 pad0[0x34]; f32 f34; u8 pad38[0x108]; s16 h140; u8 pad142[0xF]; s8 b151; } S5;
void func_0028D4B0(S5 *p) {
    extern s8 func_00175700();
    extern void func_001843A0();
    f32 c;
    if (func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if (p->b151 != 0) {
        p->b151 = 0;
        {
            u32 t = *(u8 *)((u8 *)p + 0x1E6);
            *(u8 *)((u8 *)p + 0x1E6) = t ^ 1;
        }
        p->h140 = *(u8 *)((u8 *)p + 0x1E6);
        if (p->h140 == 0) {
            p->f34 -= 26.66666603f;
        } else {
            p->f34 += 26.66666603f;
        }
    }
}

u8 *func_002E0530(u8 *p) {
    extern u8 *func_001E7FD0(u8 *);
    u8 *r = 0;
    f32 c;
    if (p[0x1B7] == 0 || p[0x212] != 0) {
        return 0;
    }
    if ((*(u16 *)(p + 0x20E) & 0xC00) == 0) return r;
    if (p[0x20D] == 2) {
        c = 106.6666641f + *(f32 *)(p + 0x430);
        if (*(f32 *)(p + 0x38) < c) {
            return r;
        }
        r = func_001E7FD0(p);
        if (r != 0) p[0x20B] = 1;
    } else if (p[0x20D] == 0) {
        r = func_001E7FD0(p);
        if (r != 0) p[0x20B] = 0;
    }
    return r;
}

typedef struct { u8 pad0[0x21]; u8 b21; u8 pad22[0x12]; f32 f34; f32 f38; } S11;
extern f32 D_004F1FC8;
extern f32 D_004F1FD4;
void func_003C3050(S11 *p) {
    extern s32 func_00118FA8(f32);
    s16 *q = (s16 *)((u8 *)p + 0xD0);
    p->f34 = 320.0f + D_004F1FC8;
    if (p->b21 == 0) {
        p->f34 += 213.3333282f;
    } else {
        p->f34 -= 213.3333282f;
    }
    q[1] = func_00118FA8(D_004F1FD4 - 154.2857056f);
    p->f38 = q[0] + q[1];
}

