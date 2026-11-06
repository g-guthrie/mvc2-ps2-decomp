#include "objects.h"
extern void func_0c06f29c(struct Actor *, struct ActorSub2a4 *);
extern int func_0c02a39a(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c042018(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c0344a0(struct Actor *, int);
extern void func_0c044f1c(struct Actor *);
extern void (*table_0c240ef4[])(struct Actor *);
void func_0c070fd4(struct Actor *a)
{
    struct ActorSub2a4 *sub = &a->sub2a4;
    *(unsigned char *)&sub->w4 = 255;
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f56 < a->f41c) a->f56 = a->f41c + -2.1428571f;
    else {
        func_0c06f29c(a, sub);
        if (--a->s28 >= 0) return;
    }
    a->b6++;
    *(unsigned char *)&sub->w4 = 0;
    a->f92 = 3.3333333f;
    if (a->w130) a->f92 = -a->f92;
    a->f104 = 0;
    a->f96 = 21.42857f;
    a->f108 = -0.80357140303f;
    func_0c02a39a(a, 0);
    func_0c02a0c4(a, 15, 7);
}
void func_0c0710a4(struct Actor *a)
{
    func_0c02a026(a);
    func_0c042018(a);
    if (func_0c044e52(a)) { func_0c0344a0(a, 43); func_0c044f1c(a); }
}
void func_0c0710d8(struct Actor *a) { table_0c240ef4[a->b6](a); }
