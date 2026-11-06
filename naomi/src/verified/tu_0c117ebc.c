/* Five actor callbacks and their final shared literal pool. */
#include "objects.h"
extern void (*dat_0c24cb14[])(struct Actor *, char *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0442fa(struct Actor *), func_0c0432ca(struct Actor *);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c1ba1a0(struct Actor *, int, int);
extern void func_0c179178(struct Actor *, int, int);
void func_0c117f6a(struct Actor *, char *);
void func_0c117ebc(struct Actor *a, char *sub)
{
    dat_0c24cb14[a->b6](a, sub);
}
void func_0c117ece(struct Actor *a, char *sub)
{
    a->b7++;
    func_0c048bb0(a, 5);
    func_0c0442fa(a);
    func_0c0432ca(a);
    func_0c02a39a(a, 0);
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b1f9 = 0;
    a->f56 = a->f41c;
    *sub = 0;
    a->b1a1 = a->b1a3 + 48;
    a->w1ac = 0;
    a->b19e = 0;
    *(void **)&a->p1c4 = (void *)0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 21, a->b1a3);
    a->s30 = a->b141;
    a->b141 = 0;
    func_0c117f6a(a, sub);
}
void func_0c117f6a(struct Actor *a, char *sub)
{
    func_0c02a026(a);
    if (a->b141) {
        a->b7++;
        a->s28 = 10;
        func_0c1ba1a0(a, 2, 0);
    }
}
void func_0c117f9a(struct Actor *a, char *sub)
{
    func_0c02a026(a);
    if (--a->s28 == 0) {
        a->b7++;
        func_0c179178(a, 0, 0);
        a->b27a = 16;
        a->b27b = 0;
    }
}
void func_0c117fd2(struct Actor *a, char *sub)
{
    func_0c02a026(a);
    if (--a->s30 == 0) {
        a->b7++;
        *sub = 1;
        func_0c02a0c4(a, 21, a->b1a3 + 2);
    }
}
