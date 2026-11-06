/* Blinking pickup marker: spawner, phase dispatcher, appear and blink/fade phases.
 * The unsigned 3U in the l84 index keeps retail's add #3 before the scale (no displacement fold). */
#include "objects.h"
struct FloatPair_0c2329a0 { float x, y; };
extern struct Obj_tu5_03 *func_0c0374da(int, int, int);
extern struct ActorFlags *dat_0c2d6f84;
extern struct ActorGlobalRoot *dat_0c2d964c;
extern int func_0c1ec190(void);
extern void func_0c037688(struct Obj_tu5_03 *);
extern struct Vec3_tu5_03 dat_0c232934[];
extern struct FloatPair_0c2329a0 dat_0c2329a0[];
void func_0c1d9b98(struct Obj_tu5_03 *a);
void func_0c1d9cb4(struct Obj_tu5_03 *a);
static void appear(struct Obj_tu5_03 *a);
void func_0c1d9b70(void)
{
    struct Obj_tu5_03 *a;
    if ((a = func_0c0374da(0, 5, 1)) != 0) {
        a->b12c = 0;
        a->p16 = func_0c1d9b98;
        a->lcc = 0xc0d;
    }
}
void func_0c1d9b98(struct Obj_tu5_03 *a)
{
    switch (a->b4) {
    case 0:
        appear(a);
        break;
    case 1:
        func_0c1d9cb4(a);
        break;
    }
}
static void appear(register struct Obj_tu5_03 *a)
{
    unsigned int v;
    int n;
    if (++a->w28 >= 120) {
        a->w28 = 120;
        v = dat_0c2d6f84->i90;
        if ((v <= 500 || v >= 1000) && v <= 3500) {
            a->b4++;
            a->b5 = 0;
            a->w28 = 0;
            a->l84 = ((int *)dat_0c2d964c->p0)[(int)(func_0c1ec190() % 4 + 3U)];
            n = (unsigned int)func_0c1ec190() % 9;
            a->pos = dat_0c232934[n];
            a->angles.scalar.l44 = (int)dat_0c2329a0[n].x;
            a->angles.scalar.l48 = (int)dat_0c2329a0[n].y;
            a->f124 = a->f120 = 1.0f;
            a->f128 = a->f120;
        }
    }
}
void func_0c1d9cb4(struct Obj_tu5_03 *a)
{
    switch ((unsigned char)a->b5) {
    case 0:
        a->w28++;
        a->b12c = a->w28 % 2;
        if (a->w28 >= 5) {
            a->b5++;
            a->w28 = 0;
            a->b12c = 1;
            a->f124 = a->f120 = 1.0f;
            a->f128 = a->f120;
        }
        break;
    case 1:
        a->f124 = a->f120 -= 0.066666670144f;
        a->f128 = a->f120;
        if (++a->w28 >= 15) {
            a->b4 = 0;
            a->b12c = 0;
            if ((unsigned int)dat_0c2d6f84->i90 > 4500) func_0c037688(a);
        }
        break;
    }
}
