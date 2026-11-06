#include "objects.h"
extern struct LinkedActor *func_0c0374da(void *,int,int);
extern void (*table_0c250f1c[])(struct LinkedActor *);
extern void (*table_0c250f40[])(struct LinkedActor *);
void func_0c15e3a2(struct LinkedActor *);
struct LinkedActor *func_0c15e32c(struct Actor *owner)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,0))!=0){
  unsigned char *p;
  a->p16=func_0c15e3a2;a->p24=(struct LinkedActor *)owner;a->b32=0;
  p=(unsigned char *)&owner->sub2a4;p[7]=1;p[8]=1;p[9]=0;
 }
 return a;
}
struct LinkedActor *func_0c15e36e(struct Actor *owner,unsigned char mode)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(owner,1,2))!=0){a->p16=func_0c15e3a2;a->p24=(struct LinkedActor *)owner;a->b32=mode;}
 return a;
}
void func_0c15e3a2(struct LinkedActor *a){table_0c250f1c[a->b32](a);}
void func_0c15e3b6(struct LinkedActor *a){table_0c250f40[a->b4](a);}
