#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c181116(struct LinkedActor *);
extern void (*table_0c253ff4[])(struct LinkedActor *);
extern void (*table_0c254024[])(struct LinkedActor *);
void func_0c17edfc(struct LinkedActor *);
struct LinkedActor *func_0c17ed28(struct LinkedActor *owner,unsigned char mode,unsigned char value)
{
 struct LinkedActor *child;
 unsigned int *dst;
 if(child=func_0c0374da(0,1,1)){
  child->p16=func_0c17edfc;
  dst=&child->wcc.dword_value;
  child->f52=owner->f52;
  child->f56=owner->f56;
  child->p24=owner;
  child->b1=owner->b1;
  child->w38=0x3504;
  child->b32=mode;
  child->b33=value;
  *dst=(unsigned int)((struct Actor *)owner)->p20c;
 }
 return child;
}
struct LinkedActor *func_0c17ed88(struct LinkedActor *owner)
{
 struct LinkedActor *child;
 unsigned int *dst,*src;
 int i;
 for(i=0;i<8;i++){
  if(child=func_0c0374da(0,1,1)){
   child->p16=func_0c17edfc;
   dst=&child->wcc.dword_value;
   src=&owner->wcc.dword_value;
   child->f52=owner->f52;
   child->f56=owner->f56;
   child->p24=owner->p24;
   child->b1=owner->b1;
   child->w38=0x3504;
   child->b32=9;
   child->b33=i;
   *dst=*src;
   child->p20=owner;
  }
 }
 return child;
}
void func_0c17edfc(struct LinkedActor *a) { func_0c181116(a); table_0c253ff4[a->b32](a); }
void func_0c17ee1a(struct LinkedActor *a) { table_0c254024[a->b4](a); }
