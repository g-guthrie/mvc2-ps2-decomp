/* Two linked children that mirror their owner's sprite state each frame. */
#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c037688(struct LinkedActor *);
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern void func_0c029e70(struct LinkedActor *,int,int);
extern char func_0c029fc4(struct LinkedActor *);
extern void func_0c029f0e(struct LinkedActor *,int,int,int);
extern void func_0c188d04(struct LinkedActor *,struct LinkedActor *);
extern struct ActorFlags *dat_0c2d6f84;
extern unsigned char dat_0c2f837c;
void func_0c1be04c(struct LinkedActor *);
void func_0c1be17e(struct LinkedActor *);
struct LinkedActor *func_0c1bdfcc(struct LinkedActor *owner)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,3,0))!=0){a->p16=func_0c1be04c;a->b32=*(unsigned char *)&a->b33=0;a->p24=owner;a->b1=owner->b1;a->w38=0x3801;}
 return a;
}
struct LinkedActor *func_0c1be008(struct LinkedActor *owner)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,4,0))!=0){a->p16=func_0c1be17e;a->b32=*(unsigned char *)&a->b33=0;a->p24=owner;a->b1=owner->b1;a->w38=0x3801;
  a->wcc.dword_value=(unsigned short)owner->sdc.w158.short_value;}
 return a;
}
void func_0c1be04c(struct LinkedActor *a)
{
 struct LinkedActor *o=a->p24;
 int v;
 if(a->b4>=2)goto kill;
 if(a->b4==0){
  a->b4++;a->sdc=o->sdc;a->sdc.b12c=1;
  a->b2=o->b2;a->b1=o->b1;a->v80.x=o->v80.x;a->v80.y=o->v80.y;
  a->b1a3=o->b1a3;a->b1a4=o->b1a4;a->b48=o->b48;a->v80=o->v80;
  a->b36=o->b36;
  if(dat_0c2d6f84->b3==4){kill:func_0c037688(a);return;}
  a->f52=o->f52;a->f56=o->f56;a->s28=0;a->b49--;
 }
 a->sdc.b12c=0;
 a->b36=o->b36;
 if(o->sdc.b12c){
  a->f52=o->f52;a->f56=o->f56;
  a->sdc.w130=o->sdc.w130;
  v=((char *)&((struct Actor *)o)->w150)[1];
  if((unsigned short)v){
   a->sdc.b12c=1;
   if(a->s28!=(unsigned short)v){a->s28=v;func_0c02a0c4(a,23,v);return;}
   goto t;t:if(dat_0c2f837c==0)func_0c02a026(a);return;
  }else a->s28=v;
 }else a->sdc.b12c=0;
}
void func_0c1be17e(struct LinkedActor *a)
{
 struct LinkedActor *o=a->p24;
 if(a->b4>=2||a->wcc.dword_value!=(unsigned short)o->sdc.w158.short_value){func_0c037688(a);return;}
 if(a->b4==0){
  a->b4++;a->sdc=o->sdc;a->sdc.b12c=1;
  a->b2=o->b2;a->b1=o->b1;a->v80.x=o->v80.x;a->v80.y=o->v80.y;
  a->b1a3=o->b1a3;a->b1a4=o->b1a4;a->b48=o->b48;a->v80=o->v80;
  a->b36=o->b36;
  a->f96=342.85712f;a->f92=13.33333302f;
  if(a->sdc.w130)a->f92=-a->f92;
  a->f52=o->f52+a->f92;a->f56=o->f56+a->f96;
  a->b49=-8;
  func_0c029e70(a,27,0);return;
 }
 if(a->b5==0){
  a->f52=o->f52+a->f92;a->f56=o->f56+a->f96;
  a->b36=o->b36;a->b49=-8;
  if(func_0c029fc4(a)>=0)return;
  a->b5++;a->b34=0;func_0c029f0e(a,27,1,0);return;
 }
 goto c;c:if(o->sdc.b141>=0){
 if(a->b34!=o->sdc.b141){a->b34=o->sdc.b141;func_0c029f0e(a,27,1,a->b34);func_0c188d04(a,o);}
 a->f52=o->f52+a->f92;a->f56=o->f56+a->f96;return;
 }
 a->sdc.b12c=0;a->b4++;a->b5=0;
}
