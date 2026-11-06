#include "objects.h"
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern void func_0c1d53e4(struct LinkedActor *);
extern void func_0c02a026(struct LinkedActor *);
extern void func_0c1cea66(struct LinkedActor *,struct LinkedActorVec3 *,int);
extern void (*table_0c259f40[])(struct LinkedActor *,struct LinkedActor *);
void func_0c1ae974(struct LinkedActor *,struct LinkedActor *);
void func_0c1ae908(struct LinkedActor *a,struct LinkedActor *parent) { table_0c259f40[a->b7](a,parent); }
void func_0c1ae91a(struct LinkedActor *a,struct LinkedActor *parent) {
 a->b7++; a->s28=70;
 if(!(a->sdc.w130=parent->sdc.w130)) a->f52=parent->f52-98.33333f;
 else a->f52=parent->f52+98.33333f;
 a->f56=parent->f56+6.428571224213f;
 func_0c02a0c4(a,25,22);
 ((struct Actor *)a)->b0=1;
 func_0c1d53e4(a);
 func_0c1ae974(a,parent);
}
void func_0c1ae974(struct LinkedActor *a,struct LinkedActor *parent) {
 struct LinkedActorVec3 offset;
 if(--a->s28==0) {
  a->b7++;
  a->f92=!a->sdc.w130?-3.3333333f:3.3333333f;
  a->f104=0.0f; a->f96=4.28571415f; a->f108=-0.80357140303f;
  offset.x=0.0f; offset.y=34.2857132f;
  func_0c1cea66(a,&offset,0);
  func_0c02a0c4(a,25,20);
  return;
 }
 func_0c02a026(a);
}
void func_0c1ae9ee(struct LinkedActor *a,struct LinkedActor *parent) {
 float target;
 a->f52+=a->f92; a->f92+=a->f104;
 a->f56+=a->f96; a->f96+=a->f108;
 target=((struct Actor *)parent)->f41c+6.428571224213f;
 if(a->f56>target) return;
 a->b7++; a->f56=target;
 func_0c02a0c4(a,18,8);
}
