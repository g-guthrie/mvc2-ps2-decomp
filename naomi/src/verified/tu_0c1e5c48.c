#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct ActorGlobalRoot *dat_0c2d964c;
extern int func_0c1d91a8(int),func_0c1d8ff8(int,int);
extern int func_0c1d901e(void);
extern int func_0c1d912a(int *,float *),func_0c1d917e(int *,float *);
void func_0c1e5c8c(struct Obj_tu5_03 *);
void func_0c1e5c48(void)
{
    struct Obj_tu5_03 *a;
    if((a=func_0c0374da(0,5,1))!=0){
        a->b12c=1;
        a->l84=dat_0c2d964c->p0->entries[19].value;
        a->p16=func_0c1e5c8c;
        a->lcc=0x800;
        func_0c1d91a8(a->l84);
    }
}
void func_0c1e5c8c(struct Obj_tu5_03 *a)
{
    int first; float value;
    a->w28++;
    if(a->w28>=1000)a->w28=0;
    func_0c1d8ff8((*(int (*)[36])dat_0c2d964c->p0)[20],a->l84);
    while(func_0c1d901e()==0){
        func_0c1d912a(&first,&value);
        value+=a->w28*0.00100000005f;
        func_0c1d917e(&first,&value);
    }
}
