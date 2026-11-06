#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *),func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c0346da(struct Actor *,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c2404b4[])(struct Actor *);
extern void func_0c0429a4(struct Actor *,struct LinkedActorVec3 *,int);
extern struct Actor *func_0c135404(struct Actor *,int);
extern unsigned short dat_0c22f1b0[];
void func_0c0671e8(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c06720a(struct Actor *a){table_0c2404b4[a->b6](a);}
void func_0c06721c(struct Actor *a)
{
 int zero;
 if(a->b255==6){a->b3f0=255;a->b3f1=16;}
 a->b6++;zero=0;a->s28=zero;func_0c0442fa(a);
 if(a->b1f9==2){
 a->b1f9=2;a->f92=0;a->f96=0;a->f104=0;a->f108=0;a->f108=-0.80357140303f;
 a->b1a1=80;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;
 dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,22,8);
 }else{
 a->b1f9=zero;func_0c0432ca(a);
 a->b1a1=80;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;
 dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,22,6);
 }

}
void func_0c0672de(struct Actor *a)
{
 struct LinkedActorVec3 position;
 int five=5;
 a->b3f8=2;a->b328=five;a->b3f1=a->b255==6?2:0;a->b328=five;
 func_0c02a026(a);
 if(!a->b141){a->b6++;a->b3f0=0;a->b3f1=0;
 position.x=-53.3333321f;position.y=377.142853f;position.z=0;
 func_0c0429a4(a,&position,1);}
}
void func_0c06737e(struct Actor *a)
{
 int zero;
 struct Actor *child;
 a->b3f8=2;a->b328=5;*(char *)&a->b328=5;
 func_0c02a026(a);zero=0;
 if(a->b140){a->b140=zero;func_0c0346da(a,48);}
 if(a->b141){
 if(++a->s28>=8){
 a->b6++;a->b3f9=zero;a->b3f8=zero;a->b327=zero;a->b328=zero;
 if(a->b1f9!=2)func_0c02a0c4(a,22,7);else func_0c02a0c4(a,22,9);
 }else{
 if((child=func_0c135404(a,1))){
 child->f52=dat_0c22f1b0[a->s28]*1.66666663f;
 if(!a->w130)child->f52=-child->f52;
 child->f52+=a->f52;
 }
 }
 }
}
