#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c25bd3c[])(struct LinkedActor *,struct LinkedActor *);
void func_0c1bc7e8(struct LinkedActor *);
struct LinkedActor *func_0c1bc740(struct LinkedActor *parent,unsigned char kind,unsigned char selector) {
 struct LinkedActor *a;
 if((a=func_0c0374da(0,3,0))!=0) {
  short *cache;
  a->p16=func_0c1bc7e8; a->w38=0x3700;
  a->p24=parent;
  a->b1=parent->b1; a->b32=kind; a->b33=selector;
  cache=&a->wcc.short_value;
  *cache=parent->sdc.w158.short_value;
 }
 return a;
}
struct LinkedActor *func_0c1bc794(struct LinkedActor *parent,unsigned char kind,unsigned char selector) {
 struct LinkedActor *a;
 if((a=func_0c0374da(0,4,0))!=0) {
  short *cache;
  a->p16=func_0c1bc7e8; a->w38=0x3700;
  a->p24=parent;
  a->b1=parent->b1; a->b32=kind; a->b33=selector;
  cache=&a->wcc.short_value;
  *cache=parent->sdc.w158.short_value;
 }
 return a;
}
void func_0c1bc7e8(struct LinkedActor *a) { table_0c25bd3c[a->b32](a,a->p24); }
