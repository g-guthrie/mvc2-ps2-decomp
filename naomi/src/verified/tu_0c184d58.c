#include "objects.h"

extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c037688(struct Actor *);

void func_0c184d58(struct Actor *a)
{
    struct Actor *p = a->p20;
    char *s = (char *)p + 0xcc;
    func_0c02a026(a);
    a->f52 = p->f52;
    a->f56 = p->f56;
    if (s[4]) {
        a->b5++;
        func_0c02a0c4(a, 22, 27);
    }
}

void func_0c184da6(struct Actor *a, struct Actor *b)
{
    struct Actor *p = a->p20;
    char *s1 = (char *)p + 0xcc;
    char *s2 = (char *)&b->sub2a4;
    func_0c02a026(a);
    a->f52 = p->f52;
    a->f56 = p->f56;
    if (s2[13])
        a->b12c = 0;
    if (s1[4] == 0)
        a->b4++;
}

void func_0c184df6(struct Actor *a)
{
    a->b4++;
    a->b12c = 0;
}

void func_0c184e04(struct Actor *a)
{
    a->b12c = 0;
    func_0c037688(a);
}
