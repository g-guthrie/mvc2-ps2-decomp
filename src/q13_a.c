typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00174170();
extern void func_001757E0(void *p, s32 a, s32 b);
extern u8 D_004C1730[2][4];
extern void func_003DAA40(void);
extern void func_00174910(void *p, s32 a);
extern s32 func_00175700();
extern s32 func_00174240(void *p);
extern void func_001E7F60(void *p);
extern u8 *func_003DA750();
extern void func_00183D50(u8 *);
extern void func_0019F4F0(void);
extern void func_001843A0();
extern void func_00183920(void *p, f32 *v);
extern void func_001E3710(void *p, s32 a);
extern void func_001E3210(void *p, s32 a);
typedef struct { u8 p0[5]; u8 b5; u8 p6[0x16]; s16 h1C; u8 p1e[0x1A]; f32 f38; u8 p3c[0x24]; f32 f60; u8 p64[8]; f32 f6c; u8 p70[0x18]; s8 b88; } S_0034A4B0;
extern void func_00199FF0();
typedef struct { u8 p0[3]; u8 b3; } Q;
extern u8 *D_004C2840;
typedef struct { u8 p0[7]; u8 b7; u8 p8[0x2C]; f32 f34; f32 f38; u8 p3c[0x20]; f32 f5c; f32 f60; u8 p64[4]; f32 f68; f32 f6c; u8 p70[0x177]; s8 b1e7; } S_001AC170;
extern void func_003B9500(void);
extern s32 func_0018AB10(void *p);
extern void func_00185490(void *p);
extern void func_00183D10(void *p);
extern u8 *D_004C2794;
extern void func_0011D8F8(void *p, s32 a, s32 b);
extern void func_0018EA00(void *p, void *q);
extern void func_0018E810(void *p, void *q);
extern void func_0018E790(void *p);
extern void func_0018E6C0(void *p);
typedef struct { u8 p0[0x34]; f32 f34; f32 f38; } S_001C64B0;
extern void func_0019B110(void *p, s32 a);
extern void func_001266A0(void *p, s32 a, s32 b);
extern void func_001741D0(void *p, f32 *v);
typedef struct { u8 p0[0x34]; u8 p34[0x20]; f32 f54; u8 p58[0xF5]; u8 b14d; } S_001746D0;
extern void func_003B1A70();
extern void (*D_004C1F98[2])();
extern s32 D_00473FA0[];
extern s32 D_00473FA4[];
extern void func_003B5530(void *p, s32 a);
typedef struct { u8 p0[5]; u8 b5; u8 p6[0x1D]; u8 b23; u8 p24[0x38]; f32 f5c; u8 p60[8]; f32 f68; u8 p6c[0xD4]; s16 h140; } S_003B5140;
extern s32 func_001E1FF0(s16 a);
extern void func_004020D8(s32 a, s16 b);
extern s32 D_004C2B50;
extern u8 D_004C2726;
extern f32 D_004CD168[];
extern s32 D_004CD158[];
typedef struct { u8 p0[6]; u8 b6; u8 p7[0x2D]; f32 f34; f32 f38; u8 p3c[0x20]; f32 f5c; f32 f60; u8 p64[4]; f32 f68; f32 f6c; u8 p70[0xE1]; s8 b151; } S_00258500;

void func_0031B1A0(u8 *p) {
    s8 i = p[0x1E7];
    s32 r;
    if (i < 0) i = 0;
    r = func_00174170() & 3;
    func_001757E0(p, 0, D_004C1730[i][r]);
}

void func_0019F470(u8 *p, s32 x, s32 y) {
    u8 *o;
    if ((o = func_003DA750(p, 3, 2)) != 0) {
        *(void**)(o + 0x10) = (void*)func_0019F4F0;
        *(s32*)(o + 0x18) = *(s32*)(p + 0x18);
        *(u8**)(o + 0x14) = p;
        o[1] = p[1];
        o[0x20] = x;
        o[0x21] = y;
        *(s16*)(o + 0x26) = 0xB01;
        o[0x13C] = 0;
    }
}

void func_00221D20(u8 *p) {
    u32 v[4];
    s8 r = func_00175700(p);
    if (r < 0) {
        func_001843A0(p);
        return;
    }
    if (*(s8*)(p + 0x151) != 0) {
        p[0x151] = 0;
        v[1] = 0x432B6DB6;
        v[0] = 0;
        func_00183920(p, (f32*)v);
    }
    if (*(s8*)(p + 0x150) != 0) {
        p[0x150] = 0;
        func_001E3710(p, 0x16);
        func_001E3210(p, 0x20);
    }
}

