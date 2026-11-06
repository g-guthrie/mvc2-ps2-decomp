#include "objects.h"
extern void func_0c03edcc(struct Actor *, struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);

void func_0c09d210(struct Actor *a)
{
    float v[3];
    
    a->b6++;
    v[0] = a->f52;
    v[1] = a->p1c8->f52;
    v[2] = a->p1c8->f52 - a->f52;
    func_0c03edcc(a, a->p1c8);
    v[2] = a->p1c8->f52 - a->f52 - v[2];
    v[2] /= 16.0f;
    a->f52 = v[0];
    a->p1c8->f52 = v[1];
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    a->p1c8->f92 = 0;
    a->p1c8->f96 = 0;
    a->p1c8->f104 = 0;
    a->p1c8->f108 = 0;
    a->p1c8->f92 = v[2];
    a->f92 = -v[2];
    a->s28 = 16;
}

void func_0c09d2d6(struct Actor *a)
{
    func_0c02a026(a);
    if (a->p1c8->b1fd) {
        a->f52 += a->f92;
        a->f92 += a->f104;
    } else {
        a->p1c8->f52 += a->p1c8->f92;
        a->p1c8->f92 += a->p1c8->f104;
    }
    if (--a->s28 == 0) {
        a->b6++;
        a->s28 = 2;
        a->b34 = 0;
        func_0c03edcc(a, a->p1c8);
        func_0c02a0c4(a, 15, 2);
    }
}
