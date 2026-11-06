#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c02a684(struct Actor *, int, void *, int);
extern int func_0c02a39a(struct Actor *, int);
extern void func_0c18f420(struct Actor *, int);
extern void func_0c043324(struct Actor *);
extern void *table_0c23fdbc[];

void func_0c061ebc(struct Actor *a)
{
    unsigned char *p = (unsigned char *)&a->sub2a4;
    p[12] = 7;
    a->b6++;
    func_0c18f420(a, 1);
    a->s28 = 60;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->f96 = 2.1428571f;
    a->f108 = -0.066964284f;
    func_0c02a684(a, 0, table_0c23fdbc[a->b37], 1);
    func_0c02a0c4(a, 20, 5);
}

void func_0c061f22(struct Actor *a)
{
    struct ActorSubControlBytes *p = (struct ActorSubControlBytes *)&a->sub2a4;
    float zero;
    p->b12 = 7;
    zero = 0.0f;
    if (--a->s28 == 0) {
        int none = 0;
        p->b12 = none;
        func_0c02a39a(a, none);
        a->f92 = zero;
        a->f96 = zero;
        a->f104 = zero;
        a->f108 = zero;
        a->f108 = -0.80357140303f;
        a->b6++;
        a->b7 = 0;
        func_0c02a0c4(a, 1, 9);
    } else {
        if (!a->b140) {
            a->f56 += a->f96;
            a->f96 += a->f108;
        }
        if (a->f96 < 0.0f) {
            a->f96 = zero;
            a->f108 = zero;
        }
        func_0c02a026(a);
    }
}

void func_0c061fbe(struct Actor *a)
{
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f56 < a->f41c) {
        a->b7++;
        a->f56 = a->f41c;
        func_0c043324(a);
        func_0c02a0c4(a, 1, 3);
    }
}
