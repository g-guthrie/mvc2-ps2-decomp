#include "objects.h"
extern unsigned char dat_0c24a30c[],dat_0c24a31c[],dat_0c24a32c[],dat_0c24a33c[],dat_0c24a34c[],dat_0c24a35c[],dat_0c24a36a[],dat_0c24a378[],dat_0c24a388[],dat_0c24a398[];
extern unsigned char dat_0c24a3a8[],dat_0c24a3ac[],dat_0c24a3b0[],dat_0c24a3b4[],dat_0c24a3b8[],dat_0c24a3bc[];
extern void (*table_0c24a460[])(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern unsigned char func_0c0465cc(struct Actor *),func_0c046b6c(struct Actor *),func_0c0469f4(struct Actor *),func_0c046d3c(struct Actor *);
extern unsigned char func_0c046e7e(struct Actor *,unsigned char *,unsigned char *),func_0c047068(struct Actor *,unsigned char *,unsigned char *),func_0c046dd0(struct Actor *,int);
extern int func_0c046d54(struct Actor *);
extern void func_0c045f1c(struct Actor *),func_0c0463fc(struct Actor *),func_0c047aac(struct Actor *,unsigned char *),func_0c045248(struct Actor *,int);
extern void func_0c044cbc(struct Actor *),func_0c0346da(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int);
unsigned char func_0c0f4b30(struct Actor *a),func_0c0f4b76(struct Actor *a),func_0c0f4bbc(struct Actor *a),func_0c0f4c02(struct Actor *a),func_0c0f4c70(struct Actor *a);
unsigned char func_0c0f4cc0(struct Actor *a),func_0c0f4d10(struct Actor *a),func_0c0f4d84(struct Actor *a),func_0c0f4dea(struct Actor *a),func_0c0f4e3a(struct Actor *a);
unsigned char func_0c0f4ede(struct Actor *a),func_0c0f4f14(struct Actor *a),func_0c0f4f4a(struct Actor *a);
int func_0c0f4f80(struct Actor *a);
void func_0c0f5040(struct Actor *a),func_0c0f5112(struct Actor *a),func_0c0f51c0(struct Actor *a),func_0c0f5292(struct Actor *a);
void func_0c0f4a30(struct Actor *a)
{
 if(func_0c0465cc(a))return;
 if(func_0c046b6c(a))return;
 if(func_0c0469f4(a))return;
 if(func_0c046d3c(a))return;
 if(func_0c0f4b30(a))return;
 if(func_0c0f4b76(a))return;
 if(func_0c0f4c02(a))return;
 if(func_0c0f4bbc(a))return;
 if(func_0c0f4c70(a))return;
 if(func_0c0f4cc0(a))return;
 if(func_0c0f4d10(a))return;
 if(func_0c0f4d84(a))return;
 if(func_0c0f4dea(a))return;
 if(func_0c0f4e3a(a))return;
 if(func_0c0f4f80(a))return;
 if(func_0c046dd0(a,6)){a->b1e9=6;a->b5=0;a->b7=0;a->b6=0;func_0c045248(a,21);return;}
 func_0c045f1c(a);func_0c0463fc(a);
}
unsigned char func_0c0f4b30(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24a388,a->x3a4))return 0;
 else if(!*a->p40c)return 0;
 a->b1e9=10;a->b5=0;a->b7=0;a->b6=0;
 func_0c045248(a,29);return 1;
}
unsigned char func_0c0f4b76(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24a398,a->x3ac))return 0;
 else if(!*a->p40c)return 0;
 a->b1e9=14;a->b5=0;a->b7=0;a->b6=0;
 func_0c045248(a,29);return 1;
}
unsigned char func_0c0f4bbc(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24a33c,a->x374))return 0;
 func_0c047aac(a,a->x374);
 a->b1e9=3;a->b5=0;a->b7=0;a->b6=0;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c0f4c02(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24a34c,a->x3b4))return 0;
 func_0c047aac(a,a->x3b4);
 a->b1e9=8;a->b5=0;a->b7=0;a->b6=0;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c0f4c70(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24a32c,a->x36c))return 0;
 else {struct ActorSub2a4 *s=&a->sub2a4;if(s->b0)return 0;}
 func_0c047aac(a,a->x36c);
 a->b1e9=2;a->b5=0;a->b7=0;a->b6=0;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c0f4cc0(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24a378,a->x384))return 0;
 else if(!*a->p40c)return 0;
 func_0c047aac(a,a->x384);
 a->b1e9=5;a->b5=0;a->b7=0;a->b6=0;
 func_0c045248(a,29);return 1;
}
unsigned char func_0c0f4d10(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24a30c,a->x364))return 0;
 else {struct ActorSub2a4 *s=&a->sub2a4;if(s->b0)return 0;}
 func_0c047aac(a,a->x364);
 a->b1e9=1;a->b5=0;a->b7=0;a->b6=0;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c0f4d84(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24a31c,a->x39c))goto fail;
 else {struct ActorSub2a4 *s=&a->sub2a4;if(s->b0)goto fail;}
 if(!a->b1fc){if(a->b1d4){fail:return 0;}a->b1d4++;}
 func_0c047aac(a,a->x39c);
 a->b1e9=9;a->b5=0;a->b7=0;a->b6=0;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c0f4dea(struct Actor *a)
{
 if(!func_0c047068(a,dat_0c24a35c,a->x37c))return 0;
 if(a->b1a1==8)func_0c047aac(a,a->x37c);
 a->b1e9=4;a->b5=0;a->b7=0;a->b6=0;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c0f4e3a(struct Actor *a)
{
 if(!func_0c047068(a,dat_0c24a36a,a->x38c))return 0;
 func_0c047aac(a,a->x38c);
 a->b1e9=7;a->b5=0;a->b7=0;a->b6=0;
 func_0c045248(a,21);return 1;
}
int func_0c0f4eac(struct Actor *a)
{
 if(func_0c0f4ede(a)||func_0c0f4f14(a)||func_0c0f4f4a(a))return 1;
 return 0;
}
unsigned char func_0c0f4ede(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24a388,a->x3a4))return 0;
 else if(!*a->p40c)return 0;
 a->b258=10;return 1;
}
unsigned char func_0c0f4f14(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24a398,a->x3ac))return 0;
 else if(!*a->p40c)return 0;
 a->b258=14;return 1;
}
unsigned char func_0c0f4f4a(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24a378,a->x384))return 0;
 else if(!*a->p40c)return 0;
 a->b258=5;return 1;
}
int func_0c0f4f80(struct Actor *a)
{
 if(!func_0c046d54(a))return 0;
 else if(!*a->p40c)return 0;
 a->b1e9=16;a->b5=0;
 func_0c045248(a,29);
 a->b6=a->b7=0;return 1;
}
void func_0c0f4fe0(void){}
void func_0c0f4fe4(struct Actor *a){table_0c24a460[a->b1ff](a);}
void func_0c0f4ff8(struct Actor *a){func_0c044cbc(a);if((unsigned char)a->b1fe==1){if(a->b1f9==1)func_0c0f5292(a);else func_0c0f51c0(a);}else if(a->b1f9==1)func_0c0f5112(a);else func_0c0f5040(a);}
void func_0c0f5040(struct Actor *a)
{
 int zero=0,one=1;
 switch(a->b1e8){
 case 0:a->b158=zero;a->b1a1=zero;func_0c0346da(a,20);a->p3f4=dat_0c24a3a8;a->b1a7=zero;break;
 case 1:a->b158=one;a->b1a1=one;func_0c0346da(a,21);a->p3f4=dat_0c24a3ac;a->b1a7=one;break;
 case 2:a->b158=2;a->b1a1=2;a->p3f4=dat_0c24a3b0;a->b1a7=2;func_0c0346da(a,22);break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,7,a->b158);
}
void func_0c0f5112(struct Actor *a)
{
 int zero=0;
 switch(a->b1e8){
 case 0:a->b158=zero;a->b1a1=6;func_0c0346da(a,20);a->p3f4=dat_0c24a3a8;a->b1a7=zero;break;
 case 1:a->b158=1;a->b1a1=7;func_0c0346da(a,21);a->p3f4=dat_0c24a3ac;a->b1a7=1;break;
 case 2:a->b158=2;a->b1a1=8;a->p3f4=dat_0c24a3b0;a->b1a7=2;func_0c0346da(a,22);break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,9,a->b158);
}
void func_0c0f51c0(struct Actor *a)
{
 int zero=0;
 switch(a->b1e8){
 case 0:a->b158=zero;a->b1a1=3;func_0c0346da(a,20);a->p3f4=dat_0c24a3b4;a->b1a7=zero;break;
 case 1:a->b158=1;a->b1a1=4;func_0c0346da(a,21);a->p3f4=dat_0c24a3b8;a->b1a7=1;break;
 case 2:a->b158=2;a->b1a1=5;a->p3f4=dat_0c24a3bc;a->b1a7=2;func_0c0346da(a,22);break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,8,a->b158);
}
void func_0c0f5292(struct Actor *a)
{
 int zero=0;
 switch(a->b1e8){
 case 0:a->b158=zero;a->b1a1=9;func_0c0346da(a,20);a->p3f4=dat_0c24a3b4;a->b1a7=zero;break;
 case 1:a->b158=1;a->b1a1=10;func_0c0346da(a,21);a->p3f4=dat_0c24a3b8;a->b1a7=1;break;
 case 2:a->b158=2;a->b1a1=11;a->p3f4=dat_0c24a3bc;a->b1a7=2;func_0c0346da(a,22);break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,10,a->b158);
}
