#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c037688(struct LinkedActor *);
extern void (*table_0c259f88[])(struct LinkedActor *);
void func_0c1af006(struct LinkedActor *);
void func_0c1af0a0(struct LinkedActor *);
struct LinkedActor *func_0c1aefcc(struct LinkedActor *parent) {
 struct LinkedActor *a;
 if((a=func_0c0374da(0,3,0))!=0) { a->p16=func_0c1af006; a->p24=parent; a->w38=0x1e02; a->b32=((char *)&((struct Actor *)parent)->w150)[1]; }
 return a;
}
void func_0c1af006(struct LinkedActor *a) { table_0c259f88[a->b4](a); }
void func_0c1af018(struct LinkedActor *a) {
 a->b4++;
 a->sdc=a->p24->sdc; a->sdc.b12c=1;
 a->b2=a->p24->b2; a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x; a->v80.y=a->p24->v80.y;
 a->b1a3=a->p24->b1a3; a->b1a4=a->p24->b1a4;
 a->b48=a->p24->b48; a->v80=a->p24->v80;
 a->b36=a->p24->b36;
 a->sdc.b12c=1; a->b36=15; a->s28=8;
 a->f52=a->p24->f52; a->f56=a->p24->f56;
 func_0c1af0a0(a);
}
void func_0c1af0a0(struct LinkedActor *a) { if(--a->s28<=0) a->b4++; }
void func_0c1af0b6(struct LinkedActor *a) { a->b4++; a->sdc.b12c=0; func_0c037688(a); }
