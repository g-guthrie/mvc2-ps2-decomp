#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0429a4(struct Actor *,struct LinkedActorVec3 *,int),func_0c19d2ac(struct Actor *,int,int),func_0c02a0c4(struct Actor *,int,int);
extern struct LinkedActor *func_0c148d54(struct Actor *,unsigned char,unsigned char);
void func_0c09bca0(struct Actor *a)
{
 struct LinkedActorVec3 position;
 a->b3f8=2;a->b328=5;a->b3f1=a->b255==6?2:0;func_0c02a026(a);
 if(a->b141){int zero=0;a->b6++;a->b141=zero;a->b3f0=zero;a->b3f1=zero;
  position.x=-103.33333f;position.y=167.142853f;position.z=0.0f;func_0c0429a4(a,&position,1);
  a->s28=7;a->s30=zero;}
}
void func_0c09bd1e(struct Actor *a)
{
 a->b3f8=2;a->b328=5;func_0c02a026(a);
 if(a->b141){a->b141=0;func_0c148d54(a,1,a->s30&3);func_0c19d2ac(a,6,a->s30&3);func_0c19d2ac(a,15,a->s30&3);
  a->s30++;if(--a->s28==0)a->b6++;}
}
void func_0c09bd8a(struct Actor *a)
{
 a->b3f8=2;a->b328=5;func_0c02a026(a);
 if(func_0c02a026(a)<0){a->b6++;func_0c02a0c4(a,22,5);}
}
