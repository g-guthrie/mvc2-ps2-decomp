#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c252ba0[])(struct LinkedActor *);
extern signed char func_0c02a026(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *, int, int);
extern void func_0c037688(struct LinkedActor *);
void func_0c173d86(struct LinkedActor *);
struct LinkedActor *func_0c173d38(struct LinkedActor *owner, struct LinkedActor *source)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,0)) != 0) {
   a->p16=func_0c173d86;
   a->p24=owner;
   a->wcc.dword_value=(unsigned int)source;
   a->w38=0x2f03;
   if(owner->pad1==0) a->b32=0;
   else a->b32=owner->b32+1;
 }
 return a;
}
void func_0c173d86(struct LinkedActor *a) { table_0c252ba0[a->b4](a); }
void func_0c173d98(struct LinkedActor *a)
{
 struct LinkedActor *source=(struct LinkedActor *)a->wcc.dword_value;
 short direction;
 a->b4++;
 a->s28=120;
 a->s30=8;
 a->sdc=source->sdc;
 a->sdc.b12c=1;
 a->b2=source->b2;
 a->b1=source->b1;
 a->v80.x=source->v80.x;
 a->v80.y=source->v80.y;
 a->b1a3=source->b1a3;
 a->b1a4=source->b1a4;
 a->b48=source->b48;
 a->v80=source->v80;
 a->b36=source->b36;
 a->b49=-1;
 a->pad11[0]=0;
 a->pad11[1]=0;
 direction=32;
 if(a->sdc.w130) direction=-32;
 a->f52=a->p24->f52+direction*1.66666663f;
 a->f56=((struct Actor *)source)->f41c;
 func_0c02a0c4(a,20,4);
}
void func_0c173e6c(struct LinkedActor *a)
{
 struct LinkedActor *owner=a->p24;
 a->b36=owner->b36;
 if(a->s30) {
   if(--a->s30==0 && a->b32<4) func_0c173d38(a,owner);
 }
 if(--a->s28==0) {a->b4++;func_0c02a0c4(a,20,3);}
 else func_0c02a026(a);
}
void func_0c173ec6(struct LinkedActor *a)
{
 if(func_0c02a026(a)<0) {a->b4++;a->sdc.b12c=0;}
}
void func_0c173ee8(struct LinkedActor *a) {a->sdc.b12c=0;func_0c037688(a);}
