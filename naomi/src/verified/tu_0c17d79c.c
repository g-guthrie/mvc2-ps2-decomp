#include "objects.h"
extern struct ActorVec2 dat_0c253dac[];
void func_0c17d79c(struct LinkedActor *a)
{
 float offset;
 struct LinkedActor *owner=a->p24;
 if(!a->b32){
  a->f52=owner->f52;
  a->f56=owner->f56+218.57143f;
  offset=81.666667f;
  if(!((struct Actor *)owner)->b1d2)offset=-81.666667f;
 }else{
  struct LinkedActor *other=a->p20;
  a->f52=other->f52;
  a->f56=other->f56+dat_0c253dac[owner->b1a3].y;
  offset=dat_0c253dac[owner->b1a3].x;
  if(!((struct Actor *)owner)->b1d2)offset=-offset;
 }
 a->f52+=offset;
}
