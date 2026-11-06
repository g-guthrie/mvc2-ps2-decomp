/* Indexed attachment placement, owner-relative offsets and initialization. */
#include "objects.h"
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern void (*table_0c257cac[])(struct LinkedActor *,struct LinkedActor *);
void func_0c194684(struct LinkedActor *a){
 float *limit=&((struct Actor *)a)->f136;
 struct LinkedActor *owner=a->p20;
 int offset,index;
 a->sdc.b12c=0;a->b49=4;
 offset=((unsigned char)a->b33*64)<<16;
 if(!a->sdc.w130)offset=-offset;
 a->f52=owner->f52+offset*1.66666663f/65536.0f;
 a->f56=owner->f56+(2048-(short)(((unsigned char)a->b33*8)<<8))*2.1428571f/256.0f;
 index=(unsigned char)a->b33-1;if(index<0)index=0;
 *limit=(index<<22)*1.66666663f/65536.0f;
 a->s28=0;func_0c02a0c4(a,23,0);
}
void func_0c194724(struct LinkedActor *a,struct LinkedActor *owner){
 short offset;
 a->b49=-2;offset=8192;if(!a->sdc.w130)offset=-8192;
 a->sdc.b12c=1;a->f52=owner->f52+offset*1.66666663f/256.0f;
 a->f56=owner->f56+216.42856f;
 func_0c02a0c4(a,23,1);
}
void func_0c19476a(struct LinkedActor *a,struct LinkedActor *owner){
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;
 a->b36=owner->b36;table_0c257cac[a->b32](a,owner);
}
