/* Rotating player-slot cursor: spawn, spin until selected, then fade out. */
#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern void func_0c037688(struct Obj_tu5_03 *);
extern int **dat_0c2d9658;
extern struct Vec3_tu5_03 dat_0c25e964[];
extern unsigned char dat_0c2fb15a[];
extern unsigned char dat_0c22ff29[];
extern void (*table_0c25e97c[])(struct Obj_tu5_03 *);
void func_0c1c79f0(struct Obj_tu5_03 *);
void func_0c1c7960(struct Obj_tu5_03 *parent)
{
    struct Obj_tu5_03 *a;
    if ((a = func_0c0374da(0, 5, 1)) != 0) {
        a->b12c = 1;
        a->p24 = parent;
        a->p200 = &parent->f136;
        a->b32 = parent->b32;
        a->b33 = parent->b33;
        a->p16 = func_0c1c79f0;
        a->l84 = (*dat_0c2d9658)[parent->b32 + 2];
        a->pos = dat_0c25e964[parent->b32];
        a->angles.scalar.l48 = 0;
        a->lcc = 0x819;
        a->f80 = 1.0f; a->f84 = 1.0f; a->f88 = 1.0f;
        a->pad34 = parent->b32;
    }
}
void func_0c1c79f0(struct Obj_tu5_03 *a){table_0c25e97c[a->b4](a);}
void func_0c1c7a02(struct Obj_tu5_03 *a)
{
    if (a->b32) a->angles.scalar.l48 -= 0x400;
    else a->angles.array[2] += 0x400;
    if (dat_0c2fb15a[a->b32] & (1 << a->b33)) {
        a->b4++;
        a->l84 = (*dat_0c2d9658)[dat_0c22ff29[((struct Actor *)a->p24)->b1 * 2] + 120];
        a->lcc = 0x810;
        a->w28 = 20;
    }
}
void func_0c1c7a6c(struct Obj_tu5_03 *a)
{
    a->w28--;
    if (a->w28 <= 0) {
        a->b4++;
        a->b12c = 0;
    }
}
void func_0c1c7a88(struct Obj_tu5_03 *a){func_0c037688(a);}
