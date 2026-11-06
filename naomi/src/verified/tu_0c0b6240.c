#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c1bfa20(struct Actor *),func_0c04b02a(struct Actor *),func_0c1d82fe(struct Actor *),func_0c0437b8(struct Actor *),func_0c025900(struct Actor *,char,char);
extern struct LinkedActor *func_0c1a5dcc(struct Actor *,unsigned char);
extern void func_0c1d330c(struct Actor *,struct LinkedActorVec3 *,int,int);
void func_0c0b6246(struct Actor *a);
void func_0c0b6240(struct Actor *a){a->b6++;func_0c0b6246(a);}
void func_0c0b6246(struct Actor *a)
{
 struct Actor *linked;struct LinkedActorVec3 position;int zero=0;
 linked=a->p20c;func_0c02a026(a);
 if(a->b141&8){
  a->b141=zero;a->p1c8->p1b4=a;a->p1c8->b1a1=36;
  linked->pad220[10]=3;linked->pad220[8]=3;func_0c1bfa20(linked);func_0c04b02a(a);
 }
 if(a->b141==2){
  position=*(struct LinkedActorVec3 *)((char *)a+52);
  position.x+=a->w130?140.0f:-140.0f;position.y+=204.0f;
  func_0c1a5dcc(a,2);func_0c1d330c(a,&position,1,145);a->b141=zero;func_0c1d82fe(a->p20c);
 }
 if(((signed char *)&a->w150)[1]==15){((signed char *)&a->w150)[1]=zero;a->b141=zero;func_0c1a5dcc(a,0);}
 if(a->b141==4){a->b141=zero;func_0c1a5dcc(a,3);func_0c0437b8(a);}
 if(a->b141){
  struct Actor *other;
  func_0c025900(a,0,0);a->b141=0;other=a->p1c8;other->p1b4=a;other->b1f6=1;other->b1a1=35;
 }
}
