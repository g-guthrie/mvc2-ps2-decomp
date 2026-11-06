#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
typedef void (*ActorSubHandler)(struct Actor *, struct ActorSub2a4 *);
extern ActorHandler table_0c2406f4[];
extern ActorSubHandler table_0c240700[];
extern char func_0c02a026(struct Actor *);
extern void func_0c1385f8(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c137500(struct Actor *, int);

void func_0c0694bc(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        a->b5++;
}
void func_0c0694dc(struct Actor *a) { table_0c2406f4[a->b7](a); }
void func_0c0694ee(struct Actor *a)
{
    a->b7++;
    func_0c1385f8(a, 3);
    a->s28 = 24;
    func_0c02a0c4(a, 0, 0);
}
void func_0c069514(struct Actor *a)
{
    func_0c02a026(a);
    if (--a->s28 == 0) {
        a->b7++;
        func_0c02a0c4(a, 18, 3);
    }
}
void func_0c069544(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        a->b5++;
}
void func_0c069564(struct Actor *a)
{
    table_0c240700[a->b7](a, &a->sub2a4);
}
void func_0c06957a(struct Actor *a, struct ActorSub2a4 *sub)
{
    a->b7++;
    *(float *)((char *)sub + 16) = a->f52;
    *(float *)((char *)sub + 20) = a->f56;
    a->f52 += a->b1d2 ? 640.0f : -640.0f;
    a->b1d2 ^= 1;
    a->w130 = (unsigned char)a->b1d2;
    ((unsigned char *)sub)[4] = 1;
    func_0c137500(a, 5);
    a->s28 = 48;
    func_0c02a0c4(a, 10, 1);
}
void func_0c0695ea(struct Actor *a)
{
    if (--a->s28 == 0) {
        a->b7++;
        func_0c02a0c4(a, 21, 2);
    }
}
