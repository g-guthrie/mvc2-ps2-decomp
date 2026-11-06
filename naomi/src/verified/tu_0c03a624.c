#include "objects.h"

extern unsigned char func_0c0464c4(struct Actor *);
extern unsigned char func_0c046030(struct Actor *);
extern int func_0c043c66(struct Actor *);
extern unsigned char func_0c043a10(struct Actor *);
extern unsigned char func_0c044846(struct Actor *);
extern unsigned char func_0c044c60(struct Actor *);
extern void func_0c0453c4(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c044df4(struct Actor *);
extern signed char func_0c02a026(struct Actor *);

void func_0c03a624(struct Actor *a)
{
    if (a->b201 == 0) {
        if (func_0c0464c4(a) != 0)
            return;
        if (func_0c046030(a) != 0)
            return;
        if (func_0c043c66(a) != 0)
            return;
        if (func_0c043a10(a) != 0)
            return;
        if (func_0c044846(a) != 0)
            return;
        if (func_0c044c60(a) != 0)
            return;
    }
    if ((*((unsigned short *)((unsigned char *)a + 0x340)) & 0x1000) == 0) {
        func_0c0453c4(a, 7);
        func_0c02a0c4(a, 3, 2);
        return;
    }
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c044df4(a);
    if (func_0c02a026(a) >= 0)
        return;
    func_0c0453c4(a, 6);
}
