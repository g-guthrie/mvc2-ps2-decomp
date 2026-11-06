/* Full attachment-frame follower group; five functions exact. Update differs only in the frame temporary register. */
#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c252ab0[])(struct LinkedActor *,struct LinkedActor *);
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c037688(struct LinkedActor *);
void func_0c1738a0(struct LinkedActor *),func_0c17392c(struct LinkedActor *,struct LinkedActor *),func_0c173974(struct LinkedActor *,struct LinkedActor *);
struct LinkedActor *func_0c173868(struct LinkedActor *p)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,0))){a->p16=func_0c1738a0;a->p24=p;a->w38=0x2f01;A(a)->i204=*(unsigned short *)&A(p)->b158;}
 return a;
}
void func_0c1738a0(struct LinkedActor *a){table_0c252ab0[a->b4](a,a->p24);}
void func_0c1738b4(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;a->b2=owner->b2;a->b1=owner->b1;a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;a->b49=-1;
 func_0c02a0c4(a,21,13);func_0c17392c(a,owner);
}
void func_0c17392c(struct LinkedActor *a,struct LinkedActor *owner)
{
 func_0c02a026(a);a->b36=owner->b36;
 *(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&owner->f52;
 {int frame=*(unsigned short *)&A(owner)->b158;if(A(a)->i204!=frame)func_0c173974(a,owner);}
}
void func_0c173970(struct LinkedActor *a,struct LinkedActor *owner){}
void func_0c173974(struct LinkedActor *a,struct LinkedActor *owner){a->sdc.b12c=0;func_0c037688(a);}
