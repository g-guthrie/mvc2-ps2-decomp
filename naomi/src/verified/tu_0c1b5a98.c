#include "objects.h"
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern void func_0c1d53e4(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern void func_0c02a026(struct LinkedActor *);
extern void (*table_0c25b11c[])(struct LinkedActor *);
void func_0c1b5a98(struct LinkedActor *a,struct LinkedActor *parent) {
 float position;
 a->sdc=parent->sdc; a->sdc.b12c=1;
 a->b2=parent->b2; a->b1=parent->b1;
 a->v80.x=parent->v80.x; a->v80.y=parent->v80.y;
 a->b1a3=parent->b1a3; a->b1a4=parent->b1a4;
 a->b48=parent->b48; a->v80=parent->v80;
 a->b36=parent->b36;
 a->b4++; a->b36=11;
 a->f56=((struct Actor *)parent)->f41c;
 position=dat_0c2d9260.f8c+106.666664124f; a->f92=-10.0f;
 if(((struct Actor *)parent)->b1d2) { position=dat_0c2d9260.f88-106.666664124f; a->f92=-a->f92; }
 a->f52=position; func_0c1d53e4(a); func_0c02a0c4(a,23,28);
}
void func_0c1b5b46(struct LinkedActor *a,struct LinkedActor *parent) {
 float difference,offset;
 switch((unsigned char)a->b5) {
 case 0:
  a->f52+=a->f92; a->f92+=a->f104; func_0c02a026(a);
  difference=a->f52-parent->f52;
  if(difference<0) difference=-difference;
  if(difference<106.666664124f) {
   a->b5++;
   offset=106.666664124f;
   if(((struct Actor *)parent)->b1d2) offset=-106.666664124f;
   a->f52=parent->f52+offset;
   a->f92=0; a->f96=0; a->f104=0; a->f108=0;
   func_0c02a0c4(a,23,29);
  }
  break;
 case 1:
  if(!parent->sdc.b141) {
   func_0c02a026(a);
   if(a->sdc.b141) { a->b5++; a->sdc.b141=0; parent->b33|=0x80; }
  }
  break;
 case 2: func_0c02a026(a); break;
 }
}
void func_0c1b5c50(struct LinkedActor *a) { table_0c25b11c[a->b4](a); }
