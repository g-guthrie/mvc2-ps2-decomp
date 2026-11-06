#include "objects.h"

struct Host150 { unsigned char pad[0x150]; unsigned char b150; };

typedef void (*SubHandler)(struct Actor *, struct ActorSub2a4 *);

extern void func_0c02a39a(struct Actor *, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c0438de(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern SubHandler table_0c249f24[];

void func_0c0ee5fc(struct Actor *a, struct Actor *b)
{
    if ((&((struct Host150 *)a)->b150)[1])
        b->b4 = 1;
    if (a->b141) {
        a->b141 = 0;
        func_0c02a39a(a, 0);
    }
    if (func_0c02a026(a) < 0) {
        if (a->b1f9 == 2) {
            func_0c0438de(a);
            return;
        }
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        func_0c0437b8(a);
    }
}

void func_0c0ee666(struct Actor *a)
{
    table_0c249f24[a->b6](a, &a->sub2a4);
}
