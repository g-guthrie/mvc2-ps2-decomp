#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern int func_0c1ec190(void);
extern short dat_0c2406cc[];
extern void (*table_0c2406c4[])(struct Actor *);
extern void (*table_0c2406d4[])(struct Actor *);
extern void (*table_0c2406e0[])(struct Actor *, struct ActorSub2a4 *);
extern void func_0c02a0c4(struct Actor *, int, int);
void func_0c0691e8(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}
void func_0c06920a(struct Actor *a)
{
    table_0c2406c4[a->b6](a);
}
void func_0c069242(struct Actor *a);
void func_0c06921c(struct Actor *a)
{
    a->b6++;
    a->b12c = 1;
    a->s30 = dat_0c2406cc[func_0c1ec190() & 3];
    func_0c069242(a);
}
void func_0c069242(struct Actor *a)
{
    table_0c2406d4[a->s30](a);
}
void func_0c069252(struct Actor *a)
{
    table_0c2406e0[a->b7](a, &a->sub2a4);
}
void func_0c069268(struct Actor *a, struct SolHorizontalTarget *target)
{
    a->b7++;
    target->x = a->f52;
    target->y = a->f56;
    a->f52 += a->b1d2 ? -320.0f : 320.0f;
    a->f56 += 171.42856f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->f92 = a->b1d2 ? 13.33333302f : -13.33333302f;
    a->f96 = -1.07142854f;
    a->s28 = 32;
    func_0c02a0c4(a, 18, 0);
}
