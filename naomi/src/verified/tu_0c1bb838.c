#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern int func_0c02849a(void);
extern void func_0c029e70(struct LinkedActor *,int,int);
extern void func_0c029fc4(struct LinkedActor *);
extern void (*table_0c25bc1c[])(struct LinkedActor *,struct Actor *);
extern void (*table_0c25bc2c[])(struct LinkedActor *,struct Actor *);
void func_0c1bb8aa(struct LinkedActor *);
void func_0c1bb8d0(struct LinkedActor *,struct Actor *);
void func_0c1bba6c(struct LinkedActor *,struct Actor *);
struct LinkedActor *func_0c1bb838(struct LinkedActor *owner,float x,float y,unsigned short kind)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,3,0))!=0){
  a->p16=func_0c1bb8aa;a->p24=owner->p24;a->b1=owner->b1;a->wcc.pointer_value=owner;
  a->b32=kind>>8;a->b33=kind;a->w38=0x3600;a->f52=x;a->f56=y;
  a->b34=owner->b34;owner->b34^=1;
 }
 return a;
}
void func_0c1bb8aa(struct LinkedActor *a)
{
 struct Actor *t=(struct Actor *)a->p24;
 if(a->b33)((struct ActorSub2a4Extended *)&t->sub2a4)->l28=4;
 if(a->b32==0)func_0c1bb8d0(a,t);else func_0c1bba6c(a,t);
}
void func_0c1bb8d0(struct LinkedActor *a,struct Actor *t){table_0c25bc1c[a->b4](a,t);}
void func_0c1bb8e2(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;
 a->b2=owner->b2;a->b1=owner->b1;a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;
 a->b36=owner->b36;a->b36=8;a->b34=0;
 a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;
 {int r=(unsigned char)func_0c02849a();r-=0x80;a->f92=(float)(r<<9)*1.66666663f/65536.0f;}
 a->f108=-0.401785702f;
 func_0c029e70(a,27,(func_0c02849a()&3)+5);
}
void func_0c1bb9d0(struct LinkedActor *a,struct Actor *owner)
{
 unsigned short i;
 func_0c029fc4(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(a->f56>owner->f41c)return;
 a->b4++;
 for(i=0;i<3;i++)func_0c1bb838(a,a->f52,a->f56+8.5714283f,(unsigned char)a->b33+0x100);
}
void func_0c1bba6c(struct LinkedActor *a,struct Actor *t){table_0c25bc2c[a->b4](a,t);}
