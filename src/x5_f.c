typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[0x34]; f32 f34, f38; u8 pad1[0x5C - 0x3C]; f32 f5c, f60; u8 pad2[4]; f32 f68, f6c; } S5;
extern s8 func_00175700();
void func_00263FC0(S5 *p) {
    f32 *a, *b, *c, *d;
    f32 v;
    func_00175700(p);
    a = &p->f5c; c = &p->f68; b = &p->f60; d = &p->f6c;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (*(s8 *)((u8 *)p + 0x151) != 0) {
        u32 t = ((u8 *)p)[6];
        ((u8 *)p)[6] = t + 1;
        *(s32 *)a = 0;
        *(s32 *)b = 0;
        *(s32 *)c = 0;
        *(s32 *)d = 0;
        if (((u8 *)p)[0x1E6] != 0) {
            v = 1.6666666269302368f;
        } else {
            v = -1.6666666269302368f;
        }
        p->f5c = v;
    }
}

typedef struct { u8 pad0[0x34]; f32 f34, f38; u8 pad1[0x5C - 0x3C]; f32 f5c, f60; u8 pad2[4]; f32 f68, f6c; } S6;
extern void func_001863F0();
extern void func_002572D0();
extern void func_00257220();
extern void func_00257100();
extern void func_00256FC0();
void func_00256EF0(S6 *p) {
    u8 *q = (u8 *)p;
    if (q[0x1FC] < 3) {
        p->f34 += p->f5c;
        p->f5c += p->f68;
        p->f38 += p->f60;
        p->f60 += p->f6c;
        func_001863F0(p);
    }
    if (q[0x212] == 1) {
        if (q[0x20D] == 1) {
            func_002572D0(p);
            return;
        }
        func_00257220(p);
    } else {
        if (q[0x20D] == 1) {
            func_00257100(p);
        } else {
            func_00256FC0(p);
        }
    }
}

typedef struct { f32 x, y, z; } V3;
extern void func_00175670();
void func_0019AF40(u8 *p, u8 *q) {
    u8 *r;
    u8 *a3;
    f32 t;
    p[0x13C] = 0;
    r = *(u8 **)(p + 0x14);
    a3 = r + 0x88;
    if (r[3] != 1 || *(u16 *)(r + 0x26) != 0x601 || !(r[4] < 2)) {
        u32 u = p[4];
        p[4] = u + 1;
        return;
    }
    *(V3 *)(p + 0x34) = *(V3 *)(a3 + 0x1C);
    if (q[0x20B] == 5) {
        t = 53.33333206176758f;
        if (*(s16 *)(q + 0x140) != 0) t = -t;
        *(f32 *)(p + 0x34) += t;
    }
    func_00175670(p);
    p[0x13C] = 1;
}

typedef struct { u8 pad0[0x34]; f32 f34, f38; u8 pad1[0x5C - 0x3C]; f32 f5c, f60; u8 pad2[4]; f32 f68, f6c; } S8;
extern void func_001843A0();
extern s8 func_00175700();
void func_0031CFB0(u8 *actor) {
    S8 *p = (S8 *)actor;
    u8 *q = (u8 *)p;
    s16 v;
    func_00175700(p);
    if (*(s8 *)(q + 0x151) == 0) {
        if (q[0x20] != 0 && q[0x214] == 0) {
            q[0x20] = 0;
            *(u32 *)(q + 0x5C) = 0xC1855555;
            if (q[0x1E6] != 0) {
                p->f5c = -p->f5c;
            }
        }
        p->f34 += p->f5c;
        p->f5c += p->f68;
        p->f38 += p->f60;
        p->f60 += p->f6c;
        v = *(s16 *)(q + 0x1C) - 1;
        *(s16 *)(q + 0x1C) = v;
        if (v <= 0) func_001843A0(p);
    }
}

typedef struct { u8 pad0[0x34]; f32 f34, f38; u8 pad1[0x5C - 0x3C]; f32 f5c, f60; u8 pad2[4]; f32 f68, f6c; } SA;
typedef struct { u8 pad[0x430]; f32 f430; } SB;
extern s8 func_00175700();
extern void func_001757E0();
extern void func_001E7F60();
void func_00362960(SA *p, SB *q) {
    f32 k = 171.4285583496094f;
    u32 t;
    func_00175700(p);
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (p->f38 <= k + q->f430) {
        t = ((u8 *)p)[6];
        ((u8 *)p)[6] = t + 1;
        *(u32 *)((u8 *)p + 0x6C) = 0xBF4DB6DB;
        func_001757E0(p, 0x17, 0x1E);
    } else {
        func_001E7F60(p);
    }
}

typedef struct { u8 pad0[0x34]; f32 f34, f38; u8 pad1[0x5C - 0x3C]; f32 f5c, f60; u8 pad2[4]; f32 f68, f6c; } SC;
extern s8 func_00175700();
extern void func_003266E0();
void func_003230A0(SC *p) {
    u8 *q = (u8 *)p;
    f32 v;
    s16 w;
    u32 t;
    if (q[6] == 0) {
        t = q[6];
        q[6] = t + 1;
        *(s16 *)(q + 0x1C) = 0x1E;
        v = -10.833333015441895f;
        if (q[0x1E6] != 0) v = -v;
        p->f5c = v;
        *(s32 *)&p->f68 = 0;
        *(s32 *)&p->f60 = 0;
        *(s32 *)&p->f6c = 0;
    } else {
        func_00175700(p);
        p->f34 += p->f5c;
        p->f5c += p->f68;
        p->f38 += p->f60;
        p->f60 += p->f6c;
        w = *(s16 *)(q + 0x1C) - 1;
        *(s16 *)(q + 0x1C) = w;
        if (w == 0) func_003266E0(p);
    }
}

typedef struct { u8 pad0[0x34]; f32 f34, f38; u8 pad1[0x5C - 0x3C]; f32 f5c, f60, f64, f68, f6c; u8 pad2[0x430 - 0x70]; f32 f430; } SD;
extern u8 D_004F1F45;
extern u8 D_004F1F46;
extern s8 func_00175700();
extern void func_001757E0();
extern void func_001E3710();
extern void func_0019D270();
void func_00227A10(SD *p) {
    u32 t;
    func_00175700(p);
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (p->f38 < p->f430) {
        t = ((u8 *)p)[6];
        ((u8 *)p)[6] = t + 1;
        ((u8 *)p)[0x20D] = 0;
        p->f34 = p->f64;
        p->f38 = p->f430;
        func_001E3710(p, 0x31);
        func_0019D270(p, 0);
        D_004F1F45 = 1;
        D_004F1F46 = 1;
        func_001757E0(p, 0x12, 1);
    }
}
