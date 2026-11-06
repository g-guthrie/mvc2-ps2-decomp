#include "objects.h"
extern void func_0c1d2a56(struct LinkedActorVec3 *,int);
extern void func_0c0346da(struct Actor *,int);
extern void func_0c042018(struct Actor *);
extern void func_0c0421b8(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c04933c(struct Actor *);
extern unsigned char func_0c043a10(struct Actor *);
extern unsigned char func_0c044ae4(struct Actor *);
extern void func_0c045248(struct Actor *,int);
extern void func_0c02a0c4(struct Actor *,int,int);
extern unsigned char func_0c044e52(struct Actor *);
extern unsigned char func_0c044846(struct Actor *);
extern unsigned char func_0c044be2(struct Actor *);
extern void func_0c044f1c(struct Actor *);
extern void func_0c0438de(struct Actor *);
void func_0c03b48c(struct Actor *a)
{
 struct LinkedActorVec3 position;
 if(a->b1dd<0 && a->b1de){
 a->b6=2;a->s28=28;a->b1dd=0;
 position.x=a->position24c.x;position.y=a->position24c.y;position.z=a->f60;
 func_0c1d2a56(&position,(short)a->w130);func_0c0346da(a,68);return;
 }
 func_0c042018(a);func_0c0421b8(a);func_0c02a026(a);
 if(a->b1de){a->b1de--;func_0c04933c(a);}
 else{
 a->b211=0;
 if(func_0c043a10(a))return;
 if(!func_0c044ae4(a)){
 if(a->f108>-0.066964284f)a->f108=-0.80357140303f;
 a->f104=0;
 if(!a->b1fc){a->b6=1;func_0c045248(a,3);}else{a->b6=1;func_0c045248(a,14);}
 func_0c02a0c4(a,1,9);return;
 }
 }
 if(func_0c044e52(a)){
 if(a->b1de)a->b1ef=8;
 if(!func_0c044846(a) && !func_0c044be2(a))func_0c044f1c(a);
 }
}
void func_0c03b5f6(struct Actor *a)
{
 struct Actor *target=a->p1b8;
 float offset;
 if(!target)target=a->p20c;
 if(--a->s28<=0){func_0c0438de(a);return;}
 offset=5.0f;if(target->w130)offset=-5.0f;
 if(!((char)target->b1fd&(1<<(short)target->w130)))target->f52=target->f52+offset;
}
