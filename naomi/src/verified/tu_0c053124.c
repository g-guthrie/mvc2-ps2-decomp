/* Motion and counter callbacks, 053124..053B94.
 * 29 reviewed native functions, 2322 code bytes, eight pools/350 bytes. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c048bb0(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c0437b8(struct Actor *),func_0c0438de(struct Actor *),func_0c043324(struct Actor *),func_0c0451f2(struct Actor *),func_0c131554(struct Actor *,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char dat_0c23f384[];
extern void (*table_0c23f388[])(struct Actor *,struct ActorSub2a4 *);
extern void (*table_0c23f39c[])(struct Actor *),(*table_0c23f3b0[])(struct Actor *);
extern void (*table_0c23f3c0[])(struct Actor *,struct ActorSub2a4 *),(*table_0c23f3cc[])(struct Actor *,struct ActorSub2a4 *);
#define MOVE a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108
#define CLEAR_RECORD a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++
void func_0c0531c2(struct Actor *),func_0c0531f4(struct Actor *,struct ActorSub2a4 *),func_0c0534b0(struct Actor *),func_0c05375e(struct Actor *),func_0c0539de(struct Actor *);
void func_0c053124(struct Actor *a)
{
 int zero;
 a->b6++;func_0c0442fa(a);func_0c0432ca(a);func_0c048bb0(a,5);
 zero=0;a->f56=a->f41c;a->b1f9=zero;a->b1a1=a->b1a3+48;
 CLEAR_RECORD;func_0c02a0c4(a,21,a->b1a3);
}
void func_0c05318a(struct Actor *a)
{
 if(func_0c02a026(a)<0){func_0c0437b8(a);return;}
 if(a->b141){int zero=0;a->b141=zero;func_0c131554(a,zero);}
}
void func_0c0531c2(struct Actor *a)
{
 register float previous=a->f96;float next;
 a->f56+=a->f96;a->f96+=a->f108;next=a->f96;
 if(previous>0.0f && next<0.0f)a->f108=-1.607142806054f;
}

void func_0c0531f4(struct Actor *a,struct ActorSub2a4 *state)
{
 if((unsigned char)state->b0>0 && state->b1>0 && a->b140){
  int zero=0;unsigned char action=a->b140;a->b140=zero;
  if(a->b19e){
   if(a->b19e&1){if(!(--state->b1>0))return;}
   else if(!((unsigned char)--state->b0>0))return;
  }
  a->b1a1=action;CLEAR_RECORD;
 }
}
void func_0c053296(struct Actor *a){table_0c23f388[a->b6](a,&a->sub2a4);}
void func_0c0532ac(struct Actor *a,struct ActorSub2a4 *state)
{
 int zero;float speed;
 func_0c0442fa(a);a->f56=a->f41c;a->b6++;func_0c0432ca(a);
 zero=0;a->b1fc=zero;a->b1f9=zero;func_0c048bb0(a,10);
 if(!a->b1a3){speed=10.0f;a->f96=17.142856598f;}
 else{speed=16.666666031f;a->f96=34.285713195801f;}
 if(!a->b1d2)speed=-speed;a->f92=speed;
 a->f104=a->b1d2?-0.729166626931f:0.729166626931f;
 a->f108=-1.071428537369f;a->b1a1=a->b1a3+51;CLEAR_RECORD;
 state->b0=dat_0c23f384[(unsigned char)a->b1a3*2];
 state->b1=(dat_0c23f384+(unsigned char)a->b1a3*2)[1];
 func_0c02a0c4(a,21,a->b1a3+2);
}
void func_0c0533d0(struct Actor *a,struct ActorSub2a4 *state)
{
 func_0c02a026(a);func_0c0531f4(a,state);
 if(!a->b141){a->b6++;func_0c0451f2(a);}
}
void func_0c053408(struct Actor *a,struct ActorSub2a4 *state)
{
 register float previous;float next;
 func_0c0531c2(a);previous=a->f92;a->f52+=a->f92;a->f92+=a->f104;next=a->f92;next*=previous;
 if(next<0.0f)a->b6++;
 func_0c02a026(a);
}
void func_0c053444(struct Actor *a,struct ActorSub2a4 *state)
{
 func_0c0531c2(a);
 if(a->f56>a->f41c){if(a->b141==0)func_0c02a026(a);}
 else{a->b6++;a->b1f9=0;a->f56=a->f41c;func_0c043324(a);}
}
void func_0c05348e(struct Actor *a,struct ActorSub2a4 *state){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c0534b0(struct Actor *a)
{
 if(a->b141>0){int zero=0;a->b141=zero;a->b1a1=a->b1a3+57;CLEAR_RECORD;}
}
void func_0c0534e8(struct Actor *a){table_0c23f39c[a->b6](a);}
void func_0c053518(struct Actor *a)
{
 int zero;float speed;
 a->b6++;func_0c0442fa(a);func_0c0432ca(a);func_0c048bb0(a,10);
 zero=0;a->f56=a->f41c;a->b1a1=a->b1a3+57;CLEAR_RECORD;
 a->f96=8.571428299f;a->f108=-0.803571403027f;func_0c0451f2(a);
 speed=a->b1a3?6.25f:4.166666507721f;a->f92=a->b1d2?speed:-speed;
 a->f104=0.0f;func_0c02a0c4(a,21,4);
}
void func_0c0535ba(struct Actor *a)
{
 float previous=a->f96;MOVE;
 if(previous*a->f96>0.0f)func_0c02a026(a);
 else{a->b6++;a->s28=(unsigned char)a->b1a3*2;func_0c02a0c4(a,21,6);func_0c0534b0(a);}
}
void func_0c053664(struct Actor *a)
{
 if(a->b141<0){a->b141=0;if(--a->s28<0){a->b6++;func_0c02a0c4(a,21,5);return;}}
 a->f52+=a->f92;a->f92+=a->f104;func_0c02a026(a);func_0c0534b0(a);
}
void func_0c0536c0(struct Actor *a)
{
 MOVE;
 if(!(a->f56>a->f41c)){a->b6++;a->f56=a->f41c;a->b1f9=0;func_0c02a0c4(a,21,7);func_0c043324(a);}
 else func_0c02a026(a);
}
void func_0c05373c(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c05375e(struct Actor *a)
{
 if(a->b141>0){int zero=0;a->b141=zero;a->b1a1=a->b1a3+60;CLEAR_RECORD;}
}
void func_0c053796(struct Actor *a){table_0c23f3b0[a->b6](a);}
void func_0c0537c8(struct Actor *a)
{
 int zero;float boost;
 a->b6++;func_0c048bb0(a,5);zero=0;a->b1a1=a->b1a3+60;CLEAR_RECORD;
 boost=a->b1a3?4.166666507721f:2.5f;
 if(a->b1d2){if(a->f92<0.0f)goto flip;}
 else{boost=-boost;if(a->f92>0.0f)goto flip;}
 goto apply;
 flip:boost=-boost;
 apply:a->f92+=boost;a->f104=0.0f;a->s28=(unsigned char)a->b1a3*2;func_0c02a0c4(a,21,8);
}
void func_0c053862(struct Actor *a)
{
 int zero;MOVE;zero=0;
 if(!(a->f56>a->f41c)){a->b6=3;a->f56=a->f41c;a->b1f9=zero;func_0c043324(a);func_0c02a0c4(a,1,3);return;}
 if(a->b141<0){a->b141=zero;if(--a->s28<0){a->b6++;func_0c02a0c4(a,21,10);return;}}
 func_0c02a026(a);func_0c05375e(a);
}

void func_0c05392e(struct Actor *a)
{
 MOVE;
 if(!(a->f56>a->f41c)){a->b6++;a->f56=a->f41c;a->b1f9=0;func_0c043324(a);func_0c02a0c4(a,1,3);}
 else if(func_0c02a026(a)<0)func_0c0438de(a);
}
void func_0c0539bc(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c0539de(struct Actor *a){MOVE;if(!(a->f56>a->f41c))a->f56=a->f41c;}
void func_0c053a2e(struct Actor *a){table_0c23f3c0[a->b6](a,&a->sub2a4);}
void func_0c053a64(struct Actor *a,struct ActorSub2a4 *state)
{
 int zero;
 a->b6++;func_0c0442fa(a);func_0c048bb0(a,2);zero=0;a->b1a1=a->b1a3+63;CLEAR_RECORD;
 a->f92/=16.0f;a->f96/=8.0f;a->f108/=64.0f;a->f104=0.0f;func_0c02a0c4(a,21,a->b1a3+14);
}
void func_0c053aea(struct Actor *a,struct ActorSub2a4 *state)
{
 func_0c0539de(a);func_0c02a026(a);
 if(a->b141){a->b141=0;a->b6++;func_0c131554(a,1);}
}
void func_0c053b1c(struct Actor *a,struct ActorSub2a4 *state)
{
 func_0c0539de(a);
 if(func_0c02a026(a)<0){float stopped=0.0f;a->f96=stopped;a->f108=stopped;func_0c0438de(a);}
}
void func_0c053b4a(struct Actor *a){table_0c23f3cc[a->b6](a,&a->sub2a4);}
