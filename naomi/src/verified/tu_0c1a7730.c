#include "objects.h"
extern void func_0c029fc4(struct LinkedActor *);
extern void (*table_0c259388[])(struct LinkedActor *,struct LinkedActor *);
void func_0c1a7730(struct LinkedActor *a,struct LinkedActor *parent) {
 func_0c029fc4(a);
 if(parent->b1d0) ((struct Actor *)a)->f100=0.050000001f;
 else if(--a->s28==0) ((struct Actor *)a)->f100=0.0125000002f;
 else return;
 a->b5++;
}
void func_0c1a7772(struct LinkedActor *a) {
 func_0c029fc4(a);
 ((struct Actor *)a)->f264-=((struct Actor *)a)->f100;
 if(((struct Actor *)a)->f264>0.0f) return;
 a->b4++; a->sdc.b12c=0;
 if(((struct Actor *)a->p20)->b3==3 && a->p20->w38==0x1802) {
  a->p20->b35 &= ~a->b35;
  if(a->b32==7) goto clear_bit;
  if(a->b32==8) { clear_bit: a->p20->b35 &= 254; }
 }
}
void func_0c1a77ec(struct LinkedActor *a,struct LinkedActor *parent) {
 table_0c259388[(unsigned char)a->b5](a,parent);
 if(!(a->sdc.w130=parent->sdc.w130)) a->f52=parent->f52+a->f92;
 else a->f52=parent->f52-a->f92;
 a->f56=parent->f56+a->f96;
 a->b36=parent->b36;
}
