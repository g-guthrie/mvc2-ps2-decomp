#include "objects.h"
struct Counter_0c0b9428 { unsigned char pad[2]; signed char b2; };

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c245398[];
extern char func_0c02a026(struct Actor *);
extern int func_0c047bbe(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0437b8(struct Actor *);

void func_0c0b9428(struct Actor *a, struct Counter_0c0b9428 *b)
{
    func_0c02a026(a);
    if (b->b2 >= 0 && func_0c047bbe(a)) {
        b->b2--;
        a->s28++;
    }
    if (--a->s28 <= 0) {
        a->b6++;
        func_0c02a0c4(a, 21, a->b1a3 + 8);
    }
}

void func_0c0b9486(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c0b94a8(struct Actor *a)
{
    table_0c245398[a->b6](a);
}
