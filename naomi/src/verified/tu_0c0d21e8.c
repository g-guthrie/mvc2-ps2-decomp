/* Throw follow-up handlers 0x0c0d21e8-0x0c0d2444; flag test spelled as in tu_0c0d6094. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c043324(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c02a39a(struct Actor *,int),func_0c0439c4(struct Actor *),func_0c048ce6(struct Actor *),func_0c025900(struct Actor *,char,char),func_0c1d4610(struct Actor *,struct LinkedActorVec3 *);
extern struct Actor *func_0c037d54(struct Actor *);
extern struct LinkedActor *func_0c1b0b40(struct LinkedActor *,unsigned char);
void func_0c0d21e8(struct Actor *a)
{
 func_0c02a026(a);a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(func_0c044e52(a)){func_0c043324(a);a->b6++;func_0c02a0c4(a,20,1);}
}
void func_0c0d2256(struct Actor *a){if(func_0c02a026(a)<0){func_0c02a39a(a,0);func_0c0439c4(a);}}
struct Actor *func_0c0d227e(struct Actor *a)
{
 int zero=0;struct Actor *target=(struct Actor *)zero;
 if((a->w1fa&0x0c00)&&!a->b1fe&&a->b1a3){
  if((target=func_0c037d54(a))){if(a->b1f9==2)a->b1f7=1;else if(!a->b1f9)a->b1f7=zero;else target=(struct Actor *)zero;}
 }
 return target;
}
void func_0c0d22e0(struct Actor *a)
{
 struct Actor *other;struct LinkedActorVec3 p;
 if(!a->b1f7){p.x=-26.666666031f;p.y=175.71428f;}else{p.x=-61.666664124f;p.y=109.2857132f;}
 if(!(a->w1fa&0x800))a->b1d2=a->w130=a->w130^1;
 a->p1c8->b1d2=a->p1c8->w130=a->w130^1;
 func_0c048ce6(a);a->b1a0=10;
 {struct ActorFlags64 *f;f=(struct ActorFlags64 *)&(other=a->p1c8)->l414;&other;if(((f->hi&0)|(f->lo&0x04000000))&&!a->b1f7)a->p1c8->f56=a->f41c+102.85714f;}
 func_0c025900(a,6,6);func_0c1d4610(a,&p);func_0c02a0c4(a,15,0);
}
void func_0c0d23d8(struct Actor *a)
{
 func_0c02a026(a);if(a->b141){a->b6++;a->b141=0;func_0c1b0b40((struct LinkedActor *)a,2);}
}
