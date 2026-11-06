#include "objects.h"
struct Actor *func_0c0d995e(struct Actor *a);
extern char func_0c02a026(struct Actor*);
extern void func_0c02a0c4(struct Actor*,int,int);
extern void func_0c043324(struct Actor*);
extern void func_0c0439c4(struct Actor*);
extern unsigned char func_0c044e52(struct Actor*);
typedef struct Actor *(*ActorFactory_0c0d995e)(struct Actor *);
extern ActorFactory_0c0d995e table_0c248aa0[];
extern void func_0c02a39a(struct Actor *, int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c0d98c4(struct Actor *a);
void func_0c0d9932(struct Actor*a);
struct Actor *func_0c0d995e(struct Actor *a);

void func_0c0d9840(struct Actor *a)
{
    func_0c02a39a(a, 0);
    a->b6++;
    a->b1f9 = 2;
    a->f56 += 102.85714f;
    a->f92 = 26.666666031f;
    if (!a->b1d2)
        a->f92 = -a->f92;
    a->f104 = 0;
    a->f96 = 0;
    a->f108 = -0.5357143f;
    a->b1a1 = 65;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 20, 3);
}

void func_0c0d98c4(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c044e52(a)) {
        a->b6++;
        func_0c043324(a);
        func_0c02a0c4(a, 20, 4);
    }
}

void func_0c0d9932(struct Actor*a){if(func_0c02a026(a)<0)func_0c0439c4(a);else if(a->b141)a->b141=0;}

struct Actor *func_0c0d995e(struct Actor *a)
{
    return table_0c248aa0[a->b1f9](a);
}
