/* Five actor callbacks and their shared literal pool at 0x0c0ae6ce. */
#include "objects.h"
typedef void (*ActorHandler)(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c0439c4(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern ActorHandler dat_0c244860[];
extern ActorHandler table_0c244884[];

void func_0c0ae584(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c044e52(a)) {
        a->b6++;
        func_0c02a0c4(a, 20, 1);
        func_0c043324(a);
    }
}

void func_0c0ae5f2(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        func_0c02a39a(a, 0);
        func_0c0439c4(a);
    } else if (a->b141)
        a->b141 = 0;
}

void func_0c0ae626(struct Actor *p)
{
    dat_0c244860[p->b1e9](p);
}

void func_0c0ae63a(struct Actor *a)
{
    table_0c244884[a->b6](a);
}

void func_0c0ae64c(struct Actor *a)
{
    a->b6++;
    a->b1f9 = 0;
    a->f56 = a->f41c;
    func_0c0442fa(a);
    func_0c0432ca(a);
    func_0c048bb0(a, 5);
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b1a1 = a->b1fe + 48;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c0442fa(a);
    func_0c02a0c4(a, 21, a->b1a3);
}
