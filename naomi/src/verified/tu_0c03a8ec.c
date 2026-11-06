#include "objects.h"

struct Obj_0c03a8ec {
    unsigned char pad[0x340];
    unsigned short w340;
};

extern int func_0c043c66(struct Obj_0c03a8ec *);
extern unsigned char func_0c043a10(struct Obj_0c03a8ec *);
extern unsigned char func_0c044846(struct Obj_0c03a8ec *);
extern int func_0c0439d8(struct Obj_0c03a8ec *, int);
extern unsigned char func_0c043d3a(struct Obj_0c03a8ec *);
extern unsigned char func_0c044c60(struct Obj_0c03a8ec *);
extern char func_0c02a026(struct Obj_0c03a8ec *);
extern void func_0c0453c4(struct Obj_0c03a8ec *, int);

void func_0c03a8ec(struct Obj_0c03a8ec *a)
{
    if (func_0c043c66(a))
        return;
    if (func_0c043a10(a))
        return;
    if (func_0c044846(a))
        return;
    if (func_0c0439d8(a, 0))
        return;
    if (func_0c043d3a(a))
        return;
    if (func_0c044c60(a))
        return;
    if (func_0c02a026(a) < 0)
        func_0c0453c4(a, 0);
}

void func_0c03a954(struct Obj_0c03a8ec *a)
{
    if (func_0c043c66(a))
        return;
    if (func_0c043a10(a))
        return;
    if (func_0c044846(a))
        return;
    if (func_0c043d3a(a))
        return;
    if (func_0c044c60(a))
        return;
    if (func_0c02a026(a) >= 0) {
        if ((a->w340 & 0xc00) == 0)
            return;
    }
    func_0c0453c4(a, 6);
}
