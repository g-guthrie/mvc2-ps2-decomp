#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern int func_0c047bbe(struct Actor *);
extern void func_0c0344a0(struct Actor *,int),func_0c0437b8(struct Actor *),func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c043324(struct Actor *),func_0c02a0c4(struct Actor *,int,int);
extern struct LinkedActor *func_0c165b30(struct Actor *,unsigned char,unsigned char);
extern void func_0c0429a4(struct Actor *,struct Vec3_tu5_03 *,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern unsigned int dat_0c2489fc[];
extern char dat_0c248a3c[];
extern void (*table_0c248a1c[])(struct Actor *);
extern void (*table_0c248a44[])(struct Actor *,struct ActorSub2a4 *);
void func_0c0d888e(struct Actor *,unsigned char),func_0c0d8dec(struct Actor *);
#define FRAME (((char *)&a->w150)[1])
#define RECORD a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++
#define MOTION a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108
void func_0c0d8738(struct Actor *a,struct ActorSub2a4 *state)
{
 a->b3f8=2;a->b328=5;
 if(state->b0 && (func_0c047bbe(a)||a->b255==5||a->b255==4)){
  state->b0--;if(((unsigned char)state->b0&7)==0)a->s30++;
 }
 if(func_0c02a026(a)<0){a->b6++;a->b3f9=0;a->b3f8=0;a->b327=0;a->b328=0;func_0c0d888e(a,1);return;}
 if(FRAME&1){FRAME&=0xfe;func_0c0344a0(a,30);func_0c165b30(a,11,0);func_0c165b30(a,11,1);func_0c165b30(a,11,2);}
 if((unsigned char)FRAME==254){if(a->s30){FRAME=-4;a->b142=32;}else FRAME=-6;}
 if((unsigned char)FRAME==252){a->s30--;a->s28=(a->s28+1)&3;func_0c0d888e(a,0);}
}
void func_0c0d886c(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c0d888e(struct Actor *a,unsigned char phase){func_0c165b30(a,a->s28+3,0);a->b158=dat_0c2489fc[a->s28*2+phase];func_0c02a0c4(a,21,a->b158);}
void func_0c0d88ca(struct Actor *a){table_0c248a1c[a->b6](a);}
void func_0c0d88dc(struct Actor *a)
{
 int zero;
 if(a->b255==6){a->b3f0=255;a->b3f1=16;}
 a->b6++;zero=0;a->b1a1=55;RECORD;
 func_0c0442fa(a);a->f56=a->f41c;a->b1f9=zero;a->f92=0;a->f96=0;a->f104=0;a->f108=0;a->s28=zero;
 a->f92=a->b1d2?8.33333302f:-8.33333302f;func_0c0432ca(a);func_0c165b30(a,2,0);func_0c02a0c4(a,21,18);
}
void func_0c0d8986(struct Actor *a)
{
 struct Vec3_tu5_03 point;
 a->b3f8=2;a->b328=5;a->b3f1=a->b255==6?2:0;func_0c02a026(a);
 if(a->b141){a->b6++;a->b141=0;a->b3f0=0;a->b3f1=0;point.x=-6.66666651f;point.y=126.42857f;point.z=0;func_0c0429a4(a,&point,1);}
}
void func_0c0d8a36(struct Actor *a)
{
 int zero=0;struct Tbl_ub3_01 **statistics;
 a->b3f8=2;a->b328=5;
 if(func_0c02a026(a)>=0){
  func_0c0d8dec(a);if(FRAME&1)a->f52+=a->f92;
  a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
  if(a->b14b){a->b14b=zero;func_0c165b30(a,8,0);}return;
 }
 statistics=&dat_0c2f83f8;
 if(a->b6==2){
  a->b6++;a->b1a1=55;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;(*statistics)->arr[a->b2]++;a->s28=zero;
  a->f92=a->b1d2?8.33333302f:-8.33333302f;func_0c165b30(a,2,0);func_0c02a0c4(a,21,19);
 }else{
  a->b6++;a->b1a1=56;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;(*statistics)->arr[a->b2]++;a->s28=zero;
  a->f92=a->b1d2?26.666666031f:-26.666666031f;a->f104=a->b1d2?-1.25f:1.25f;a->f96=34.2857132f;a->f108=-1.07142854f;
  func_0c165b30(a,8,0);func_0c02a0c4(a,21,20);
 }
}
void func_0c0d8bd6(struct Actor *a){a->b3f8=2;a->b328=5;func_0c02a026(a);func_0c0d8dec(a);if(FRAME&1){a->b6++;a->b1f9=2;func_0c165b30(a,8,0);}}
void func_0c0d8c4c(struct Actor *a)
{
 float zero=0;unsigned char direction;
 a->b3f8=2;a->b328=5;MOTION;direction=a->b1d2;
 if((direction&&a->f92<0)||(!direction&&a->f92>0)){a->f92=zero;a->f104=zero;}
 if(FRAME>=0){func_0c02a026(a);func_0c0d8dec(a);}
 if(a->f96<0){a->b6++;a->b3f9=0;a->b3f8=0;a->b327=0;a->b328=0;a->f92=zero;a->f104=zero;func_0c02a0c4(a,21,5);}
}
void func_0c0d8d30(struct Actor *a)
{
 MOTION;if(FRAME>=0)func_0c02a026(a);
 if(!(a->f56>a->f41c)){a->b6++;a->f56=a->f41c;a->b1f9=0;a->f92=0;a->f96=0;a->f104=0;a->f108=0;func_0c043324(a);func_0c02a0c4(a,21,6);}
}
void func_0c0d8dca(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c0d8dec(struct Actor *a){int zero=0;if(a->b141){if(a->b19e)a->s28++;if(a->s28<3){a->b1a1=dat_0c248a3c[a->b141>>1];goto L;L:a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;}}}
void func_0c0d8e3c(struct Actor *a){table_0c248a44[a->b6](a,&a->sub2a4);}
