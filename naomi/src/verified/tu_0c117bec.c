#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c1ba1a0(struct Actor *, int, int);
extern void func_0c043324(struct Actor *);
extern int func_0c02849a(struct Actor *);
extern ActorHandler table_0c24cadc[];
extern ActorHandler table_0c24caf8[];

void func_0c117bec(struct Actor *a)
{
    func_0c02a026(a);
    if (--a->s28 == 0) {
        a->b6++;
        a->f56 = a->f41c;
        a->f96 = 17.142857f;
        a->f108 = -1.0714286f;
        func_0c02a0c4(a, 18, 9);
        func_0c1ba1a0(a, 0, 0);
    }
}

void func_0c117c3e(struct Actor *a)
{
    func_0c02a026(a);
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f41c < a->f56)
        return;
    a->f56 = a->f41c;
    a->b5++;
    func_0c043324(a);
}

void func_0c117c8c(struct Actor *a)
{
    table_0c24cadc[a->b6](a);
}

void func_0c117c9e(struct Actor *a)
{
    if (!(func_0c02849a(a) & 1))
        a->b158 = 0;
    else
        a->b158 = 1;
    func_0c02a0c4(a, 19, a->b158);
    a->b6++;
}

void func_0c117cd2(struct Actor *a)
{
    func_0c02a026(a);
}

void func_0c117cd8(struct Actor *a)
{
    table_0c24caf8[a->b6](a);
}

void func_0c117cea(struct Actor *a)
{
    if (a->b6 == 0) {
        a->b6++;
        func_0c02a0c4(a, 19, 2);
    } else {
        func_0c02a026(a);
    }
}

void func_0c117d04(struct Actor *a)
{
    if (a->b6 == 0) {
        a->b6++;
        func_0c02a0c4(a, 19, 0);
    } else {
        func_0c02a026(a);
    }
}
