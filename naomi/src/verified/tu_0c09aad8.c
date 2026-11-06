#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c048bb0(struct Actor *,int),func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c02a39a(struct Actor *,int),func_0c0437b8(struct Actor *),func_0c0438de(struct Actor *),func_0c044450(struct Actor *,struct Actor *),func_0c19d2ac(struct Actor *,int,int),func_0c043324(struct Actor *);
extern int func_0c0447bc(struct Actor *);
extern struct ActorFlags *dat_0c2d6f84;
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern signed char dat_0c243540[];
extern void (*table_0c243528[])(struct Actor *);
extern void (*table_0c243530[])(struct Actor *,struct ActorSub2a4 *),(*table_0c243548[])(struct Actor *,struct ActorSub2a4 *);
#define CHARGE (*(unsigned short *)&a->pad7d[0])
#define STATE14 (*(char *)&state->s14)
#define STATE7 state->b7
#define CLEAR_RECORD a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++
#define MOVE a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108
void func_0c09af30(struct Actor *,unsigned char);
void func_0c09aad8(struct Actor *a){a->b6++;func_0c048bb0(a,5);func_0c0442fa(a);a->f56=a->f41c;a->b1f9=0;a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;func_0c0432ca(a);func_0c02a0c4(a,21,26);}
void func_0c09ab26(struct Actor *a){func_0c02a026(a);if(a->b141){a->b6++;CHARGE=128;}}
void func_0c09ab4a(struct Actor *a)
{
 int zero;
 func_0c02a39a(a,(dat_0c2d6f84->flags&2)?8:0);func_0c02a026(a);zero=0;
 if(!a->b141){a->b6++;CHARGE=zero;a->s28=1;func_0c02a39a(a,0);return;}
 if(!(CHARGE&128)){a->b6++;func_0c02a39a(a,0);a->b1a1=72;CLEAR_RECORD;a->s28=zero;func_0c02a0c4(a,21,6);}
}
void func_0c09abee(struct Actor *a)
{
 if(func_0c02a026(a)<0){func_0c0437b8(a);return;}
 if(!a->s28&&a->b19e){a->s28=1;if(func_0c0447bc(a)){a->b6=0;a->b1f7=194;func_0c044450(a,a->p1b0);}}
}
void func_0c09ac72(struct Actor *a){table_0c243528[a->b6](a);}
void func_0c09ac84(struct Actor *a){table_0c243530[a->b7](a,&a->sub2a4);}
void func_0c09ac9a(struct Actor *a){a->b7++;func_0c09af30(a,0);func_0c048bb0(a,5);func_0c0442fa(a);a->f56=a->f41c;a->b1f9=0;a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;func_0c0432ca(a);func_0c02a0c4(a,21,a->b1a3+7);}
void func_0c09acf2(struct Actor *a,struct ActorSub2a4 *state)
{
 func_0c02a026(a);if(a->b141){a->b7++;a->s28=a->b1a3?30:15;a->s30=STATE14+1;a->b34=1;STATE7=0;a->f92=a->b1d2?13.33333302f:-13.33333302f;func_0c19d2ac(a,3,STATE14?1:0);}
}
void func_0c09ada8(struct Actor *a,struct ActorSub2a4 *state)
{
 func_0c02a026(a);MOVE;
 if(!--a->s28){a->b7++;a->f92=a->b1d2?5.0f:-5.0f;a->f104=a->b1d2?-0.1041666642f:0.1041666642f;func_0c09af30(a,1);func_0c02a0c4(a,21,a->b1a3+9);return;}
 if(a->b19e){if(!--a->b34){char one=1;a->b34=one;a->s28++;STATE7++;if(!--a->s30)a->s28=one;else{if(STATE7>one)func_0c09af30(a,2);else func_0c09af30(a,0);}}}
}
void func_0c09aec4(struct Actor *a){MOVE;if(func_0c02a026(a)<0){a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;func_0c0437b8(a);}}
void func_0c09af30(struct Actor *a,unsigned char index){int zero=0;index+=a->b255==3?3:0;a->b1a1=dat_0c243540[index];CLEAR_RECORD;}
void func_0c09af70(struct Actor *a){table_0c243548[a->b7](a,&a->sub2a4);}
void func_0c09af86(struct Actor *a){int zero=0;a->b7++;a->b1a1=58;CLEAR_RECORD;func_0c048bb0(a,5);func_0c0442fa(a);a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;func_0c02a0c4(a,21,a->b1a3+11);}
void func_0c09afea(struct Actor *a,struct ActorSub2a4 *state){func_0c02a026(a);if(a->b141){a->b7++;a->s28=a->b1a3?30:15;a->s30=STATE14+1;a->b34=1;STATE7=0;a->f92=a->b1d2?13.33333302f:-13.33333302f;func_0c19d2ac(a,3,(STATE14?1:0)+2);}}
void func_0c09b08e(struct Actor *a,struct ActorSub2a4 *state)
{
 int zero;
 func_0c02a026(a);MOVE;zero=0;
 if(!--a->s28){a->b7++;a->f92=a->b1d2?5.0f:-5.0f;a->f104=a->b1d2?-0.0520833321f:0.0520833321f;a->f96=-6.428571224213f;a->f108=-0.80357140303f;a->b1a1=59;
  a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,21,a->b1a3+13);return;
 }
 if(a->b19e){if(!--a->b34){char one=1;a->b34=one;a->s28++;STATE7++;if(!--a->s30)a->s28=one;else{if(STATE7>one)a->b1a1=77;else{goto s;s:a->b1a1=58;}a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;}}}
}
void func_0c09b20c(struct Actor *a){MOVE;if(!(a->f56>a->f41c)){a->b7++;a->f56=a->f41c;a->b1f9=0;func_0c02a0c4(a,1,3);func_0c043324(a);return;}if(func_0c02a026(a)<0)func_0c0438de(a);}
void func_0c09b29a(struct Actor *a){if(func_0c02a026(a)<0){a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;func_0c0437b8(a);}}
