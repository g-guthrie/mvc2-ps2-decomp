#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern struct ActorFlags *dat_0c2d6f84;
extern ActorHandler table_0c240418[];
extern ActorHandler table_0c24042c[];
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern int func_0c03916c(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern int func_0c043628(struct Actor *);
extern void func_0c190390(struct Actor *);

void func_0c065e80(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        a->b5++;
        func_0c02a0c4(a, 0, 0);
    }
}

void func_0c065eaa(struct Actor *a)
{
    if (func_0c03916c(a)) {
        func_0c0437b8(a);
    } else {
        table_0c240418[a->b32](a);
    }
}

void func_0c065ed6(struct Actor *a)
{
    if (a->b6 == 0) {
        a->b6++;
        if ((dat_0c2d6f84->b128 & 1) && func_0c043628(a) == 1) {
            func_0c02a0c4(a, 19, 0);
            func_0c190390(a);
            return;
        } else {
            func_0c02a0c4(a, 19, 1);
        }
    } else {
        func_0c02a026(a);
    }
}

void func_0c065f2a(struct Actor *a)
{
    if (a->b6 == 0) {
        a->b6++;
        func_0c02a0c4(a, 19, 5);
    } else {
        func_0c02a026(a);
    }
}

void func_0c065f44(struct Actor *a)
{
    if (a->b6 == 0) {
        a->b6++;
        func_0c02a0c4(a, 19, 4);
    } else {
        func_0c02a026(a);
    }
}

void func_0c065f5e(struct Actor *a)
{
    if (a->b6 == 0) {
        a->b6++;
        func_0c02a0c4(a, 19, 6);
    } else {
        func_0c02a026(a);
    }
}

void func_0c065f78(struct Actor *a)
{
    table_0c24042c[a->b1e9](a);
}
