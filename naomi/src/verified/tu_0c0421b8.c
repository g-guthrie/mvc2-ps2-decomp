#include "objects.h"

extern const unsigned short dat_0c23e270[];
extern const unsigned int dat_0c23bdc4[];
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern float dat_0c2d9300;
extern void func_0c0437b8(struct Actor *);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c0453c4(struct Actor *, int);
extern int func_0c02849a(void);


void func_0c0425e4(struct Actor *a, struct Actor *b, struct MotionGlobal_0c2d9260 *g);
void func_0c04251a(struct Actor *a, struct Actor *b, struct MotionGlobal_0c2d9260 *g);
void func_0c042688(struct Actor *a);

void func_0c0421b8(struct Actor *a)
{
    if (a->b1fc == 1 && !(a->f96 > 0.0f)) {
        a->b1fc = 2;
        a->f108 = (float)(short)dat_0c23e270[a->b1] * 2.1428571f / 256.0f;
    }
}

void func_0c0421f4(struct Actor *a)
{
    if (a->b19e && !a->pad1d7[0]) {
        a->pad1d7[0]++;
        a->f96 *= 0.75f;
    }
}

void func_0c04221c(struct Actor *a)
{
    struct MotionGlobal_0c2d9260 *g = &dat_0c2d9260;
    float d;

    if (a->b1f4)
        return;
    if (a->pad324[0])
        return;
    if (a->b201 && a->b5 != 2) {
        d = a->p20c->f56 - a->f56 + 274.28571f;
        if (0.0f > d) {
            a->f56 += d / 8.0f;
        } else {
            d = a->f56 - a->f41c + -34.2857132f;
            if (0.0f > d) a->f56 -= d / 2.0f;
        }
        d = dat_0c2d9300 + -205.71428f;
        if (a->f56 > d)
            a->f56 = d;
    }
    a->b1fd = 0;
    d = g->f12 + -285.0f;
    if ((int)a->f52 <= (int)d) {
        a->f52 = d;
        a->b1fd = 2;
    } else {
    d = g->f12 + 285.0f;
    if ((int)a->f52 >= (int)d) {
        a->f52 = d;
        a->b1fd = 1;
    }
    }
}

void func_0c04231c(struct Actor *a)
{
    struct MotionGlobal_0c2d9260 *g = &dat_0c2d9260;
    float d;

    if (!a->pad324[0])
        return;
    if (a->b201 && a->b5 != 2) {
        d = a->p20c->f56 - a->f56 + 274.28571f;
        if (0.0f > d) {
            a->f56 += d / 8.0f;
        } else {
            d = a->f56 - a->f41c + -34.2857132f;
            if (0.0f > d) a->f56 -= d / 2.0f;
        }
        d = dat_0c2d9300 + -205.71428f;
        if (a->f56 > d)
            a->f56 = d;
    }
    a->b1fd = 0;
    d = g->f12 + -293.333344f;
    if ((int)a->f52 <= (int)d) {
        a->f52 = d;
        a->b1fd = 2;
    } else {
    d = g->f12 + 293.333344f;
    if ((int)a->f52 >= (int)d) {
        a->f52 = d;
        a->b1fd = 1;
    }
    }
}

void func_0c042414(struct Actor *a)
{
    struct MotionGlobal_0c2d9260 *g;
    struct Actor *b;
    float d;

    if (!a->w420)
        return;
    if (a->b1d0 == 28)
        return;
    if (a->b1d0 == 23)
        return;
    g = &dat_0c2d9260;
    b = a->p20c;
    d = g->f12 + -285.0f;
    if ((int)a->f52 < (int)d) {
        if (g->f98 + 35.0f > a->f52) {
            a->f52 = g->f98 + 35.0f;
        } else {
            func_0c042688(a);
            func_0c0425e4(a, b, g);
        }
    } else {
    d = g->f12 + 285.0f;
    if ((int)a->f52 > (int)d) {
        if (a->f52 > g->f9c + -35.0f) {
            a->f52 = g->f9c + -35.0f;
        } else {
            func_0c042688(a);
            func_0c04251a(a, b, g);
        }
    } else if (!b->b5) {
        goto L0;
    L0:
        b->b235 = 0;
    }
    }
}

void func_0c04251a(struct Actor *a, struct Actor *b, struct MotionGlobal_0c2d9260 *g)
{
    float x = g->f12 + 445.0f;

    if (a->b1 == 41)
        x += 53.3333321f;
    if (!(x > a->f52)) {
        if (!b->b5 && a->b1d0 == 10)
            return;
        a->f52 = x;
        a->f56 = a->f41c;
        a->b201 = 0;
        func_0c0437b8(a);
        func_0c02a39a(a, 1);
        if (b->b5)
            return;
    } else {
        if (b->b5)
            return;
        if (a->b1d0 == 10)
            return;
        a->f56 = a->f41c;
        a->b201 = 0;
        func_0c0437b8(a);
        func_0c02a39a(a, 1);
    }
    func_0c0453c4(a, 10);
}

void func_0c0425e4(struct Actor *a, struct Actor *b, struct MotionGlobal_0c2d9260 *g)
{
    float x = g->f12 + -445.0f;

    if (a->b1 == 41)
        x -= 53.3333321f;
    if (!(a->f52 > x)) {
        if (!b->b5 && a->b1d0 == 10)
            return;
        a->f52 = x;
        a->f56 = a->f41c;
        a->b201 = 0;
        func_0c0437b8(a);
        func_0c02a39a(a, 1);
        if (b->b5)
            return;
    } else {
        if (b->b5)
            return;
        if (a->b1d0 == 10)
            return;
        a->f56 = a->f41c;
        a->b201 = 0;
        func_0c0437b8(a);
        func_0c02a39a(a, 1);
    }
    func_0c0453c4(a, 10);
}

void func_0c042688(struct Actor *a)
{
    a->b1f3 = 2;
    a->w340 &= 0x3f0;
    a->w348 &= 0x3f0;
    a->w342 &= 0x3f0;
    a->w34a &= 0x3f0;
    a->w34e &= 0x3f0;
    a->w34c &= 0x3f0;
}

void func_0c0426c2(struct Actor *a, short v)
{
    if ((a->s25c = v + ((const signed char *)dat_0c23bdc4)[func_0c02849a() & 31]) <= 0)
        a->s25c = 1;
}
