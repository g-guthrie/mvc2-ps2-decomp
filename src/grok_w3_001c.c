typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef float f32;

#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define H(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define I(p, o) (*(s32 *)((u8 *)(p) + (o)))

typedef struct {
    f32 x, y, z;
} V3;

typedef struct {
    u8 pad[16];
    void (*callback)(void);
    u8 pad20[4];
    void *arg;
    u8 pad28[4];
} Entry;

extern u8 D_0044DDA0[];
extern u8 D_0044DAC0[];
extern void func_001757E0(u8 *, s32, s32);
extern void func_001C5110(u8 *);
extern s8 func_00175700(u8 *);
extern void func_001E3240(u8 *, s32);
extern void func_001CB5A0(u8 *, s32, s32);
extern void func_001CB5D0(u8 *);
extern Entry *func_003DA750(s32, s32, s32);
extern void func_001C1700(void);
extern void func_001C1DF0(void);
extern void func_00175C00(u8 *, s32);
extern s8 func_00175670(u8 *);
extern void func_001CF6A0(u8 *);

void func_001CCF40(u8 *p, s32 a1) {
    func_001757E0(p, 23, D_0044DDA0[(u8)a1]);
}

void func_001C4D30(u8 *p) {
    if (S(p, 28) < 61)
        p[5]++;
    func_001C5110(p);
}

void func_001D6CD0(u8 *p, u8 *q) {
    *(V3 *)(p + 52) = *(V3 *)(q + 52);
    func_001757E0(p, 21, 1);
}

void func_001C4760(u8 *p) {
    if (func_00175700(p) < 0) {
        p[6] = 1;
        p[7] = 0;
    }
}

void func_001DDB60(u8 *p, u8 *q) {
    F(p, 52) = F(q, 52);
    F(p, 56) = F(q, 56);
    if (q[703]) {
        p[5]++;
        p[316] = 1;
        S(p, 28) = 56;
    }
}

void func_001D6D80(u8 *p, u8 *q) {
    *(V3 *)(p + 52) = *(V3 *)(q + 52);
    if (I(p, 208) != H(q, 360)) {
        p[4] = 2;
        p[316] = 0;
    }
    func_00175700(p);
}

void func_001D6DC0(u8 *p) {
    func_001E3240(p, 31);
    p[4]++;
    p[316] = 0;
}

void func_001CB180(u8 *p) {
    func_001CB5A0(p, 27, D_0044DAC0[I(p, 208) >> 1]);
}

void func_001C16B0(u8 *p) {
    Entry *e = func_003DA750(0, 3, 0);
    if (e) {
        e->callback = func_001C1700;
        e->arg = p;
    }
}

void func_001C1DA0(u8 *p) {
    Entry *e = func_003DA750(0, 4, 0);
    if (e) {
        e->callback = func_001C1DF0;
        e->arg = p;
    }
}

void func_001C1B40(u8 *p, u8 *q) {
    p[5] = 0;
    p[316] = 0;
    q[697] = 0;
    func_00175C00(q, 1);
    func_001E3240(q, 39);
}

void func_001C8330(u8 *p) {
    s16 v = (s16)(S(p, 28) - 1);
    S(p, 28) = v;
    if (v == 0) {
        p[7]++;
        *(s16 *)(p + 28) = 16;
        S(p, 320) ^= 1;
    }
}

void func_001CB540(u8 *p) {
    if (p[5] == 0) {
        p[5]++;
        func_001CB5A0(p, 27, 95);
    }
    func_001CB5D0(p);
}

void func_001DBC80(u8 *p) {
    func_00175700(p);
    S(p, 30) = (s8)p[338];
    if ((s8)p[337] < 0)
        p[316] = 0;
    else
        p[316] = 1;
}

void func_001CF440(u8 *p) {
    p[36] = 0;
    p[316] = 1;
    if (func_00175670(p) < 0)
        func_001CF6A0(p);
}

void func_001C25B0(u8 *p) {
    if (func_00175700(p) < 0) {
        p[214] = p[6];
        p[215] = p[7];
        p[6] = 2;
        p[7] = 0;
    }
}