void func_0034A4B0(S_0034A4B0 *p) {
    s16 v;
    func_00175700(p);
    if (p->b88 != 0 || *(s8*)((u8*)p + 0x1B3) != 0 || (v = p->h1C - 1, p->h1C = v, v == 0)) {
        u32 t = p->b5;
        p->b5 = t + 1;
        func_001757E0(p, 0x16, 0x2E);
    } else {
        p->f38 += p->f60;
        p->f60 += p->f6c;
    }
}

void func_00199F50(u8 *p) {
    u8 *q = *(u8**)(p + 0x18);
    if (q[3] == 0) {
        if (*(s8*)(q + 0x1B3) != 0) {
            func_00199FF0();
            return;
        }
        if (*(s8*)(q + 0x1B4) != 0) {
            p[0x13C] = 1;
            return;
        }
    }
    {
        s16 v = *(s16*)(p + 0x1C) - 1;
        *(s16*)(p + 0x1C) = v;
        if (v == 0) {
            func_00199FF0();
            return;
        }
    }
    p[0x13C] = 1;
    if (p[0x21] != 0) {
        p[0x13C] = *(s8*)(D_004C2840 + 0x1C) & 1;
    }
}

void func_001AC170(S_001AC170 *p, S_001AC170 *q) {
    f32 two = 2.0f;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (q->f60 <= two) {
        u32 t = p->b7;
        p->b7 = t + 1;
        func_001757E0(p, 0x17, (q->b1e7 + 7) & 0xFF);
    }
    func_00175700(p);
}

void func_003B93A0(u8 *p) {
    s16 i;
    u8 *o;
    for (i = 0; i < 4; i++) {
        if ((o = func_003DA750(0, 1, 1)) != 0) {
            *(void**)(o + 0x10) = (void*)func_003B9500;
            *(f32*)(o + 0x34) = *(f32*)(p + 0x34);
            *(f32*)(o + 0x38) = *(f32*)(p + 0x38);
            *(u8**)(o + 0x18) = p;
            *(u8**)(o + 0x14) = p;
            o[1] = p[1];
            *(s16*)(o + 0x26) = 0x3503;
            o[0x20] = 0;
            o[0x21] = i;
        }
    }
}

void func_00279D80(u8 *p, s8 *q) {
    s16 v;
    p[0x33C] = 5;
    func_00175700(p);
    if (*q >= 0) {
        if (func_0018AB10(p) != 0) {
            *q = *q - 1;
            *(s16*)(p + 0x1C) = *(s16*)(p + 0x1C) + 1;
        }
    }
    v = *(s16*)(p + 0x1C) - 1;
    *(s16*)(p + 0x1C) = v;
    if (v <= 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 0x15, 4);
    }
}

void func_0022AFB0(u8 *p) {
    u32 t = p[6];
    s16 *e;
    p[6] = t + 1;
    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 0x10;
    }
    func_00185490(p);
    func_00183D10(p);
    *(f32*)(p + 0x38) = *(f32*)(p + 0x430);
    p[0x20D] = 0;
    p[0x1B5] = 0x30;
    p[0x1B2] = *(u16*)(p + 0x1C0) = 0;
    *(s32*)(p + 0x1D8) = 0;
    e = (s16*)((p[2] << 1) + (u32)D_004C2794);
    e[0x3E] = e[0x3E] + 1;
    func_001757E0(p, 0x16, 0xF);
}

void func_0018E0B0(u8 *p, u8 *q) {
    s32 v;
    p[0x247] = 7;
    func_0011D8F8(p + 0x370, 0, 8);
    p[0x24A] = 0x78;
    v = *(s8*)(p + 0x246);
    p[0x24D] = v;
    if (v == 0) p[0x24D] = 0x10;
    func_0018EA00(p, q);
    func_0018E810(p, q);
    if (p[0x20D] == 2) {
        func_0018E790(p);
    } else {
        *(s16*)(p + 0x1C) = 2;
        p[0x20D] = 2;
        func_0018E6C0(p);
    }
}

void func_001C64B0(u8 *p, u8 *q) {
    u8 *r = q + 0x2B8;
    if (q[0x2C3] == 0) {
        p[7] = 5;
        p[0] = 1;
        p[0x13C] = 1;
        *(s16*)(p + 0x1C) = 0x20;
        func_001757E0(p, 0x19, 0x11);
        return;
    }
    if (r[0xA] == 0) {
        u32 t = p[7];
        p[7] = t + 1;
        p[0] = 0;
        p[0x13C] = 0;
    } else {
        S_001C64B0 *a = (S_001C64B0*)p, *b = (S_001C64B0*)q;
        a->f34 += (b->f34 - a->f34) / 8.0f;
        a->f38 += (b->f38 - a->f38) / 8.0f;
    }
}

