/* EE GCC 2.96: -O2 -G8.
 *
 * Stream-player state handlers in retail order. func_00404178 dispatches to
 * the four handlers defined above it; GCC 2.96 treats calls to functions it
 * has already compiled in the unit as non-throwing, and only then does reorg
 * see $v0 dead after them and keep retail's plain bne branches.
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
#include "cri_sj_ring_buffer_types.h"

typedef struct StreamGroup StreamGroup;

extern u8 D_004BC7C0[];

typedef struct {
    s8 b0;
    s8 b1;
    s8 b2;
    s8 b3;
    s32 h;
    s32 w8;
    s32 wC;
    u8 pad10[0x28];
    s32 w38;
    s16 h3c;
    s16 h3e;
    s16 h40;
    s16 h42;
    u8 pad44[4];
    s32 w48;
    u8 pad4c[4];
    s32 w50;
    u8 pad54[0x20];
    s32 w74;
    u8 pad78[0x14];
    s32 w8C;
    s32 w90;
} C43;

void func_004035D8(C43 *p)
{
    extern s32 func_003FF5C8(s32);
    extern s32 func_003FFF90(void *);
    extern void func_003FB2E8(s32, s32, u8 *, s32);
    extern void func_003FB178(u8 *, u8 *);
    extern void func_00401868(C43 *);
    extern s32 func_003FFF78(void *);
    extern s32 func_00400020(void *);
    extern s32 func_003FFFC0(void *);
    extern void func_003FF600(StreamGroup *, s32);
    extern s32 func_00400098(void *);
    extern void func_004007A0(s32, s32);
    extern void func_00400790(s32, void *, C43 *);
    extern s32 func_00400080(s32);
    extern void func_003FFF30(s32, s32);
    extern void func_003FFF50(s32, s32);
    extern void func_003FFF40(s32, s32);
    extern void func_003FFF20(s32, void *, C43 *);
    extern s32 func_003FFFF0(StreamGroup *);
    extern s32 func_003FFFA8(s32);
    extern void func_003FF288(void *, s32);
    typedef struct S_0040ED28 S_0040ED28;
    extern void func_003FF240(S_0040ED28 *, s32);
    extern void func_003FF228(void *, s32);
    extern void func_003FF328(s32, s32);
    extern void func_003FF258(s32 *, s32);
    extern void func_00403228(C43 *);
    extern void func_003F6470(s32, s32);
    extern s32 func_003FFF60(s32);
    extern s32 func_004000D0(s32);
    extern void func_003FF338(s32, s32);
    extern void func_003FF148(s8 *, s32);
    extern void func_004031A8();
    extern void func_00403020();
    extern void func_00403308();
    u8 buf[32];
    s32 unit = 0x800;
    s32 a, h, b, c, n, v, w, x;
    h = p->h;
    if (func_003FF5C8(h) != 2) return;
    b = func_003FFF90((void *)h);
    if (p->b3 < b) {
        func_003FB2E8(b, p->b3, buf, 16);
        func_003FB178(D_004BC7C0, buf);
        func_00401868(p);
        return;
    }
    a = func_003FFF78((void *)h);
    b = func_00400020((void *)h);
    if (b > 0) {
        p->w48 = a / p->w38 * 3;
    } else {
        p->w48 = a / p->w38 * 3 / 2;
    }
    w = func_003FFFC0((void *)h) * 2;
    {
        s32 t;
        t = p->w48 + w;
        p->w48 = t / w * w;
    }
    func_003FF600((StreamGroup *)h, p->w48);
    if (b > 0) {
        if (p->b2 == 2) {
            p->w50 = 0;
        } else {
            v = func_00400098((void *)h);
            p->w50 = unit - v % unit;
            p->w50 = p->w50 % unit;
            n = (v + 0x7FF) / unit;
            p->w8C = n;
            func_004007A0(p->w8, n);
            func_00400790(p->w8, func_004031A8, p);
        }
        p->w90 = func_00400080(h);
        func_003FFF30(h, p->w90);
        func_003FFF50(h, 0);
        func_003FFF40(h, 0);
        func_003FFF20(h, func_00403020, p);
    } else {
        if (p->w8) func_004007A0(p->w8, 0x7FFFFFFF);
        func_003FFF30(h, func_003FFFF0((StreamGroup *)h));
        func_003FFF50(h, 0);
        func_003FFF40(h, 0);
        func_003FFF20(h, func_00403308, p);
    }
    a = func_003FFF78((void *)h);
    b = func_003FFF90((void *)h);
    c = func_003FFFF0((StreamGroup *)h);
    v = func_003FFFA8(h);
    func_003FF288((void *)p->wC, v);
    func_003FF240((S_0040ED28 *)p->wC, a);
    func_003FF228((void *)p->wC, b);
    func_003FF328(p->wC, c);
    func_003FF258((s32 *)p->wC, p->h40);
    func_00403228(p);
    if (p->w74) func_003F6470(p->w74, a);
    unit = 2;
    if (func_003FFF60(h) == unit) {
        func_003FF338(p->wC, func_004000D0(h));
    }
    func_003FF148((s8 *)p->wC, 1);
    p->b1 = unit;
}

extern s32 D_004C22C4;
extern s32 func_003FF190(void *);
extern s32 func_003FF1A8(void *);
extern s32 func_003FFFC0(void *);
extern s32 func_003FF5C8(s32);
extern void func_003FF160(s32, s32);
extern s32 func_00401F38(u8 *);
extern void *func_0011D8F8(void *, int, unsigned int);

void func_00403900(u8 *p)
{
    s32 a = *(s32 *)(p + 0xC);
    s32 b = *(s32 *)(p + 4);
    s32 c;
    s32 d;
    c = func_003FF190((void *)a);
    d = func_003FF1A8((void *)a);
    if (!(c < *(s32 *)(p + 0x48) * 2) || !(func_003FFFC0((void *)b) < d) || func_003FF5C8(*(s32 *)(p + 4)) == 3) {
        if (*(s8 *)(p + 0x70) == 0) {
            if (*(s8 *)(p + 0x72) == 0) {
                func_003FF160(a, 1);
                *(s32 *)(p + 0x9C) = 0;
                *(s32 *)(p + 0xA0) = D_004C22C4;
            }
            p[1] = 3;
        }
        p[0x71] = 1;
    }
    if (func_003FF5C8(*(s32 *)(p + 4)) == 3) {
        s32 n;
        s32 m;
        s32 **q;
        s32 i;
        s32 *o;
        s32 sp[2];
        n = func_00401F38(p);
        m = *(s32 *)(p + 0x48) * n * 2;
        if (n > 0) {
            q = (s32 **)(p + 0x18);
            i = n;
            do {
                o = *q;
                q++;
                (*(void (**)(s32 *, s32, s32, s32 *))(*(s32 *)o + 0x18))(o, 0, m, sp);
                func_0011D8F8((void *)sp[0], 0, sp[1]);
                (*(void (**)(s32 *, s32, s32 *))(*(s32 *)o + 0x20))(o, 1, sp);
            } while (--i != 0);
        }

    }
}

extern s32 func_003FF5C8(s32);
extern s32 func_003FFF90(void *);
extern s32 D_004C2404;
extern s32 D_004C2408;
typedef struct VO { s32 (**vt)(struct VO *, s32); } VO;
typedef struct { u8 p0; u8 f1; char p2[2]; s32 f4; char p8[0x10]; VO *objs[1]; } Q3A70;

void func_00403A70(Q3A70 *q) {
    s32 r, n, i; VO **pp;
    if (func_003FF5C8(q->f4) == 3) {
        i = 0;
        n = func_003FFF90((void *)q->f4);
        pp = q->objs;
        D_004C2404 = n;
        for (; i < n; i++) {
            VO *o = *pp++;
            r = o->vt[9](o, 1);
            D_004C2408 = r;
            if (r >= 0x40) break;
        }
        if (i == n) {
            *(s32 *)((u8 *)q + 0xA8) = 0;
            q->f1 = 4;
        }
    }
}

extern s32 D_004C240C;
typedef SJCK PR;

void func_00403B20(u8 *p)
{
    extern s32 func_003FF190(void *);
    extern s32 func_003FFF90(void *);
    extern void func_003F9630(void);
    extern void func_003F9660(void);
    extern void func_004104E0(PR *, s32, PR *, PR *);
    extern void func_003FF148(s8 *, s32);
    extern void func_003FF160(s32, s32);
    extern void func_0040EA00(s32, s32);
    PR A[2];
    PR B[2];
    PR *pa, *pb;
    s32 i, n, fp, mx, r, a;
    u32 mn, v;
    s32 **q, **q2, **q3;
    s32 *o;

    i = 0;
    r = func_003FF190(*(void **)(p + 0xC));
    a = *(s32 *)(p + 4);
    D_004C240C = r;
    n = func_003FFF90((void *)a);
    func_003F9630();
    mn = *(u32 *)(p + 0x48);
    if (n > 0) {
        q = (s32 **)(p + 0x18);
        do {
            o = *q++;
            (*(void (**)(s32 *, s32, s32, PR *))(*(s32 *)o + 0x18))(o, 0, mn * 2, &A[i]);
            v = (u32)A[i].len >> 1;
            i++;
            if (v < mn) mn = v;
        } while (i < n);
    }
    i = 0;
    if (n > 0) {
        fp = mn * 2;
        q2 = (s32 **)(p + 0x18);
        do {
            pa = &A[i];
            pb = &B[i];
            func_004104E0(pa, fp, pa, pb);
            func_0011D8F8(pa->data, 0, A[i].len);
            i++;
            o = *q2;
            (*(void (**)(s32 *, s32, PR *))(*(s32 *)o + 0x20))(o, 1, pa);
            o = *q2++;
            (*(void (**)(s32 *, s32, PR *))(*(s32 *)o + 0x1C))(o, 0, pb);
        } while (i < n);
    }
    *(s32 *)(p + 0xA8) = *(s32 *)(p + 0xA8) + mn;
    mx = 0;
    func_003F9660();
    if (n > 0) {
        q3 = (s32 **)(p + 0x18);
        i = n;
        do {
            o = *q3++;
            v = (*(u32 (**)(s32 *, s32))(*(s32 *)o + 0x24))(o, 1);
            if ((s32)(v >> 1) >= mx) mx = v >> 1;
        } while (--i != 0);
    }
    if (mx + func_003FF190(*(void **)(p + 0xC)) - *(s32 *)(p + 0xA8) <= 0) {
        func_003FF148(*(s8 **)(p + 0xC), 0);
        func_003FF160(*(s32 *)(p + 0xC), 0);
        func_0040EA00(*(s32 *)(p + 0xC), 1);
        p[1] = 5;
    }
}

extern u8 D_004BC818[];
extern void func_003FB128(u8 *);
extern void func_00403D28(u8 *);
extern void func_004040F0(u8 *);
extern void func_00404070(u8 *);

void func_00404178(u8 *p)
{
    s8 k;

    if (p == 0) {
        func_003FB128(D_004BC818);
        return;
    }
    k = p[1];
    if (k == 3)
        func_00403A70((Q3A70 *)p);
    else if (k == 1)
        func_004035D8((C43 *)p);
    else if (k == 2)
        func_00403900(p);
    else if (k == 4)
        func_00403B20(p);
    else if (k == 5)
        func_00403D28(p);
    func_004040F0(p);
    func_00404070(p);
}
