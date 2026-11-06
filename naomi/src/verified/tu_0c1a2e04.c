#include "objects.h"
extern char func_0c029fc4(struct LinkedActor *);
extern int func_0c02849a(void);
extern void (*table_0c258f5c[])(struct LinkedActor *);
extern void func_0c029e70(struct LinkedActor *,unsigned char,unsigned char);
void func_0c1a2e04(struct LinkedActor *a)
{ if(func_0c029fc4(a)<0) a->b4=2; }
void func_0c1a2e22(struct LinkedActor *a)
{
 struct LinkedActor *parent;
 struct Actor *target;
 float vertical,horizontal;
 a->sdc.b12c=0;
 parent=a->p24;
 if(parent->sdc.b141==2) a->b4=2;
 else if(parent->sdc.b141==3) {
  target=((struct Actor *)parent)->p1c8;
  vertical=0.53571428f;
  horizontal=0.41666666f;
  switch(func_0c02849a()&3) {
  case 0: target->f52+=horizontal; target->f56+=vertical; return;
  case 1: target->f52-=horizontal; goto subtract_y;
  case 2: target->f52-=horizontal; target->f56+=vertical; return;
  case 3: target->f52+=horizontal;
  subtract_y: target->f56-=vertical; return;
  }
 }
}
void func_0c1a2ea8(struct LinkedActor *a)
{
 short *state=&a->wcc.short_value;
 struct LinkedActor *parent=a->p24;
 if(*state!=parent->sdc.w158.short_value) a->b4=2;
 else {
  table_0c258f5c[a->b6](a);
  a->b36=parent->b36;
  a->b49=-1;
 }
}
void func_0c1a2ee8(struct LinkedActor *a)
{
 a->b6++;
 func_0c029e70(a,27,a->b32);
 a->sdc.w130=0;
 a->f56+=154.28571f;
}
