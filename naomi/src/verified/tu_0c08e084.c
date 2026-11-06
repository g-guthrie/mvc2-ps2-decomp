#include "objects.h"
extern void func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c0437b8(struct Actor *);
extern void func_0c02a39a(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c1418f8(struct Actor *,int,int);
extern char func_0c02a026(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern void (*table_0c242934[])(struct Actor *);
extern void func_0c0429a4(struct Actor *,struct LinkedActorVec3 *,int);
void func_0c08e116(struct Actor *,struct ActorSub2a4 *);
void func_0c08e2da(struct Actor *,struct ActorSub2a4 *);
void func_0c08e084(struct Actor *a,struct ActorSub2a4 *sub)
{
 if(a->b255==6){a->b3f0=255;a->b3f1=16;}
 a->b6++;func_0c0442fa(a);func_0c02a39a(a,0);func_0c0432ca(a);
 a->f92=0;a->f96=0;a->f104=0;a->f108=0;
 a->b1f9=0;a->f56=a->f41c;a->b1a1=79;a->w1ac=0;a->b19e=0;*(unsigned int *)&a->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,22,10);func_0c08e116(a,sub);
}
void func_0c08e116(struct Actor *a,struct ActorSub2a4 *sub)
{
 struct LinkedActorVec3 position;
 a->b3f8=2;a->b328=5;a->b3f1=a->b255==6?2:0;func_0c02a026(a);
 if(a->b141&1){
 a->b141&=0xfe;a->b6++;
 position.x=-13.33333302f;position.y=300.0f;position.z=0;
 a->b3f0=0;a->b3f1=0;func_0c0429a4(a,&position,1);
 }
}
void func_0c08e18e(struct Actor *a)
{
 a->b3f8=2;a->b328=5;
 if(func_0c02a026(a)<0){a->b3f9=0;a->b3f8=0;a->b327=0;a->b328=0;func_0c0437b8(a);}
 else if(a->b141&2){a->b141&=0xfd;func_0c1418f8(a,2,0);dat_0c2d9260.b5=3;dat_0c2d9260.b6=1;}
}
void func_0c08e236(struct Actor *a){table_0c242934[a->b6](a);}
void func_0c08e248(struct Actor *a,struct ActorSub2a4 *sub)
{
 if(a->b255==6){a->b3f0=255;a->b3f1=16;}
 a->b6++;func_0c0442fa(a);func_0c02a39a(a,0);func_0c0432ca(a);
 a->f92=0;a->f96=0;a->f104=0;a->f108=0;
 a->b1f9=0;a->f56=a->f41c;a->b1a1=84;a->w1ac=0;a->b19e=0;*(unsigned int *)&a->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,22,13);func_0c08e2da(a,sub);
}
void func_0c08e2da(struct Actor *a,struct ActorSub2a4 *sub)
{
 struct LinkedActorVec3 position;
 a->b3f8=2;a->b328=5;a->b3f1=a->b255==6?2:0;func_0c02a026(a);
 if(a->b141&1){
 a->b141&=0xfe;a->b6++;
 position.x=95.0f;position.y=261.42856f;position.z=0;
 a->b3f0=0;a->b3f1=0;func_0c0429a4(a,&position,1);
 }
}
