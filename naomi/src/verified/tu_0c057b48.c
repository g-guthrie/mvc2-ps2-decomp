#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern int func_0c047b98(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c05bbd6(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
void func_0c057b48(struct Actor *a)
{
    struct ActorSub2a4 *sub = &a->sub2a4;
    a->b1ea = 1;
    a->b1ed = 2;
    a->b1f5 = 2;
    a->b1f2 = 3;
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    if (func_0c047b98(a)) {
        if (a->b525) {
            if (a->b141) {
                a->b141 = 0;
                if (a->b142 != 1) a->b142--;
            }
        } else a->b142 = 1;
        sub->b2++;
        if ((char)sub->b2 > 20) sub->b2 = 20;
    }
    if (func_0c044e52(a)) {
        a->b7++;
        a->f92 = 0;
        a->f96 = 0;
        a->f104 = 0;
        a->f108 = 0;
        dat_0c2d9260.b5 = 3;
        dat_0c2d9260.b6 = 1;
        func_0c05bbd6(a);
        func_0c02a0c4(a, 15, 20);
    }
}
