typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef float f32;

#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define P(p, o) (*(u8 **)((u8 *)(p) + (o)))

typedef struct {
    f32 x, y, z;
} V3;

typedef struct {
    u8 pad[16];
    void (*callback)(void);
    u8 pad20[4];
    void *arg;
    u8 pad28[4];
    u8 mode;
} Entry;

typedef struct EventValueSource {
    u8 padding[360];
    u16 value;
} EventValueSource;

typedef struct EventState {
    u8 padding[24];
    EventValueSource *value_source;
} EventState;

extern s8 func_00175700(u8 *);
extern s8 func_00175670(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern void func_001754A0(u8 *, s32, s32);
extern void func_001CF6F0(u8 *);
extern void func_001C4830(u8 *, s32);
extern void func_001C1330();
extern void func_001C9360(u8 *);
extern void func_001CADB0(u8 *);
extern void func_001CAD90(u8 *);
extern void func_001CAC90(u8 *);
extern void func_001CA780(u8 *);
extern void func_001CA890(u8 *);
extern void func_001C48E0(void);
extern void func_001C1B40(u8 *, u8 *);
extern void func_001C1C50(u8 *, u8 *);
void func_001C1AE0(u8 *p, u8 *q);
extern void func_001C1BC0(u8 *);
extern void func_001C1D40(u8 *, u8 *);
extern void func_001C3A80(u8 *, u8 *);
extern void func_001C3F20(void);
extern Entry *func_003DA750(s32, s32, s32);
extern u16 *D_004C2718;
extern u8 *D_004C2708;
extern void (*jtbl_0044CE70[])(u8 *);
extern void (*jtbl_0044CB38[])(u8 *);
extern void (*jtbl_0044CB48[])(u8 *);

void func_001C5030(u8 *p) {
    u8 *q = P(p, 24);
    if (q[4] >= 2) {
        p[4] = 2;
        p[316] = 0;
        return;
    }
    *(V3 *)(p + 52) = *(V3 *)(q + 52);
    p[316] = (u8)*(s8 *)(q + 316);
}

void func_001C4710(u8 *p) {
    func_00175700(p);
    if (*(s8 *)(p + 337) != 0) {
        p[7]++;
        func_001C4830(p, p[32]);
    }
}

void func_001C6690(u8 *p) {
    func_00175700(p);
    if (*(s8 *)(p + 337) != 0) {
        p[7]++;
        S(p, 320) ^= 1;
    }
}

void func_001CEF00(u8 *p) {
    func_001CF6F0(p);
    p[36] = 7;
    *D_004C2718 = ((EventState *)p)->value_source->value;
    func_001754A0(p, 27, 11);
}

void func_001CEFA0(u8 *p) {
    func_001CF6F0(p);
    p[36] = 7;
    *D_004C2718 = ((EventState *)p)->value_source->value;
    func_001754A0(p, 27, 14);
}

void func_001CEFF0(u8 *p) {
    F(p, 52) = F(P(p, 24), 52);
    F(p, 56) = F(P(p, 24), 1072);
    p[36] = 0;
    *D_004C2718 = ((EventState *)p)->value_source->value;
    func_001754A0(p, 27, 16);
}

void func_001C12B0(u8 *p, u8 *q) {
    p[317] = (u8)*(s8 *)(P(q, 24) + 317);
    S(p, 318) = S(P(q, 24), 318);
    func_001C1330(p, q);
    p[36] = (u8)*(s8 *)(q + 36);
}

void func_001C0CC0(u8 *p) {
    func_001C1330(p);
    p[36] = 8;
    if (func_00175670(p) < 0) {
        p[4]++;
        p[316] = 0;
    }
}

void func_001C1250(u8 *p, u8 *q) {
    p[317] = (u8)*(s8 *)(P(q, 24) + 317);
    S(p, 318) = S(P(q, 24), 318);
    func_001C1330(p, q);
    p[36] = (u8)*(s8 *)(q + 36);
    func_00175670(p);
}

void func_001C1A80(u8 *p, u8 *q) {
    if (q[888] == 0)
        func_001C1B40(p, q);
    else {
        func_001C1C50(p, q);
        func_001C1AE0(p, q);
    }
}

void func_001C1AE0(u8 *p, u8 *q) {
    p[316] = (u8)*(s8 *)(q + 316);
    p[36] = (u8)*(s8 *)(q + 36);
    func_001C1BC0(p);
    func_001C1D40(p, q);
    func_00175670(p);
}

void func_001C31A0(u8 *p, u8 *q) {
    if (q[484] != 22)
        func_001C3A80(p, q);
    else
        jtbl_0044CB38[p[7]](p);
}

void func_001C32F0(u8 *p, u8 *q) {
    if (q[484] != 22)
        func_001C3A80(p, q);
    else
        jtbl_0044CB48[p[7]](p);
}

void func_001C3EC0(u8 *p, u8 mode) {
    Entry *e = func_003DA750(0, 3, 0);
    if (e) {
        e->callback = func_001C3F20;
        e->arg = p;
        e->mode = mode;
        p[699] = 255;
    }
}

void func_001C4EC0(u8 *p) {
    u8 *q = P(p, 24);
    if (q[4] >= 2) {
        p[4] = 2;
        p[316] = 0;
        return;
    }
    *(V3 *)(p + 52) = *(V3 *)(q + 52);
    p[316] = (u8)*(s8 *)(q + 316);
    func_00175670(p);
}

void func_001C4890(s32 a0, u8 mode) {
    Entry *e = func_003DA750(a0, 3, 2);
    if (e) {
        e->callback = func_001C48E0;
        e->mode = mode;
        e->arg = (void *)a0;
    }
}

void func_001C7A80(u8 *p, u8 *q) {
    if (func_00175700(p) < 0) {
        p[7]++;
        S(q, 28) = 0;
    }
}

void residual_001C9310(u8 *p) {
    p[4]++;
    p[316] = 1;
    p[36] = 0;
    S(p, 320) = 0;
    func_001757E0(p, 23, 17);
    func_001C9360(p);
}

void residual_001CA730(u8 *p) {
    p[5]++;
    p[6] = 1;
    func_001CADB0(p);
    func_001CAC90(p);
    S(p, 28) = 60;
    func_001CA780(p);
}

void func_001CA840(u8 *p) {
    p[5]++;
    p[6] = 1;
    func_001CAD90(p);
    func_001CAC90(p);
    S(p, 28) = 1;
    func_001CA890(p);
}

void func_001CF5F0(u8 *p) {
    if (func_00175700(p) < 0) {
        p[5]++;
        func_001757E0(p, 21, 42);
    }
}

void func_001C88C0(u8 *p) {
    D_004C2708 = p + 208;
    jtbl_0044CE70[p[4]](p);
}
