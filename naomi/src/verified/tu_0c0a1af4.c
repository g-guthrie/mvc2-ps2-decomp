/* Actor positioning handler centred between two global x values. */
#include "objects.h"
extern void func_0c09e43a(struct Actor *);
extern void func_0c025900(struct Actor *,int,int);
extern int dat_0c2d9634;
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;

void func_0c0a1af4(struct Actor *a)
{
    func_0c09e43a(a);
    a->b1ea = 1; a->b1ed = 2; a->b1f5 = 2;
    dat_0c2d9634 = 2;
    a->b6++;
    func_0c025900(a, 1, 13);
    a->f52 = (dat_0c2d9260.f88 + dat_0c2d9260.f8c) / 2.0f;
    a->f52 += a->b1d2 ? -133.33333f : 133.33333f;
}
