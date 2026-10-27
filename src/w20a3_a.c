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
