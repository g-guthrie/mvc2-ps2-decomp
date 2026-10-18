typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 p0[6]; u8 b6; u8 p7[0x140-7]; s16 h140; } PCo;
typedef struct { u8 p0[5]; u8 b5; u8 p6[0x18-6]; PCo *o; s16 h1c; u8 p1e[0x38-0x1E]; f32 f38; u8 p3c[0x5C-0x3C]; f32 f5c; f32 f60; u8 p64[4]; f32 f68; f32 f6c; } PC;
void func_00370810(PC *p) {
    extern void func_00175700(PC *);
    extern void func_001757E0(PC *, s32, s32);
    f32 v;
    if (p->o->b6 == 8) func_00175700(p);
    if (p->o->b6 == 12) {
        { u32 t = p->b5; p->b5 = t + 1; }
        if (p->o->h140 != 0) v = 13.333333015441895f; else v = -13.333333015441895f;
        p->f5c = v;
        p->f68 = 0;
        p->f60 = 6.4285712242126465f;
        p->f6c = 2.0089285373687744f;
        p->h1c = 30;
        p->f38 = 51.42856979370117f;
        func_001757E0(p, 0x17, 0x2E);
    }
}
typedef struct { u8 p0[0x34]; f32 f34; u8 p38[0x151-0x38]; s8 b151; u8 p152[0x1E6-0x152]; u8 b1e6; u8 p1e7[0x1FC-0x1E7]; u8 b1fc; } PI;
void func_00209690(PI *p) {
    extern s8 func_00175700(PI *);
    extern void func_001843A0(PI *);
    f32 d, c;
    f32 z = 0.0f;
    switch (p->b1fc) {
    case 2:
        if (func_00175700(p) < 0) {
            func_001843A0(p);
        } else {
            d = p->b151;
            if (d != z) {
                p->b151 = 0;
                if (p->b1e6 != 0) c = 1.6666666269302368f; else c = -1.6666666269302368f;
                d = d * c;
                p->f34 += d;
            }
        }
        break;
    case 0:
    case 1:
        if (func_00175700(p) < 0) func_001843A0(p);
        break;
    default:
        break;
    }
}
typedef struct { u8 p0[7]; u8 b7; u8 p8[0x5C-8]; f32 f5c; f32 f60; u8 p64[4]; f32 f68; f32 f6c; u8 p70[0x140-0x70]; s16 h140; u8 p142[0x151-0x142]; s8 b151; u8 p152[0x2B8-0x152]; u8 *w2b8; } PO;
typedef struct { u8 p0[0x140]; s16 h140; u8 p142[0x1B5-0x142]; u8 b1b5; u8 p1b6[0x1C8-0x1B6]; PO *w1c8; u8 p1cc[0x20A-0x1CC]; u8 b20a; u8 p20b[2]; u8 b20d; } PP;
void func_00201A80(PO *p) {
    extern s8 func_00175700(PO *);
    extern void func_001757E0(PO *, s32, s32);
    extern void func_00198100(PO *, s32);
    extern void func_00190D50(PP *, PO *);
    extern void func_00200990(PO *);
    PP *o;
    PP **pp;
    pp = (PP **)((u8 *)p + 0x2B8);
    if (func_00175700(p) < 0) {
        u32 t;
        *(u8 *)((u8 *)p + 0x40D) = 0;
        *(u8 *)((u8 *)p + 0x40C) = 0;
        *(u8 *)((u8 *)p + 0x33B) = 0;
        *(u8 *)((u8 *)p + 0x33C) = 0;
        t = p->b7;
        p->b7 = t + 1;
        p->f5c = 3.3333332538604736f;
        p->f68 = 0;
        p->f60 = -4.285714149475098f;
        p->f6c = -1.0714285373687744f;
        if (p->h140 != 0) p->f5c = -p->f5c;
        func_001757E0(p, 0x16, 0x13);
        return;
    }
    if (p->b151 != 0) {
        p->b151 = 0;
        func_00198100(p, 2);
        o = *pp;
        o->w1c8 = p;
        o->h140 = p->h140;
        o->b20a = 1;
        o->b20d = 2;
        o->b1b5 = 0x44;
        func_00190D50(o, p);
        func_00190D50(o, p);
        func_00200990(p);
    }
}
typedef struct { u8 p0[2]; u8 b2; u8 p3[3]; u8 b6; u8 p7[0x34-7]; f32 f34; f32 f38; u8 p3c[0x5C-0x3C]; f32 f5c; f32 f60; u8 p64[4]; f32 f68; f32 f6c; u8 p70[0x1E6-0x70]; u8 b1e6; u8 b1e7; u8 p1e8[0x1EE-0x1E8]; u8 b1ee; u8 p1ef[0x430-0x1EF]; f32 f430; } PQ;
void func_00178560(PQ *p) {
    extern void func_00185490(PQ *);
    extern void func_0018D0C0(PQ *);
    extern void func_00175700(PQ *);
    extern void func_00186CE0(PQ *, s32);
    extern void func_00158C70(f32 *, s32);
    if (p->b6 == 0) {
        u32 t = p->b6;
        p->b6 = t + 1;
        func_00185490(p);
        if (p->b1e6 != 0) {
            p->f5c = -10.833333015441895f;
            p->f68 = 0.3125f;
        } else {
            p->f5c = 10.833333015441895f;
            p->f68 = -0.3125f;
        }
        p->f60 = 17.14285659790039f;
        p->f6c = -1.6071428060531616f;
        if (p->b1ee == 0) {
            p->f5c = 0;
            p->f68 = 0;
        }
    }
    func_0018D0C0(p);
    p->f38 += p->f60;
    p->f60 += p->f6c;
    func_00175700(p);
    if (p->f38 <= p->f430) {
        p->f38 = p->f430;
        if (p->b1ee == 0) {
            func_00186CE0(p, 0x17);
            func_00158C70(&p->f34, p->b2);
            return;
        } else {
            p->b1e7 = 1;
            func_00186CE0(p, 0x11);
        }
    }
}
typedef struct { u8 p0[7]; u8 b7; u8 p8[0x21-8]; u8 b21; } PTo;
typedef struct { u8 p0[7]; u8 b7; u8 p8[0x34-8]; f32 f34; f32 f38; u8 p3c[0x50-0x3C]; f32 f50; u8 p54[0x5C-0x54]; f32 f5c; f32 f60; u8 p64[4]; f32 f68; f32 f6c; u8 p70[0x140-0x70]; s16 h140; u8 p142[0x430-0x142]; f32 f430; } PT;
void func_0027F560(PT *p) {
    extern PTo *func_001BFCA0(PT *, s32);
    extern void func_001757E0(PT *, s32, s32);
    f32 *a, *b, *c, *d;
    PTo *o;
    f32 f;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    d = &p->f6c;
    c = &p->f68;
    b = &p->f60;
    a = &p->f5c;
    if (p->f38 <= p->f430) {
        u32 t = p->b7;
        p->b7 = t + 1;
        p->f38 = p->f430;
        func_001BFCA0(p, 2);
        o = func_001BFCA0(p, 2);
        if (o != 0) o->b21 = 1;
        f = 200.0f * p->f50;
        if (p->h140 == 0) f = -f;
        p->f34 += f;
        *a = 0;
        *b = 0;
        *c = 0;
        *d = 0;
        func_001757E0(p, 0x15, 2);
    }
}
typedef struct { u8 p0[4]; u8 b4; u8 p5[2]; u8 b7; u8 p8[0x34-8]; f32 f34; f32 f38; u8 p3c[0x5C-0x3C]; f32 f5c; f32 f60; u8 p64[4]; f32 f68; f32 f6c; u8 p70[0xD0-0x70]; s32 wd0; u8 pd4[0x13C-0xD4]; s8 b13c; } PU;
void func_003BF500(PU *p) {
    extern void func_00175700(PU *);
    extern s32 func_00174170(void);
    extern void func_001E7F60(PU *);
    u32 t;
    s16 g;
    func_00175700(p);
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (p->f38 < (f32)p->wd0) {
        t = p->b7;
        p->b7 = t + 1;
        if (t == 0) {
            p->b13c = p->b13c & 1;
            p->f38 = (f32)p->wd0;
            g = -(func_00174170() & 0x30) - 0x10;
            p->f60 = 3.2142856121063232f;
            p->f6c = (2.1428570747375488f * g) / 256.0f;
        } else {
            u32 u = p->b4;
            p->b4 = u + 1;
        }
    }
    p->b13c = p->b13c ^ 1;
    if (p->b7 == 0) func_001E7F60(p);
}
typedef struct { u8 p0[0x34]; f32 f34; f32 f38; u8 p3c[0x140-0x3C]; s16 h140; } PV;
extern s32 D_0045CD20[];
extern s32 D_0045CD24[];
void func_00308AB0(PV *p, s32 n) {
    extern void func_001E3710(PV *, s32);
    extern void func_0015B200(PV *, f32 *, s32, s32);
    f32 v[3];
    v[0] = p->f34;
    v[1] = p->f38;
    if (p->h140 == 0) {
        v[0] -= 1.6666666269302368f * D_0045CD20[(u8)n * 2] / 65536.0f;
    } else {
        v[0] += 1.6666666269302368f * D_0045CD20[(u8)n * 2] / 65536.0f;
    }
    v[1] += 2.142857074737549f * D_0045CD24[(u8)n * 2] / 65536.0f;
    if (n == 0) func_001E3710(p, 0x49);
    func_0015B200(p, v, 1, 0x409);
}
