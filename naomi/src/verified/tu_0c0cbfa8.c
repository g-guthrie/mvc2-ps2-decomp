/* Motion, landing and effect callbacks, 0c0cbfa8..0c0cc8f8. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c043324(struct Actor *),func_0c0438de(struct Actor *),func_0c0437b8(struct Actor *),func_0c0442fa(struct Actor *),func_0c048bb0(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c161fc4(struct Actor *),func_0c1aefcc(struct Actor *);
extern struct LinkedActor *func_0c161300(struct LinkedActor *,unsigned char);
extern void func_0c0429a4(struct Actor *,struct LinkedActorVec3 *,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*dat_0c247fc4[])(struct Actor *,struct ActorSub2a4 *);
extern void (*dat_0c247fd0[])(struct Actor *),(*dat_0c247fe4[])(struct Actor *),(*dat_0c247ff4[])(struct Actor *);
#define MOVE a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108
#define CLEAR_RECORD a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++
void func_0c0cc058(struct Actor *),func_0c0cc1d4(struct Actor *),func_0c0cc4dc(struct Actor *);
void func_0c0cbfa8(struct Actor *a)
{
 MOVE;
 if(!(a->f56>a->f41c)){a->b6++;a->f56=a->f41c;a->b1f9=0;func_0c043324(a);func_0c02a0c4(a,1,3);}
 else if(func_0c02a026(a)<0)func_0c0438de(a);
}
void func_0c0cc036(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c0cc058(struct Actor *a){MOVE;if(!(a->f56>a->f41c))a->f56=a->f41c;}
void func_0c0cc0a8(struct Actor *a){dat_0c247fc4[a->b6](a,&a->sub2a4);}
void func_0c0cc0dc(struct Actor *a,struct ActorSub2a4 *state)
{
 int zero;
 a->b6++;func_0c0442fa(a);func_0c048bb0(a,2);zero=0;
 a->b1a1=a->b1a3+64;CLEAR_RECORD;
 a->f92/=16.0f;a->f96/=8.0f;a->f108/=64.0f;a->f104=0.0f;
 func_0c02a0c4(a,21,a->b1a3+14);
}
void func_0c0cc162(struct Actor *a,struct ActorSub2a4 *state)
{
 func_0c0cc058(a);func_0c02a026(a);
 if(a->b141){a->b141=0;a->b6++;func_0c161300((struct LinkedActor *)a,1);}
}
void func_0c0cc194(struct Actor *a,struct ActorSub2a4 *state)
{
 func_0c0cc058(a);
 if(func_0c02a026(a)<0){float stopped=0.0f;a->f96=stopped;a->f108=stopped;func_0c0438de(a);}
}
void func_0c0cc1c2(struct Actor *a){dat_0c247fd0[a->b6](a);}
void func_0c0cc1d4(struct Actor *a)
{
 MOVE;
 if(!(a->f56>a->f41c)){float stopped=0.0f;a->f56=a->f41c;a->f96=stopped;a->f108=stopped;}
}
void func_0c0cc260(struct Actor *a)
{
 int zero;
 if(a->b255==6){a->b3f0=255;a->b3f1=16;}
 a->b6++;func_0c0442fa(a);
 a->f92/=16.0f;a->f96/=16.0f;a->f108/=64.0f;a->f104=0.0f;
 zero=0;a->b1a1=87;CLEAR_RECORD;func_0c02a0c4(a,22,3);
}
void func_0c0cc2e4(struct Actor *a)
{
 struct LinkedActorVec3 position;
 int zero;
 a->b3f8=2;a->b328=5;a->b3f1=a->b255==6?2:0;
 MOVE;func_0c02a026(a);
 if(a->b141){a->b6++;zero=0;a->b141=zero;a->b3f0=zero;a->b3f1=zero;
 position.x=-93.33332825f;position.y=100.7142792f;position.z=0.0f;func_0c0429a4(a,&position,1);}
}
void func_0c0cc3c0(struct Actor *a)
{
 a->b3f8=2;a->b328=5;MOVE;
 if(func_0c02a026(a)<0){a->b6++;a->s28=6;a->s30=80;func_0c02a0c4(a,22,4);}
}
void func_0c0cc438(struct Actor *a)
{
 int zero;
 a->b3f8=2;a->b328=5;func_0c02a026(a);func_0c0cc1d4(a);
 if(--a->s30<=0){a->b6++;zero=0;a->b3f9=zero;a->b3f8=zero;a->b327=zero;a->b328=zero;func_0c02a0c4(a,22,5);return;}
 if(--a->s28<=0){a->s28=4;func_0c161fc4(a);}
}
void func_0c0cc4a6(struct Actor *a){func_0c0cc1d4(a);if(func_0c02a026(a)<0)func_0c0438de(a);}
void func_0c0cc4ca(struct Actor *a){dat_0c247fe4[a->b6](a);}
void func_0c0cc4dc(struct Actor *a){if(--a->s28<0){a->s28=2;func_0c1aefcc(a);}}
void func_0c0cc514(struct Actor *a)
{
 int zero;unsigned char alternate;float speed,acceleration,stopped;
 a->b6++;func_0c0442fa(a);func_0c048bb0(a,2);zero=0;
 a->f56=a->f41c;a->b1f9=zero;a->s28=zero;stopped=0.0f;a->f96=stopped;a->f108=stopped;
 alternate=(unsigned char)a->b1fe;speed=alternate?16.666666031f:25.0f;acceleration=alternate?-0.6770833135f:-0.78125f;
 a->f92=a->b1d2?speed:-speed;a->f104=a->b1d2?acceleration:-acceleration;
 func_0c02a0c4(a,21,21);
}
void func_0c0cc5a6(struct Actor *a)
{
 int zero;float offset;
 func_0c0442fa(a);func_0c0cc4dc(a);a->b1f5=2;func_0c02a026(a);zero=0;
 if(a->b140){offset=(char)a->b140;offset*=1.666666627f;a->b140=zero;a->f52+=a->b1d2?-offset:offset;}
 if(a->b141){a->b141=zero;a->b6++;}
}
void func_0c0cc63c(struct Actor *a)
{
 func_0c0442fa(a);func_0c0cc4dc(a);a->b1f5=2;MOVE;
 if(0.0f>a->f104*a->f92){
  int one=1;
  if(!((char)a->b1fd&(one<<(a->b1d2^one)))){func_0c02a026(a);return;}
 }
 a->b6++;func_0c02a0c4(a,21,22);
}
void func_0c0cc6cc(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c0cc6ee(struct Actor *a){dat_0c247ff4[a->b6](a);}
void func_0c0cc700(struct Actor *a)
{
 int zero;unsigned char alternate;float speed,acceleration,stopped;
 a->b6++;func_0c0442fa(a);func_0c048bb0(a,2);zero=0;
 a->f56=a->f41c;a->b1f9=zero;a->s28=zero;stopped=0.0f;a->f96=stopped;a->f108=stopped;
 alternate=(unsigned char)a->b1fe;speed=alternate?-16.666666031f:-23.3333320618f;acceleration=alternate?0.6770833135f:0.78125f;
 a->f92=a->b1d2?speed:-speed;a->f104=a->b1d2?acceleration:-acceleration;
 func_0c02a0c4(a,21,21);
}
void func_0c0cc7c8(struct Actor *a)
{
 int zero;float offset;
 func_0c0442fa(a);func_0c0cc4dc(a);a->b1f5=2;func_0c02a026(a);zero=0;
 if(a->b140){offset=(char)a->b140;offset*=1.666666627f;a->b140=zero;a->f52+=a->b1d2?-offset:offset;}
 if(a->b141){a->b141=zero;a->b6++;}
}
void func_0c0cc82c(struct Actor *a)
{
 func_0c0442fa(a);func_0c0cc4dc(a);a->b1f5=2;MOVE;
 if(0.0f>a->f104*a->f92 && !((char)a->b1fd&(1<<a->b1d2))){func_0c02a026(a);return;}
 a->b6++;func_0c02a0c4(a,21,22);
}
void func_0c0cc8b8(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
