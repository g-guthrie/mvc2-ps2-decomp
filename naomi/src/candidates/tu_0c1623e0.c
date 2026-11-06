/* Candidate: func_0c162468 differs only in callee-saved allocation (retail r11=1,
 * r10=&dat_0c2f83f8; ours swapped) and scratch r1/r2/r3 rotation in three spots. */
#include "objects.h"
#define LA struct LinkedActor
struct Tail19c {
    char b19c, b19d, b19e, b19f, b1a0, b1a1, pad1a2[0x1ac - 0x1a2];
    short w1ac;
    char pad1ae[0x1c4 - 0x1ae];
    int l1c4;
    char pad1c8[0x255 - 0x1c8];
    unsigned char b255;
    char pad256[0x2f4 - 0x256];
    int l2f4;
};
#define T(a) ((struct Tail19c *)(a)->pad11)
extern LA *func_0c0374da(LA *, int, int);
extern void (*table_0c2515f4[])(LA *);
extern float dat_0c2515e4[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(LA *);
extern void func_0c02a0c4(LA *, int, int);
extern void func_0c0346da(LA *, int);
extern void func_0c037d0c(LA *), func_0c037688(LA *);
void func_0c162468(LA *);
void func_0c162720(LA *);

LA *func_0c1623e0(LA *a, char b)
{
    LA *q;
    if ((q = func_0c0374da(0, 1, 0)) != 0) {
        q->p16 = func_0c162720;
        q->p24 = a;
        q->b32 = b;
        q->w38 = 0x1f00;
    }
    return q;
}

LA *func_0c162414(LA *a, char b, char c)
{
    LA *q;
    if ((q = func_0c0374da(0, 1, 0)) != 0) {
        q->p16 = func_0c162468;
        q->p24 = a;
        q->b32 = b;
        q->b34 = c;
        q->w38 = 0x1f00;
        q->wcc.arrcc[0] = (unsigned short)a->sdc.w158.short_value;
        q->b1 = a->b1;
    }
    return q;
}

void func_0c162468(LA *a)
{
    LA *o = a->p24;
    float *t;
    if (!a->b4) {
        a->b4++;
        a->sdc = o->sdc;
        a->sdc.b12c = 1;
        a->b2 = o->b2;
        a->b1 = o->b1;
        a->v80.x = o->v80.x;
        a->v80.y = o->v80.y;
        a->b1a3 = o->b1a3;
        a->b1a4 = o->b1a4;
        a->b48 = o->b48;
        a->v80 = o->v80;
        a->b36 = o->b36;
        a->sdc.b12c = 1;
        T(a)->b19c = 66;
        T(a)->b19d = 66;
        if (T(o)->b255 == 8) {
            T(a)->b1a1 = 75;
            T(a)->w1ac = 0;
            T(a)->b19e = 0;
            T(a)->l1c4 = 0;
            dat_0c2f83f8->arr[a->b2]++;
            a->s30 = 15;
            a->s28 = 15;
        } else {
            if (!a->b32) T(a)->b1a1 = a->b1a3 + 50;
            else T(a)->b1a1 = a->b1a3 + 72;
            T(a)->w1ac = 0;
            T(a)->b19e = 0;
            T(a)->l1c4 = 0;
            dat_0c2f83f8->arr[a->b2]++;
            a->s30 = 4;
            if (!a->b1a3) a->s28 = 25;
            else a->s28 = 30;
        }
        func_0c02a0c4(a, 23, (char)a->b32 + 18);
        func_0c0346da(o, 75);
    }
    t = dat_0c2515e4;
    a->f52 = t[a->b32 * 2];
    t += a->b32 * 2;
    a->f56 = t[1];
    if (a->sdc.w130) a->f52 = -a->f52;
    a->f52 += o->f52;
    a->f56 += o->f56;
    if (a->wcc.arrcc[0] == (unsigned short)o->sdc.w158.short_value) {
        if (a->b4 == 1) {
            if (T(a)->b19f) goto next;
            if (T(a)->b1a0) {
                T(a)->b1a0--;
                return;
            }
            if (--a->s30 < 0) {
                a->s30 = 4;
                if (!a->b32) T(a)->b1a1 = a->b1a3 + 50;
                else T(a)->b1a1 = a->b1a3 + 72;
                T(a)->w1ac = 0;
                T(a)->b19e = 0;
                T(a)->l1c4 = 0;
                dat_0c2f83f8->arr[a->b2]++;
            }
            func_0c02a026(a);
            if (--a->s28 < 0) {
                a->s28 = 0;
next:
                a->b4++;
                func_0c02a0c4(a, 23, (char)a->b32 + 20);
                return;
            }
            func_0c037d0c(a);
            return;
        }
        if (a->b4 == 2) {
            if (func_0c02a026(a) >= 0) return;
            a->b4++;
            a->sdc.b12c = 0;
            T(o)->l2f4 = 1;
            return;
        }
    }
    func_0c037688(a);
}

void func_0c162720(LA *a)
{
    table_0c2515f4[a->b4](a);
}
