/* Linked-actor family at 0x0c1b2a40: spawner, b32/b4 dispatchers and owner-copy launch states. */
#include "objects.h"
struct ActorSub2a4Flags { unsigned char pad0[15]; unsigned char b15; };
extern struct LinkedActor *func_0c0374da(int,int,int);
extern char func_0c029fc4(struct LinkedActor *);
extern void func_0c029e70(struct LinkedActor *,int,int);
extern void func_0c037688(struct LinkedActor *);
extern float func_0c1ec2c0(int);
extern struct ActorFlags *dat_0c2d6f84;
extern struct ActorSub2a4Flags *dat_0c2fb428;
extern void (*table_0c25aea4[])(struct LinkedActor *);
extern void (*table_0c25aeac[])(struct LinkedActor *);
extern void (*table_0c25aebc[])(struct LinkedActor *);
void func_0c1b2a74(struct LinkedActor *a);
void func_0c1b2dd8(struct LinkedActor *a);

struct LinkedActor *func_0c1b2a40(struct LinkedActor *owner,char mode)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,3,0))){a->p16=func_0c1b2a74;a->p24=owner;a->b32=mode;a->w38=0x2400;}
 return a;
}
void func_0c1b2a74(struct LinkedActor *a)
{
 dat_0c2fb428=(struct ActorSub2a4Flags *)&((struct Actor *)a->p24)->sub2a4;
 table_0c25aea4[a->b32](a);
}
void func_0c1b2a94(struct LinkedActor *a){table_0c25aeac[a->b4](a);}
void func_0c1b2aa6(struct LinkedActor *a)
{
 a->b4++;a->sdc=a->p24->sdc;a->sdc.b12c=1;a->b2=a->p24->b2;a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;a->b48=a->p24->b48;
 a->v80=a->p24->v80;a->b36=a->p24->b36;a->sdc.w130=a->p24->sdc.w130;a->b36=0;
 a->f52=a->p24->f52;a->f56=a->p24->f56;
 func_0c029e70(a,27,0);
}
void func_0c1b2b36(struct LinkedActor *a)
{
 if(!a->b5){
  if(!a->p24->sdc.b141)goto hide;
  a->b5++;a->s30=60;
  if(a->sdc.w130)a->f92=-3.3333333f;else a->f92=3.3333333f;
  a->f104=0.0f;a->f96=12.85714245f;a->f108=-0.5357143f;
 }
 func_0c029fc4(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(--a->s30<0){func_0c1b2dd8(a);return;}
 if(a->s30>40){hide:a->sdc.b12c=1;return;}
 a->sdc.b12c=(dat_0c2d6f84->flags&1)^a->b2;
}
void func_0c1b2c36(struct LinkedActor *a){table_0c25aebc[a->b4](a);}
void func_0c1b2c48(struct LinkedActor *a)
{
 a->b4++;a->sdc=a->p24->sdc;a->sdc.b12c=1;a->b2=a->p24->b2;a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;a->b48=a->p24->b48;
 a->v80=a->p24->v80;a->b36=a->p24->b36;a->sdc.w130=a->sdc.w130^1;
 a->f52=a->p24->f52;
 a->f52+=a->sdc.w130?-213.33333f:213.33333f;
 a->f56=((struct Actor *)a->p24)->f41c;a->f56+=34.2857132f;
 a->sdc.b12c=0;
 func_0c029e70(a,27,1);
}
void func_0c1b2d3c(struct LinkedActor *a)
{
 register int one=1;
 a->sdc.b12c=one;
 if(!a->b5){
  if(func_0c029fc4(a)<0){
   a->b5++;dat_0c2fb428->b15=one;a->s30=one;a->s28=one;a->b34=0;
  }else if(!a->sdc.b141){return;}
  return;
 }
 func_0c029fc4(a);
 a->f56+=func_0c1ec2c0(((40-a->b34)&31)<<11)*4.28571415f;
 if(--a->s28==0){a->b34++;a->s28=a->s30;}
}
void func_0c1b2dd8(struct LinkedActor *a)
{
 a->b4=3;a->sdc.b12c=0;func_0c037688(a);
}
