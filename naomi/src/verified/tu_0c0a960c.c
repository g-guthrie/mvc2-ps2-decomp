#include "objects.h"
extern void func_0c042018(struct Actor *);
extern void (*table_0c2444f8[])(struct Actor *, struct ActorSub2a4 *);
extern void (*table_0c244504[])(struct Actor *, struct ActorSub2a4 *);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a0c4(struct Actor *, unsigned char, unsigned char);
extern char func_0c02a026(struct Actor *);
extern void func_0c0429a4(struct Actor *, struct LinkedActorVec3 *, int);
extern void func_0c150268(struct Actor *, int);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0438de(struct Actor *);
void func_0c0a960c(struct Actor *a)
{
    if (a->b1f9 == 2) {
        func_0c042018(a);
        if (a->f56 < a->f41c) a->f56 = a->f41c;
    }
    table_0c2444f8[a->b6](a, &a->sub2a4);
}
void func_0c0a964c(struct Actor *a, struct ActorSub2a4 *unused)
{
    func_0c02a39a(a, 0);
    if (a->b255 == 6) {
        a->b3f0 = 0xff;
        a->b3f1 = 16;
    }
    a->b6++;
    if (a->b1f9 == 2) {
        a->f92 /= 16.0f;
        a->f96 /= 8.0f;
        a->f108 /= 64.0f;
        a->f104 = 0;
    }
    func_0c0442fa(a);
    a->b1a1 = 57;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    if (a->b1f9 == 0) {
        func_0c0432ca(a);
        func_0c02a0c4(a, 22, 0);
    } else func_0c02a0c4(a, 22, 64);
}
void func_0c0a9706(struct Actor *a, struct ActorSub2a4 *unused)
{
    struct LinkedActorVec3 position;
    float zero;
    a->b3f1 = a->b255 == 6 ? 2 : 0;
    if (func_0c02a026(a) >= 0) {
        a->b6++;
        a->b3f0 = 0;
        a->b3f1 = 0;
        zero = 0;
        if (a->b1f9 == 2) {
            func_0c02a0c4(a, 22, 65);
            position.x = zero;
            /* Retail adds to this stack slot without initializing it. */
            position.y += 94.2857132f;
        } else {
            goto L1; L1:
            func_0c02a0c4(a, 22, 1);
            position.x = zero;
            position.y += 51.42857f;
        }
        func_0c0429a4(a, &position, 1);
    }
}
void func_0c0a97c2(struct Actor *a, struct ActorSub2a4 *unused)
{
    a->b3f8 = 2;
    a->b328 = 5;
    if (func_0c02a026(a) < 0) {
        a->b3f9 = 0;
        a->b3f8 = 0;
        a->b327 = 0;
        a->b328 = 0;
        if (a->b1f9 == 0) func_0c0437b8(a);
        else { goto L2; L2: func_0c0438de(a); }
    } else { goto L3; L3: if (a->b141) {
        a->b141 = 0;
        func_0c150268(a, 0);
    }}
}
void func_0c0a9834(struct Actor *a)
{
    if (a->b1f9 == 2) {
        func_0c042018(a);
        if (a->f56 < a->f41c) a->f56 = a->f41c;
    }
    table_0c244504[a->b6](a, &a->sub2a4);
}
