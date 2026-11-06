/* Spot effect spawned with a kind/sub pair: copies the owner's draw block, offsets
 * from the 0x0c25575c spot table, then blinks with the 0xcc gauge as its timer. */
#include "objects.h"
#define A(p) ((struct Actor *)(p))
#define G(p) ((struct LinkedActorGauge_0c163a64 *)&(p)->wcc)
struct Spot_0c25575c { short x, y, dir, sound; };
extern struct LinkedActor *func_0c0374da(int, int, int);
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c0288a8(struct LinkedActor *, int);
extern void func_0c02a0c4(struct LinkedActor *, int, int);
extern void func_0c037d0c(struct LinkedActor *);
extern void func_0c037688(struct LinkedActor *);
extern void (*table_0c2557d8[])(struct LinkedActor *);
extern void (*table_0c2557dc[])(struct LinkedActor *, struct LinkedActor *);
extern void (*table_0c2557ec[])(struct LinkedActor *);
extern struct Spot_0c25575c table_0c25575c[];
extern unsigned char table_0c2557ac[][2];
extern short table_0c2557c0[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c183456(struct LinkedActor *a, struct LinkedActor *o);
void func_0c183678(struct LinkedActor *a, struct LinkedActor *o);
void func_0c18379e(struct LinkedActor *a);

struct LinkedActor *func_0c183408(struct LinkedActor *o, unsigned char kind, unsigned char sub)
{
    struct LinkedActor *a;
    if ((a = func_0c0374da(0, 1, 0)) != 0) {
        a->p16 = func_0c183456;
        a->w38 = 0x3700;
        a->p24 = o;
        a->b1 = o->b1;
        a->b32 = kind;
        a->b33 = sub;
    }
    return a;
}

void func_0c183456(struct LinkedActor *a, struct LinkedActor *o)
{
    o = a->p24;
    if (o->sdc.w158.bytes[1] != 21) {
        func_0c18379e(a);
        return;
    }
    table_0c2557d8[a->b32](a);
}

void func_0c18347e(struct LinkedActor *a, struct LinkedActor *o)
{
    table_0c2557dc[a->b4](a, o);
}

void func_0c1834a4(struct LinkedActor *a, struct LinkedActor *o)
{
    struct LinkedActorGauge_0c163a64 *g = G(a);
    a->b4++;
    a->sdc = o->sdc;
    a->sdc.b12c = 1;
    a->b2 = o->b2;
    a->b1 = o->b1;
    a->v80.x = o->v80.x;
    a->v80.y = o->v80.y;
    a->b1a3 = o->b1a3;
    a->b1a4 = o->b1a4;
    a->b48 = o->b48;
    a->v80 = o->v80;
    a->b36 = o->b36;
    a->sdc.b12c = 1;
    a->b49 = -1;
    A(a)->b1a1 = A(a)->b33 + 60;
    A(a)->w1ac = 0;
    A(a)->b19e = 0;
    A(a)->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    A(a)->b19c = 66;
    A(a)->b19d = 66;
    a->f52 = o->f52;
    a->f56 = o->f56;
    a->f60 = o->f60;
    if (!a->sdc.w130)
        a->f52 += table_0c25575c[A(a)->b33].x * 1.66666663f;
    else
        a->f52 -= table_0c25575c[A(a)->b33].x * 1.66666663f;
    a->f56 += table_0c25575c[A(a)->b33].y * 2.1428571f;
    a->b34 = table_0c25575c[A(a)->b33].dir;
    if (a->sdc.w130) {
        a->b34 = 32 - a->b34;
        a->b34 &= 31;
    }
    g->b0 = ((unsigned char *)table_0c2557ac)[A(a)->b33 * 2];
    g->b1 = table_0c2557ac[A(a)->b33][1];
    func_0c0288a8(a, table_0c2557c0[g->b1]);
    func_0c02a0c4(a, 23, table_0c25575c[A(a)->b33].sound);
    a->s28 = 20;
    func_0c183678(a, o);
}

void func_0c183678(struct LinkedActor *a, struct LinkedActor *o)
{
    a->b36 = o->b36;
    table_0c2557ec[A(a)->b5](a);
}

void func_0c183692(struct LinkedActor *a)
{
    struct LinkedActorGauge_0c163a64 *g = G(a);
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (--a->s28 == 0) {
        a->b4++;
        return;
    }
    if (--g->b0 == 0) {
        g->b0 = 2;
        if (g->b1)
            g->b1--;
        func_0c0288a8(a, table_0c2557c0[g->b1]);
    }
    if (A(a)->b19f)
        goto n;
    func_0c037d0c(a);
    if (A(a)->b19e) {
n:
        a->b5++;
        a->s28 = 16;
    }
}

void func_0c183764(struct LinkedActor *a)
{
    func_0c02a026(a);
    a->sdc.b12c ^= 1;
    if (--a->s28 == 0)
        a->b4++;
}

void func_0c183790(struct LinkedActor *a)
{
    a->b4++;
    a->sdc.b12c = 0;
}

void func_0c18379e(struct LinkedActor *a)
{
    a->sdc.b12c = 0;
    func_0c037688(a);
}
