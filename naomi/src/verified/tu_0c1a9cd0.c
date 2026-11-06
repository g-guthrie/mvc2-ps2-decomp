#include "objects.h"

struct Obj_0c1a9cd0 {
    unsigned char pad0[24];
    struct Obj_0c1a9cd0 *p24;
    unsigned char pad28[32 - 28];
    unsigned char b32;
    unsigned char pad33[0x2a6 - 33];
    char b2a6;
};

extern void func_0c037688(struct Obj_0c1a9cd0 *a);

void func_0c1a9cd0(struct Obj_0c1a9cd0 *a)
{
    if (a->b32 == 1)
        a->p24->b2a6 = a->p24->b2a6 + -1;
    func_0c037688(a);
}
