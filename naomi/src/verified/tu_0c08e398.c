#include "objects.h"

struct ActorFlagsGlobal { unsigned char pad[5]; unsigned char b5, b6; };
typedef void (*ActorHandler)(struct Actor *);

extern struct ActorFlagsGlobal dat_0c2d9260;
extern ActorHandler table_0c242940[], table_0c24294c[];
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c14205c(struct Actor *, int, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);

void func_0c08e464(struct Actor *a, struct Actor *b);

void func_0c08e398(struct Actor *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    if (func_0c02a026(a) < 0) {
        a->b3f9 = 0;
        a->b3f8 = 0;
        a->b327 = 0;
        a->b328 = 0;
        func_0c0437b8(a);
        return;
    }
    if (a->b141 & 1) {
        a->b141 &= 0xfe;
        func_0c14205c(a, 0, 0);
        dat_0c2d9260.b5 = 3;
        dat_0c2d9260.b6 = 1;
    }
}

void func_0c08e400(struct Actor *a)
{
    table_0c242940[a->b6](a);
}

void func_0c08e412(struct Actor *a, struct Actor *b)
{
    a->b6++;
    func_0c0442fa(a);
    func_0c02a39a(a, 0);
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b1f9 = 0;
    a->f56 = a->f41c;
    func_0c02a0c4(a, 20, 2);
    func_0c08e464(a, b);
}

void func_0c08e464(struct Actor *a, struct Actor *b)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c08e486(struct Actor *a)
{
    table_0c24294c[a->b6](a);
}
