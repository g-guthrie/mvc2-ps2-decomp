#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern int func_0c03916c(struct Actor *);
extern unsigned int func_0c02849a(void);
extern void func_0c044cbc(struct Actor *),func_0c043352(struct Actor *),func_0c044df4(struct Actor *),func_0c0437b8(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c0346da(struct Actor *,int),func_0c048bb0(struct Actor *,int),func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *);
extern struct LinkedActor *func_0c1af0ec(struct LinkedActor *,unsigned char),*func_0c161300(struct LinkedActor *,unsigned char);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern signed char dat_0c247f2c[],dat_0c247f30[];
extern void (*table_0c247f08[])(struct Actor *),(*table_0c247f14[])(struct Actor *),(*table_0c247f24[])(struct Actor *),(*table_0c247f38[])(struct Actor *);
extern void (*table_0c247f80[])(struct Actor *,struct ActorSub2a4 *);
#define MOVE a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108
#define CLEAR_RECORD a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++
void func_0c0cb560(struct Actor *),func_0c0cb642(struct Actor *),func_0c0cb67a(struct Actor *);
void func_0c0cb298(struct Actor *a)
{
 int zero;
 if(!a->b6){func_0c044cbc(a);a->b6++;a->b1a1=26;a->b1f9=1;func_0c02a0c4(a,20,12);zero=0;CLEAR_RECORD;func_0c0346da(a,22);func_0c048bb0(a,5);}
 if(a->b1ff==3)func_0c043352(a);MOVE;func_0c044df4(a);if(func_0c02a026(a)<0)func_0c0437b8(a);
}
void func_0c0cb360(struct Actor *a){table_0c247f08[a->b6](a);func_0c043352(a);}
void func_0c0cb37e(struct Actor *a)
{
 func_0c02a026(a);if(!a->b141){a->b6++;a->f96=0.0f;a->f108=0.0f;a->f92=a->b1d2?20.0f:-20.0f;a->f104=a->b1d2?-0.625f:0.625f;}
}
void func_0c0cb412(struct Actor *a)
{
 MOVE;
 if(a->f104*a->f92>0.0f){a->b6++;a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;a->f56=a->f41c;func_0c02a0c4(a,2,2);return;}
 func_0c02a026(a);
}
void func_0c0cb488(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c0cb4aa(struct Actor *a){table_0c247f14[a->b6](a);func_0c043352(a);}
void func_0c0cb4c8(struct Actor *a)
{
 a->f96=0.0f;a->f108=0.0f;a->b6++;a->f92=a->b1d2?-20.0f:20.0f;a->f104=a->b1d2?0.625f:-0.625f;func_0c02a0c4(a,2,1);
}
void func_0c0cb50c(struct Actor *a){func_0c02a026(a);if(a->b141){a->b141=0;a->b6++;func_0c0cb560(a);}}
void func_0c0cb560(struct Actor *a){MOVE;if(a->f104*a->f92>0.0f){a->b6++;func_0c02a0c4(a,2,3);return;}func_0c02a026(a);}
void func_0c0cb5bc(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c0cb5de(struct Actor *a){table_0c247f24[a->b6](a);}
void func_0c0cb5f0(struct Actor *a){a->b6++;a->b12c=1;func_0c02a0c4(a,18,0);}
void func_0c0cb604(struct Actor *a)
{
 if(func_0c02a026(a)<0)a->b5++;if(a->b141){a->b141=0;func_0c1af0ec((struct LinkedActor *)a,0);}
}
void func_0c0cb638(struct Actor *a){if(!a->b6)func_0c0cb642(a);else func_0c0cb67a(a);}
void func_0c0cb642(struct Actor *a)
{
 int mode;
 a->b6++;mode=dat_0c247f30[a->b32];if(!a->b32){a->s28=func_0c02849a()&3;mode=dat_0c247f2c[a->s28];}func_0c02a0c4(a,19,mode);
}
void func_0c0cb67a(struct Actor *a)
{
 if(func_0c03916c(a)){func_0c0437b8(a);return;}
 func_0c02a026(a);
 if(!a->b32){int timer=a->s28;if((timer==1||timer==3)&&a->b141){a->b141=0;func_0c1af0ec((struct LinkedActor *)a,1);}}
}
void func_0c0cb6f8(struct Actor *a){table_0c247f38[a->b1e9](a);}
void func_0c0cb70c(struct Actor *a)
{
 int zero;
 if(a->b14b){a->b1a1=a->b14b;zero=0;CLEAR_RECORD;a->b14b=zero;}
}
void func_0c0cb742(struct Actor *a){table_0c247f80[a->b6](a,&a->sub2a4);}
void func_0c0cb758(struct Actor *a)
{
 int zero;
 a->b6++;func_0c0442fa(a);func_0c0432ca(a);func_0c048bb0(a,5);zero=0;
 a->f56=a->f41c;a->b1f9=zero;a->b1a1=a->b1a3+48;CLEAR_RECORD;func_0c02a0c4(a,21,a->b1a3);
}
void func_0c0cb7be(struct Actor *a)
{
 if(func_0c02a026(a)<0){func_0c0437b8(a);return;}
 if(a->b141){a->b141=0;func_0c161300((struct LinkedActor *)a,0);}
}
