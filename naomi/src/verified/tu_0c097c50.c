#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c0442fa(struct Actor *);
extern int func_0c02a39a(struct Actor *, int);
extern void func_0c025900(struct Actor *, int, int);
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c0429a4(struct Actor *, struct LinkedActorVec3 *, int);
void func_0c097ce6(struct Actor *a);
void func_0c097c50(register struct Actor *a)
{
    register void *zero;
    if (a->b255 == 6) {
        a->b3f0 = 255;
        a->b3f1 = 16;
    }
    a->b6++;
    zero = 0;
    ((struct ActorCountdowns *)a)->l2e4 = (int)zero;
    func_0c0442fa(a);
    func_0c02a39a(a, (int)zero);
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->f56 = a->f41c;
    a->b1fc = (int)zero;
    a->b1f9 = (int)zero;
    a->b1a1 = 57;
    a->w1ac = (int)zero;
    a->b19e = (int)zero;
    *(unsigned int *)&a->p1c4 = (unsigned int)zero;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 22, (int)zero);
    func_0c0432ca(a);
    func_0c097ce6(a);
}
void func_0c097ce6(struct Actor *a)
{
    struct LinkedActorVec3 v;
    a->b3f8 = 2;
    a->b328 = 5;
    a->b3f1 = a->b255 == 6 ? 2 : 0;
    func_0c02a026(a);
    if (a->b141) {
        a->b6++;
        if (a->b2 == 0)
            func_0c025900(a, 13, 3);
        else
            func_0c025900(a, 13, 4);
        a->b3f0 = 0;
        a->b3f1 = 0;
        v.x = 20.0f;
        v.y = 231.42856f;
        v.z = 0.0f;
        func_0c0429a4(a, &v, 1);
    }
}
