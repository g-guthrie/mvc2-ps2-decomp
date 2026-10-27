typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

typedef struct { u8 pad[5]; u8 f5; } S134;


extern s32 func_00189310();
extern u8 D_00453570[];

extern f32 D_004C9F54[2], D_004F1FF0[2], D_004F1F50[2];


extern void func_0016B0C0();
extern s32 func_00174170();


extern void func_00174A40();
void func_003645C0(u8 *p) {
    u8 *o;
    s16 v;
    s16 w = *(s16 *)(p + 0x1E);
    o = *(u8 **)(p + 0x14);
    *(s16 *)(p + 0x1E) = w + 200;
    *(V3 *)(p + 0x34) = *(V3 *)(o + 0x34);
    func_00174A40(p, *(s16 *)(p + 0x1E));
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        u32 t = p[5];
        p[5] = t + 1;
        *(s16 *)(p + 0x1C) = 6;
    }
}

typedef struct {
    u8 p0[0x34];
    f32 f34, f38, f3c;
    u8 p1[0x5C - 0x40];
    f32 f5c, f60, f64, f68, f6c;
    u8 p2[0x430 - 0x70];
    f32 f430;
} Obj;

extern s8 func_00175700();
extern void func_001757E0();
extern void func_00175C00();

extern void func_003DAA40();
extern s32 func_001E7F60(u8 *);
void func_003C4C40(u8 *p, u8 *q) {
    s8 r;
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38) + *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x3C) = *(f32 *)(q + 0x3C);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    *(s8 *)(p + 0x31) = -1;
    r = func_00175700(p);
    if (r < 0) {
        func_003DAA40(p);
        return;
    }
    if (*(s8 *)(p + 0x1B3) == 0) func_001E7F60(p);
}

extern void func_001843A0();
extern void func_00183920();
extern void func_001E3710();
void func_001F5EF0(u8 *p) {
    u32 v[3];
    s8 r = func_00175700(p);
    if (r < 0) {
        func_001843A0(p);
        return;
    }
    if (*(s8 *)(p + 0x150) != 0) {
        p[0x150] = 0;
        v[0] = 0x42855555;
        v[1] = 0x434DB6DB;
        func_00183920(p, v);
    }
    if (p[0x15B] != 0) {
        func_001E3710(p, 0x16);
        p[0x15B] = 0;
    }
}

extern void func_001830D0();
void func_00237FD0(u8 *p) {
    u32 v[3];
    u8 x = 2;
    p[0x40C] = x;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? x : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x150) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x150] = 0;
        p[0x404] = 0;
        p[0x405] = 0;
        v[0] = 0;
        v[1] = 0x42DEDB6D;
        func_001830D0(p, v, 1);
    }
}

extern void func_001266A0();
extern void func_0018C6E0(void *);
extern void func_0015D010();
void func_002E8250(u8 *p) {
    u32 v[3];
    func_001266A0(p, 5, 5);
    if (*(u16 *)(p + 0x20E) & 0x400) {
        *(s16 *)(p + 0x140) ^= 1;
        p[0x1E6] ^= 1;
    }
    func_0018C6E0(p);
    v[0] = 0xC2D55555;
    v[1] = 0x432B6DB6;
    func_0015D010(p, v);
    p[0x1B4] = 10;
    p[6] = 0;
    p[7] = 0;
    func_001757E0(p, 0xF, 1);
}

void func_001EC700(Obj *o) {
    u8 *p = (u8 *)o;
    o->f34 += o->f5c;
    o->f5c += o->f68;
    o->f38 += o->f60;
    o->f60 += o->f6c;
    if (o->f38 <= o->f430) {
        u32 t = p[6];
        p[6] = t + 1;
        o->f38 = o->f430;
        p[0x20D] = 0;
        func_001757E0(p, 0x16, 3);
        return;
    }
    func_00175700(p);
}

extern u8 D_00459C50[];
extern s32 func_0018A990();
extern void func_002CAFC0();
extern void func_00186A60();

extern void func_00183d50();
void func_00282790(Obj *o) {
    u8 *p = (u8 *)o;
    if (*(s8 *)(p + 0x1B2) != 0) {
        if (*(s16 *)(p + 0x1E) == 0) *(s16 *)(p + 0x1E) = 1;
    }
    func_00175700(p);
    if (o->f38 <= o->f430) {
        u32 t = p[7];
        p[7] = t + 1;
        p[0x210] = 0;
        p[0x224] = 0;
        p[0x20D] = 1;
        o->f38 = o->f430;
        *(u32 *)&o->f5c = 0;
        *(u32 *)&o->f60 = 0;
        *(u32 *)&o->f68 = 0;
        *(u32 *)&o->f6c = 0;
        func_00183d50(p);
        func_001757E0(p, 10, 4);
    }
}

