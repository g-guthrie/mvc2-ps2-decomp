typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00175700(void *p);
extern void func_001757E0(void *p, s32 a, s32 b);
extern void func_001E3710(void *p, s32 a);
extern void func_0033C6E0(void *p);
extern u8 *func_003DA750();
extern void func_003A5E90(void *p);
extern s32 func_0016A930(void *p, s32 a, s32 b);
extern void func_003DAA40(void *p);
extern void (*D_00442580[])(void *);

typedef struct { u8 pad[0x10]; u8 x, y; u8 pad2[0xA]; } E16;

extern s8 *D_004C2840;

typedef struct { s16 a, b; } P2;
extern P2 D_004CB010[];

extern void (*D_00442580[])(void *);
extern void func_003DAA40(void *p);

extern void func_003D77C0(void *p);

extern f32 D_004F1FC8;
extern f32 D_004F1FD4;
extern s16 func_00118FA8(f32 x);

extern u8 *D_004C2794;
extern u8 D_004BFCB0[8];

extern s32 func_002B2EC0(void *p);
extern s32 func_002B2F20(void *p);
extern s32 func_002B2F80(void *p);
extern s32 func_002B2FE0(void *p);
extern s32 func_002B3050(void *p);

extern void (*D_004C1BC0[2])(void *);

extern void func_00175670(void *p);
extern void func_001975C0(void *p, void *q);

extern s32 func_00292DC0(void *p);
extern u8 D_00457970[];

extern void func_00175910(void *p, s32 a, s32 b, s32 c);
extern u8 D_0044B290[];

typedef struct { f32 x, y, z; } V3;
extern V3 D_004B7CD8;
extern s32 D_004C283C;
extern void func_00333B00(void *p);

extern u8 *D_004C2930;
extern u8 *D_004C2934;
extern u8 *D_004C2938;
extern void (*D_00461E10[])(void *);
extern void (*D_00461E20[])(void *);

typedef struct { u8 b[0x5B8]; } E5B8;
extern E5B8 D_004F20B0[];
extern void func_00175C00(void *p, s32 a);

extern u8 D_00459C50[];
extern s32 func_00189310(void *p, void *a, void *b);
extern void func_0018A990(void *p, s32 a);
extern void func_002CAFC0(void *p);

extern s16 D_004C27A4;
extern void func_001A3FF0(void *p);

extern s32 D_004C2838;
extern void func_001610C0(void *p);
extern void func_00161240(void *p);
extern void func_00170DF0(u32);
extern void func_00152550(void *, void (*)(u8 *));

typedef struct { s16 a, b; } P2s;
extern P2s D_0045F800[];
extern V3 D_0045F820[];
extern u32 func_00417A40(void);

extern void func_001843A0(void *p);
extern void func_00296FB0(void *p);


void func_00204B10(u8 *p) {
    s8 r;
    if (*(f32 *)(p + 0x6C) == 0.0f) *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    r = func_00175700(p);
    if (r < 0) func_00184540(p);
}

void func_0033C7A0(u8 *p, u8 b) {
    u8 *q = func_003DA750(0, 6, 1);
    if (q != 0) {
        q[0x13C] = 1;
        *(void **)(q + 0x10) = func_0033C6E0;
        *(s32 *)(q + 0xD0) = 0x800;
        *(u8 **)(q + 0xC8) = p + 0x88;
        q[0x20] = b;
    }
}

void func_0020B770(u8 *p) {
    s16 v;
    func_00175700(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 0x15, (u8)(p[0x1B7] * 2 + 6));
    }
}

void func_0034A430(u8 *p) {
    s8 r;
    u8 *q = p + 0x88;
    if (*(s8 *)(p + 0x1B3) != 0) *q = 1;
    r = func_00175700(p);
    if (r < 0) {
        u32 t = p[5];
        p[5] = t + 1;
        func_001E3710(p, 0x16);
        func_001757E0(p, 0x16, 0x2D);
    }
}

void func_003A5E10(u8 *p, u8 a, u8 b) {
    u8 *q = func_003DA750(p, 1, 2);
    if (q != 0) {
        *(void **)(q + 0x10) = func_003A5E90;
        *(s16 *)(q + 0x26) = 0x2E02;
        *(u8 **)(q + 0x14) = p;
        q[1] = p[1];
        *(s32 *)(q + 0x18) = *(s32 *)(p + 0x18);
        q[0x20] = a;
        q[0x21] = b;
    }
}

void func_003D7AD0(u8 *p) {
    u8 *q;
    s32 v;
    func_00175700(p);
    q = func_003DA750(p, 1, 2);
    if (q != 0) {
        *(void **)(q + 0x10) = func_003D77C0;
        *(s32 *)(q + 0x18) = *(s32 *)(p + 0x18);
        q[0x20] = 1;
        *(s32 *)(q + 0xD0) = 0;
        *(u8 **)(q + 0x14) = p;
        *(s32 *)(q + 0xD4) = 0;
        v = *(s32 *)(p + 0xD8) - 1;
        *(s32 *)(p + 0xD8) = v;
        if (v == 0) {
            *(s32 *)(p + 0xD8) = 5;
            *(s32 *)(q + 0xD4) = 0xFF;
        }
    }
}

s32 func_002B2E30(void *p) {
    if (func_002B2EC0(p)) return 1;
    if (func_002B2F20(p)) return 1;
    if (func_002B2F80(p)) return 1;
    if (func_002B2FE0(p)) return 1;
    return func_002B3050(p) != 0;
}

void func_00196630(u8 *p, u8 *q) {
    if (p[0x21] < 2) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        func_00175670(p);
        func_001975C0(p, q);
    }
}

void func_00183BA0(u8 *p) {
    s32 i;
    s32 off;
    s8 v = *(s8 *)(p + 0x25D) - 1;
    *(s8 *)(p + 0x25D) = v;
    if (v != 0 && p[5] == 0) {
        u8 a = p[0x1E4];
        if (a != 0x1D) {
            if (a == 0x1C) return;
        } else return;
    }
    p[0x25C] = 0;
    i = 0;
    off = 0;
    do {
        func_00175C00((u8 *)D_004F20B0 + off, 1);
        i++;
        off += 0x5B8;
    } while (i < 6);
}

void func_002053B0(u8 *p) {
    s16 v;
    p[0x208] = 3;
    p[0x201] = 3;
    p[0x207] = 3;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        *(s16 *)(p + 0x1C) = 4;
    }
}
