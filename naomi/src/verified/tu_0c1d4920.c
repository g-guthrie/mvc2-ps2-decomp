/* Two puff-effect constructors at a position (raised by 137.14) and their
 * per-frame scale/alpha updaters, which free the object after 16 frames. */
#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int, int, int);
extern struct ActorGlobalRoot *dat_0c2d9650;
extern float dat_0c2614a4[], dat_0c26151c[];
extern void func_0c037688(struct Obj_tu5_03 *);
void func_0c1d4aa8(struct Obj_tu5_03 *), func_0c1d4af6(struct Obj_tu5_03 *);
void func_0c1d4920(struct Vec3_tu5_03 *pos)
{
    struct Obj_tu5_03 *a;
    if ((a = func_0c0374da(0, 7, 1))) {
        a->b12c = 1;
        a->p16 = func_0c1d4aa8;
        a->l84 = ((int *)dat_0c2d9650->p0)[195];
        a->pos = *pos;
        a->pos.y += 137.142853f;
        a->lcc = 49;
        a->w28 = 0;
        a->f116 = 1.0f;
        a->f80 = 1.0f;
        a->f84 = 1.0f;
        a->f88 = 1.0f;
    }
}
void func_0c1d498c(struct Vec3_tu5_03 *pos)
{
    struct Obj_tu5_03 *a;
    if ((a = func_0c0374da(0, 7, 1))) {
        a->b12c = 1;
        a->p16 = func_0c1d4af6;
        a->l84 = ((int *)dat_0c2d9650->p0)[196];
        a->pos = *pos;
        a->pos.y += 137.142853f;
        a->lcc = 49;
        a->w28 = 0;
        a->f116 = 1.0f;
        a->f80 = 1.0f;
        a->f84 = 1.0f;
        a->f88 = 1.0f;
    }
}
void func_0c1d49f8(struct Obj_tu5_03 *a)
{
    if (a->w28 > 15) {
        func_0c037688(a);
        return;
    }
    a->f116 = dat_0c2614a4[a->w28];
    a->f80 += 0.12f;
    a->f84 += 0.12f;
    a->w28++;
}
void func_0c1d4a2e(struct Obj_tu5_03 *a)
{
    a->l84 = ((int *)dat_0c2d9650->p0)[186 + a->w30];
    if (a->w28 > 15) {
        func_0c037688(a);
        return;
    }
    a->f116 = dat_0c26151c[a->w28];
    a->w28++;
    if (a->w28 < 8)
        a->w30++;
}
