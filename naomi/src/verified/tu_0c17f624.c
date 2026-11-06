#include "objects.h"
extern void func_0c181094(struct LinkedActor *),func_0c180cbc(struct LinkedActor *),func_0c180cf8(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern void func_0c180e1a(struct LinkedActor *),func_0c180e44(struct LinkedActor *),func_0c180dd2(struct LinkedActor *);
extern int func_0c180e52(struct LinkedActor *),func_0c180f3e(struct LinkedActor *);
extern void (*table_0c25407c[])(struct LinkedActor *),(*table_0c254084[])(struct LinkedActor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c17f624(struct LinkedActor *a)
{
 struct LinkedActor *owner;
 a->b4++; a->b5=0; a->b6=0;
 owner=a->p24;
 func_0c181094(a);
 a->f52=owner->f52; a->f56=owner->f56;
 func_0c180cbc(a);
 ((struct Actor *)a)->b1a1=22; ((struct Actor *)a)->w1ac=0; ((struct Actor *)a)->b19e=0; ((struct Actor *)a)->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;
 func_0c180cf8(a);
 func_0c02a0c4(a,25,19);
}
void func_0c17f694(struct LinkedActor *a){if(((struct Actor *)a)->b19f)func_0c180e1a(a);else if(func_0c180e52(a))func_0c180e44(a);else table_0c25407c[(unsigned char)a->b5](a);}
void func_0c17f6d2(struct LinkedActor *a)
{
 if(((struct Actor *)a)->b19e){
  struct Actor *other=((struct Actor *)a)->p1b0;
  if(other->b3 == 0 && !*((char *)other+0x411) && ((unsigned char)other->b1<24 || (unsigned char)other->b1>26) && !(((struct Actor *)a)->b19e&127)) { goto detach;detach:func_0c180dd2(a);return; }
 }else if(!func_0c180f3e(a))goto dispatch;
 goto feedback;feedback:func_0c180e44(a);return;
 dispatch: table_0c254084[a->b6](a);
}
