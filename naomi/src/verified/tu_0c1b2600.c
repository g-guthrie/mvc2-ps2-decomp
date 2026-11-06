#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern void (*table_0c25ae60[])(struct LinkedActor *);
extern void (*table_0c25ae70[])(struct LinkedActor *);
extern void (*table_0c25ae7c[])(struct LinkedActor *);
extern void (*table_0c25ae84[])(struct LinkedActor *);
void func_0c1b2654(struct LinkedActor *);
void func_0c1b266c(struct LinkedActor *);
struct LinkedActor *func_0c1b2600(struct LinkedActor *parent,unsigned char kind,unsigned char selector) {
 struct LinkedActor *a;
 if((a=func_0c0374da(0,3,0))!=0) {
  short *cache;
  a->p16=func_0c1b2654; a->p24=parent;
  a->b32=kind; a->b33=selector; a->w38=0x2300;
  cache=&a->wcc.short_value; a->b1=parent->b1; *cache=parent->sdc.w158.short_value;
 }
 return a;
}
void func_0c1b2654(struct LinkedActor *a) { table_0c25ae60[a->b4](a); }
void func_0c1b2666(struct LinkedActor *a) { a->b4++; func_0c1b266c(a); }
void func_0c1b266c(struct LinkedActor *a) { table_0c25ae70[a->b32](a); }
void func_0c1b2680(struct LinkedActor *a) { table_0c25ae7c[(unsigned char)a->b5](a); }
void func_0c1b2692(struct LinkedActor *a) {
 a->b5++;
 a->sdc=a->p24->sdc; a->sdc.b12c=1;
 a->b2=a->p24->b2; a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x; a->v80.y=a->p24->v80.y;
 a->b1a3=a->p24->b1a3; a->b1a4=a->p24->b1a4;
 a->b48=a->p24->b48; a->v80=a->p24->v80;
 a->b36=a->p24->b36;
 a->b36=0;
 a->f52=a->p24->f52; a->f56=a->p24->f56+-6.42857143f;
 func_0c02a0c4(a,23,0);
}
void func_0c1b271c(struct LinkedActor *a) { short *cache=&a->wcc.short_value; if(*cache!=a->p24->sdc.w158.short_value) a->b4=2; }
void func_0c1b2734(struct LinkedActor *a) { table_0c25ae84[(unsigned char)a->b5](a); }
