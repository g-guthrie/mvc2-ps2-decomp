#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern int func_0c0427f2(struct Actor *);
extern int func_0c042780(struct Actor *);
extern void func_0c04b02a(struct Actor *);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c1cea66(struct Actor *, struct LinkedActorVec3 *, int);
extern void func_0c02a0c4(struct Actor *, int, int);

void func_0c0d6200(struct Actor *a)
{
    struct LinkedActorVec3 v;
    struct Actor *o = a->p1c8;

    func_0c02a026(a);
    if (func_0c0427f2(a)) a->b142 = 1;
    if (!a->s30) {
        if (func_0c042780(a->p1c8) || (!a->s30 && (!--a->s28 || (!a->s30 && !o->w420))))
            a->s30 = 1;
    }
    if (a->b141 == 0) {
    } else {
        if (a->b141 > 0) {
            o->b1a1 = (a->b141 & 1) ? 33 : 34;
            func_0c04b02a(a);
            func_0c0346da(a, 15);
            a->b141 = 0;
            v.x = -110.0f;
            v.y = 139.28571f;
            v.z = 0.0f;
            func_0c1cea66(a, &v, 1);
        } else if (a->s30) {
            a->b6++;
            func_0c02a0c4(a, 15, 1);
        }
    }
}
