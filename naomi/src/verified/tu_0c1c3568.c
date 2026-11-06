/* Spawns the two side markers and the per-player banner effects. */
#include "objects.h"
extern struct Effect1cf *func_0c0374da(int, int, int);
extern struct PlayerSlotScore dat_0c2d7088[];
extern int **dat_0c2d9654;
extern struct Vec3_tu5_03 dat_0c25d270[], dat_0c25d288[], dat_0c25d2ac;
extern void func_0c1c36c8(struct Effect1cf *), func_0c1c3706(struct Effect1cf *);
void func_0c1c357c(int side), func_0c1c35d6(int i);
void func_0c1c3568(void)
{
    func_0c1c357c(0);
    func_0c1c357c(1);
    func_0c1c35d6(0);
    func_0c1c35d6(1);
}
void func_0c1c357c(int side)
{
    struct Effect1cf *a;

    if ((a = func_0c0374da(0, 11, 1)) != 0) {
        a->b12c = 1;
        a->p16 = func_0c1c36c8;
        a->l84 = (*dat_0c2d9654)[85];
        a->pos = dat_0c25d270[side];
        a->lcc = 0x10801;
        a->b32 = side;
    }
}
void func_0c1c35d6(int i)
{
    struct Effect1cf *a;
    struct Actor *p;
    unsigned *f;
    int m;

    f = &(p = &dat_0c2d7088[i].actor)->l414;
    &p;
    if (m = *f & 0x7000000)
        return;
    if ((a = func_0c0374da(0, 11, 1)) != 0) {
        a->b12c = 1;
        a->p16 = func_0c1c3706;
        a->l84 = (*dat_0c2d9654)[96];
        a->pos = dat_0c25d288[i];
        a->lcc = 0x10c11;
        a->b32 = i;
        a->s28 = 0;
        a->s30 = 0;
        a->v80 = dat_0c25d2ac;
        a->sc.f120 = a->sc.f124 = a->sc.f128 = 1.0f;
        a->v104.x = 0.0f;
        a->v104.y = 21845.0f;
        a->v104.z = 43690.0f;
    }
}
