typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 D_004C2858;
extern u16 *D_004C2718;

extern s32 func_0012ABC0(s32 a, s32 b);
extern s8 func_0012A990(s32 a, s32 b, s32 c, s32 d);
extern void func_001E41B0(s32 a);
extern void func_001E41C0(s32 a);

void func_0012A320(u8 *p) {
    u8 v;
    D_004C2858 = func_0012A990(func_0012ABC0(3, 0), D_004C2858, 7, 2);
    if ((s8)p[0x40] != D_004C2858) {
        v = D_004C2858 << 3;
        func_001E41B0(v);
        func_001E41C0(v);
        p[0x40] = D_004C2858;
    }
}

typedef struct { u8 pad[0x160]; s8 b[8]; } S1CF;
extern void func_001CF6F0(void *p);
extern void func_001CF6A0(void *p);
extern void func_00175670(void *p);
extern void func_001CF7A0(void *p);
extern void func_001CF720(void *p);

void func_001CF280(u8 *p) {
    S1CF *a;
    s8 *b;
    s8 f;
    s8 *q;
    func_001CF6F0(p);
    p[0x13C] = 1;
    p[0x24] = 7;
    if (*D_004C2718 != *(u16 *)(*(u8 **)(p + 0x18) + 0x168)) {
        func_001CF6A0(p);
        return;
    }
    a = *(S1CF **)(p + 0x18);
    b = a->b;
    f = b[1];
    q = b + 1;
    if (f != 0) {
        *q = 0;
        func_00175670(p);
    }
    func_001CF7A0(p);
    func_001CF720(p);
}

extern s32 D_004C28AC;
extern s32 D_004C28B8;
extern s8 *D_004C2840;
extern void func_0012DA40(s32 a, s32 b, s32 c);
extern void func_00176230(s32 a, s32 b);

void func_0016FA10(void) {
    if (D_004C2840[0x29] == 0) {
        func_0012DA40(0x355, D_004C28AC, 2);
        func_0012DA40(0x356, D_004C28B8 + 0x100000, 2);
    } else {
        func_0012DA40(0x355, D_004C28AC, 2);
        func_0012DA40(0x356, D_004C28B8 + 0x100000, 2);
    }
    func_00176230(D_004C28B8 + 0x100000, D_004C28B8);
}

typedef struct {
    u8 pad[0x1C];
    struct { u8 *a; u8 *b; s32 c; } ent[1];
} T18A;
extern T18A *D_004C2794;
extern s16 D_004D1802[];
extern u8 D_00449080[];
extern s32 func_00174170(void);

u8 func_0018AC30(u8 *p) {
    u8 *s0;
    u8 *s1;
    u8 *t;
    s32 r;
    s0 = D_004C2794->ent[p[2]].a;
    s1 = D_004C2794->ent[p[2]].b;
    if (*(s16 *)(s0 + 0x434) < *(s16 *)(s1 + 0x434)) {
        t = s0;
        s0 = s1;
        s1 = t;
    }
    r = func_00174170() & 0x1F;
    if (D_00449080[D_004D1802[0]] < r) {
        s0 = s1;
    }
    return s0[0x425];
}

extern u8 D_004C27D0;
extern u8 *D_004C283C;
extern void func_00122FE0();
extern void func_00416AE0(s32 a);
extern void func_004171E0();
extern void func_001532F0();
extern void func_0011D8F8(void *p, s32 a, s32 b);
extern void func_003DD260(void *p);
extern void func_001538B0(void *p, s32 a, void *q);
extern void func_00416CC0(s32 a);

void func_00153250(void) {
    u8 t[0x40];
    u8 buf[0x1E4];
    u8 *g;
    s16 *ip;
    s32 *tbl;
    if (D_004C27D0 != 8) {
        func_00122FE0();
        func_00416AE0(0);
        func_004171E0();
        func_001532F0();
        func_0011D8F8(buf, 0, 0x1E4);
        func_003DD260(t);
        g = D_004C283C;
        *(u8 **)(buf + 0x84) = g;
        ip = (s16 *)(buf + 0xCC);
        *ip = 0;
        tbl = *(s32 **)(g + 0x1C);
        func_001538B0(buf, tbl[*ip], t);
        func_00416CC0(1);
    }
}
