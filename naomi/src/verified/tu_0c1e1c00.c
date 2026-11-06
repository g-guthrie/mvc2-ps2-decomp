#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct ActorGlobalRoot *dat_0c2d964c;
extern void func_0c1d91a8(int);
extern void func_0c1d8ff8(int,int);
extern int func_0c1d901e(void);
extern void func_0c1d912a(int *,float *),func_0c1d917e(int *,float *);
extern float func_0c1ec2c0(int);
struct ActorInputPair { union ActorGlobalEntry actor,stream; };
void func_0c1e1c1c(int);
void func_0c1e1c96(struct Obj_tu5_03 *);
void func_0c1e1c00(void)
{
    int i;
    for(i=0;i<4;i++)func_0c1e1c1c(i);
}
void func_0c1e1c1c(int n)
{
    struct Obj_tu5_03 *a;
    if((a=func_0c0374da(0,5,1))!=0){
        a->b12c=1;
        a->p16=func_0c1e1c96;
        a->l84=((struct ActorGlobalTable *)&(*(union ActorGlobalEntry (*)[36])dat_0c2d964c->p0)[n*2])->entries[9].value;
        a->lcc=0xc01;
        a->b32=n;
        a->f120=0.0f;
        a->f124=0.0f;
        a->f128=0.0f;
        a->w28=180-n*360/6;
        func_0c1d91a8(a->l84);
    }
}
void func_0c1e1c96(struct Obj_tu5_03 *a)
{
    int id;
    float value;
    a->w28++;
    if(a->w28>=1000)a->w28=0;
    func_0c1d8ff8(((struct ActorInputPair *)&(*(union ActorGlobalEntry (*)[36])dat_0c2d964c->p0)[(long)a->b32*2+9])->stream.value,a->l84);
    while(func_0c1d901e()==0){
        func_0c1d912a(&id,&value);
        value+=a->w28*0.00100000005f;
        func_0c1d917e(&id,&value);
    }
    {
        double amplitude=0.25;
        a->f120=func_0c1ec2c0((int)(a->w28*3600.0f/1000.0f*65536.0f/360.0f+0.5f)&0xffff)*amplitude+amplitude;
        a->f124=a->f120;
    }
    a->f128=a->f120;
}
