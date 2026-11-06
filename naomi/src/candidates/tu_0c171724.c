/* Complete motion/history translation. The timed animation update and state
 * dispatcher match exactly. The initialization/update split still shifts
 * later exports, and the motion cleanup differs in register allocation. */
#include "objects.h"
#define M(a) ((struct Actor *)(a))
extern signed char func_0c02a026(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern void func_0c037d0c(struct LinkedActor *);
extern void func_0c0346da(struct LinkedActor *,int);
extern void func_0c037688(struct LinkedActor *);
extern void (*table_0c2528cc[])(struct LinkedActor *);
void func_0c1719be(struct LinkedActor *,struct LinkedActor *);
void func_0c171930(struct LinkedActor *,struct LinkedActor *);
void func_0c171724(struct LinkedActor *a,struct Actor *owner)
{
 float zero;
 func_0c02a026(a);
 a->f52+=M(a)->f92;
 M(a)->f92 += M(a)->f104;
 a->f56+=a->f96;
 a->f96+=M(a)->f108;
 zero=0;
 if(M(a)->f92*M(a)->f104>0.0f) {float stopped=0.0f; M(a)->f92=stopped; M(a)->f104=stopped;}
 if(!(owner->f41c<a->f56)) {
   a->b5++;
   a->f56=owner->f41c;
   a->s28=12;
 } else {
   if(a->pad11[3])goto stop_motion;
   func_0c037d0c(a);
   if(!a->pad11[2])return;
 stop_motion:
   a->b5++;
   a->s28=1;
 }
}
void func_0c1717ce(struct LinkedActor *a)
{
 func_0c02a026(a);
 if(--a->s28==0) {a->b5++;func_0c02a0c4(a,23,13);func_0c0346da(a,73);}
}
void func_0c171806(struct LinkedActor *a,struct LinkedActor *owner)
{
 struct ActorSub2a4 *q=&((struct Actor *)owner)->sub2a4;
 if(func_0c02a026(a)<0) {
   a->b4++;
   q->b2--;
   func_0c1719be(a,owner);
 }
}
void func_0c171846(struct LinkedActor *a) {table_0c2528cc[a->b4](a);}
void func_0c171874(struct LinkedActor *a,struct LinkedActor *owner)
{
 struct LinkedActor *p;
 char *samples;
 unsigned int i;
 a->b4++;
 samples=(char *)&M(a)->f92;
 p=a->p20;
 a->sdc=owner->sdc;
 a->sdc.b12c=1;
 a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;
 a->v80=owner->v80;
 a->b36=owner->b36;
 a->sdc.b12c=1;
 a->b49=-1;
 a->f52=p->f52;a->f56=p->f56;a->f60=p->f60;
 i=0;do {
   *(short *)(i+samples)=(short)a->f52;
   *(short *)(i+(samples+8))=(short)a->f56;
 }while((i+=2)<8);
 func_0c02a0c4(a,23,12);
 func_0c171930(a,owner);
}
void func_0c171930(struct LinkedActor *a,struct LinkedActor *owner)
{
 struct LinkedActor *parent=a->p20;
 struct LinkedActor *p=*(struct LinkedActor **)((char *)a+8);
 register short *xs=(short *)&M(a)->f92;
 a->b36=owner->b36;func_0c02a026(a);
 a->f52=xs[3];xs[3]=xs[2];xs[2]=xs[1];xs[1]=xs[0];xs[0]=(short)p->f52;
 {
  short *ys=xs+4;
  a->f56=xs[7];ys[3]=ys[2];ys[2]=ys[1];ys[1]=ys[0];ys[0]=(short)p->f56;
 }
 if((unsigned char)parent->b5==2)a->b4++;
}
void func_0c1719be(struct LinkedActor *a,struct LinkedActor *owner) {a->b4++;a->sdc.b12c=0;}
void func_0c1719cc(struct LinkedActor *a) {a->sdc.b12c=0;func_0c037688(a);}
