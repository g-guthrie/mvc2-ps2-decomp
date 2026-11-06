#include "objects.h"
void func_0c179778(struct Actor *a,struct Actor *b)
{
 a->f52=b->f52; a->f56=b->f56; a->f60=b->f60;
 if(a->b32==2){
  if(!a->w130)a->f52+=-26.666667f;
  else a->f52+=26.666667f;
 }else{
  if(!a->w130)a->f52+=-53.333333f;
  else a->f52+=53.333333f;
 }
 a->f52+=a->f92;
}
