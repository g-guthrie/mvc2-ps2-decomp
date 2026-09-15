typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))

typedef struct {
    f32 x, y, z;
} V3;

typedef struct {
    f32 x, y, z, w;
} V4;

typedef struct {
    char pad0[4];
    s32 count;
    f32 source;
    char pad1[8];
    f32 lo;
    f32 hi;
} DivDupX;

typedef struct {
    char pad0[4];
    s32 count;
    char pad1[4];
    f32 source;
    char pad2[12];
    f32 lo;
    f32 hi;
} DivDupY;

typedef struct {
    char pad0[4];
    s32 count;
    char pad1[8];
    f32 source;
    char pad2[16];
    f32 lo;
    f32 hi;
} DivDupZ;

typedef struct {
    s32 c0;
    s32 c1;
    f32 src;
    char pad[8];
    f32 q;
    f32 r;
} DivNegX;

typedef struct {
    s32 c0;
    s32 c1;
    char p0[4];
    f32 src;
    char p1[12];
    f32 q;
    f32 r;
} DivNegY;

typedef struct {
    s32 c0;
    s32 c1;
    char p0[8];
    f32 src;
    char p1[16];
    f32 q;
    f32 r;
} DivNegZ;

typedef struct {
    s32 i0;
    s32 i1;
    char p0[4];
    f32 f12;
    char p1[12];
    f32 f28;
    f32 f32;
} MixDiv;

void func_0032D110(DivDupX *s) {
    s->lo = s->hi = s->source / (f32)s->count;
}

void func_0032D130(DivDupY *s) {
    s->lo = s->hi = s->source / (f32)s->count;
}

void func_0032D150(DivDupZ *s) {
    s->lo = s->hi = s->source / (f32)s->count;
}

void func_0032D170(DivNegX *s) {
    s->r = s->src / (f32)s->c1;
    s->q = s->r * (f32)s->c0;
    s->r = -s->r;
}

void func_0032D1B0(DivNegY *s) {
    s->r = s->src / (f32)s->c1;
    s->q = s->r * (f32)s->c0;
    s->r = -s->r;
}

void func_0032D1F0(DivNegZ *s) {
    s->r = s->src / (f32)s->c1;
    s->q = s->r * (f32)s->c0;
    s->r = -s->r;
}

void func_0032D350(MixDiv *s) {
    s->f28 = s->f32 + (s->f12 - (f32)s->i1 * s->f32) / (f32)s->i0;
}

void func_00389920(u8 *d, u8 *s) {
    *(s16 *)(d + 320) = *(s16 *)(s + 320);
    *(V3 *)(d + 52) = *(V3 *)(s + 52);
}

void func_00396EC0(u8 *d, u8 *s, u8 *a) {
    F(d, 52) = F(s, 52);
    F(d, 56) = F(s, 56);
    F(d, 52) += F(a, 8);
    F(d, 56) += F(a, 12);
}

void func_0034CF30(u8 *p) {
    u8 *q = *(u8 **)(p + 24);
    F(p, 52) = F(q, 52) + F(p, 100);
    F(p, 56) = F(q, 56) + F(p, 112);
}

void func_0034B040(u8 *d, u8 *s) {
    u8 *q = *(u8 **)(s + 696);
    f32 a = F(q, 52);
    F(d, 52) = a + (a - F(s, 52));
    F(d, 56) = F(s, 56);
}

f32 func_002ADC20(u8 *p) {
    f32 v = F(p, 92);
    F(p, 52) += v;
    F(p, 92) += F(p, 104);
    F(p, 56) += F(p, 96);
    F(p, 96) += F(p, 108);
    return F(p, 92) * v;
}

void func_00132F70(u8 *p) {
    s8 *q = *(s8 **)(p + 20);
    p[316] = q[316];
    q = *(s8 **)(p + 20);
    *(V4 *)(p + 116) = *(V4 *)(q + 116);
}
