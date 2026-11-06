/* Falling-shot state handlers: the gravity step at 0x0c10786a, the timed
 * re-fire that spends counter byte 8 of its record, the landing check, and
 * the b6/b7 dispatchers. */
#include "objects.h"
struct ShotCount { unsigned char pad[8]; char b8; };
extern void (*table_0c24b5bc[])(struct Actor *);
extern void (*table_0c24b5cc[])(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c172474(struct Actor *, int, int), func_0c02a0c4(struct Actor *, int, int), func_0c0438de(struct Actor *);
void func_0c10786a(struct Actor *a);
void func_0c1077cc(register struct Actor *a, register struct ShotCount *c)
{
    func_0c10786a(a);
    func_0c02a026(a);
    if (c->b8) {
        if (!a->s28--) {
            a->s28 = 3;
            func_0c172474(a, 2, 1);
            c->b8--;
        }
    }
    if (!--a->s30) {
        a->b7++;
        func_0c02a0c4(a, 21, a->b1a3 + 6);
    }
}
void func_0c107834(struct Actor *a)
{
    func_0c10786a(a);
    if (func_0c02a026(a) < 0)
        func_0c0438de(a);
}
void func_0c107858(struct Actor *a){table_0c24b5bc[a->b7](a);}

void func_0c10786a(struct Actor *a)
{
    if (!a->b201) {
        a->f56 += a->f96;
        a->f96 += a->f108;
    }
    if (a->f41c > a->f56)
        a->f56 = a->f41c;
}

void func_0c1078a4(struct Actor *a)
{
 if(a->b1f9==2)a->b6=1;
 table_0c24b5cc[a->b6](a);
}