void func_003207F0(u8 *p) {
    u32 v[4];
    s8 r = func_00175700(p);
    s32 f;
    if (r < 0) {
        func_001843A0(p);
        return;
    }
    f = *(s8*)(p + 0x151);
    if (f & 1) {
        *(s8*)(p + 0x151) = f ^ 1;
        func_001E3210(p, 0x20);
        func_0019B110(p, 1);
    }
    f = *(s8*)(p + 0x151);
    if (f & 2) {
        *(s8*)(p + 0x151) = f ^ 2;
        v[0] = 0xC2D55555;
        v[1] = 0x42CDB6DB;
        func_00183920(p, (f32*)v);
    }
}

void func_00200F70(u8 *p) {
    s8 r = func_00175700(p);
    if (r < 0) {
        u32 t;
        func_001266A0(p, 0, 0);
        t = p[7];
        p[7] = t + 1;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        *(u32*)(p + 0x5C) = 0;
        *(u32*)(p + 0x68) = 0;
        *(u32*)(p + 0x5C) = 0x40555555;
        *(u32*)(p + 0x60) = 0xC0892492;
        *(u32*)(p + 0x6C) = 0xBF892492;
        if (*(s16*)(p + 0x140) != 0) {
            *(f32*)(p + 0x5C) = -*(f32*)(p + 0x5C);
        }
        func_001757E0(p, 0x16, 0x13);
    }
}

s32 func_001746D0(S_001746D0 *p) {
    f32 v[2];
    u32 x;
    f32 sum;
    func_001741D0((u8*)p + 0x34, v);
    x = p->b14d;
    sum = v[1] + (34.285713f + 2.142857f * (f32)x * p->f54);
    return !(sum < 0.0f);
}

void func_003B1850(u8 *p, u8 *q) {
    u32 t;
    *(s8*)(p + 0x24) = *(s8*)(q + 0x24) + *(s8*)(p + 0x31);
    if (*(s8*)(p + 0x24) > 7) *(s8*)(p + 0x24) = 7;
    if (*(s8*)(p + 0x24) < 0) *(s8*)(p + 0x24) = 0;
    if (q[0x169] != 0x15) {
        t = p[4];
        p[4] = t + 1;
        func_003B1A70(p);
        return;
    }
    if (q[5] != 0) {
        t = p[4];
        p[4] = t + 1;
        func_003B1A70(p);
    } else {
        D_004C1F98[p[5]]();
    }
}

void func_003B5140(S_003B5140 *p, s32 a1) {
    s16 h = *(s16*)((u8*)p + 0x1C);
    *(s16*)((u8*)p + 0x1C) = h - 1;
    if (h == 0) {
        p->f5c = 1.6666666f * (f32)D_00473FA0[p->b23 * 2] / 65536.0f;
        p->f68 = 1.6666666f * (f32)D_00473FA4[p->b23 * 2] / 65536.0f;
        if (p->h140 != 0) {
            p->f5c = -p->f5c;
            p->f68 = -p->f68;
        }
        { u32 t = p->b5; p->b5 = t + 1; }
    }
    func_003B5530(p, a1);
}

void func_001E41C0(u8 a) {
    u8 x = a;
    u8 c;
    if (x > 0x7F) a = 0x7F;
    c = a;
    func_004020D8(D_004C2B50, func_001E1FF0(c & 0x7F));
    D_004C2726 = a;
    D_004CD168[0] = (f32)a;
    D_004CD158[0] = 0;
}

void func_00258500(S_00258500 *p) {
    if (p->b151 != 0) {
        u32 t = p->b6;
        p->b6 = t + 1;
        func_00183D50((u8 *)p);
        p->b151 = 0;
    }
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    func_00175700(p);
}

void func_002CF2A0(u8 *p) {
    u32 t = p[6];
    s16 *e;
    p[6] = t + 1;
    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 0x10;
    }
    func_00185490(p);
    func_00183D10(p);
    *(f32*)(p + 0x38) = *(f32*)(p + 0x430);
    p[0x20D] = 0;
    p[0x1B5] = 0x4C;
    p[0x1B2] = *(u16*)(p + 0x1C0) = 0;
    *(s32*)(p + 0x1D8) = 0;
    e = (s16*)((p[2] << 1) + (u32)D_004C2794);
    e[0x3E] = e[0x3E] + 1;
    func_001757E0(p, 0x16, 1);
}
