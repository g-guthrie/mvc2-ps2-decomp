/* v2_a: mw -O3 -sdatathreshold 0 */
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef unsigned long long u64;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
extern int func_00175700();
extern void func_00175C00();
extern void func_001E3210();
extern void func_001757E0();
typedef struct { u8 pad[0x2B8]; s8 b[8]; } S_002C78B0;
void func_002C78B0(u8 *p) {
    s8 *q;
    p[0x33A] = 0xFF;
    q = ((S_002C78B0 *)p)->b;
    if (*(s8 *)(p + 0x161) != 0) {
        q[4] = 1;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        func_00175C00(p, 0);
    }
    if ((s8)func_00175700(p) < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        *(s16 *)(p + 0x1E) = 16;
        *(u32 *)(p + 0x60) = 0x40092492;
        func_001E3210(p, 15);
        func_001757E0(p, 0x13, 4);
    }
}

typedef struct { u8 pad[0x34]; f32 f34, f38; u8 pad2[0x1C]; f32 f58, f5c, f60, f64, f68, f6c; } S_0019E8F0;
extern int func_00175700();
extern void func_001757E0();
void func_0019E8F0(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    s16 v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        u32 t = p[5];
        p[5] = t + 1;
        ((S_0019E8F0 *)p)->f34 = ((S_0019E8F0 *)q)->f34;
        ((S_0019E8F0 *)p)->f38 = ((S_0019E8F0 *)q)->f38;
        *(s16 *)(p + 0x1C) = 0x300;
        func_001757E0(p, 0x13, 0xB);
    }
    func_00175700(p);
    ((S_0019E8F0 *)p)->f34 += ((S_0019E8F0 *)p)->f5c;
    ((S_0019E8F0 *)p)->f5c += ((S_0019E8F0 *)p)->f68;
    ((S_0019E8F0 *)p)->f38 += ((S_0019E8F0 *)p)->f60;
    ((S_0019E8F0 *)p)->f60 += ((S_0019E8F0 *)p)->f6c;
}

typedef struct { u8 pad[0x34]; f32 f34, f38; u8 pad2[0x1C]; f32 f58, f5c, f60, f64, f68, f6c; } S_002C3BE0;
extern int func_00175700();
void func_002C3BE0(u8 *p) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x1FE] = 1;
    p[0x201] = 2;
    p[0x209] = 2;
    func_00175700(p);
    ((S_002C3BE0 *)p)->f34 += ((S_002C3BE0 *)p)->f5c;
    ((S_002C3BE0 *)p)->f5c += ((S_002C3BE0 *)p)->f68;
    ((S_002C3BE0 *)p)->f38 += ((S_002C3BE0 *)p)->f60;
    ((S_002C3BE0 *)p)->f60 += ((S_002C3BE0 *)p)->f6c;
    {
        s16 v = *(s16 *)(p + 0x1E) - 1;
        *(s16 *)(p + 0x1E) = v;
        if (v == 0) {
            u32 t = p[6];
            p[6] = t + 1;
            *(u32 *)(p + 0x6C) = 0xC04DB6DB;
        }
    }
}

extern s16 D_0044DC90[];
extern void func_001CBE10();
extern int func_00175670();
extern void func_001754A0();
void func_001CC610(u8 *p) {
    s16 v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        s16 w;
        func_001CBE10(p, 3, p[0x1E]);
        *(volatile s16 *)(p + 0x1E) += 1;
        w = D_0044DC90[*(volatile s16 *)(p + 0x1E)];
        *(s16 *)(p + 0x1C) = w;
        if (w < 0) {
            *(volatile s16 *)(p + 0x1E) = 0;
            *(s16 *)(p + 0x1C) = D_0044DC90[*(volatile s16 *)(p + 0x1E)];
        }
    }
    if ((s8)func_00175670(p) < 0) {
        u32 t = p[5];
        p[5] = t + 1;
        func_001754A0(p, 0x1B, 9);
    }
}

extern int func_00175700();
extern void func_001757E0();
extern void func_0019DF50();
extern void func_003594D0();
extern void func_0035ACA0();
extern void func_0035A7B0();
void func_003595B0(u8 *p, u8 *q) {
    if ((s8)func_00175700(p) < 0) {
        u32 t = p[5];
        p[5] = t + 1;
        *(s16 *)(p + 0x1C) = 0x1E0;
        p[0x169] = 0x17;
        p[0x168] = 0x18;
        func_001757E0(p, p[0x169], p[0x168]);
        func_0019DF50(p, 5, 0);
        func_0019DF50(p, 1, 0);
        func_003594D0(p, q);
    } else {
        func_0035ACA0(p, q);
        func_0035A7B0(p, q);
    }
}

