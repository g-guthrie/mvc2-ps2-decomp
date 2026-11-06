/* Ten actor callbacks, with the near movement helper and both pools. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *), func_0c0438de(struct Actor *);
extern void (*dat_0c24cb20[])(struct Actor *, char *);
extern void (*dat_0c24cb34[])(struct Actor *, char *);
extern void (*dat_0c24cb48[])(struct Actor *, char *);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c1ba1a0(struct Actor *, int, int);
extern void func_0c179178(struct Actor *, int, int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c118108(struct Actor *, char *);
void func_0c118212(struct Actor *);
void func_0c118048(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}
void func_0c11806a(struct Actor *a, char *sub)
{
    dat_0c24cb20[a->b7](a, sub);
}
void func_0c11807c(struct Actor *a, char *sub)
{
    a->b7++;
    func_0c048bb0(a, 5);
    func_0c0442fa(a);
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->f96 = -2.1428571f;
    *sub = 0;
    a->b1a1 = a->b1a3 + 48;
    a->w1ac = 0;
    a->b19e = 0;
    *(void **)&a->p1c4 = (void *)0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 21, a->b1a3 + 4);
    a->s30 = a->b141;
    a->b141 = 0;
    func_0c118108(a, sub);
}
void func_0c118108(struct Actor *a, char *sub)
{
    func_0c118212(a);
    func_0c02a026(a);
    if (a->b141) {
        a->b7++;
        a->s28 = 10;
        func_0c1ba1a0(a, 2, 1);
    }
}
void func_0c11813c(struct Actor *a)
{
    func_0c118212(a);
    func_0c02a026(a);
    if (--a->s28 == 0) {
        a->b7++;
        func_0c179178(a, 0, 1);
    }
}
void func_0c11819c(struct Actor *a, char *sub)
{
    func_0c118212(a);
    func_0c02a026(a);
    if (--a->s30 == 0) {
        a->b7++;
        a->s28 = 28;
        *sub = 1;
    }
}
void func_0c1181d4(struct Actor *a)
{
    func_0c118212(a);
    func_0c02a026(a);
    if (a->s28-- == 0)
        func_0c0438de(a);
}
void func_0c118200(struct Actor *a, char *sub)
{
    dat_0c24cb34[a->b7](a, sub);
}
void func_0c118212(struct Actor *a)
{
    if (!a->b201) {
        a->f56 += a->f96;
        a->f96 += a->f108;
    }
    if (a->f41c > a->f56)
        a->f56 = a->f41c;
}
void func_0c11824c(struct Actor *a, char *sub)
{
    if (a->b1f9 == 2)
        a->b6 = 1;
    dat_0c24cb48[a->b6](a, sub);
}
