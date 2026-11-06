#include "objects.h"

extern char func_0c02a026(struct Actor *);
extern void func_0c037688(struct Actor *);

void func_0c185618(struct Actor *a, struct Actor *b)
{
    unsigned char *sub = (unsigned char *)b + 0x2a4;
    func_0c02a026(a);
    a->f52 = b->f52;
    a->f56 = b->f56;
    if (b->b6 == 1) {
        struct Actor *linked = b->p20c;
        a->f56 = linked->f56;
        a->f56 -= 17.142857f;
    }
    if (sub[19]) {
        a->b12c = 0;
        a->b4++;
    }
}

void func_0c18567a(struct Actor *a)
{
    a->b4++;
    a->b12c = 0;
}

void func_0c185688(struct Actor *a)
{
    a->b12c = 0;
    func_0c037688(a);
}
