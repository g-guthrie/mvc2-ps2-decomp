#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c259e00[])(struct LinkedActor *);
extern void (*table_0c259e10[])(struct LinkedActor *,struct LinkedActor *);
extern void (*table_0c259e48[])(struct LinkedActor *,struct LinkedActor *);
void func_0c1acd1c(struct LinkedActor *);
void func_0c1acd9a(struct LinkedActor *);
struct LinkedActor *func_0c1accc0(struct LinkedActor *parent,unsigned char selector) {
 struct LinkedActor *a;
 if((a=func_0c0374da(0,3,0))!=0) { a->p16=func_0c1acd1c; a->p24=parent; a->b32=selector; }
 return a;
}
struct LinkedActor *func_0c1accee(struct LinkedActor *parent,unsigned char selector) {
 struct LinkedActor *a;
 if((a=func_0c0374da(0,4,0))!=0) { a->p16=func_0c1acd1c; a->p24=parent; a->b32=selector; }
 return a;
}
void func_0c1acd1c(struct LinkedActor *a) { table_0c259e00[a->b4](a); }
void func_0c1acd2e(struct LinkedActor *a) {
 struct LinkedActor *parent=a->p24;
 a->b4++; a->w38=0x1c07;
 a->sdc=parent->sdc;
 a->sdc.b12c=1;
 a->b2=parent->b2; a->b1=parent->b1;
 a->v80.x=parent->v80.x; a->v80.y=parent->v80.y;
 a->b1a3=parent->b1a3; a->b1a4=parent->b1a4;
 a->b48=parent->b48; a->v80=parent->v80;
 a->b36=parent->b36;
 ((struct Actor *)a)->b0=1;
 a->sdc.b12c=1; a->b36=7;
 func_0c1acd9a(a);
}
void func_0c1acd9a(struct LinkedActor *a) { table_0c259e10[a->b32](a,a->p24); }
void func_0c1acdb0(struct LinkedActor *a,struct LinkedActor *parent) {
 unsigned char *sub=(unsigned char *)&((struct Actor *)parent)->sub2a4;
 if(parent->b5 || parent->b1d0!=29) { sub[11]=0; sub[10]=1; }
 table_0c259e48[a->b7](a,parent);
}
