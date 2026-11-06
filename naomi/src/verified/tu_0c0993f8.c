/* 0x0c0993f8..0x0c099e24: 23 functions and nine pools. */
#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern unsigned char func_0c047886(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c045248(struct Actor *,int),func_0c044cbc(struct Actor *),func_0c0346da(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c043352(struct Actor *),func_0c044df4(struct Actor *),func_0c0437b8(struct Actor *),func_0c0421f4(struct Actor *),func_0c0420f8(struct Actor *),func_0c042018(struct Actor *),func_0c0421b8(struct Actor *),func_0c044f1c(struct Actor *),func_0c0438de(struct Actor *);
extern void (*table_0c243444[])(struct Actor *),(*table_0c243454[])(struct Actor *);
extern const unsigned int dat_0c2432e8[];
extern const unsigned int dat_0c2432ec[];
extern const unsigned int dat_0c2432f0[];
extern const unsigned int dat_0c2432f4[];
extern const unsigned int dat_0c2432f8[];
extern const unsigned int dat_0c2432fc[];
extern const unsigned int dat_0c243300[];
extern const unsigned int dat_0c243304[];
extern const unsigned int dat_0c243308[];
extern const unsigned int dat_0c24330c[];
extern const unsigned int dat_0c243310[];
extern const unsigned int dat_0c243314[];
extern const unsigned int dat_0c243318[];
extern const unsigned int dat_0c24331c[];
extern const unsigned int dat_0c243320[];
extern const unsigned int dat_0c243324[];
extern const unsigned int dat_0c243328[];
extern const unsigned int dat_0c24332c[];
void func_0c099492(struct Actor *);
void func_0c0994a6(struct Actor *);
void func_0c09950c(struct Actor *);
void func_0c0995b4(struct Actor *);
void func_0c099684(struct Actor *);
void func_0c099730(struct Actor *);
void func_0c099804(struct Actor *);
void func_0c09982c(struct Actor *);
void func_0c09983e(struct Actor *);
void func_0c09995a(struct Actor *);
void func_0c099a7e(struct Actor *);
void func_0c099a92(struct Actor *);
void func_0c099aa0(struct Actor *);
void func_0c099b5a(struct Actor *);
void func_0c099b92(struct Actor *);
void func_0c099c20(struct Actor *);
void func_0c099c58(struct Actor *);
void func_0c099c98(struct Actor *);
void func_0c099d5c(struct Actor *);
void func_0c099d72(struct Actor *);
void func_0c099db4(struct Actor *);
void func_0c099dd6(struct Actor *);
void func_0c0993f8(struct Actor *a)
{
 struct ActorSubByteState *state=(struct ActorSubByteState *)&a->sub2a4;
 if(state->b5){
  int zero=0;
  if(a->w340&256){
   if((unsigned char)state->b6++>=100){state->b6=zero;if(*(char *)&((struct ActorSub2a4 *)state)->s14<48)(*(char *)&((struct ActorSub2a4 *)state)->s14)++;}
  }else{
   state->b5=zero;
   if(func_0c047886(a)){
    int one=1;
    a->b5=zero;if(a->b1f9==2)a->b6=one;else a->b6=zero;a->b7=zero;a->b1e9=4;a->b1a3=one;func_0c045248(a,21);
   }
  }
 }
}
void func_0c099492(struct Actor *a){table_0c243444[a->b1ff](a);}
void func_0c0994a6(struct Actor *a){func_0c044cbc(a);if((unsigned char)a->b1fe==1){if(a->b1f9==1)func_0c099730(a);else func_0c099684(a);}else if(a->b1f9==1)func_0c0995b4(a);else func_0c09950c(a);}
void func_0c09950c(struct Actor *a)
{
 int zero=0;switch(a->b1e8){
 case 0: a->b158=zero;a->b1a1=zero;func_0c0346da(a,20);a->p3f4=(void *)dat_0c2432e8;a->b1a7=zero;break;
 case 1: {int mode=1;a->b158=mode;a->b1a1=mode;func_0c0346da(a,21);a->p3f4=(void *)dat_0c2432ec;a->b1a7=mode;break;}
 case 2: {int mode=2;a->b158=mode;a->b1a1=mode;func_0c0346da(a,22);a->p3f4=(void *)dat_0c2432f0;a->b1a7=mode;break;}
}a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,7,a->b158);
}
void func_0c0995b4(struct Actor *a)
{
 int zero=0;switch(a->b1e8){
 case 0: a->b158=zero;a->b1a1=6;func_0c0346da(a,20);a->p3f4=(void *)dat_0c2432e8;a->b1a7=zero;break;
 case 1: a->b158=1;a->b1a1=7;func_0c0346da(a,21);a->p3f4=(void *)dat_0c2432ec;a->b1a7=1;break;
 case 2: a->b158=2;a->b1a1=8;func_0c0346da(a,22);a->p3f4=(void *)dat_0c2432f0;a->b1a7=2;break;
}a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,9,a->b158);
}
void func_0c099684(struct Actor *a)
{
 int zero=0;switch(a->b1e8){
 case 0: a->b158=zero;a->b1a1=3;func_0c0346da(a,20);a->p3f4=(void *)dat_0c2432f4;a->b1a7=zero;break;
 case 1: a->b158=1;a->b1a1=4;func_0c0346da(a,21);a->p3f4=(void *)dat_0c2432f8;a->b1a7=1;break;
 case 2: a->b158=2;a->b1a1=5;func_0c0346da(a,22);a->p3f4=(void *)dat_0c2432fc;a->b1a7=2;break;
}a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,8,a->b158);
}
void func_0c099730(struct Actor *a)
{
 int zero=0;switch(a->b1e8){
 case 0: a->b158=zero;a->b1a1=9;func_0c0346da(a,20);a->p3f4=(void *)dat_0c2432f4;a->b1a7=zero;break;
 case 1: a->b158=1;a->b1a1=10;func_0c0346da(a,21);a->p3f4=(void *)dat_0c2432f8;a->b1a7=1;break;
 case 2: a->b158=2;a->b1a1=11;func_0c0346da(a,22);a->p3f4=(void *)dat_0c2432fc;a->b1a7=2;break;
}a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,10,a->b158);
}
void func_0c099804(struct Actor *a){if((a->b1fe==0 && (a->b1d6&15)) || (a->b1fe!=0 && (a->b1d6&240)))func_0c09982c(a);}
void func_0c09982c(struct Actor *a){if((unsigned char)a->b1fe==1)func_0c09995a(a);else func_0c09983e(a);}
void func_0c09983e(struct Actor *a)
{
 int zero=0;switch(a->b1e8){
case 0:a->b158=zero;a->b1a1=12;func_0c0346da(a,20);if(!a->b1fc)a->p3f4=(void *)dat_0c243300;else a->p3f4=(void *)dat_0c243318;a->b1a7=zero;break;
case 1:a->b158=1;a->b1a1=13;func_0c0346da(a,21);if(!a->b1fc)a->p3f4=(void *)dat_0c243304;else a->p3f4=(void *)dat_0c24331c;a->b1a7=1;break;
case 2:a->b158=2;a->b1a1=14;func_0c0346da(a,22);if(!a->b1fc)a->p3f4=(void *)dat_0c243308;else a->p3f4=(void *)dat_0c243320;a->b1a7=2;break;
}a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,11,a->b158);if(a->b1d6&15)a->b1d6-=1;
}
void func_0c09995a(struct Actor *a)
{
 int zero=0;switch(a->b1e8){
case 0:a->b158=zero;a->b1a1=15;func_0c0346da(a,20);if(!a->b1fc)a->p3f4=(void *)dat_0c24330c;else a->p3f4=(void *)dat_0c243324;a->b1a7=zero;break;
case 1:a->b158=1;a->b1a1=16;func_0c0346da(a,21);if(!a->b1fc)a->p3f4=(void *)dat_0c243310;else a->p3f4=(void *)dat_0c243328;a->b1a7=1;break;
case 2:a->b158=2;a->b1a1=17;func_0c0346da(a,22);if(!a->b1fc)a->p3f4=(void *)dat_0c243314;else a->p3f4=(void *)dat_0c24332c;a->b1a7=2;break;
}a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,12,a->b158);if(a->b1d6&240)a->b1d6-=16;
}
void func_0c099a7e(struct Actor *a){table_0c243454[a->b1ff](a);}
void func_0c099a92(struct Actor *a){func_0c043352(a);func_0c099aa0(a);}
void func_0c099aa0(struct Actor *a){a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;func_0c044df4(a);if((unsigned char)a->b1fe==1){if(a->b1f9==1)func_0c099c58(a);else func_0c099c20(a);}else if(a->b1f9==1)func_0c099b92(a);else func_0c099b5a(a);}
void func_0c099b5a(struct Actor *a){switch(a->b1e8){case 0:case 1:case 2:if(func_0c02a026(a)<0)func_0c0437b8(a);break;}}
void func_0c099b92(struct Actor *a){float event;switch(a->b1e8){case 2:if(func_0c02a026(a)<0)goto fail;event=(float)a->b141;if(event){a->b141=0;event*=a->b1d2?1.666666626931f:-1.666666626931f;a->f52+=event;}break;case 0:case 1:if(func_0c02a026(a)<0)fail:func_0c0437b8(a);break;}}
void func_0c099c20(struct Actor *a){switch(a->b1e8){case 0:case 1:case 2:if(func_0c02a026(a)<0)func_0c0437b8(a);break;}}
void func_0c099c58(struct Actor *a){switch(a->b1e8){case 2:func_0c099c98(a);break;case 0:case 1:if(func_0c02a026(a)<0)func_0c0437b8(a);break;}}
void func_0c099c98(struct Actor *a){if(!a->b6){func_0c02a026(a);if(a->b141){a->b6++;a->f92=a->b1d2?14.166666030884f:-14.166666030884f;a->f104=a->b1d2?-0.729166626931f:0.729166626931f;}}else{func_0c043352(a);if(a->b141)a->f52+=a->f92;a->f92+=a->f104;if(func_0c02a026(a)<0){a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;func_0c0437b8(a);}}}
void func_0c099d5c(struct Actor *a){func_0c0421f4(a);func_0c0420f8(a);func_0c099d72(a);}
void func_0c099d72(struct Actor *a){func_0c042018(a);func_0c0421b8(a);if((unsigned char)a->b1fe==1)func_0c099dd6(a);else func_0c099db4(a);if(func_0c044e52(a))func_0c044f1c(a);}
void func_0c099db4(struct Actor *a){if(func_0c02a026(a)<0)func_0c0438de(a);}
void func_0c099dd6(struct Actor *a){if(func_0c02a026(a)<0)func_0c0438de(a);}
