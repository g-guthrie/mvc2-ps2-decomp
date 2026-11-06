#include "objects.h"
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern void func_0c0344a0(struct LinkedActor *,int);
extern void func_0c037688(struct LinkedActor *);
void func_0c1bdc78(struct LinkedActor *a,struct LinkedActor *parent) {
 struct LinkedActor *host;
 if(!a->b4) {
  a->b4++;
 a->sdc=parent->sdc; a->sdc.b12c=1;
 a->b2=parent->b2; a->b1=parent->b1;
 a->v80.x=parent->v80.x; a->v80.y=parent->v80.y;
 a->b1a3=parent->b1a3; a->b1a4=parent->b1a4;
 a->b48=parent->b48; a->v80=parent->v80;
 a->b36=parent->b36;
  func_0c02a0c4(a,18,4);
 }
 host=a->p20;
 a->f52=host->f52; a->f56=host->f56; a->b36=host->b36;
 if(host->sdc.b141) { host->sdc.b141=0; func_0c037688(a); }
}
void func_0c1bdd12(struct LinkedActor *a,struct LinkedActor *parent) {
 if(!a->b4) {
  a->b4++;
 a->sdc=parent->sdc; a->sdc.b12c=1;
 a->b2=parent->b2; a->b1=parent->b1;
 a->v80.x=parent->v80.x; a->v80.y=parent->v80.y;
 a->b1a3=parent->b1a3; a->b1a4=parent->b1a4;
 a->b48=parent->b48; a->v80=parent->v80;
 a->b36=parent->b36;
  a->f52=parent->f52; a->f56=parent->f56;
  a->s28=parent->sdc.w158.short_value; a->b49=-8;
  func_0c02a0c4(a,18,a->b33+7);
  func_0c0344a0(parent,31);
 }
 a->b36=parent->b36;
 if(a->s28!=(unsigned short)parent->sdc.w158.short_value) func_0c037688(a);
}
