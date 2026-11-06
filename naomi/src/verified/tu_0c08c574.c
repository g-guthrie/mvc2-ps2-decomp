#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c196c1c(struct Actor *, int, int);
extern int func_0c02849a(struct Actor *);

struct Glob_08c574 {
    unsigned char pad[5];
    unsigned char b5;
    unsigned char b6;
};
extern struct Glob_08c574 dat_0c2d9260;
extern ActorHandler table_0c24279c[];

void func_0c08c574(struct Actor *a)
{
    a->b6 = a->b6 + 1;
    a->b12c = 1;
    a->f56 += 480.0f;
    a->f92 = 0.0f;
    a->f104 = 0.0f;
    a->f96 = -8.5714283f;
    a->f108 = -0.5357143f;
    a->b159 = 18;
    a->b158 = 0;
    func_0c02a0c4(a, a->b159, a->b158);
}

void func_0c08c5c6(struct Actor *a)
{
    func_0c02a026(a);
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f41c < a->f56)
        goto done;
    a->f56 = a->f41c;
    a->f96 = 0.0f;
    a->f108 = 0.0f;
    dat_0c2d9260.b5 = 3;
    dat_0c2d9260.b6 = 1;
    a->b159 = 18;
    a->b158 = 1;
    func_0c02a0c4(a, a->b159, a->b158);
    func_0c196c1c(a, 2, 0);
    func_0c196c1c(a, 2, 1);
    a->b6 = a->b6 + 1;
done:
    ;
}

void func_0c08c64a(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        a->b5++;
}

void func_0c08c66a(struct Actor *a)
{
    if ((func_0c02849a(a) & 1) == 0)
        a->b158 = 0;
    else
        a->b158 = 1;
    func_0c02a0c4(a, 19, a->b158);
    a->b6 = a->b6 + 1;
}

void func_0c08c69e(struct Actor *a)
{
    func_0c02a026(a);
}

void func_0c08c6a4(struct Actor *a)
{
    table_0c24279c[a->b6](a);
}
