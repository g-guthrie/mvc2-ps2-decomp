/* Character-slot effect spawner and its state dispatcher. */
#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct ActorFlags *dat_0c2d6f84;
extern int **dat_0c2d9658;
extern struct SelectionFlags59e8 dat_0c2fb158;
extern struct Vec3_tu5_03 dat_0c25e298[][3];
extern void (*table_0c25e2e0[])(struct Obj_tu5_03 *);
extern void func_0c02fe52(struct Obj_tu5_03 *);
void func_0c1c69fa(struct Obj_tu5_03 *);
struct Obj_tu5_03 *func_0c1c690c(struct Actor *parent, char b)
{
    struct Obj_tu5_03 *a;
    if (b && dat_0c2d6f84->b81 == 7) return;
    if ((a = func_0c0374da(0, 5, 1)) != 0) {
        a->b12c = 1;
        a->p24 = (struct Obj_tu5_03 *)parent;
        a->b32 = parent->b524;
        a->b33 = parent->s30;
        if (parent->b524) {
            a->angles.scalar.l44 = 0x8000;
            a->l84 = (*dat_0c2d9658)[178];
        } else {
            a->angles.scalar.l44 = 0;
            a->l84 = (*dat_0c2d9658)[177];
        }
        if (dat_0c2fb158.combined_mask == 3)
            a->pos = dat_0c25e298[parent->b524][0];
        else
            a->pos = *(&dat_0c25e298[parent->b524][0] + dat_0c2fb158.combined_mask);
        a->lcc = 0x801;
        a->ld8 = dat_0c2fb158.combined_mask;
        if (b) a->p16 = func_0c02fe52;
        else a->p16 = func_0c1c69fa;
        return a;
    }
}
void func_0c1c69fa(struct Obj_tu5_03 *a){table_0c25e2e0[a->b4](a);}
