/* Assembled by tools/clone.py from verified twins. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern void func_0c0344a0(struct Actor *, int);
extern void func_0c05bbd6(struct Actor *);
extern void func_0c1d357a(struct LinkedActorVec3 *, int);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c04b02a(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);

void func_0c05a100(struct Actor *a)
{
    struct Actor *other;
    struct LinkedActorVec3 position;
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    (void)func_0c02a026(a);
    if (func_0c044e52(a) != 0) {
        a->b7++;
        dat_0c2d9260.b5 = 2;
        dat_0c2d9260.b6 = 1;
        func_0c0344a0(a, 21);
        func_0c05bbd6(a);
        other = a->p1c8;
        other->b1a1 = 82;
        a->b1a1 = 82;
        position.x = other->f52;
        position.y = a->f41c;
        func_0c1d357a(&position, 1);
        func_0c0346da(a, 73);
        func_0c04b02a(a);
        func_0c02a0c4(a, 15, 56);
    }
}

/* func_0c05a1b2: no verified twin. Ghidra draft:
*/
void func_0c05a1b2(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        a->b7++;
        func_0c02a0c4(a, 15, 60);
        return;
    }
    if (a->b141 != 0) {
        a->b141 = 0;
        a->w130 ^= 1;
        a->b1d2 = *(unsigned char *)&a->w130;
    }
    if (a->b140 != 0) {
        a->b140 = 0;
        if (a->w130 != 0)
            a->f52 += 160.0f;
        else
            a->f52 -= 160.0f;
    }
}
