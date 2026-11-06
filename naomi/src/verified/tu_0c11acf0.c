/* Three actor callbacks and their shared literal pool, 372 bytes. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *), func_0c0438de(struct Actor *);
extern void (*dat_0c24ce00[])(struct Actor *, struct ActorSub2a4 *);
extern void func_0c0442fa(struct Actor *), func_0c0432ca(struct Actor *);
extern void func_0c0344a0(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c11acf0(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f56 < a->f41c)
        a->f56 = a->f41c;
    if (func_0c02a026(a) >= 0)
        return;
    if (!a->b7) {
        func_0c0437b8(a);
        return;
    }
    a->f108 = -0.80357140303f;
    func_0c0438de(a);
}
void func_0c11ad78(struct Actor *a)
{
    dat_0c24ce00[a->b6](a, &a->sub2a4);
}
void func_0c11ad8e(struct Actor *a, char *sub)
{
    if (a->b255 == 6) {
        a->b3f0 = 255;
        a->b3f1 = 16;
    }
    a->b6++;
    sub[11] = 0;
    sub[12] = 0;
    sub[13] = 0;
    sub[14] = 0;
    sub[15] = 0;
    sub[10] = 16;
    func_0c0442fa(a);
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b1f9 = 0;
    a->f56 = a->f41c;
    func_0c0432ca(a);
    a->b1a1 = 46;
    a->w1ac = 0;
    a->b19e = 0;
    *(void **)&a->p1c4 = (void *)0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c0344a0(a, 22);
    func_0c02a0c4(a, 22, 0);
}
