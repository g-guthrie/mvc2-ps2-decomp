#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0344a0(struct Actor *, int);
extern void func_0c1bb838(struct Actor *,int,float,float),func_0c037d0c(struct Actor *);
extern void func_0c037688(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern short dat_0c2556b8[];
void func_0c181eac(struct Actor *a);
void func_0c181f70(struct Actor *a);
void func_0c181f7e(struct Actor *a);

void func_0c181eac(struct Actor *a)
{
    short i;
    short *p;
    func_0c02a026(a);
    if ((a->s30 += 0x2000) == 0) a->b19e = 0;
    if (--a->s28 == 0) {
        a->b4++;
        if (!a->b32) func_0c0344a0(a, 35);
        p = dat_0c2556b8;
        for (i = 0; i < 8; i++) {
            float x = a->f52 + *p++ * 1.66666663f;
            float y = a->f56 + *p++ * 2.1428571f;
            func_0c1bb838(a, 1, x, y);
        }
        a->b1a1 = 61;
        a->w1ac = 0;
        a->b19e = 0;
        a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
    }
    func_0c037d0c(a);
}

void func_0c181f70(struct Actor *a)
{
    a->b4++;
    a->b12c = 0;
}

void func_0c181f7e(struct Actor *a){func_0c037688(a);}
