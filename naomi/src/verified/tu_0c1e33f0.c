#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct ActorGlobalRoot *dat_0c2d964c;
extern void func_0c1e31d0(struct Obj_tu5_03 *);
void func_0c1e33f0(struct Obj_tu5_03 *parent,int n)
{
    struct Obj_tu5_03 *a;
    if((a=func_0c0374da(0,5,1))!=0){
        a->b12c=1;
        a->p16=func_0c1e31d0;
        a->l84=(*(int (*)[36])dat_0c2d964c->p0)[n+1];
        a->lcc=0x800;
        a->p20=parent;
        a->p200=&parent->f136;
        a->b32=n;
    }
}
