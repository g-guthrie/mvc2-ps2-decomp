#include "objects.h"
int func_0c15dc08(struct Actor *a,struct Actor *b)
{
 struct Rect8_15dc08 *ra; register struct Rect8_15dc08 *rb;
 register float ax,distance; float bx,span;
 ra=&a->p170[(unsigned short)a->p1c0->index4];
 ax=(float)ra->x*1.66666663f;
 rb=&b->p170[(unsigned short)b->p1c0->index0];
 bx=(float)rb->x*1.66666663f;
 if(a->w130)ax=-ax;
 ax=ax+a->f52;
 if(b->w130)bx=-bx;
 bx=bx+b->f52;
 distance=ax-bx;
 if(distance<0.0f)distance=-distance;
 span=(float)rb->half_x*1.66666663f;
 if(span==0.0f)return 0;
 span+=(float)ra->half_x*1.66666663f;
 if(!(span>distance))return 0;
 {
  float by;register float scale_y=2.1428571f;
  ax=(float)ra->y*scale_y;ax=-ax;ax=ax+a->f56;
  by=(float)rb->y*scale_y;by=-by;by=by+b->f56;
  distance=ax-by;
  if(distance<0.0f)distance=-distance;
  by=(float)rb->half_y*scale_y;
  if(by==0.0f)return 0;
  by+=(float)ra->half_y*scale_y;
  if(by>distance)return 1;
 }
 return 0;
}