extern void *func_00194100(u8 *);
extern void func_00194990();
void func_00194710(u8 *p, u8 *q) {
    u8 *a = *(u8 **)(q + 0x1DC);
    u8 *b = *(u8 **)(a + 0x1E0);
    if (*(s8 *)(a + 0x211) != 0 || b[5] == 2) {
        p[0x21] |= 0x80;
        p[5] = 3;
        func_00194990(p, q);
        return;
    }
    {
        u32 t = p[5];
        p[5] = t + 1;
    }
    if (func_00194100(p) == 0) {
        p[0x21] |= 0x80;
        p[5] = 3;
        func_00194990(p, q);
    }
}

extern void func_00175670();
void func_0019AAE0(Obj *o) {
    u8 *p = (u8 *)o;
    f32 z = 0.0f;
    f32 *a2 = (f32 *)(p + 0x5C);
    f32 *a3 = (f32 *)(p + 0x68);
    o->f34 += o->f5c;
    o->f5c += o->f68;
    o->f38 += o->f60;
    o->f60 += o->f6c;
    if (o->f60 <= z) {
        u32 t = p[5];
        p[5] = t + 1;
        *a2 = z;
        *a3 = z;
        *(u32 *)(p + 0x60) = 0xC0092492;
        *(u32 *)(p + 0x6C) = 0xBE892492;
        func_00175670(p);
        *(s16 *)(p + 0x1C) = 0;
    }
}

extern void func_003B3880();
extern void func_003B3870();
extern int func_00174470(const void *);


extern u8 func_001898E0();
extern s8 D_004F7FC8[];
typedef struct { u8 a; s8 b; } C189;
u8 func_00189830(u8 *a, u8 *b, C189 *c) {
    s8 v = c->b - 1;
    u32 t;
    c->b = v;
    if (v <= 0) {
        return c->a = 0;
    }
    t = *(u16 *)(b + 0xA);
    if (t == 0x800) {
        if (*(u16 *)(a + 0x35E) != t) return 0;
    } else {
        if ((*(u16 *)(a + 0x35E) & t) == 0) return 0;
    }
    c->a += 1;
    c->b = D_004F7FC8[a[2]] * 10 + 15;
    return func_001898E0();
}

typedef struct { u8 p0[0x34]; f32 f34; u8 p1[0x434 - 0x38]; s16 s434; } Q2B;


void func_0022EAA0(Obj *o) {
    u8 *p = (u8 *)o;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) >= 0) {
        o->f34 += o->f5c;
        o->f5c += o->f68;
        o->f38 += o->f60;
        o->f60 += o->f6c;
    }
    if (o->f38 < o->f430) {
        u32 t;
        o->f38 = o->f430;
        func_00183d50(p);
        t = p[7];
        p[7] = t + 1;
        func_001757E0(p, 0x12, 2);
    }
}

extern void func_0011D8F8();
extern void func_0018EA00();
extern void func_0018E810();
extern void func_001E3A10();
extern void func_00158C70();
void func_0018DDD0(Obj *o, u8 *q) {
    u8 *p = (u8 *)o;
    s8 t;
    p[0x247] = 0x11;
    func_0011D8F8(p + 0x370, 0, 8);
    p[0x24A] = 0x78;
    t = *(s8 *)(p + 0x246);
    p[0x24D] = t;
    if (t == 0) p[0x24D] = 0x10;
    func_0018EA00(p, q);
    func_0018E810(p, q);
    o->f38 = o->f430;
    p[0x20D] = 3;
    func_001757E0(p, 0xD, 0x1A);
    *(s16 *)(p + 0x1C) = 4;
    func_001E3A10(p);
    func_00158C70(p + 0x34, p[2]);
}

extern u8 *func_003DA750();
extern void func_00383C90();
void func_00383BF0(u8 *p, u8 b, u8 n) {
    s32 i;
    u8 *o;
    for (i = 0; i < n; i++) {
        if ((o = func_003DA750(0, 1, 0)) == 0) break;
        *(void **)(o + 0x10) = func_00383C90;
        *(s32 *)(o + 0x18) = *(s32 *)(p + 0x18);
        *(u8 **)(o + 0x14) = p;
        o[0x20] = b;
        o[0x21] = i;
        *(s16 *)(o + 0x26) = 0x1B00;
    }
}

extern s16 D_004B5712[], D_004B5710[];
typedef struct {
    u8 p0[0x34];
    f32 f34, f38;
    u8 p1[0x140 - 0x3C];
    s16 s140;
} B3D;


typedef struct N52 { u8 p0[0xC]; struct N52 *next; } N52;
extern N52 *D_004D36AC;
extern u8 D_00444800[];
extern void func_00123090();
extern void func_00151A20();
extern void func_001520E0();
extern void func_00417AE0();
extern void func_00417FE0();
extern void func_00153AB0();
