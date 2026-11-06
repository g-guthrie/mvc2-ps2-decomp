#include "objects.h"

struct ActorCompanionRef_0c08532c { unsigned char pad[4]; struct Actor *p4; };
typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c242114[];
extern ActorHandler table_0c24211c[];
extern ActorHandler table_0c242128[];
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0445fe(struct Actor *, struct Actor *);
extern void func_0c04bad8(struct Actor *, struct Actor *);
extern void func_0c025900(struct Actor *, int, int);
extern void func_0c043324(struct Actor *);
extern void func_0c044f1c(struct Actor *);

void func_0c08532c(struct Actor *a, struct ActorCompanionRef_0c08532c *ref)
{
    struct Actor *p = ref->p4;
    if (p->w420 == 0) {
        p->f96 = -0.80357140303f;
        func_0c0437b8(a);
        return;
    }
    a->b7++;
    func_0c02a0c4(a, 15, 3);
    a->b1f7 = 195;
    func_0c0445fe(a, p);
    func_0c04bad8(p, a);
    func_0c025900(a, 5, 5);
    p->b236 = 0;
}
void func_0c085390(struct Actor *a)
{
    func_0c02a026(a);
    if (a->b141 >= 0) {
        a->f52 += a->f92;
        a->f92 += a->f104;
        a->f56 += a->f96;
        a->f96 += a->f108;
    }
    if (a->f56 < a->f41c) {
        a->f56 = a->f41c;
        func_0c043324(a);
        func_0c044f1c(a);
    }
}
void func_0c085404(struct Actor *a)
{
    a->b7++;
    a->f96 = 51.42857f;
    a->f108 = -0.80357140303f;
    func_0c02a0c4(a, 22, 6);
}
void func_0c085422(struct Actor *a) { table_0c242114[a->b7](a); }
void func_0c085434(struct Actor *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    table_0c24211c[a->b7](a);
}
void func_0c085454(struct Actor *a)
{
    a->b1ea = 1;
    a->b1ed = 2;
    a->b1f5 = 2;
    a->b3f8 = 2;
    a->b328 = 5;
    table_0c242128[a->b7](a);
}
