typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct N3 {
    s32 f0;
    struct N3 *f4;
    struct I3 *f8;
    s32 fC;
    s32 f10;
    s16 f14;
    s16 f16;
} N3;
typedef struct I3 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s16 f10;
    s16 f12;
} I3;

extern N3 *D_004C2AB4;
extern s16 D_0062BC34[];

s32 func_003EBA80(N3 *n, I3 *it) {
    extern N3 *func_003EB960();
    extern void func_003EBA10(N3 *, N3 *);
    N3 *s0;
    s16 a0;
    if (n == 0) {
        if (D_004C2AB4 == 0) {
            if ((s0 = func_003EB960()) == 0) return 0;
            func_003EBA10(n, s0);
            a0 = D_0062BC34[0];
        } else {
            if ((s0 = func_003EB960()) == 0) return 0;
            n = D_004C2AB4;
            D_004C2AB4 = s0;
            s0->f4 = n->f4;
            func_003EBA10(s0, n);
            a0 = D_0062BC34[0];
        }
    } else if (n->f4 == 0) {
        if ((s0 = func_003EB960()) == 0) return 0;
        func_003EBA10(n, s0);
        a0 = n->f14 + n->f16;
    } else {
        if ((s16)(n->f4->f14 - (n->f14 + n->f16)) >= it->f10) {
            if ((s0 = func_003EB960()) == 0) return 0;
            func_003EBA10(n, s0);
            a0 = n->f14 + n->f16;
        } else return 0;
    }
    it->f12 = a0;
    s0->f8 = it;
    s0->fC = it->f4;
    s0->f10 = it->f0;
    s0->f14 = a0;
    s0->f16 = it->f10;
    return 1;
}

typedef struct { f32 x, y, z; } V3;

void func_0035BC20(u8 *p, u8 *q) {
    extern void func_001E3210(u8 *, s32);
    extern void func_0019FC30(u8 *, s32);
    extern void func_00175700(u8 *);
    extern s32 func_00182D30(u8 *);
    extern void func_001843A0(u8 *);
    extern void func_001845F0(u8 *);
    u8 *s0;
    u8 *s1;
    u32 s2;
    s16 t;
    s0 = q + 0x2B8;
    if (*(u8 **)(*(u8 **)(p + 0x1E0) + 0x1E0) != p) {
        p[4] = 2;
        *(s16 *)(p + 0x1C) = 0;
        func_001E3210(p, 0x23);
        func_0019FC30(p, p[0x22]);
        return;
    }
    func_00175700(p);
    s1 = *(u8 **)(p + 0x14);
    s2 = p[0x23];
    s1[0x1FF] = 2;
    *(V3 *)(p + 0x34) = *(V3 *)(s1 + 0x34);
    if (*(s8 *)(s1 + 0x1B3) != 0) {
        if (s1[5] != 3) {
            p[0x152] = 1;
            func_00175700(p);
        } else {
            *(s16 *)(p + 0x1C) = 0;
            s0[s2 + 1] |= 0x80;
        }
    }
    s1[0x13C] = 0;
    if (func_00182D30(s1) != 0) {
        p[0x152] = 1;
        *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) - (p[0x1B7] * 4 + 3);
    }
    t = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = t;
    if (t < 0) {
        u8 *v;
        u8 *w;
        u32 u;
        u = p[5];
        p[5] = u + 1;
        v = (u8 *)(s2 + (u32)s0);
        v[1] &= 0xFD;
        w = v + 1;
        if (*(s16 *)(s1 + 0x434) == 0) {
            s1[0x20A] = 7;
        } else {
            s1[0x20A] = 0;
            if ((*w & 0x80) == 0) {
                if (p[0x1B7] != 0) s1[0x203] = 8;
                if (s1[0x20D] != 2) func_001843A0(s1);
                else func_001845F0(s1);
            }
        }
        func_001E3210(p, 0x23);
        func_0019FC30(p, p[0x22]);
    }
}