static s32 func_00291800(u8 *a) {
    u8 f = a[0x1E6];
    u8 *o = *(u8 **)(a + 0x220);
    if (!f) {
        if (*(f32 *)(a + 0x34) < *(f32 *)(o + 0x34)) return 1;
    }
    if (f) {
        if (*(f32 *)(a + 0x34) <= *(f32 *)(o + 0x34)) return 0;
        return 1;
    }
    return 0;
}
extern s32 func_00175700();
extern void func_001757E0();
extern void func_00292420();
void func_002918A0(u8 *p, u8 *q) {
    u8 t = q[0x18];
    if (t == 0) {
        q[0x18] = t + 1;
        { u32 e = p[0x1E6]; p[0x1E6] = e ^ 1; }
        *(s16 *)(p + 0x140) = p[0x1E6];
        q[0x19] = 1;
        func_001757E0(p, 0x16, 0xA);
    }
    if (func_00291800(p)) {
        q[0x18] = 0;
        func_002918A0(p, q);
        return;
    }
    if ((s8)func_00175700(p) < 0) {
        p[7] = 0;
        q[0x18] = 0;
        q[0x19] = 0;
        func_001757E0(p, 0x16, 8);
    }
    func_00292420(p);
}

typedef struct { u8 pad[0x34]; f32 f34, f38; u8 pad2[0x1C]; f32 f58, f5c, f60, f64, f68, f6c; } S_002A3F80;
extern int func_00175700();
extern void func_001843A0();
extern void func_00183DF0();
void func_002A3F80(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        *(int *)(p + 0x5C) = 0;
        *(int *)(p + 0x60) = 0;
        *(int *)(p + 0x68) = 0;
        *(int *)(p + 0x6C) = 0;
        func_001843A0(p);
        return;
    }
    func_00183DF0(p, 3);
    if (*(s8 *)(p + 0x151) != 0) {
        f32 a = *(volatile f32 *)(p + 0x5C);
        f32 z = 0.0f;
        if (a * *(volatile f32 *)(p + 0x68) < z) {
            ((S_002A3F80 *)p)->f34 += a;
        }
        ((S_002A3F80 *)p)->f5c += ((S_002A3F80 *)p)->f68;
        ((S_002A3F80 *)p)->f38 += ((S_002A3F80 *)p)->f60;
        ((S_002A3F80 *)p)->f60 += ((S_002A3F80 *)p)->f6c;
    }
}

extern int func_00184B30();
extern int func_00184720();
extern int func_00187D70();
extern int func_001884C0();
extern int func_00175700();
extern void func_00186CE0();
extern void func_00159A40();
extern void func_001757E0();
void func_0017B500(u8 *p) {
    if (func_00184B30(p)) return;
    if (func_00184720(p)) return;
    if (func_00187D70(p)) {
        return;
    }
    if (func_001884C0(p)) {
        func_00186CE0(p, 0x13);
        func_00159A40(p + 0x34, 0);
        return;
    }
    if ((s8)func_00175700(p) < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x168] = (p[0x20D] == 1) ? 5 : 1;
        func_001757E0(p, 5, p[0x168]);
    }
}

typedef struct { u8 pad[0x34]; f32 f34, f38; u8 pad2[0x1C]; f32 f58, f5c, f60, f64, f68, f6c; u8 pad3[0x3C0]; f32 f430; } S_00268990;
extern void func_00183D50();
extern void func_001843A0();
void func_00268990(S_00268990 *p) {
    int *z5c, *z60, *z68, *z6c;
    z6c = (int *)&p->f6c;
    z68 = (int *)&p->f68;
    z60 = (int *)&p->f60;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    z5c = (int *)&p->f5c;
    if (p->f38 <= p->f430) {
        p->f38 = p->f430;
        ((u8 *)p)[0x20D] = 0;
        func_00183D50(p);
        *z5c = 0;
        *z60 = 0;
        *z68 = 0;
        *z6c = 0;
        func_001843A0(p);
    }
}

typedef struct { u8 pad[0x34]; f32 f34, f38; u8 pad2[0x1C]; f32 f58, f5c, f60, f64, f68, f6c; } S_0022BE90;
extern int func_00175700();
extern void func_00184540();
extern void func_00126400();
void func_0022BE90(u8 *p) {
    ((S_0022BE90 *)p)->f34 += ((S_0022BE90 *)p)->f5c;
    ((S_0022BE90 *)p)->f5c += ((S_0022BE90 *)p)->f68;
    ((S_0022BE90 *)p)->f38 += ((S_0022BE90 *)p)->f60;
    ((S_0022BE90 *)p)->f60 += ((S_0022BE90 *)p)->f6c;
    if ((s8)func_00175700(p) < 0) {
        func_00184540(p);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        u8 *q;
        int e;
        p[0x151] = 0;
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x20A] = 1;
        q[0x20D] = 2;
        q[0x1B5] = 0x22;
        e = *(s8 *)(p + 0x1E6) ^ 1;
        q[0x1E6] = e;
        *(s16 *)(q + 0x140) = (u8)e;
        func_00126400(1, q);
    }
}

extern void func_00186A60();
extern void func_0018F630();
void func_0018F550(u8 *p, int b, int c) {
    int x;
    int y;
    p[5] = 3;
    p[7] = 0;
    p[6] = 0;
    p[0x24C] = 0;
    p[0x13C] = 1;
    *(int *)(p + 0x48) = 0;
    *(V3 *)(p + 0x50) = *(V3 *)(p + 0x298);
    *(u32 *)(p + 0x118) = 0x3F800000;
    func_00186A60(p, 0x20);
    p[0x247] = 2;
    x = (u8)c;
    p[0x242] = x % 32;
    y = (u8)b;
    p[0x243] = y % 16;
    p[0x248] = 1;
    func_0018F630(p, b);
}

