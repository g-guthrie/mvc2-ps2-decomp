typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct S36CC30p {
    u8 pad0[7];
    u8 b7;
    u8 pad1[0x2C];
    f32 f34;
    f32 f38;
    f32 f3C;
} S36CC30p;
typedef struct S36CC30 {
    u8 pad0[0x18];
    S36CC30p *p18;
    u8 pad1[8];
    u8 b24;
    u8 pad2[0xF];
    f32 f34;
    f32 f38;
    f32 f3C;
    u8 pad3[0x10];
    f32 f50;
    f32 f54;
    u8 pad4[0xE4];
    u8 b13C;
} S36CC30;
void func_001757E0(void *p, s32 a, s32 b);

void func_0036CC30(S36CC30 *a) {
    a->b13C = 1;
    a->f34 = a->p18->f34;
    a->f38 = a->p18->f38;
    a->f3C = a->p18->f3C;
    a->b24 = 12;
    a->f50 += 0.015625f;
    a->f54 += 0.015625f;
    func_001757E0(a, 0x17, (u8)(a->p18->b7 + 0x12));
}

#define B(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define W(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))

typedef struct S1C4CA0q {
    u8 pad[0x430];
    f32 f430;
} S1C4CA0q;
typedef struct S1C4CA0 {
    u8 pad0[5];
    u8 b5;
    u8 pad1[0x12];
    S1C4CA0q *p18;
    u8 pad2[0x18];
    f32 f34;
    f32 f38;
    u8 pad3[0x20];
    f32 f5C;
    f32 f60;
    u8 pad4[4];
    f32 f68;
    f32 f6C;
} S1C4CA0;
void func_001C5110(void *p);
void func_00175700(void *p);

void func_001C4CA0(S1C4CA0 *a) {
    S1C4CA0q *q = a->p18;
    f32 c = 21.4285698f;
    a->f34 += a->f5C;
    a->f5C += a->f68;
    a->f38 += a->f60;
    a->f60 += a->f6C;
    if (a->f38 <= c + q->f430) {
        u32 t = a->b5;
        a->b5 = t + 1;
        a->f38 = c + q->f430;
    }
    func_001C5110(a);
}

void func_0015A580(u8 *a) {
    s16 v;
    F(a, 0x74) += 0.25f;
    F(a, 0x34) += F(a, 0x5C);
    F(a, 0x5C) += F(a, 0x68);
    F(a, 0x38) += F(a, 0x60);
    F(a, 0x60) += F(a, 0x6C);
    v = *(s16 *)(a + 0x1C) - 1;
    *(s16 *)(a + 0x1C) = v;
    if (v == 0) {
        u32 t = a[4];
        a[4] = t + 1;
        *(s16 *)(a + 0x1C) = 8;
    }
}

typedef struct V3 { f32 x, y, z; } V3;
void func_001266A0(void *p, s32 a, s32 b);
extern void func_0018C6E0(void *);
void func_0015D010(void *p, V3 *v);
void func_001757E0(void *p, s32 a, s32 b);

void func_002A5DF0(u8 *p) {
    V3 v;
    func_001266A0(p, 5, 5);
    func_0018C6E0(p);
    B(p, 0x1B4) = 10;
    v.x = -55.0f;
    v.y = 117.857140f;
    v.z = 0.0f;
    func_0015D010(p, &v);
    if ((p[0x22] & 2) == 0) {
        p[0x1E6] ^= 1;
        *(s16 *)(p + 0x140) = p[0x1E6];
    }
    func_001757E0(p, 0xF, 4);
}

typedef struct S371E70 {
    u8 pad0[5];
    u8 b5;
    u8 pad1[0x4A];
    f32 f50;
    f32 f54;
    u8 pad2[0xFB];
    s8 b153;
} S371E70;

void func_00371E70(S371E70 *p) {
    if (p->f50 > 1.0f) {
        p->f50 = 1.0f;
        p->f54 = 1.0f;
    } else {
        p->f50 += 0.04f;
        p->f54 += 0.04f;
    }
    func_00175700(p);
    if (p->b153 < 0) {
        u32 t = p->b5;
        p->b5 = t + 1;
        func_001757E0(p, 0x17, 0x1E);
    }
}
