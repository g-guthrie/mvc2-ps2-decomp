typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct PE PE;
typedef struct QE QE;
typedef struct XE XE;
struct PE {
    u8 p00[0x1C];
    s16 h1c;
    u8 p1e[0x34 - 0x1E];
    f32 f34;
    f32 f38;
    u8 p3c[0x5C - 0x3C];
    f32 f5c;
    f32 f60;
    u8 p64[0x13C - 0x64];
    u8 b13c;
};
struct QE {
    u8 p00[8];
    s16 h8;
    s16 hA;
    u8 pc[3];
    s8 bf;
    f32 f10;
    f32 f14;
    u8 p18[0x28 - 0x18];
    s32 w28;
    f32 f2c;
    s8 b30;
    u8 p31[3];
    u8 b34;
};
struct XE {
    u8 p00[0x34];
    f32 f34;
    f32 f38;
    u8 p3c[0x430 - 0x3C];
    f32 f430;
};

extern u8 D_00473340[];
extern u8 D_004C1F38[8];

void func_003AC6F0(u8 *p_, u8 *q_) {
    extern void func_003AB400(void);
    extern void func_001E3210(u8 *, s32);
    extern void func_003ACA10(u8 *, u8 *, u8 *);
    extern s32 func_00182D30(u8 *);
    extern void func_003AADA0(u8 *, u8 *);
    extern s32 func_00182E20(u8 *);
    extern u8 *func_003AD580(u8 *, u8 *, s16 *);
    extern void func_00175580(u8 *, s32, u8, s32);
    extern void func_003ACCC0(u8 *, u8 *, s32, u8 *);
    extern void func_001823C0(u8 *);
    PE *p = (PE *)p_;
    QE *q = (QE *)q_;
    XE *X;
    u8 *Xb;
    u8 *s1;
    QE *s2;
    s32 s3;
    u32 t;
    s32 d;
    Xb = *(u8 **)(p_ + 0x18);
    X = (XE *)Xb;
    Xb[0x201] = 3;
    Xb[0x206] = 3;
    if (Xb[6] == 6) {
        func_003AB400();
        return;
    }
    t = (u16)(*(s16 *)(Xb + 0x362) & 0x360);
    if (t != 0) {
        if (((u16)t & 0x300) != 0) {
            *(s16 *)(q_ + 0x30) = 1;
            Xb[6] = 9;
        } else {
            *(s16 *)(q_ + 0x30) = 2;
            Xb[6] = 10;
        }
    }
    {
        s16 v = p->h1c - 1;
        p->h1c = v;
        if (v > 0) {
            if ((p->h1c & 7) == 0) {
                func_001E3210(Xb, 0x1E);
                func_003ACA10(p_, q_, Xb);
            }
            if (func_00182D30(*(u8 **)(Xb + 0x1DC)) != 0) {
                p->h1c = -1;
            }
        }
    }
    if (p->h1c < 0) {
        Xb[6] = 2;
        (*(u8 **)(Xb + 0x1DC))[0x20A] = 7;
        func_003AADA0(p_, q_);
        return;
    }
    if (func_00182E20(Xb) != 0) {
        func_003ACA10(p_, q_, Xb);
    }
    {
        s16 v = q->h8 - 1;
        q->h8 = v;
        if (v <= 0) {
            u8 *o;
            q->h8 = 2;
            if ((q->hA & 1) == 0) {
                o = func_003AD580(p_, p_, &q->h8);
                if (o != 0) {
                    o[0x21] = q->b30;
                    *(s16 *)(o + 0x1C) = q->hA / 2;
                    *(s16 *)(o + 0x1E) = q->bf;
                }
            }
            s1 = p_;
            s2 = q;
            s3 = 0;
            while (q->bf >= s3) {
                s32 h = s2->hA;
                if (h < 0) {
                    s2->hA = h + 1;
                } else {
                    s1[0x168] = D_004C1F38[D_00473340[h]];
                    d = (u8)(((s1[0x22] + 4) & 0xF8) / 8);
                    func_00175580(s1, 0x1B, s1[0x168], d);
                    s2->hA = (s2->hA + 1) & 0x1F;
                }
                s1 = *(u8 **)(s1 + 0xC);
                s3++;
                s2 = (QE *)(s1 + 0x88);
            }
        }
    }
    {
        f32 a, b;
        a = p->f5c + q->f10;
        q->f2c = a;
        p->f34 = a;
        b = p->f60 + q->f14;
        p->f38 = b;
        a = b - (137.1428528f + X->f430);
        if (a < 0.0f) {
            p->f38 = b + a;
            X->f38 += a;
        }
    }
    func_003ACCC0(p_, q_, q->w28, Xb);
    X->f34 += p->f34 - q->f2c;
    func_001823C0(Xb);
    p->b13c = 1;
    q->b34 = 1;
    q->bf = 0;
}
