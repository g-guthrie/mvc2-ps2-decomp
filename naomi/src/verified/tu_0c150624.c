#include "objects.h"

typedef void (*Handler_0c150624)(struct Actor *);
extern Handler_0c150624 table_0c250428[];

void func_0c150624(struct Actor *a)
{
    a->b36 = 11;
    table_0c250428[a->b5](a);
}
