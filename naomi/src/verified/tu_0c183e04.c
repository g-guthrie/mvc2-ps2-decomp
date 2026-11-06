#include "objects.h"
typedef void (*Handler_183e04)(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern Handler_183e04 table_0c25586c[];

void func_0c183e04(struct Actor *a, struct Actor *b)
{
    unsigned char *s = (unsigned char *)&b->sub2a4;
    struct Actor *p = a->p20;
    a->f52 = p->f52 + a->f92;
    a->f56 = p->f56 + a->f96;
    func_0c02a026(a);
    if (s[13])
        a->b12c = 0;
}

void func_0c183e48(struct Actor *a)
{
    table_0c25586c[a->b4](a);
}
