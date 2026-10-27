typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u8 D_0045BD30[];

s32 func_002F6BF0(u8 *p) {
    extern s32 func_00189310(u8 *, u8 *, u8 *);
    extern void func_0018A990(u8 *, u8 *);
    extern void func_00186A60(u8 *, s32);
    u8 *q;
    s32 i;
    s32 n;

    q = p + 0x2B8;
    if (func_00189310(p, D_0045BD30, p + 0x388) == 0) return 0;
    n = 0;
    i = 0;
    do {
        if (q[i] == 0) n++;
        i++;
    } while (i < 6);
    if (n == 6) return 0;
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            if (*(s8 *)(p + 0x1E8) != 0) return 0;
            *(s8 *)(p + 0x1E8) = *(s8 *)(p + 0x1E8) + 1;
        }
    }
    func_0018A990(p, p + 0x388);
    {
        u32 t = p[0x1B7];
        p[0x1B7] = t + ((*(s8 *)(p + 0x212) << 1) & 0xFF);
    }
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 1;
    func_00186A60(p, 0x15);
    return 1;
}

typedef struct {
    u8 p0[0x34]; f32 f34; f32 f38; u8 p2[0x5C - 0x3C];
    f32 f5c; f32 f60; u8 p3[4]; f32 f68; f32 f6c;
    u8 p4[0x151 - 0x70]; s8 b151; u8 p5[0x20D - 0x152]; u8 b20D;
    u8 p6[0x430 - 0x20E]; f32 f430;
} HB2;

void func_00235F20(HB2 *p) {
    extern s8 func_00175700();
    extern void func_001843A0(HB2 *);
    extern void func_00184540(HB2 *);
    extern void func_001865B0(HB2 *);
    f32 k;

    if (p->b20D != 2) {
        if (func_00175700(p) >= 0) return;
        func_001843A0(p);
        return;
    }
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (p->f38 < p->f430) {
        p->f38 = p->f430;
        p->b20D = 0;
        func_001865B0(p);
        return;
    }
    if (func_00175700(p) < 0) func_00184540(p);
    if ((p->b151 & 1) == 0) return;
    p->b151 = 0;
    k = 0.8035714030265808f;
    p->f60 = p->f60 + k;
    *(u32 *)&p->f6c = 0xBF4DB6DB;
}

typedef struct {
    u8 p0[7]; u8 b7; u8 p1[0x5C - 8]; f32 f5c; f32 f60; u8 p2[4]; f32 f68; f32 f6c;
    u8 p3[0x20B - 0x70]; u8 b20B;
} HB3;

void func_001F16C0(HB3 *p) {
    extern s8 func_00175700();
    extern void func_001757E0(HB3 *, s32, s32);
    extern u8 *func_001E8070(u8 *);
    extern void func_001E3210(HB3 *, s32);
    extern void func_001266A0(HB3 *, s32, s32);
    extern void func_0015D010(HB3 *, u32 *);
    extern void func_00185770(u8 *, u8 *);
    u8 *u;
    u32 v[3];

    if (func_00175700(p) < 0) {
        p->b7 = 9;
        p->f5c = p->f5c / 16.0f;
        p->f68 = 0.0f;
        p->f60 = p->f60 / 8.0f;
        p->f6c = p->f6c / 64.0f;
        func_001757E0(p, 15, 16);
        return;
    }
    if ((u = func_001E8070((u8 *)p)) != 0) {
        func_001E3210(p, 5);
        {
            u32 t = p->b7;
            p->b7 = t + 1;
        }
        func_001266A0(p, 5, 5);
        v[0] = 0xC312AAAA;
        v[1] = 0x432B6DB6;
        func_0015D010(p, v);
        func_001757E0(p, 15, 17);
        p->b20B = 0xC4;
        func_00185770((u8 *)p, u);
    }
}

typedef struct { f32 x, y, z; } HV3;
extern HV3 D_00459430[];
extern HV3 D_00459434[];
extern HV3 D_00459438[];

