#pragma opt_lifetimes off
#pragma opt_propagation off
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad[0x2B8];
    u8 b[8];
} SB;

extern u8 D_004D18A1;
typedef struct { u8 pad[0x5C]; f32 f5c; } N5C;

void func_0027FF50(u8 *p)
{
    extern s32 func_00175700(u8 *);
    extern int func_001757E0(u8 *, s32, s32);
    extern void func_00181F10(u8 *);
    extern void func_00185490(u8 *);
    extern void func_00280330(u8 *);
    u8 *q;
    u8 *s;
    N5C *sa = (N5C *)p;

    switch (p[6]) {
    default:
        break;
    case 0:
        p[0x2B9] = 1;
        p[6]++;
        func_001757E0(p, 0, 2);
        break;
    case 1:
        p[0x2B9] = 1;
        func_00175700(p);
        if (p[7] == 0) {
            if (*(s8 *)(p + 0x151) != 0) {
                p[0x151] = 0;
                p[7]++;
            }
        } else if (*(s8 *)(p + 0x151) == 0) {
            *(f32 *)(p + 0x118) = (f32)*(s8 *)(p + 0x152) / (f32)*(s8 *)(*(u8 **)(p + 0x164) + 2);
        } else {
            p[6]++;
            p[7] = 0;
            *(s16 *)(p + 0x1C) = 0x1E;
            *(u32 *)(p + 0x5C) = 0xC1555555;
            *(s32 *)(p + 0x68) = 0;
            if (*(s16 *)(p + 0x140) != 0)
                sa->f5c = -sa->f5c;
        }
        break;
    case 2:
        { s32 c = 1; s = ((SB *)p)->b; s[1] = c; q = s + 1; }
        *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) - 1;
        func_00181F10(p);
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x2BC) = (f32)*(s16 *)(p + 0x1C) / 30.0f;
        if (*(s16 *)(p + 0x1C) == 0) {
            p[6]++;
            *q = 0;
        }
        break;
    case 3:
        if (!(D_004D18A1 & 2) && (*(u16 *)(p + 0x354) & 0xC00)) {
            func_00181F10(p);
            *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        } else {
            p[6]++;
            func_00185490(p);
            func_001757E0(p, 0, 4);
        }
        break;
    case 4:
        if ((s8)func_00175700(p) < 0)
            func_00280330(p);
        break;
    }
}

extern f32 D_004F1FD8;
extern f32 D_004F1FDC;

typedef struct { u32 a, b, c, d; } P2;

