#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern int func_0c038fdc(int);
extern int func_0c1ec190(void);
extern void func_0c037688(struct Obj_tu5_03 *);
extern struct ActorGlobalRoot *dat_0c2d964c;
extern int dat_0c262850[];
struct SolMotion { struct Vec3_tu5_03 start,end; };
extern struct SolMotion dat_0c2627fc[];
extern struct SolMotion dat_0c26280c[];
extern float dat_0c262844[];
extern int *dat_0c262964[];
extern int dat_0c262970[];
void func_0c1e1142(struct Obj_tu5_03 *ignored);
void func_0c1e1168(int);
void func_0c1e11f0(struct Obj_tu5_03 *);
void func_0c1e12ac(struct Obj_tu5_03 *);
void func_0c1e12f0(struct Obj_tu5_03 *);
void func_0c1e1120(void)
{
    struct Obj_tu5_03 *a;
    if((a=func_0c0374da(0,5,1))!=0){
        a->b12c=0;
        a->p16=func_0c1e1142;
    }
}
void func_0c1e1142(struct Obj_tu5_03 *ignored)
{
    int i;
    if(func_0c038fdc(0))for(i=0;i<3;i++)func_0c1e1168(i);
}
void func_0c1e1168(int n)
{
    struct Obj_tu5_03 *a;
    if((a=func_0c0374da(0,5,1))!=0){
        a->b12c=1;
        a->p16=func_0c1e11f0;
        a->l84=(*(int (*)[36])dat_0c2d964c->p0)[dat_0c262850[n]];
        a->pos=dat_0c2627fc[n].start;
        a->pos.x+=(int)func_0c1ec190()%330;
        a->lcc=0x801;
        a->b32=n;
    }
}
void func_0c1e11f0(struct Obj_tu5_03 *a)
{
    a->pos.y+=a->f96;
    a->f96+=dat_0c262844[a->b32];
    switch(a->b4){
    case 0:
        if(!(a->pos.y>-85.0f)){
            func_0c1e12ac(a);
            a->b4++;
        }
        break;
    case 1:
        if(!(a->pos.y>dat_0c26280c[a->b32].start.x))func_0c037688(a);
        break;
    }
}
void func_0c1e12ac(struct Obj_tu5_03 *parent)
{
    struct Obj_tu5_03 *a;
    if((a=func_0c0374da(0,5,1))!=0){
        a->b12c=1;
        a->p16=func_0c1e12f0;
        a->pos=parent->pos;
        a->lcc=0x801;
        a->b32=parent->b32;
    }
}
void func_0c1e12f0(struct Obj_tu5_03 *a)
{
    a->l84=(*(int (*)[36])dat_0c2d964c->p0)[dat_0c262964[a->b32][a->w28]];
    if(++a->w28>=dat_0c262970[a->b32])func_0c037688(a);
}
