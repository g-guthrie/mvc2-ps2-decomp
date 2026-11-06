/* Exact141044..141174 action handler and cleanup leaf. */
#include "objects.h"
extern int func_0c0447bc(struct Actor *);
extern void func_0c0445fe(struct Actor *),func_0c037d0c(struct Actor *),func_0c037688(struct Actor *),func_0c02a0c4(struct Actor *,int,int);
extern char func_0c02a026(struct Actor *);
void func_0c141044(struct Actor *a,struct Actor *record)
{
 struct Actor *owner=record;
 struct ActorActionResult56 *state=(struct ActorActionResult56 *)&owner->sub2a4;
 if(!a->b5){
 float x=-83.3333282471f;
 if(owner->b1d2)x=83.3333282471f;
 a->f52=owner->f52+x;a->f56=owner->f56+90.0f;
 if(a->b1a0){a->b1a0--;return;}
 if(func_0c0447bc(a)){
 record=a->p1b0;
 if(record->b1a2==99){
 int one=1;
 a->b5++;owner->b1ea=one;owner->b1ed=32;owner->b19d=0;owner->b1f7=197;owner->b15a=-1;state->result=one;record->b1f4=2;
 func_0c0445fe(a);goto changed;
 }
 goto lost;
 }
 if(func_0c02a026(a)>=0){func_0c037d0c(a);return;}
 lost:a->b5++;state->result=-1;
 changed:func_0c02a0c4(a,23,24);return;
 }else if(func_0c02a026(a)<0){a->b4=2;a->b12c=0;}
}
void func_0c141136(struct Actor *a){func_0c037688(a);}
