#include "objects.h"

struct ActorVTable_a9e0 {
    void *pad[4];
    void (*slot4)(struct Actor *);
};

extern unsigned char func_0c046030(struct Actor *);
extern unsigned char func_0c0464c4(struct Actor *);
extern int func_0c043c66(struct Actor *);
extern unsigned char func_0c043a10(struct Actor *);
extern unsigned char func_0c044846(struct Actor *);
extern unsigned char func_0c043d3a(struct Actor *);
extern unsigned char func_0c044c0c(struct Actor *);
extern void func_0c0453c4(struct Actor *, int);

void func_0c03a9e0(struct Actor *a)
{
    if (a->b1 != 1)
        a->b237 = 5;
    if (a->b1 != 53 || (char)a->b140 != 0) {
    if (func_0c046030(a) != 0)
        return;
    if (func_0c0464c4(a) != 0)
        return;
    if ((char)a->b201 != 0) goto airborne;
        if (func_0c043c66(a) != 0)
            return;
        if (func_0c043a10(a) != 0)
            return;
        if (func_0c044846(a) != 0)
            return;
        if (func_0c043d3a(a) != 0)
            return;
        if (func_0c044c0c(a) != 0)
            return;
    goto handler;
airborne:
        if (func_0c043a10(a) != 0)
            return;
        if (func_0c044846(a) != 0)
            return;
        if (a->w34e & 0x0400) {
            func_0c0453c4(a, 0);
            return;
        }
    }
handler:
    ((struct ActorVTable_a9e0 *)a->p428)->slot4(a);
}
