/* Actor state routines; reviewed span 0x0c11d58c..0x0c11d820. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c02a684(struct Actor *, int, int, int);
extern int func_0c02849a(void);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c0429a4(struct Actor *, struct LinkedActorVec3 *, int);
extern void func_0c17d144(struct Actor *);
extern struct ActorSub2a4 *dat_0c2fb2f0;
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*dat_0c24d058[])(struct Actor *);
extern void (*dat_0c24d084[])(struct Actor *);
extern void (*dat_0c24d098[])(struct Actor *);
void func_0c11d75c(struct Actor *a);

void func_0c11d58c(struct Actor *a)
{
    func_0c02a684(a, 2, 17, 1);
    func_0c02a0c4(a, 19, func_0c02849a() & 1);
}
void func_0c11d5b0(struct Actor *a)
{
    func_0c02a0c4(a, 19, 2);
}
void func_0c11d5b8(struct Actor *a)
{
    func_0c02a0c4(a, 19, 3);
}
void func_0c11d5c0(struct Actor *a)
{
    func_0c02a026(a);
}
void func_0c11d5c6(struct Actor *a)
{
    dat_0c2fb2f0 = &a->sub2a4;
    dat_0c24d058[a->b1e9](a);
}
void func_0c11d5e4(struct Actor *a)
{
    dat_0c24d084[a->b6](a);
}
void func_0c11d5f6(struct Actor *a)
{
    void *zero;
    if (a->b255 == 6) {
        a->b3f0 = 0xff;
        a->b3f1 = 16;
    }
    a->b6++;
    func_0c0442fa(a);
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    zero = 0;
    a->b1a1 = (int)zero;
    a->w1ac = (int)zero;
    a->b19e = (int)zero;
    *(unsigned int *)&a->p1c4 = (unsigned int)zero;
    dat_0c2f83f8->arr[a->b2]++;
    a->f56 = a->f41c;
    a->b1f9 = (int)zero;
    func_0c0432ca(a);
    func_0c02a0c4(a, 22, (int)zero);
}
void func_0c11d678(struct Actor *a)
{
    struct LinkedActorVec3 v;
    a->b3f8 = 2;
    a->b328 = 5;
    a->b3f1 = (a->b255 == 6) ? 2 : 0;
    a->b328 = 5;
    if (a->b141) {
        a->b6++;
        a->s28 = 0x80;
        a->s30 = 6;
        a->b141 = 0;
        v.x = -11.666666031f;
        v.y = 197.142853f;
        v.z = 0.0f;
        func_0c0429a4(a, &v, 1);
    } else {
        func_0c02a026(a);
    }
}
void func_0c11d728(struct Actor *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    a->b328 = 5;
    a->b6++;
    func_0c02a684(a, 2, 10, 1);
    func_0c0346da(a, 77);
    func_0c11d75c(a);
}
void func_0c11d75c(struct Actor *a)
{
    struct ActorSub2a4Grab *s = (struct ActorSub2a4Grab *)&a->sub2a4;
    int five;
    s->b9 = 4;
    five = 5;
    a->b3f8 = 2;
    a->b328 = five;
    a->b328 = five;
    func_0c02a026(a);
    if (--a->s28 == 0) {
        a->b3f9 = 0;
        a->b3f8 = 0;
        a->b327 = 0;
        a->b328 = 0;
        a->b6++;
        func_0c02a0c4(a, 22, 1);
    } else if (--a->s30 == 0) {
        a->s30 = five;
        func_0c17d144(a);
    }
}
void func_0c11d7da(struct Actor *a)
{
    dat_0c24d098[a->b6](a);
}
