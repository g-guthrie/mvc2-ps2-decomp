typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 p0[0x34]; f32 f34, f38; u8 p3c[0x20]; f32 f5c, f60; u8 p64[4]; f32 f68, f6c; u8 p70[0x3C0]; f32 f430; } SB;
void func_0020BAB0(SB *q) {
    u8 *p = (u8 *)q;
    extern void func_00175700();
    extern void func_001757E0();
    s16 t;
    f32 *a, *b;
    func_00175700(p);
    a = &q->f60;
    b = &q->f6c;
    q->f34 += q->f5c;
    q->f5c += q->f68;
    q->f38 += q->f60;
    q->f60 += q->f6c;
    if (q->f38 <= q->f430) {
        q->f38 = q->f430;
        *a = 0;
        *b = 0;
    }
    t = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = t;
    if (t == 0) {
        p[6]++;
        func_001757E0(p, 0x15, (u8)(p[0x1B7] * 2 + 0xE));
    }
}



typedef struct { u8 p0[0x34]; f32 f34, f38; u8 p3c[0x20]; f32 f5c, f60; u8 p64[4]; f32 f68, f6c; u8 p70[0x3C0]; f32 f430; } SB3;
void func_001EB9C0(SB3 *q) {
    extern void func_00183d50();
    extern void func_001757E0();
    extern void func_00175700();
    extern void func_001EB830();
    u8 *p = (u8 *)q;
    s16 t;
    q->f34 += q->f5c;
    q->f5c += q->f68;
    q->f38 += q->f60;
    q->f60 += q->f6c;
    if (q->f38 <= q->f430) {
        p[6] = 3;
        *(f32 *)((s32)p + 0x38) = *(f32 *)((s32)p + 0x430);
        p[0x20D] = 0;
        func_00183d50(p);
        func_001757E0(p, 1, 3);
        return;
    }
    if (*(s8 *)(p + 0x151) < 0) {
        p[0x151] = 0;
        t = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = t;
        if (t < 0) {
            p[6]++;
            func_001757E0(p, 0x15, 0xA);
            return;
        }
    }
    func_00175700(p);
    func_001EB830(p);
}

typedef struct { u8 p0[0x34]; f32 f34, f38; u8 p3c[0x20]; f32 f5c, f60; u8 p64[4]; f32 f68, f6c; } SB4;
void func_002EFE30(u8 *p) {
    extern void func_00175C00();
    extern void func_001830D0();
    SB4 *q = (SB4 *)p;
    u32 v[4];
    s16 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    p[0x209] = 2;
    q->f34 += q->f5c;
    q->f5c += q->f68;
    q->f38 += q->f60;
    q->f60 += q->f6c;
    t = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = t;
    if (t == 0) {
        p[0x404] = 0;
        p[0x405] = 0;
        p[6]++;
        func_00175C00(p, 1);
        *(u32 *)(p + 0x2B8) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x5C) = 0;
        v[0] = 0xC1555555;
        v[1] = 0x435EDB6D;
        func_001830D0(p, v, 1);
    }
}

