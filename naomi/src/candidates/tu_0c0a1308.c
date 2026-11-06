/* Candidate: func_0c0a1372 still loads the func_0c0429a4 call target early (338/356); func_0c0a1308 exact; size exact. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c09e43a(struct Actor *);
extern void func_0c0429a4(struct Actor *, struct LinkedActorVec3 *, int);
extern float dat_0c2437e4[];
void func_0c0a1308(struct Actor *a);
void func_0c0a1372(struct Actor *a);

void func_0c0a1308(struct Actor *a)
{
    int z;
    a->b6++;
    if (a->b255 == 6) {
        a->b3f0 = 255;
        a->b3f1 = 16;
    }
    z = 0;
    a->b1a1 = 55;
    a->w1ac = z;
    a->b19e = z;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c0442fa(a);
    a->b1f9 = z;
    func_0c0432ca(a);
    func_0c02a0c4(a, 22, 1);
}

void func_0c0a1372(struct Actor *a)
{
    struct ActorSub2a4 *s = &a->sub2a4;
    struct LinkedActorVec3 position;
    goto L; L:
    func_0c09e43a(a);
    if (a->b141 == 1) {
        a->b141 = 0;
        position.x = -40.0f;
        position.y = 137.142853f;
        { int f = *(short *)s == 0; goto M; M: func_0c0429a4(a, &position, f); }
    }
    if (a->b141 == 2) {
        a->b6++;
        a->b141 = 0;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        a->s28 = 2;
        a->f92 = dat_0c2437e4[0];
        a->f104 = dat_0c2437e4[1];
        a->f92 = a->b1d2 ? -a->f92 : a->f92;
        a->f104 = a->b1d2 ? -a->f104 : a->f104;
        func_0c0432ca(a);
    }
    func_0c02a026(a);
}
