/* Linked child allocation, owner-state copies, and positioning callbacks. */
#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c037d0c(struct LinkedActor *),func_0c037688(struct LinkedActor *);
extern short table_0c24e2d0[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24e2c0[])(struct LinkedActor *,struct LinkedActor *);
void func_0c1321f4(struct LinkedActor *);
void func_0c1322c4(struct LinkedActor *,struct LinkedActor *);
void func_0c1323e0(struct LinkedActor *,struct LinkedActor *);
struct LinkedActor *func_0c1321b8(struct LinkedActor *owner)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,0))){a->p16=func_0c1321f4;a->p24=owner;a->b1=owner->b1;a->b32=0;a->b33=0;a->w38=0x101;}
 return a;
}
void func_0c1321f4(struct LinkedActor *a){table_0c24e2c0[a->b4](a,a->p24);}
void func_0c132208(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;
 a->v80=owner->v80;a->b36=owner->b36;func_0c1323e0(a,owner);
 a->s28=table_0c24e2d0[owner->b1a3];a->s30=owner->sdc.w158.short_value;a->pad11[0]=66;a->pad11[1]=66;func_0c02a0c4(a,20,1);
 a->pad11[5]=43;*(unsigned short *)&a->pad12[7]=0;a->pad11[2]=0;*(void **)&a->pad12[31]=(void *)0;dat_0c2f83f8->arr[a->b2]++;
 func_0c1322c4(a,owner);
}
void func_0c1322c4(struct LinkedActor *a,struct LinkedActor *owner)
{
 int zero;
 if(a->s30!=(unsigned short)owner->sdc.w158.short_value || owner->b1d0!=21)goto advance;
 a->b49=-2;func_0c1323e0(a,owner);zero=0;
 if(a->b5){if(func_0c02a026(a)>=0)goto done;a->sdc.b12c=zero;
advance:a->b4++;}
 else{
  goto events;events:if(a->sdc.b141){a->sdc.b141=zero;a->pad11[5]=43;*(unsigned short *)&a->pad12[7]=zero;a->pad11[2]=zero;*(void **)&a->pad12[31]=(void *)zero;dat_0c2f83f8->arr[a->b2]++;}
  if(!a->pad11[3]){func_0c02a026(a);if(a->s28--!=0){func_0c037d0c(a);return;}a->s28=1;if(!a->sdc.b141)goto done;}
  a->b5++;func_0c02a0c4(a,20,2);return;
 }
done:;
}
void func_0c1323c4(struct LinkedActor *a,struct LinkedActor *owner)
{
 struct ActorSub2a4 *sub=&((struct Actor *)owner)->sub2a4;sub->b3=1;a->b4++;a->sdc.b12c=0;
}
void func_0c1323da(struct LinkedActor *a,struct LinkedActor *owner){func_0c037688(a);}
void func_0c1323e0(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->f52=owner->f52+(owner->sdc.w130?140.0f:-140.0f);a->f56=owner->f56+177.857132f;
}
