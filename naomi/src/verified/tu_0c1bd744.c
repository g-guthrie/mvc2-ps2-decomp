#include "objects.h"
/* Animation counter view of the actor record at +0x2a4 used by this unit. */
struct ActorSubCycle2a4 { unsigned char pad0[8]; char b8; unsigned char pad9[33 - 9]; char b33, b34, b35; };
extern unsigned char dat_0c2f8338[];
extern unsigned char dat_0c25be48[];
extern void func_0c02a684(struct Actor *,int,int,int);
extern int func_0c02a39a(struct Actor *,int);
void func_0c1bd7a2(struct LinkedActor *,struct Actor *);
void func_0c1bd744(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;
 a->b2=owner->b2;a->b1=owner->b1;a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;
 a->b36=owner->b36;a->sdc.b12c=0;
 func_0c1bd7a2(a,(struct Actor *)owner);
}
void func_0c1bd7a2(struct LinkedActor *a,struct Actor *owner)
{
 struct ActorSubCycle2a4 *s;struct Actor *e;
 s=(struct ActorSubCycle2a4 *)&owner->sub2a4;
 owner->w3e4=2;
 if(owner->w420==0)goto next;
 e=owner->p20c;if(e->b1==24||e->b1==25){if(dat_0c2f8338[3]||dat_0c2f8338[0]==6){next:a->b4++;return;}}
 if(dat_0c2f8338[6]&(1<<(a->b2^1)))return;
 if(s->b8==0)return;
 goto d;d:if(s->b34--!=0)return;
 s->b34=4;
 if(--s->b33<0)s->b33=9;
 func_0c02a684(owner,0,owner->b37*6+dat_0c25be48[s->b33],1);
}
void func_0c1bd856(struct LinkedActor *a,struct Actor *owner)
{
 struct ActorSubCycle2a4 *s=(struct ActorSubCycle2a4 *)&owner->sub2a4;
 a->b4++;a->sdc.b12c=0;s->b8=0;s->b35=1;
 func_0c02a39a(owner,0);
}
