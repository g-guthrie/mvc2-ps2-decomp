#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c025900(struct Actor *,char,char);
extern void func_0c04b02a(struct Actor *);
extern void func_0c1ceafe(struct Actor *,struct LinkedActorVec3 *);
extern void func_0c034946(struct Actor *,int);
extern void func_0c03edcc(struct Actor *,struct Actor *);
extern void func_0c03f004(struct Actor *,struct Actor *);
extern void func_0c045248(struct Actor *,int);
extern const unsigned char dat_0c248f3c[];

void func_0c0dec0c(struct Actor *a)
{
    struct LinkedActorVec3 v;
    func_0c02a026(a);
    if (!a->b141) return;
    func_0c025900(a, 0, 0);
    a->b6++;
    a->b141 = 0;
    a->p1c8->p1b4 = a;
    a->p1c8->b1a1 = 34;
    func_0c04b02a(a);
    a->p1c8->b1f6 = 1;
    a->p1c8->b1a1 = 35;
    v.x = -106.666664124f;
    v.y = 137.142853f;
    func_0c1ceafe(a, &v);
    func_0c034946(a->p1c8, 1);
    a->f96 = 8.5714283f;
    a->f108 = -0.80357140303f;
    a->f92 = 6.66666651f;
    a->f104 = 0.0f;
    if (a->w130) a->f92 = -a->f92;
}

void func_0c0decb8(struct Actor *a)
{
    float d;
    if (a->p1c8->b14b > 0) func_0c03edcc(a->p1c8, a);
    else func_0c03f004(a->p1c8, a);
    if (a->b1f6) return;
    if (!a->p1c8->b140) return;
    a->p1c8->b140 = 0;
    d = 0.0f;
    if (((char *)&a->p1c8->w150)[1] == 1) d = 1.0f;
    if (((char *)&a->p1c8->w150)[1] == 2) d = -1.0f;
    if (!a->p1c8->w130) d = -d;
    a->f52 += d;
}

void func_0c0ded74(struct Actor *a)
{
    a->b6 = a->b7 = a->b5 = 0;
    a->b1e9 = dat_0c248f3c[a->b4c9 + a->i204 * 3];
    func_0c045248(a, 29);
}

void func_0c0ded9a(struct Actor *a)
{
    a->b6 = a->b7 = a->b5 = 0;
    a->b1e9 = (dat_0c248f3c + 6)[a->b4c9 + a->i204 * 3];
    func_0c045248(a, 29);
}

void func_0c0dedc0(struct Actor *a)
{
    a->b6 = a->b7 = a->b5 = 0;
    switch (a->b4c9) {
    case 0: a->b1e9 = 0; goto s;
    case 1: a->b1e9 = 5; goto s;
    case 2: a->b1e9 = 1;
    s: a->b1a3 = 1;
    }
    goto t; t: func_0c045248(a, 21);
}
