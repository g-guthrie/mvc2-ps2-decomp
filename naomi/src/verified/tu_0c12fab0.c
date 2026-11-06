/* Turn/approach state handlers 0x0c12fab0..0x0c13011c (int at actor +0x2c4 is a cooldown). */
#include "objects.h"
#define L2C4(a) (*(int *)&(a)->pad10b[4])
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c1d1622(struct LinkedActorVec3 *, int);
extern void func_0c04be40(struct Actor *);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c1bee94(struct Actor *);
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24e188[])(struct Actor *);
int func_0c12fdec(struct Actor *a);
int func_0c12ff04(struct Actor *a);
int func_0c12fd06(struct Actor *a);
int func_0c12ff90(struct Actor *a);
int func_0c12fd48(struct Actor *a);
void func_0c130042(struct Actor *a);
void func_0c130060(struct Actor *a);

void func_0c12fab0(struct Actor *a)
{
    if (func_0c12fdec(a) == 0 && func_0c12ff04(a) == 0 && func_0c12fd06(a) == 0)
        func_0c02a026(a);
}

void func_0c12fadc(struct Actor *a)
{
    if (func_0c12fdec(a)) return;
    if (func_0c12ff90(a)) return;
    func_0c12fd48(a);
    func_0c02a026(a);
    if (a->b14b) { int one = 1; a->b14b = 0; dat_0c2d9260.b5 = one; dat_0c2d9260.b6 = one; }
    if (!a->b141) { a->f52 += a->f92; a->f92 += a->f104; }
}

void func_0c12fb3c(struct Actor *a)
{
    struct LinkedActorVec3 v;
    unsigned char d;
    if (func_0c02a026(a) < 0) { func_0c130060(a); return; }
    goto L; L:
    if (a->b141 && L2C4(a) > 0) { unsigned int m; if (a->b525 && a->b19e) goto hit; m = 0x360; if ((a->w34e & m) || (a->w352 & m)) { hit:
        a->b141 = 0;
        a->w352 = 0;
        L2C4(a) -= 30;
        func_0c130042(a);
        d = a->w130;
        if (a->w340 & 0x800) d = 0;
        if (a->w340 & 0x400) d = 1;
        a->b1d2 = d;
        a->w130 = d;
        a->b1a1 = 125;
        a->w1ac = 0;
        a->b19e = 0;
        a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
        a->w1ac |= 0x800;
        func_0c02a0c4(a, 22, 13);
    }}
    if (a->b14b) {
        a->b14b = 0;
        dat_0c2d9260.b5 = 1;
        dat_0c2d9260.b6 = 1;
        v.x = -300.0f;
        if (a->w130) v.x = -v.x;
        v.x += a->f52;
        v.y = a->f56;
        func_0c1d1622(&v, -1);
    }
}

void func_0c12fc94(struct Actor *a)
{
    if (func_0c12fdec(a)) return;
    a->f52 += a->f92;
    a->f92 += a->f104;
    if (func_0c02a026(a) < 0) { func_0c130060(a); return; }
    goto L; L:
    if (a->b14b) {
        a->b14b = 0;
        a->b1a1 = 124;
        a->w1ac = 0;
        a->b19e = 0;
        a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
    }
}

int func_0c12fd06(struct Actor *a)
{
    int zero = 0;
    int d = zero;
    if (a->f52 < a->p20c->f52) d = 1;
    if (a->b1d2 != d) {
        a->b32 = zero;
        a->w130 = d;
        a->b1d2 = d;
        func_0c02a0c4(a, 22, 6);
        return 1;
    }
    return 0;
}

int func_0c12fd48(struct Actor *p)
{
    register struct Actor *a = p;
    int d = 0;
    char s142;
    int s140;
    void *m;
    if (a->f52 < a->p20c->f52) d = 1;
    if (a->b1d2 != d) {
        a->w130 = d;
        a->b1d2 = d;
        s142 = a->b142;
        s140 = *(char *)&a->b140;
        m = (void *)7;
        if (a->w34a & 0x800) m = (void *)14;
        func_0c02a0c4(a, 22, (int)m);
        for (;;) {
            if (*(char *)&a->b140 == s140) { a->b142 = s142; goto ret1; }
            a->b142 = 1;
            func_0c02a026(a);
        }
    ret1:
        return 1;
    }
    return 0;
}

