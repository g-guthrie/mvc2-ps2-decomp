#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern int func_0c043628(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern unsigned int func_0c02849a(void);
extern void func_0c192784(struct Actor *, short);
extern int func_0c03916c(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern char dat_0c2416ef[], dat_0c2416ec[];
extern void (*table_0c2416f4[])(struct Actor *);
extern void (*table_0c241710[])(struct Actor *);
void func_0c07bb58(struct Actor *);
void func_0c07bbcc(struct Actor *);
void func_0c07bb28(struct Actor *a)
{
    if (func_0c02a026(a) < 0) { a->b5++; a->w130 = a->b1d2; }
}
void func_0c07bb4e(struct Actor *a)
{
    if (a->b6 == 0) func_0c07bb58(a);
    else func_0c07bbcc(a);
}
void func_0c07bb58(struct Actor *a)
{
    int animation;
    a->b6++;
    if (func_0c043628(a) >= 2) { func_0c02a0c4(a, 19, 2); return; }
    animation = dat_0c2416ef[a->b32];
    if (!a->b32) {
        a->s28 = func_0c02849a() % 3U;
        animation = dat_0c2416ec[a->s28];
        if (a->s28 != 2) func_0c192784(a, a->s28);
    }
    func_0c02a0c4(a, 19, animation);
}
void func_0c07bbcc(struct Actor *a)
{
    func_0c02a026(a);
    if (func_0c03916c(a)) func_0c0437b8(a);
}
void func_0c07bbf0(struct Actor *a) { table_0c2416f4[a->b1e9](a); }
void func_0c07bc04(struct Actor *a) { table_0c241710[a->b6](a); }