typedef struct {
    u8 p0[6]; u8 b6; u8 p1[0x5C - 7]; f32 f5c; f32 f60; u8 p2[4]; f32 f68; f32 f6c;
    u8 p3[0x151 - 0x70]; s8 b151; u8 p4[0x1B2 - 0x152]; s8 b1B2;
    u8 p5[0x1B7 - 0x1B3]; u8 b1B7; u8 p6[0x1E6 - 0x1B8]; u8 b1E6;
} HA1;

void func_002BA1C0(HA1 *p) {
    extern void func_002BA590(HA1 *);
    extern void func_00186A20(HA1 *);
    extern void func_00175700();
    u32 t;

    if (p->b1B2 != 0) {
        t = p->b6;
        p->b6 = t + 1;
        func_002BA590(p);
        return;
    }
    func_00175700();
    if (p->b151 != 0) {
        t = p->b6;
        p->b6 = t + 1;
        func_00186A20(p);
        p->f5c = (p->b1E6 != 0) ? D_00459430[p->b1B7].x : -D_00459430[p->b1B7].x;
        p->f68 = (p->b1E6 != 0) ? D_00459434[p->b1B7].x : -D_00459434[p->b1B7].x;
        p->f60 = D_00459438[p->b1B7].x;
        *(u32 *)&p->f6c = 0xBFAB6DB6;
    }
}

typedef struct { u8 p0[0x34]; f32 f34; } HX1;
typedef struct {
    u8 p0[2]; u8 b2; u8 p1[0x20 - 3]; u8 b20; u8 p2[0x34 - 0x21]; f32 f34;
    u8 p3[0x5C - 0x38]; u32 w5C; u8 p4[0x140 - 0x60]; u16 h140;
    u8 p5[0x1B2 - 0x142]; u8 b1B2; u8 p6[0x1B5 - 0x1B3]; u8 b1B5;
    u8 p7[0x1C0 - 0x1B6]; u16 h1C0; u8 p8[0x1D8 - 0x1C2]; u32 w1D8;
    u8 p9[0x220 - 0x1DC]; HX1 *q220; u8 pa[0x2D8 - 0x224]; s32 w2D8;
    u8 pb[0x354 - 0x2DC]; u16 h354; u8 pc[0x362 - 0x356]; u16 h362;
    u8 pd[0x366 - 0x364]; u16 h366; u8 pe[0x539 - 0x368]; s8 b539;
} HX;

typedef struct { u8 p0[0x7C]; s16 h7C[0x40]; } HGD2;
extern HGD2 *D_004C2794;

s32 func_003246B0(HX *p) {
    extern void func_00324A00(HX *);
    extern void func_001757E0(HX *, s32, s32);
    u32 s0;
    HX1 *s1;
    u32 v3;
    u32 t;
    f32 d;

    if (p->w2D8 > 0) {
        s0 = p->h354;
        s1 = p->q220;
        v3 = p->h362 | p->h366;
        if (p->b539 != 0) {
            d = s1->f34 - p->f34;
            v3 = 0;
            if (d > 0.0f) {
                s0 = 0x400;
            } else {
                s0 = 0x800;
                d = -d;
            }
            if (d <= 266.666656f) v3 = 0x200;
        }
        if ((v3 & 0x360) != 0) {
            p->h366 = 0;
            p->b20 = 2;
            p->w2D8 = p->w2D8 - 0x1E;
            p->w5C = 0;
            func_00324A00(p);
            v3 = (p->f34 < s1->f34) ? 1 : 0;
            if (s0 & 0x800) v3 = 0;
            if (s0 & 0x400) v3 = 1;
            p->h140 = v3;
            p->b1B5 = 0x7D;
            p->b1B2 = *(u16 *)&p->h1C0 = 0;
            p->w1D8 = 0;
            D_004C2794->h7C[p->b2] += 1;
            t = p->h1C0;
            p->h1C0 = t | 0x800;
            func_001757E0(p, 0x16, 0xA);
            return 1;
        }
    }
    return 0;
}
