typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern void func_00175700();
extern void func_001E7F60(u8 *);
void func_00374410(u8 *p) {
    *(f32 *)(p + 0x50) += 0.00800000037997961f;
    *(f32 *)(p + 0x54) -= 0.0120000001043081f;
    {
    s16 v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v <= 0) { u32 t = p[6]; p[6] = t + 1; *(s16 *)(p + 0x1C) = 5; }
    }
}
void func_00374480(u8 *p) {
    *(f32 *)(p + 0x50) += 0.00800000037997961f;
    *(f32 *)(p + 0x54) -= 0.0120000001043081f;
    {
    s16 v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v <= 0) {
        *(s16 *)(p + 0x1E) = 3; *(s16 *)(p + 0x1C) = 3;
        { u32 t = p[5]; p[5] = t + 1; }
        p[6] = 0;
        *(f32 *)(p + 0x54) = 1.0f; *(f32 *)(p + 0x50) = 1.0f;
    }
    }
}
void func_00360390(u8 *p) {
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    func_001E7F60(p);
    if (*(s8 *)(p + 0x1B2)) {
        u32 t = p[5]; p[5] = t + 1;
        *(u32 *)(p + 0x60) = 0x40892492;
        *(s16 *)(p + 0x1C) = 0x78;
    }
}
typedef struct { s16 x, y; } P2;
extern P2 D_0044E2F0[];
void func_001D4B40(u8 *p, u8 *q) {
    u8 *t = *(u8 **)(q + 0x1DC);
    u32 face = q[0x1E6];
    P2 *e = &D_0044E2F0[t[1]];
    f32 dx = 1.66666662693f * e->x;
    f32 dy = 2.14285707474f * e->y;
    if (!face) dx = -dx;
    *(f32 *)(p + 0x34) = *(f32 *)(t + 0x34) + dx;
    *(f32 *)(p + 0x38) = *(f32 *)(t + 0x38) + dy;
}
void func_00354360(u8 *p, u16 idx, f32 *o1, f32 *o2) {
    s16 *e = (s16 *)((u32)*(u8 **)(p + 0x180) + idx * 8);
    f32 a, hi, lo;
    a = *(f32 *)(p + 0x38) - 2.14285707474f * e[2];
    hi = a + 2.14285707474f * e[3];
    lo = a - 2.14285707474f * e[3];
    if (*o1 < hi) *o1 = hi;
    if (!(*o2 <= lo)) *o2 = lo;
}
void func_0022FFB0(u8 *p) {
    f32 a = 16.6666660309f;
    f32 b = 18.3333320618f;
    f32 c = -0.208333328366f;
    if (*(s16 *)(p + 0x140) == 0) { a = -a; b = -b; c = -c; }
    if (p[0x1B7] != 0) *(f32 *)(p + 0x5C) = b; else *(f32 *)(p + 0x5C) = a;
    *(f32 *)(p + 0x68) = c;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x6C) = 0;
}
void func_00200D20(u8 *p) {
    f32 lim;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    lim = 548.5714111328125f + *(f32 *)(p + 0x430);
    if (lim < *(f32 *)(p + 0x38)) {
        u32 t;
        *(f32 *)(p + 0x38) = lim;
        t = p[7]; p[7] = t + 1;
    }
    func_00175700(p);
}
