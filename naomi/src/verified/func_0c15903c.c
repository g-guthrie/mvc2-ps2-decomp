/* Actor state dispatcher and its aligned literal pool. */
#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler dat_0c2508d8[];

void func_0c15903c(struct Actor *a)
{
    dat_0c2508d8[a->b4](a);
}
