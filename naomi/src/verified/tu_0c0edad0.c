#include "objects.h"
typedef void (*ActorHandler)(struct Actor *);
extern struct ActorFlags *dat_0c2d6f84;
extern char dat_0c2f837e;
extern unsigned char dat_0c249e34[], dat_0c249e3c[];
extern ActorHandler table_0c249e00[];
extern ActorHandler table_0c249e14[];
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern int func_0c03916c(struct Actor *);
extern void func_0c0437b8(struct Actor *);

void func_0c0edad0(struct Actor *a)
{
    if (func_0c03916c(a)) {
        func_0c0437b8(a);
    } else {
        table_0c249e00[a->b32](a);
    }
}

void func_0c0edafc(struct Actor *a){table_0c249e14[a->b6](a);}

void func_0c0edb0e(struct Actor *a)
{
    int m = 7;
    struct ActorFlags *g = dat_0c2d6f84;
    if (dat_0c2f837e) a->s28 = dat_0c249e34[g->flags & m]; else a->s28 = dat_0c249e3c[g->flags & m];
    switch (a->s28) {
    case 0: a->b6++; a->s30 = 60; func_0c02a0c4(a, 19, 0); break;
    case 1: a->b6 = 3; func_0c02a0c4(a, 19, 1); break;
    case 2: a->b6 = 4; func_0c02a0c4(a, 21, 5); break;
    }
}

void func_0c0edb72(struct Actor *a)
{
    if ((a->s30 = a->s30 - 1) == 0) {
        a->b6++; a->s30 = 60; func_0c02a0c4(a, 19, 4);
    }
    func_0c02a026(a);
}

void func_0c0edba2(struct Actor *a){func_0c02a026(a);}

void func_0c0edba8(struct Actor *a){func_0c02a026(a);}
