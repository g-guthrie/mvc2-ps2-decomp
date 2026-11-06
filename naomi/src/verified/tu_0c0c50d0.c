/* Special-move checker and stance-state unit for a second character
 * (0x0c0c50d0-0x0c0c5e18), the template of tu_0c0bfd60. */
#include "objects.h"
extern unsigned char func_0c0465cc(struct Actor *),func_0c046b6c(struct Actor *),func_0c0469f4(struct Actor *),func_0c046d3c(struct Actor *);
extern void func_0c045f1c(struct Actor *),func_0c0463fc(struct Actor *);
extern unsigned char func_0c046e7e(struct Actor *,unsigned char *,unsigned char *);
extern void func_0c047aac(struct Actor *,unsigned char *),func_0c045248(struct Actor *,int);
extern int func_0c046d54(struct Actor *);
extern unsigned char func_0c046dd0(struct Actor *,int);
extern void func_0c044cbc(struct Actor *),func_0c0346da(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int);
extern unsigned int dat_0c24775c[];
extern unsigned char dat_0c246dec[],dat_0c246dfc[],dat_0c246e0c[],dat_0c246e1c[],dat_0c246e2c[],dat_0c246e3c[],dat_0c246e4c[],dat_0c246e5c[],dat_0c246e6c[];
extern unsigned char dat_0c246da4[],dat_0c246da8[],dat_0c246dac[],dat_0c246db0[],dat_0c246db4[],dat_0c246db8[];
extern unsigned char dat_0c246dbc[],dat_0c246dc0[],dat_0c246dc4[],dat_0c246dc8[],dat_0c246dcc[],dat_0c246dd0[],dat_0c246dd4[],dat_0c246dd8[],dat_0c246ddc[],dat_0c246de0[],dat_0c246de4[],dat_0c246de8[];
extern struct ActorFlags *dat_0c2d6f84;
extern short dat_0c2477cc[];
extern void (*table_0c2477d4[])(struct Actor *),(*table_0c2477e4[])(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
unsigned char func_0c0c51c0(struct Actor *),func_0c0c5228(struct Actor *),func_0c0c52cc(struct Actor *),func_0c0c5334(struct Actor *),func_0c0c537a(struct Actor *);
unsigned char func_0c0c53e4(struct Actor *),func_0c0c5488(struct Actor *),func_0c0c551a(struct Actor *),func_0c0c5584(struct Actor *),func_0c0c5650(struct Actor *);
int func_0c0c5612(struct Actor *),func_0c0c56b4(struct Actor *),func_0c0c56ea(struct Actor *),func_0c0c5746(struct Actor *);
void func_0c0c585c(struct Actor *),func_0c0c5904(struct Actor *),func_0c0c59d4(struct Actor *),func_0c0c5a7a(struct Actor *);
void func_0c0c5b6e(struct Actor *),func_0c0c5b80(struct Actor *),func_0c0c5c96(struct Actor *);

void func_0c0c50d0(struct Actor *a)
{
 register unsigned int i;
 register unsigned int limit=112;
 register unsigned int *out=*((unsigned int **)((char *)a+0x428));
 register unsigned int *in=dat_0c24775c;
 i=0;
copy_next:
 *(unsigned int *)((char *)out+i)=*(unsigned int *)((char *)in+i);
 i+=4;
 if(i<limit)goto copy_next;
}
void func_0c0c50ec(struct Actor *a)
{
 if(func_0c0465cc(a))return;
 if(func_0c046b6c(a))return;
 if(func_0c0469f4(a))return;
 if(func_0c046d3c(a))return;
 if(func_0c0c52cc(a))return;
 if(func_0c0c5334(a))return;
 if(func_0c0c537a(a))return;
 if(func_0c0c51c0(a))return;
 if(func_0c0c5228(a))return;
 if(func_0c0c53e4(a))return;
 if(func_0c0c5488(a))return;
 if(func_0c0c551a(a))return;
 if(func_0c0c5584(a))return;
 if(func_0c0c5612(a))return;
 if(func_0c0c5650(a))return;
 func_0c045f1c(a);func_0c0463fc(a);
}
unsigned char func_0c0c51c0(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c246dec,a->x364))goto fail;
 if(a->b1f9==2 && a->b1fc==0){if(a->b1d4){fail:return 0;}a->b1d4++;}
 func_0c047aac(a,a->x364);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=0;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c0c5228(struct Actor *a)
{
 struct ActorSubMoveBytes *sub;
 if(!func_0c046e7e(a,dat_0c246dfc,a->x36c))goto fail;
 sub=(struct ActorSubMoveBytes *)&a->sub2a4;
 if(a->b1f9!=2){if(!sub->b29)goto ok;goto fail;}
 goto c;c:if(sub->b29>2)return 0;if(a->b1fc==0){if(a->b1d4){fail:return 0;}a->b1d4++;}
ok:
 func_0c047aac(a,a->x36c);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=2;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c0c52cc(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c246e0c,a->x38c)||!*a->p40c)goto fail;
 if(a->b1f9==2){if(a->b1d4 && !a->b1fc){fail:return 0;}a->b1d4++;}
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=7;
 func_0c045248(a,29);return 1;
}
unsigned char func_0c0c5334(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c246e1c,a->x374))return 0;
 else if(!*a->p40c)return 0;
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=4;
 func_0c045248(a,29);return 1;
}
unsigned char func_0c0c537a(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c246e2c,a->x37c))return 0;
 else if(!*a->p40c)return 0;
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=5;
 func_0c045248(a,29);return 1;
}
unsigned char func_0c0c53e4(struct Actor *a)
{
 struct ActorSubMoveBytes *sub=(struct ActorSubMoveBytes *)&a->sub2a4;unsigned char *cmd=dat_0c246e3c;
 if(sub->b8==0){
  if(func_0c046e7e(a,cmd,a->x384)){if(a->b1f9!=2){if(!sub->b5){if(!sub->b6){if(!sub->b7){func_0c047aac(a,a->x384);goto set;}}}}}return 0;
 }else{
  if(!func_0c046e7e(a,cmd,a->x384))goto fail;
  if(a->b1f9==2){if(a->b1d4&!a->b1fc){fail:return 0;}a->b1d4++;}
 }
 set:a->b5=0;a->b7=0;a->b6=0;a->b1e9=6;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c0c5488(struct Actor *a)
{
 struct ActorSubMoveBytes *sub=(struct ActorSubMoveBytes *)&a->sub2a4;int zero;
 if(sub->b3||!func_0c046e7e(a,dat_0c246e4c,a->x394))return 0;
 func_0c047aac(a,a->x394);
 zero=0;a->b5=zero;a->b7=zero;a->b6=zero;a->b1e9=12;
 func_0c045248(a,21);
 if(!a->b525)sub->b26=zero;else sub->b26=a->b1fe;
 return 1;
}
unsigned char func_0c0c551a(struct Actor *a)
{
 struct ActorSubMoveBytes *sub=(struct ActorSubMoveBytes *)&a->sub2a4;
 if(sub->b3||!func_0c046e7e(a,dat_0c246e5c,a->x39c))return 0;
 func_0c047aac(a,a->x39c);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=12;
 func_0c045248(a,21);
 if(a->b525==0)sub->b26=1;else sub->b26=a->b1fe;
 return 1;
}
unsigned char func_0c0c5584(struct Actor *a)
{
 struct ActorSubMoveBytes *sub=(struct ActorSubMoveBytes *)&a->sub2a4;
 if(sub->b3||!func_0c046e7e(a,dat_0c246e6c,a->x3a4))return 0;
 func_0c047aac(a,a->x3a4);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=12;
 func_0c045248(a,21);
 if(a->b525==0)sub->b26=2;else sub->b26=a->b1fe;
 return 1;
}
int func_0c0c5612(struct Actor *a)
{
 if(!func_0c046d54(a))goto fail;
 if(!*a->p40c){fail:return 0;}
 a->b1e9=8;a->b5=0;a->b7=0;a->b6=0;
 func_0c045248(a,29);return 1;
}
unsigned char func_0c0c5650(struct Actor *a)
{
 if(!func_0c046dd0(a,3))return 0;
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=3;
 func_0c045248(a,21);return 1;
}
int func_0c0c5688(struct Actor *a)
{
 if(func_0c0c56b4(a)||func_0c0c56ea(a)||func_0c0c5746(a))return 1;
 return 0;
}
int func_0c0c56b4(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c246e0c,a->x38c))return 0;
 else if(!*a->p40c)return 0;
 a->b258=7;return 1;
}
int func_0c0c56ea(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c246e1c,a->x374))return 0;
 else if(!*a->p40c)return 0;
 a->b258=4;return 1;
}
int func_0c0c5746(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c246e2c,a->x37c))return 0;
 else if(!*a->p40c)return 0;
 a->b258=5;return 1;
}
void func_0c0c577c(struct Actor *a)
{
 struct ActorSubMoveBytes *sub=(struct ActorSubMoveBytes *)&a->sub2a4;
 if(!a->b1a0 && sub->s30)sub->s30=sub->s30-1;
 if(sub->b13){
  if(a->b1a0)a->f52+=(float)dat_0c2477cc[dat_0c2d6f84->flags&3]*1.66666663f;
  else sub->b13=0;
 }
}
void func_0c0c57d2(struct Actor *a){table_0c2477d4[a->b1ff](a);}
void func_0c0c57e6(struct Actor *a){func_0c044cbc(a);if((unsigned char)a->b1fe==1){if(a->b1f9==1)func_0c0c5a7a(a);else func_0c0c59d4(a);}else if(a->b1f9==1)func_0c0c5904(a);else func_0c0c585c(a);}
void func_0c0c585c(struct Actor *a){int zero=0;switch(a->b1e8){case 0:a->b158=zero;a->b1a1=zero;func_0c0346da(a,20);a->p3f4=dat_0c246da4;a->b1a7=zero;break;case 1:{int mode=1;a->b158=mode;a->b1a1=mode;func_0c0346da(a,21);a->p3f4=dat_0c246da8;a->b1a7=mode;break;}case 2:{int mode=2;a->b158=mode;a->b1a1=mode;func_0c0346da(a,22);a->p3f4=dat_0c246dac;a->b1a7=mode;break;}}a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,7,a->b158);}
void func_0c0c5904(struct Actor *a){int zero=0;switch(a->b1e8){case 0:a->b158=zero;a->b1a1=6;func_0c0346da(a,20);a->p3f4=dat_0c246da4;a->b1a7=zero;break;case 1:a->b158=1;a->b1a1=7;func_0c0346da(a,21);a->p3f4=dat_0c246da8;a->b1a7=1;break;case 2:a->b158=2;a->b1a1=8;func_0c0346da(a,22);a->p3f4=dat_0c246dac;a->b1a7=2;break;}a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,9,a->b158);}
void func_0c0c59d4(struct Actor *a){int zero=0;switch(a->b1e8){case 0:a->b158=zero;a->b1a1=3;func_0c0346da(a,20);a->p3f4=dat_0c246db0;a->b1a7=zero;break;case 1:a->b158=1;a->b1a1=4;func_0c0346da(a,21);a->p3f4=dat_0c246db4;a->b1a7=1;break;case 2:a->b158=2;a->b1a1=5;a->p3f4=dat_0c246db8;a->b1a7=2;break;}a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,8,a->b158);}
void func_0c0c5a7a(struct Actor *a){int zero=0;switch(a->b1e8){case 0:a->b158=zero;a->b1a1=9;func_0c0346da(a,20);a->p3f4=dat_0c246db0;a->b1a7=zero;break;case 1:a->b158=1;a->b1a1=10;func_0c0346da(a,21);a->p3f4=dat_0c246db4;a->b1a7=1;break;case 2:a->b158=2;a->b1a1=11;a->p3f4=dat_0c246db8;a->b1a7=2;break;}a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,10,a->b158);}
void func_0c0c5b46(struct Actor *a)
{
 if(!a->b1fe){if(a->b1d6&15)goto call;}
 goto s;s:if(a->b1fe){if(!(a->b1d6&0xf0))return;call:func_0c0c5b6e(a);}
}
void func_0c0c5b6e(struct Actor *a){if((unsigned char)a->b1fe==1)func_0c0c5c96(a);else func_0c0c5b80(a);}
void func_0c0c5b80(struct Actor *a){int zero=0;switch(a->b1e8){case 0:a->b158=zero;a->b1a1=12;func_0c0346da(a,20);if(!a->b1fc)a->p3f4=dat_0c246dbc;else a->p3f4=dat_0c246dd4;a->b1a7=zero;break;case 1:a->b158=1;a->b1a1=13;func_0c0346da(a,21);if(!a->b1fc)a->p3f4=dat_0c246dc0;else a->p3f4=dat_0c246dd8;a->b1a7=1;break;case 2:a->b158=2;a->b1a1=14;func_0c0346da(a,22);if(!a->b1fc)a->p3f4=dat_0c246dc4;else a->p3f4=dat_0c246ddc;a->b1a7=2;break;}a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,11,a->b158);
 if(a->b1d6&15)a->b1d6=a->b1d6-1;
}
void func_0c0c5c96(struct Actor *a){int zero=0;switch(a->b1e8){case 0:a->b158=zero;a->b1a1=15;func_0c0346da(a,20);if(!a->b1fc)a->p3f4=dat_0c246dc8;else a->p3f4=dat_0c246de0;a->b1a7=zero;break;case 1:a->b158=1;a->b1a1=16;func_0c0346da(a,21);if(!a->b1fc)a->p3f4=dat_0c246dcc;else a->p3f4=dat_0c246de4;a->b1a7=1;break;case 2:a->b158=2;a->b1a1=17;if(a->w1fa&0x2000){a->b158=6;a->b1a1=18;}func_0c0346da(a,22);if(!a->b1fc)a->p3f4=dat_0c246dd0;else a->p3f4=dat_0c246de8;a->b1a7=2;break;}a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,12,a->b158);
 if(a->b1d6&0xf0)a->b1d6=a->b1d6-16;
}
void func_0c0c5dce(struct Actor *a){table_0c2477e4[a->b1ff](a);}
