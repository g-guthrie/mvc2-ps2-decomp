/* CPU special-move checks, normal attack selectors and attack-state handlers sharing literal pools. */
#include "objects.h"
extern unsigned char dat_0c248f90[],dat_0c248fa0[],dat_0c248fb0[],dat_0c248fc0[],dat_0c248fd0[],dat_0c248fe0[],dat_0c248ff0[];
extern unsigned char dat_0c249000[],dat_0c249010[],dat_0c249020[],dat_0c249046[],dat_0c249056[];
extern unsigned char dat_0c248f48[],dat_0c248f4c[],dat_0c248f50[],dat_0c248f54[],dat_0c248f58[],dat_0c248f5c[];
extern unsigned char dat_0c248f60[],dat_0c248f64[],dat_0c248f68[],dat_0c248f6c[],dat_0c248f70[],dat_0c248f74[];
extern unsigned char dat_0c248f78[],dat_0c248f7c[],dat_0c248f80[],dat_0c248f84[],dat_0c248f88[],dat_0c248f8c[];
extern void (*table_0c2490d8[])(struct Actor *),(*table_0c2490e8[])(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern unsigned char func_0c0465cc(struct Actor *),func_0c046b6c(struct Actor *),func_0c0469f4(struct Actor *),func_0c046d3c(struct Actor *);
extern unsigned char func_0c046e7e(struct Actor *,unsigned char *,unsigned char *),func_0c0474f8(struct Actor *,unsigned char *,unsigned char *),func_0c046dd0(struct Actor *,int);
extern int func_0c046d54(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c045f1c(struct Actor *),func_0c0463fc(struct Actor *),func_0c047aac(struct Actor *,unsigned char *),func_0c045248(struct Actor *,int);
extern void func_0c044cbc(struct Actor *),func_0c0346da(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int);
extern void func_0c043352(struct Actor *),func_0c044df4(struct Actor *),func_0c0437b8(struct Actor *),func_0c0438de(struct Actor *);
extern void func_0c0421f4(struct Actor *),func_0c0420f8(struct Actor *),func_0c042018(struct Actor *),func_0c0421b8(struct Actor *),func_0c044f1c(struct Actor *);
unsigned char func_0c0df058(struct Actor *a),func_0c0df0aa(struct Actor *a),func_0c0df0f0(struct Actor *a),func_0c0df164(struct Actor *a),func_0c0df1aa(struct Actor *a);
unsigned char func_0c0df1f0(struct Actor *a),func_0c0df238(struct Actor *a),func_0c0df2a8(struct Actor *a),func_0c0df2fc(struct Actor *a),func_0c0df34c(struct Actor *a);
unsigned char func_0c0df392(struct Actor *a),func_0c0df404(struct Actor *a);
unsigned char func_0c0df490(struct Actor *a),func_0c0df4e8(struct Actor *a),func_0c0df51e(struct Actor *a),func_0c0df554(struct Actor *a),func_0c0df58c(struct Actor *a);
int func_0c0df5c2(struct Actor *a);
void func_0c0df68c(struct Actor *a),func_0c0df75e(struct Actor *a),func_0c0df80c(struct Actor *a),func_0c0df8de(struct Actor *a);
void func_0c0df9d8(struct Actor *a),punch_0c0df9ea(struct Actor *a),kick_0c0dfb00(struct Actor *a);
void func_0c0dfc42(struct Actor *a),func_0c0dfcc4(struct Actor *a),func_0c0dfd28(struct Actor *a),func_0c0dfd60(struct Actor *a),func_0c0dfdec(struct Actor *a);
void func_0c0dfe3a(struct Actor *a);
void func_0c0dfe7c(struct Actor *a),func_0c0dfe9e(struct Actor *a);
void func_0c0def40(struct Actor *a)
{
 if(func_0c0465cc(a))return;
 if(func_0c046b6c(a))return;
 if(func_0c0469f4(a))return;
 if(func_0c046d3c(a))return;
 if(func_0c0df058(a))return;
 if(func_0c0df0aa(a))return;
 if(func_0c0df0f0(a))return;
 if(func_0c0df164(a))return;
 if(func_0c0df1aa(a))return;
 if(func_0c0df2fc(a))return;
 if(func_0c0df34c(a))return;
 if(func_0c0df392(a))return;
 if(func_0c0df1f0(a))return;
 if(func_0c0df238(a))return;
 if(func_0c0df2a8(a))return;
 if(func_0c0df404(a))return;
 if(func_0c0df5c2(a))return;
 if(func_0c046dd0(a,8)){a->b1e9=8;a->b5=0;a->b7=0;a->b6=0;func_0c045248(a,21);return;}
 func_0c045f1c(a);func_0c0463fc(a);
}
unsigned char func_0c0df058(struct Actor *a)
{
 if(!func_0c0474f8(a,dat_0c249056,a->x3ac))return 0;
 else if(*a->p40c<3)return 0;
 func_0c047aac(a,a->x3ac);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=16;
 func_0c045248(a,29);return 1;
}
unsigned char func_0c0df0aa(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c248fd0,a->x37c))return 0;
 else if(!*a->p40c)return 0;
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=3;
 func_0c045248(a,29);return 1;
}
unsigned char func_0c0df0f0(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c248fe0,a->x384))return 0;
 else if(!*a->p40c)return 0;
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=4;
 func_0c045248(a,29);return 1;
}
unsigned char func_0c0df164(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c248ff0,a->x38c))return 0;
 else if(!*a->p40c)return 0;
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=5;
 func_0c045248(a,29);return 1;
}
unsigned char func_0c0df1aa(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c248fa0,a->x36c))return 0;
 func_0c047aac(a,a->x36c);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=1;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c0df1f0(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c248f90,a->x364))return 0;
 func_0c047aac(a,a->x364);
 {int zero=0;a->b5=zero;a->b7=zero;a->b6=zero;a->b1e9=zero;}
 func_0c045248(a,21);return 1;
}
unsigned char func_0c0df238(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c248fb0,a->x374))return 0;
 func_0c047aac(a,a->x374);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=2;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c0df2a8(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c248fc0,a->x3bc))goto fail;
 if(a->b1d4){fail:return 0;}
 a->b1d4++;
 func_0c047aac(a,a->x3bc);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=13;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c0df2fc(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c249020,a->x3a4))return 0;
 else if(!*a->p40c)return 0;
 func_0c047aac(a,a->x3a4);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=11;
 func_0c045248(a,29);return 1;
}
unsigned char func_0c0df34c(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c249000,a->x394))return 0;
 func_0c047aac(a,a->x394);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=9;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c0df392(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c249010,a->x39c))return 0;
 func_0c047aac(a,a->x39c);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=10;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c0df404(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c249046,a->x3b4))return 0;
 func_0c047aac(a,a->x3b4);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=14;
 func_0c045248(a,21);return 1;
}
int func_0c0df44a(struct Actor *a)
{
 if(func_0c0df490(a)||func_0c0df4e8(a)||func_0c0df51e(a)||func_0c0df554(a)||func_0c0df58c(a))return 1;
 return 0;
}
unsigned char func_0c0df490(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c248fd0,a->x37c))return 0;
 else if(!*a->p40c)return 0;
 a->b258=3;return 1;
}
unsigned char func_0c0df4e8(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c248fe0,a->x384))return 0;
 else if(!*a->p40c)return 0;
 a->b258=4;return 1;
}
unsigned char func_0c0df51e(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c248ff0,a->x38c))return 0;
 else if(!*a->p40c)return 0;
 a->b258=5;return 1;
}
unsigned char func_0c0df554(struct Actor *a)
{
 if(!func_0c0474f8(a,dat_0c249056,a->x3ac))return 0;
 else if(*a->p40c<3)return 0;
 a->b258=16;return 1;
}
unsigned char func_0c0df58c(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c249020,a->x3a4))return 0;
 else if(!*a->p40c)return 0;
 a->b258=11;return 1;
}
int func_0c0df5c2(struct Actor *a)
{
 if(!func_0c046d54(a))return 0;
 else if(!*a->p40c)return 0;
 a->b1e9=17;a->b5=0;
 func_0c045248(a,29);
 a->b6=a->b7=0;return 1;
}
void func_0c0df62c(void){}
void func_0c0df630(struct Actor *a){table_0c2490d8[a->b1ff](a);}
void func_0c0df644(struct Actor *a){func_0c044cbc(a);if((unsigned char)a->b1fe==1){if(a->b1f9==1)func_0c0df8de(a);else func_0c0df80c(a);}else if(a->b1f9==1)func_0c0df75e(a);else func_0c0df68c(a);}
void func_0c0df68c(struct Actor *a)
{
 int zero=0,one=1;
 switch(a->b1e8){
 case 0:a->b158=zero;a->b1a1=zero;func_0c0346da(a,20);a->p3f4=dat_0c248f48;a->b1a7=zero;break;
 case 1:a->b158=one;a->b1a1=one;func_0c0346da(a,21);a->p3f4=dat_0c248f4c;a->b1a7=one;break;
 case 2:a->b158=2;a->b1a1=2;a->p3f4=dat_0c248f50;a->b1a7=2;func_0c0346da(a,22);break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,7,a->b158);
}
void func_0c0df75e(struct Actor *a)
{
 int zero=0;
 switch(a->b1e8){
 case 0:a->b158=zero;a->b1a1=6;func_0c0346da(a,20);a->p3f4=dat_0c248f48;a->b1a7=zero;break;
 case 1:a->b158=1;a->b1a1=7;func_0c0346da(a,21);a->p3f4=dat_0c248f4c;a->b1a7=1;break;
 case 2:a->b158=2;a->b1a1=8;a->p3f4=dat_0c248f50;a->b1a7=2;func_0c0346da(a,22);break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,9,a->b158);
}
void func_0c0df80c(struct Actor *a)
{
 int zero=0;
 switch(a->b1e8){
 case 0:a->b158=zero;a->b1a1=3;func_0c0346da(a,20);a->p3f4=dat_0c248f54;a->b1a7=zero;break;
 case 1:a->b158=1;a->b1a1=4;func_0c0346da(a,21);a->p3f4=dat_0c248f58;a->b1a7=1;break;
 case 2:a->b158=2;a->b1a1=5;a->p3f4=dat_0c248f5c;a->b1a7=2;func_0c0346da(a,22);break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,8,a->b158);
}
void func_0c0df8de(struct Actor *a)
{
 int zero=0;
 switch(a->b1e8){
 case 0:a->b158=zero;a->b1a1=9;func_0c0346da(a,20);a->p3f4=dat_0c248f54;a->b1a7=zero;break;
 case 1:a->b158=1;a->b1a1=10;func_0c0346da(a,21);a->p3f4=dat_0c248f58;a->b1a7=1;break;
 case 2:a->b158=2;a->b1a1=11;a->p3f4=dat_0c248f5c;a->b1a7=2;func_0c0346da(a,22);break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,10,a->b158);
}
void func_0c0df9b0(struct Actor *a)
{
 if((a->b1fe==0&&(a->b1d6&15))||(a->b1fe!=0&&(a->b1d6&0xf0)))func_0c0df9d8(a);
}
void func_0c0df9d8(struct Actor *a)
{
 if((unsigned char)a->b1fe==1)kick_0c0dfb00(a);
 else punch_0c0df9ea(a);
}
void punch_0c0df9ea(struct Actor *a)
{
 int zero=0;
 switch(a->b1e8){
 case 0:
  a->b158=zero;a->b1a1=12;func_0c0346da(a,20);
  if(!a->b1fc)a->p3f4=dat_0c248f60;else a->p3f4=dat_0c248f78;
  a->b1a7=zero;break;
 case 1:
  a->b158=1;a->b1a1=13;func_0c0346da(a,21);
  if(!a->b1fc)a->p3f4=dat_0c248f64;else a->p3f4=dat_0c248f7c;
  a->b1a7=1;break;
 case 2:
  a->b158=2;a->b1a1=14;func_0c0346da(a,22);
  if(!a->b1fc)a->p3f4=dat_0c248f68;else a->p3f4=dat_0c248f80;
  a->b1a7=2;break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,11,a->b158);
 if(a->b1d6&15)a->b1d6--;
}
void kick_0c0dfb00(struct Actor *a)
{
 int zero=0;
 switch(a->b1e8){
 case 0:
  a->b158=zero;a->b1a1=15;func_0c0346da(a,20);
  if(!a->b1fc)a->p3f4=dat_0c248f6c;else a->p3f4=dat_0c248f84;
  a->b1a7=zero;break;
 case 1:
  a->b158=1;a->b1a1=16;func_0c0346da(a,21);
  if(!a->b1fc)a->p3f4=dat_0c248f70;else a->p3f4=dat_0c248f88;
  a->b1a7=1;break;
 case 2:
  a->b158=2;a->b1a1=17;func_0c0346da(a,22);
  if(!a->b1fc)a->p3f4=dat_0c248f74;else a->p3f4=dat_0c248f8c;
  a->b1a7=2;break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,12,a->b158);
 if(a->b1d6&0xf0)a->b1d6-=16;
}
void func_0c0dfc20(struct Actor *a){table_0c2490e8[a->b1ff](a);}
void func_0c0dfc34(struct Actor *a){func_0c043352(a);func_0c0dfc42(a);}
void func_0c0dfc42(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;func_0c044df4(a);
 if((unsigned char)a->b1fe==1){if(a->b1f9==1)func_0c0dfdec(a);else func_0c0dfd60(a);}
 else{if(a->b1f9==1)func_0c0dfd28(a);else func_0c0dfcc4(a);}
}
void func_0c0dfcc4(struct Actor *a)
{
 switch(a->b1e8){case 2:case 0:case 1:if(func_0c02a026(a)<0)func_0c0437b8(a);break;}
}
void func_0c0dfd28(struct Actor *a)
{
 switch(a->b1e8){case 2:case 0:case 1:if(func_0c02a026(a)<0)func_0c0437b8(a);break;}
}
void func_0c0dfd60(struct Actor *a)
{
 switch(a->b1e8){
 case 2:if(func_0c02a026(a)<0)goto fail;break;
 case 0:case 1:
  if(func_0c02a026(a)<0){fail:func_0c0437b8(a);break;}
  if(a->b14b){int zero=0;a->b1a1=a->b14b;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;a->b14b=zero;}
  break;
 }
}
void func_0c0dfdec(struct Actor *a)
{
 switch(a->b1e8){case 0:case 1:case 2:if(func_0c02a026(a)<0)func_0c0437b8(a);break;}
}
void func_0c0dfe24(struct Actor *a){func_0c0421f4(a);func_0c0420f8(a);func_0c0dfe3a(a);}
void func_0c0dfe3a(struct Actor *a)
{
 func_0c042018(a);func_0c0421b8(a);
 if((unsigned char)a->b1fe==1)func_0c0dfe9e(a);else func_0c0dfe7c(a);
 if(func_0c044e52(a))func_0c044f1c(a);
}
void func_0c0dfe7c(struct Actor *a){if(func_0c02a026(a)<0)func_0c0438de(a);}
void func_0c0dfe9e(struct Actor *a){if(func_0c02a026(a)<0)func_0c0438de(a);}
