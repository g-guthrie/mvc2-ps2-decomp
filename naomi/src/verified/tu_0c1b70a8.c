#include "objects.h"
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern void func_0c02a026(struct LinkedActor *);
extern void (*table_0c25b524[])(struct LinkedActor *,struct LinkedActor *);
void func_0c1b70a8(struct LinkedActor *a,struct LinkedActor *parent) {
 a->sdc=parent->sdc; a->sdc.b12c=1;
 a->b2=parent->b2; a->b1=parent->b1;
 a->v80.x=parent->v80.x; a->v80.y=parent->v80.y;
 a->b1a3=parent->b1a3; a->b1a4=parent->b1a4;
 a->b48=parent->b48; a->v80=parent->v80;
 a->b36=parent->b36;
 a->b4++; a->b36=7;
 *(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&parent->f52;
 a->s28=8; func_0c02a0c4(a,23,8);
}
void func_0c1b7120(struct LinkedActor *a,struct LinkedActor *parent) {
 if(parent->b5 || parent->b1d0!=29 || --a->s28==0) { a->b4=2; a->sdc.b12c=0; }
 else func_0c02a026(parent);
}
void func_0c1b7158(struct LinkedActor *a,struct LinkedActor *parent) { table_0c25b524[a->b4](a,parent); }
void func_0c1b716a(struct LinkedActor *a,struct LinkedActor *parent) {
 a->sdc=parent->sdc; a->sdc.b12c=1;
 a->b2=parent->b2; a->b1=parent->b1;
 a->v80.x=parent->v80.x; a->v80.y=parent->v80.y;
 a->b1a3=parent->b1a3; a->b1a4=parent->b1a4;
 a->b48=parent->b48; a->v80=parent->v80;
 a->b36=parent->b36;
 a->b4++; a->b36=12;
 *(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&parent->f52;
 func_0c02a0c4(a,23,9);
}
