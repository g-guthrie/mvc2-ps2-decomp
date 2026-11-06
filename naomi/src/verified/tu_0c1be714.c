#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c037688(struct LinkedActor *);
extern void func_0c1d330c(struct LinkedActor *,struct LinkedActorVec3 *,int,int);
extern void (*table_0c25bf34[])(struct LinkedActor *,struct LinkedActor *);
void func_0c1be748(struct LinkedActor *);
void func_0c1be7b4(struct LinkedActor *,struct LinkedActor *);
void func_0c1be84c(struct LinkedActor *,struct LinkedActor *);
struct LinkedActor *func_0c1be714(struct LinkedActor *parent,int selector) {
 struct LinkedActor *a;
 if((a=func_0c0374da(0,3,1))!=0) {a->p16=func_0c1be748; a->p24=parent; a->w38=0x3a00; a->b32=selector;}
 return a;
}
void func_0c1be748(struct LinkedActor *a) {table_0c25bf34[a->b4](a,a->p24);}
void func_0c1be75c(struct LinkedActor *a,struct LinkedActor *parent) {
 a->b4++;
 a->sdc=parent->sdc; a->sdc.b12c=1;
 a->b2=parent->b2; a->b1=parent->b1;
 a->v80.x=parent->v80.x; a->v80.y=parent->v80.y;
 a->b1a3=parent->b1a3; a->b1a4=parent->b1a4;
 a->b48=parent->b48; a->v80=parent->v80;
 a->b36=parent->b36;
 func_0c1be7b4(a,parent);
}
void func_0c1be7b4(struct LinkedActor *a,struct LinkedActor *parent) {
 struct LinkedActorVec3 pos;
 if(!parent->b5) {
  if(((struct Actor *)parent)->b1d0!=21 || ((struct Actor *)parent)->b1e9!=9) goto finish;
  a->sdc.b12c=1;
  ((struct Actor *)a)->l144=((struct Actor *)parent)->l144;
  a->f52=parent->f52;
  a->f56=((struct Actor *)parent)->f41c;
  a->sdc.w130=parent->sdc.w130;
  ((struct Actor *)parent)->f56=((struct Actor *)parent)->f41c+((struct Actor *)parent)->b14b*2.1428571f;
 } else {
  pos.x=a->f52; pos.y=((struct Actor *)parent)->f41c+102.85714f; pos.z=a->f60;
  func_0c1d330c(a,&pos,1,8);
finish:
  func_0c1be84c(a,parent);
 }
}

void func_0c1be84c(struct LinkedActor *a,struct LinkedActor *parent) {a->b4++;a->sdc.b12c=0;func_0c037688(a);}