int func_0c12fdec(struct Actor *p)
{
    register struct Actor *a = p;
    struct Actor *o;
    unsigned int in, dir;
    int d;
    if (L2C4(a) > 0) {
        in = a->w34e | a->w352;
        dir = a->w340;
        o = a->p20c;
        if (a->b525) {
            float dx = o->f52 - a->f52;
            in = 0;
            if (dx > 0.0f) dir = 0x400;
            else { dir = 0x800; dx = -dx; }
            if (!(dx > 266.66666f)) in = 0x200;
        }
        if (in & 0x360) {
            a->w352 = 0;
            a->b32 = 2;
            ((int *)((char *)a + 0x2a4))[8] -= 30; /* +0x2c4; base+32 form matches retail's add */
            a->f92 = 0.0f;
            func_0c130042(a);
            d = 0;
            if (a->f52 < o->f52) d = 1;
            if (dir & 0x800) d = 0;
            if (dir & 0x400) d = 1;
            a->w130 = d;
            a->b1a1 = 125;
            a->w1ac = 0;
            a->b19e = 0;
            a->p1c4 = 0;
            dat_0c2f83f8->arr[a->b2]++;
            a->w1ac |= 0x800;
            func_0c02a0c4(a, 22, 10);
            return 1;
        }
    }
    return 0;
}

int func_0c12ff04(struct Actor *a)
{
    unsigned int in = a->w340;
    unsigned int m = 0x800;
    struct Actor *o;
    void *mode;
    float v;
    if (a->b525) {
        float dx;
        in = 0;
        o = a->p20c;
        dx = o->f52 - a->f52;
        if (dx > 266.66666f) in = 0x400;
        if (dx < -266.66666f) in = m;
    }
    if (in & 0xc00) {
        a->b32 = 1;
        v = 5.0f;
        if (in & m) v = -5.0f;
        a->f92 = v;
        func_0c130042(a);
        mode = (void *)7;
        {
            int pos = 0;
            if (a->f92 > 0.0f) pos = 1;
            if ((short)a->w130 != pos) mode = (void *)14;
        }
        func_0c02a0c4(a, 22, (int)mode);
        return 1;
    }
    return 0;
}

int func_0c12ff90(struct Actor *a)
{
    unsigned int in = a->w340 & 0xc00;
    unsigned int in2;
    void *mode;
    if (a->b525) in = 0xc00;
    if (in == 0) {
        a->b32 = 0;
        func_0c130042(a);
        mode = (void *)12;
        if (a->w34c & 0x400) mode = (void *)6;
        func_0c02a0c4(a, 22, (int)mode);
        return 1;
    }
    in2 = a->w342 & 0xc00;
    if (a->b525) in2 = 0xc00;
    if (in != in2) {
        float v = 5.0f;
        mode = (void *)7;
        if (a->w34a & 0x400) { v = -5.0f; mode = (void *)14; }
        a->f92 = v;
        func_0c02a0c4(a, 22, (int)mode);
    }
    return 0;
}

void func_0c130042(struct Actor *a)
{
    unsigned char d = 0;
    if (a->f52 < a->p20c->f52) d = 1;
    a->b1d2 = d;
    a->w130 = d;
}

void func_0c130060(struct Actor *a)
{
    a->b32 = 0;
    a->b1d2 = a->w130;
    a->f92 = 0.0f;
    func_0c02a0c4(a, 22, 12);
}

void func_0c13007c(struct Actor *a)
{
    a->b1eb = 2;
    a->i204 = 3;
    func_0c04be40(a);
    table_0c24e188[a->b6](a);
}

void func_0c1300a6(struct Actor *a)
{
    a->b6++;
    a->b202 = 0x80;
    func_0c0442fa(a);
    func_0c0432ca(a);
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->f56 = a->f41c;
    a->b1f9 = 0;
    a->b1a1 = 124;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c1bee94(a);
    func_0c02a0c4(a, 22, 5);
}
