#include "objects.h"
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern void func_0c181fb0(struct LinkedActor *,int);
extern void func_0c037688(struct LinkedActor *);
void func_0c1bbfcc(struct LinkedActor *,struct Actor *);
void func_0c1bc070(struct LinkedActor *,struct Actor *);
void func_0c1bc07e(struct LinkedActor *,struct Actor *);
static void body_0c1bbe9c(struct LinkedActor *,struct Actor *);
void func_0c1bbe90(struct LinkedActor *a,struct Actor *owner)
{
 if(a->b32==0)body_0c1bbe9c(a,owner);else func_0c1bbfcc(a,owner);
}
static void body_0c1bbe9c(struct LinkedActor *a,struct Actor *owner)
{
 if(a->b33==0){
  if(owner->f41c+377.142853f>a->f56)a->f56+=4.28571415f;
  if(a->b5==0){
   a->sdc.b12c^=1;
   func_0c02a026(a);
   if(a->s28==30)func_0c02a0c4(a,22,19);
   if(a->s28>80&&a->sdc.b141){if((unsigned char)(a->b34+=32)&0x80){a->s30^=1;func_0c181fb0(a,a->s30);}}
   if(owner->b1d0==29&&owner->b5==0&&--a->s28>=0)return;
   a->b5++;a->sdc.b12c|=2;func_0c02a0c4(a,22,18);return;
  }
  if(func_0c02a026(a)>=0)return;
  a->b4++;a->sdc.b12c=0;return;
 }
 if(owner->b5!=0||owner->b0==0){func_0c1bc07e(a,owner);return;}
 *(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&owner->f52;
 func_0c02a026(a);
}
void func_0c1bbfcc(struct LinkedActor *a,struct Actor *owner)
{
 if(a->s28){
 func_0c02a026(a);
 {int v=7;if(a->sdc.b141)v=0;a->b36=v;}
 if(owner->b1d0==29&&owner->b5==0){
  if(a->s28>60&&a->s28<120){if((unsigned char)(a->b34+=32)&0x80){a->s30^=1;func_0c181fb0(a,a->s30);}}
  if(--a->s28>0)return;
 }
 a->s28=0;func_0c02a0c4(a,22,72);return;
 }
 goto c;c:if(func_0c02a026(a)>=0)return;func_0c1bc070(a,owner);
}
void func_0c1bc070(struct LinkedActor *a,struct Actor *owner){a->b4++;a->sdc.b12c=0;}
void func_0c1bc07e(struct LinkedActor *a,struct Actor *owner){a->b4++;((struct Actor *)a)->b0=0;a->sdc.b12c=0;func_0c037688(a);}