void func_0029EEF0(u8 *p, u8 *q) {
    extern void func_00175700(u8 *);
    extern void func_00126400();
    extern void func_001E3210(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00178F20(u8 *, u8 *);
    extern void func_0018FDB0(u8 *);
    extern void func_001E3B70(u8 *, s32);
    extern void func_00191480(u8 *, u8 *, s32);
    extern void func_001548D0(u8 *, P2 *, s32);
    f32 sv;
    f32 y;
    f32 h;
    f32 k;
    s16 v;
    u32 t;
    P2 c;
    func_00175700(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v < 0) {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        func_00126400();
        func_001E3210(p, 0x2B);
        func_001757E0(p, 0x16, 0xD);
        t = p[6];
        p[6] = t + 1;
        p[7] = 0;
        *(s16 *)(p + 0x1E) = 0;
        p[0x160] = 0x21;
        sv = *(f32 *)(q + 0x34);
        func_00178F20(p, q);
        *(f32 *)(q + 0x34) = sv;
        k = 253.3333282470703f;
        *(f32 *)(q + 0x38) = *(f32 *)(q + 0x430);
        if (*(s16 *)(p + 0x140) != 0) {
            {
            f32 tp = *(f32 *)(p + 0x34);
            f32 tr;
            f32 tc = 160.0f;
            f32 td = D_004F1FDC;
            tr = td - tc;
            if (tr < tp) {
                k = -k;
                *(s16 *)((s32)p + 0x140) = p[0x1E6] = 1;
            } else {
                *(s16 *)((s32)p + 0x140) = p[0x1E6] = 0;
            }
            }
        } else {
            k = -k;
            {
            f32 tp = *(f32 *)(p + 0x34);
            f32 tr;
            f32 td = D_004F1FD8;
            f32 tc = 160.0f;
            tr = tc + td;
            if (!(tr <= tp)) {
                k = -k;
                *(s16 *)((s32)p + 0x140) = p[0x1E6] = 0;
            } else {
                *(s16 *)((s32)p + 0x140) = p[0x1E6] = 1;
            }
            }
        }
        y = *(f32 *)(p + 0x430);
        h = 48.0f;
        *(f32 *)(p + 0x5C) = (*(f32 *)(q + 0x34) + k - *(f32 *)(p + 0x34)) / h;
        *(u32 *)(p + 0x68) = 0;
        *(f32 *)(p + 0x60) = (*(f32 *)(p + 0x38) - y) / h - -19.28571319580078f;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        *(s16 *)(p + 0x1C) = 0x18;
    } else {
        func_00178F20(p, q);
        if (*(s8 *)(p + 0x151) & 1) {
            p[0x151] = 0;
            *(u8 **)(q + 0x1C8) = p;
            q[0x1B5] = 0x3E;
            func_0018FDB0(p);
            func_001E3B70(q, 1);
            func_00191480(q, p, 1);
            c.a = 0xC2555555;
            c.b = 0x42092492;
            func_001548D0(p, &c, 3);
        }
    }
}

typedef struct SA37_Q1D0 {
    u8 pad0[2];
    u8 b2;
} SA37_Q1D0;

typedef struct SA37_Q {
    u8 pad0[0x1B0];
    s8 b1b0;
    u8 pad1b1[0x1D0 - 0x1B1];
    SA37_Q1D0 *o;
} SA37_Q;

typedef struct SA37_P2 {
    u8 pad0[1];
    u8 b1;
    u8 pad2[0x5C - 2];
    f32 f5c;
    u8 pad60[0x68 - 0x60];
    s32 w68;
    u8 pad6c[0xD0 - 0x6C];
    s32 wd0;
    u8 padd4[0x1E6 - 0xD4];
    u8 b1e6;
    u8 pad1e7[0x2C7 - 0x1E7];
    s8 b2c7;
} SA37_P2;

s32 func_002AC590(SA37_P2 *p, SA37_Q *q) {
    s32 v;
    s32 d;
    f32 f;
    f32 k;
    f32 z;
    if (p->b1 != 0x22) return 0;
    if ((q->b1b0 & 6) == 0) return 0;
    if (p->wd0 != 0) return 0;
    v = p->b2c7;
    if (v == 0) return 0;
    d = 4;
    if ((s8)v > 0) {
        if ((q->o->b2 & 0x20) != 0) return 0;
        d = 2;
    }
    f = p->f5c;
    z = 0.0f;
    f = (f < z) ? -f : f;
    k = 3.3333332538604736f;
    if (!(f <= k)) {
        p->f5c /= (f32)d;
    } else {
        if (p->b1e6 != 0) {
            k = 3.3333332538604736f;
        } else {
            k = -3.3333332538604736f;
        }
        p->f5c = k;
        p->w68 = 0;
    }
    return 1;
}

s32 func_002FC750(u8 *p, u8 *q) {
    u8 *c = p + 0x2B8;
    s32 n;
    u8 a;
    f32 v;
    f32 k;
    f32 z;
    if (p[1] != 0x32) return 0;
    if ((*(s8 *)(q + 0x1B0) & 6) == 0) return 0;
    if ((a = c[0xA]) == 0) return 0;
    n = 4;
    if (a > 0) {
        n = 2;
        if ((*(u8 **)(q + 0x1D0))[2] & 0x20) return 0;
    }
    v = *(f32 *)(p + 0x5C);
    z = 0.0f;
    v = (v < z) ? -v : v;
    k = 3.3333332538604736f;
    if (!(v <= k)) {
        *(f32 *)(p + 0x5C) /= (f32)n;
    } else {
        if (p[0x1E6]) k = 3.3333332538604736f;
        else k = -3.3333332538604736f;
        *(f32 *)(p + 0x5C) = k;
        *(s32 *)(p + 0x68) = 0;
    }
    return 1;
}
