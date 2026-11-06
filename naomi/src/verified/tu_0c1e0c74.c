#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct ActorGlobalRoot *dat_0c2d964c;
extern void func_0c1d91a8(int);
extern int func_0c1d8ff8(int,int);
extern int func_0c1d901e(void);
extern int func_0c1d912a(int *,float *);
extern int func_0c1d917e(int *,float *);
void func_0c1e0cb6(struct Obj_tu5_03 *);
void func_0c1e0c74(void)
{
    struct Obj_tu5_03 *a;
    if ((a = func_0c0374da(0,5,1)) != 0) {
        a->b12c = 1;
        a->p16 = func_0c1e0cb6;
        a->l84 = dat_0c2d964c->p0->entries[2].value;
        a->lcc = 0x800;
        func_0c1d91a8(a->l84);
    }
}
void func_0c1e0cb6(struct Obj_tu5_03 *a)
{
    int id;
    float value;
    switch (a->b4) {
    case 0:
        a->w28++;
        if (a->w28 >= 100) a->w28 = 0;
        func_0c1d8ff8((*(int (*)[36])dat_0c2d964c->p0)[3],a->l84);
        while (func_0c1d901e() == 0) {
            func_0c1d912a(&id,&value);
            value += a->w28 * 0.01f;
            func_0c1d917e(&id,&value);
        }
        break;
    }
}
