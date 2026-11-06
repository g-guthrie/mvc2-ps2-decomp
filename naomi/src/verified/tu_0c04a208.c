#include "objects.h"
extern void func_0c02a0c4(struct Actor *,int,int);
struct ReactionAnimation4 { signed char animation; unsigned char stance,pad2,flags; };
#pragma section N04a208
void func_0c04a208(struct Actor *a)
{
 struct ReactionAnimation4 choice;
 if(a->b1f9==1){choice.animation=6;choice.stance=1;}
 else{
  choice.animation=3;choice.stance=0;
  if(!(a->b231&0x80)){
   if((a->b231&0x70) || ((a->b19f&4)==1))choice.animation=0;
  }
 }
 a->b1f9=choice.stance;
 if((choice.flags=a->b231&0x70)!=0){
  unsigned char *flags=&choice.flags;
  if(*flags==0x30){choice.animation+=2;goto animate;}
  if(*flags==0x20)goto increment;
  goto animate;
 }else{
  if(a->b22f>=5)++choice.animation;
  if(a->b22f>=12)goto increment;
  goto animate;
 }
increment:
 ++choice.animation;
animate:
 func_0c02a0c4(a,13,choice.animation);
}

void func_0c04a2b4(struct Actor *a)
{
 unsigned char flags;
 a->b158=10;
 flags=a->b231&0x70;
 if(flags!=0x10){
  ++a->b158;
  if(flags!=0x20)++a->b158;
 }
 func_0c02a0c4(a,13,a->b158);
 a->s28=10;a->b1f9=2;
}
