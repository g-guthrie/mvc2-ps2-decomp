#include "objects.h"

struct Vec3_0c0a2bb8 { float x, y, z; };
typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c243b04[];
extern char func_0c02a026(struct Actor *);
extern void func_0c1cea66(struct Actor *, struct Vec3_0c0a2bb8 *, int);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c025900(struct Actor *, int, int);
extern void func_0c0437b8(struct Actor *);
extern void func_0c03edcc(struct Actor *, struct Actor *);
extern void func_0c045248(struct Actor *, int);

void func_0c0a2bb8(struct Actor *a)
{
    struct Vec3_0c0a2bb8 v;
    struct Actor *b;
    if (func_0c02a026(a) >= 0) {
        if (a->b141) {
            v.x = -213.33333f;
            v.y = 188.57143f;
            func_0c1cea66(a, &v, 2);
            func_0c0346da(a, 3);
            func_0c025900(a, 0, 0);
            a->b141 = 0;
            b = a->p1c8;
            b->p1b4 = a;
            b->b1d2 = a->b1d2;
            b->b1a1 = 35;
            b->b1f6 = 1;
        }
    } else {
        a->f52 += a->w130 ? 106.666664124f : -106.666664124f;
        func_0c0437b8(a);
    }
}

void func_0c0a2c50(struct Actor *a)
{
    table_0c243b04[a->b1f7 & 63](a);
}

void func_0c0a2c68(struct Actor *a)
{
    func_0c03edcc(a->p1c8, a);
}

void func_0c0a2c76(struct Actor *a)
{
    a->b6 = a->b7 = a->b5 = 0;
    switch (a->b4c9) {
    case 0: a->b1e9 = 4; break;
    case 1: a->b1e9 = 3; break;
    case 2: a->b1e9 = 3; break;
    }
    func_0c045248(a, 29);
}
