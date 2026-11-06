/* Candidate: func_0c09aa22 uses r2 instead of r3 for the func_0c1476d0 call target (378/380); other functions exact. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c0437b8(struct Actor *);
extern void func_0c1476d0(struct Actor *, int);
extern void (*table_0c243510[])(struct Actor *, struct ActorSub2a4 *);
extern void (*table_0c243518[])(struct Actor *);

void func_0c09a95c(struct Actor *a)
{
    if (func_0c02a026(a) < 0) func_0c0437b8(a);
}

void func_0c09a97e(struct Actor *a)
{
    table_0c243510[a->b6](a, &a->sub2a4);
}

void func_0c09a994(register struct Actor *a)
{
    register void *zero;
    a->b6++;
    zero = 0;
    if (a->b1a3)
        a->b1a1 = 70;
    else {
        goto L; L: a->b1a1 = 50; }
    a->w1ac = (int)zero;
    a->b19e = (int)zero;
    *(unsigned int *)&a->p1c4 = (unsigned int)zero;
    dat_0c2f83f8->arr[a->b2]++;
    goto M; M:
    func_0c048bb0(a, 5);
    func_0c0442fa(a);
    a->f56 = a->f41c;
    a->b1f9 = (int)zero;
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    func_0c0432ca(a);
    func_0c02a39a(a, 0);
    func_0c02a0c4(a, 21, 5);
}

void func_0c09aa22(struct Actor *a)
{
    if (func_0c02a026(a) >= 0) {
        if (a->b141) {
            a->b141 = 0;
            func_0c1476d0(a, a->b1a3 ? 2 : 0);
            goto D; D:
            a->b27b = 0;
            a->b27a = 16;
            return;
        }
    } else {
        a->f92 = 0;
        a->f96 = 0;
        a->f104 = 0;
        a->f108 = 0;
        func_0c0437b8(a);
    }
}

void func_0c09aa88(struct Actor *a)
{
    table_0c243518[a->b6](a);
}
