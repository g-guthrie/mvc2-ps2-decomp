#include "objects.h"

struct Pos_0c1578a0 {
    unsigned char pad0[0x1f1];
    unsigned char b1f1;
    unsigned char pad1[0x2c4 - 0x1f2];
    int l2c4;
    unsigned char pad2[0x2cc - 0x2c8];
    int l2cc;
    int l2d0;
};

typedef void (*Handler_0c1578a0)(struct Actor *);
extern Handler_0c1578a0 table_0c250730[];
extern char func_0c02a026(struct Actor *);
extern void func_0c1a6308(struct Actor *, struct Pos_0c1578a0 *, int);
extern void func_0c037688(struct Actor *);

void func_0c1578a0(struct Actor *a, struct Pos_0c1578a0 *p)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c02a026(a) < 0) {
        func_0c1a6308(a, p, 3);
        a->b4 = 2;
        p->l2cc = 0;
        p->l2d0 = 0;
    }
}

void func_0c15790e(struct Actor *a, struct Pos_0c1578a0 *p)
{
    p->b1f1 = 2;
    p->l2c4 = 3;
    table_0c250730[a->b5](a);
}

void func_0c15792e(struct Actor *a, struct Pos_0c1578a0 *p)
{
    a->b4 = a->b4 + 1;
    a->b12c = 0;
    p->l2d0 = 0;
}

void func_0c157940(struct Actor *a, struct Pos_0c1578a0 *p)
{
    p->b1f1 = 0;
    func_0c037688(a);
}
