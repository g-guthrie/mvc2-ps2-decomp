#include "objects.h"
extern int dat_0c2d9610,dat_0c264708;
extern struct ActorGlobalRoot *dat_0c2d964c;
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct Vec3_tu5_03 dat_0c2646fc;
extern void func_0c1d91a8(int);
extern int func_0c1d8ff8(int,int);
extern int func_0c1d901e(void);
extern int func_0c1d912a(int *,float *);
extern int func_0c1d917e(int *,float *);
void func_0c1e52d8(register struct Obj_tu5_03 *a)
{
    int id;
    float value;
    float zero=0.0f;
    int state=dat_0c2d9610;
    switch(a->b4){
    case 0:
        if(state==1){
            a->b4++;
            a->b12c=1;
            a->f120=zero;
            a->f124=zero;
            a->f128=zero;
        }
        break;
    case 1:
        switch((unsigned char)a->b5){
        case 0:
            if(!( (a->f124+=0.002083333442f)<1.0f )){
                a->b5++;
                a->f120=zero;
                a->f124=1.0f;
                a->f128=zero;
            }
            break;
        case 1:
            if(state==2)a->b5++;
            break;
        case 2:
            a->f120+=1.0f/dat_0c264708;
            a->f124-=1.0f/dat_0c264708;
            a->f128+=0.200000003f/dat_0c264708;
            if(++a->w30>=dat_0c264708){
                a->b5++;
                a->f120=1.0f;
                a->f124=0.200000003f;
                a->f128=0.200000003f;
            }
            break;
        case 3:break;
        }
        a->w28++;
        if(a->w28>=1000)a->w28=0;
        func_0c1d8ff8((*(int (*)[36])dat_0c2d964c->p0)[11],a->l84);
        while(func_0c1d901e()==0){
            func_0c1d912a(&id,&value);
            value=value+a->w28*0.00100000005f;
            func_0c1d917e(&id,&value);
        }
        a->angles.scalar.l48+=55;
        break;
    }
}
void func_0c1e544a(void)
{
    struct Obj_tu5_03 *a;
    if((a=func_0c0374da(0,5,1))!=0){
        a->b12c=0;
        a->p16=func_0c1e52d8;
        a->l84=dat_0c2d964c->p0->entries[10].value;
        a->lcc=0xd09;
        a->pos=dat_0c2646fc;
        func_0c1d91a8(a->l84);
    }
}
