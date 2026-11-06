#include "objects.h"
#define LA struct LinkedActor
struct EffectTrajectory_160e04 { int x_speed,y_speed; short x_offset,y_offset; unsigned char animation,effect,pad14,pad15; };
struct Tail19c {
    char b19c, b19d, b19e, b19f, pad1a0, b1a1, pad1a2[0x1ac - 0x1a2];
    short w1ac;
    char pad1ae[0x1c4 - 0x1ae];
    int l1c4;
};
#define T(a) ((struct Tail19c *)(a)->pad11)
extern LA *func_0c0374da(LA *, int, int);
extern void (*table_0c25152c[])(LA *);
extern void (*table_0c25153c[])(LA *);
extern void (*table_0c251550[])(struct Actor *);
extern struct EffectTrajectory_160e04 dat_0c2514dc[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a0c4(LA *, int, char);
extern char func_0c02a026(struct Actor *);
extern void func_0c037d0c(struct Actor *);
void func_0c160e32(LA *);
void func_0c160fce();
void func_0c161016(struct Actor *, struct Actor *);
void func_0c16102e(struct Actor *, struct Actor *);

LA *func_0c160e04(LA *a, unsigned char b)
{
    LA *q;
    if ((q = func_0c0374da(0, 1, 0)) != 0) {
        q->p16 = func_0c160e32;
        q->p24 = a;
        q->b32 = b;
    }
    return q;
}

void func_0c160e32(LA *a)
{
    table_0c25152c[a->b4](a);
}

void func_0c160e44(LA *a)
{
    LA *o;
    struct EffectTrajectory_160e04 *entry;
    a->b4++;
    a->w38 = 0x1d06;
    o = a->p24;
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
    a->b36 = 8;
    a->sdc.b12c = 1;
    entry = &dat_0c2514dc[a->b32];
    *(struct LinkedActorVec3 *)&a->f52 = *(struct LinkedActorVec3 *)&o->f52;
    if (!a->sdc.w130) { a->f52 += entry->x_offset * 1.66666663f; a->f92 = entry->x_speed * 1.66666663f / 65536.0f; }
    else { a->f52 += -(entry->x_offset * 1.66666663f); a->f92 = -(entry->x_speed * 1.66666663f / 65536.0f); }
    a->f56 += entry->y_offset * 2.1428571f;
    a->f96 = entry->y_speed * 2.1428571f / 65536.0f;
    a->f104 = 0.0f; a->f108 = 0.0f;
    T(a)->b19c = 68; T(a)->b19d = 68; T(a)->b1a1 = entry->effect;
    T(a)->w1ac = 0; T(a)->b19e = 0; T(a)->l1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 23, entry->animation);
    func_0c160fce(a);
}

void func_0c160fce(a, o)
LA *a, *o;
{
    o = a->p24;
    if (o->b4 >= 2) {
        a->b4++;
        a->sdc.b12c = 0;
        return;
    }
    table_0c25153c[a->b32](a);
}

void func_0c161004(struct Actor *a)
{
    table_0c251550[a->b5](a);
}

void func_0c161016(struct Actor *a, struct Actor *owner)
{
    a->b5++;
    ((struct MeActor *)a)->blk_dc.b13c = 16;((struct MeActor *)a)->blk_dc.b13d = 16;((struct MeActor *)a)->blk_dc.b13e = 16;((struct MeActor *)a)->blk_dc.b13f = 16;
    func_0c16102e(a, owner);
}

void func_0c16102e(struct Actor *a, struct Actor *owner)
{
    func_0c02a026(a);
    if (!a->b141) { a->b5 = a->b5 + 1; a->f52 += a->f92; a->f92 += a->f104; }
    func_0c037d0c(a);
}
