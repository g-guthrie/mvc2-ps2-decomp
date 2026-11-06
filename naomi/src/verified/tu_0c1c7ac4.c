/* Complete pulsing display and texture-coordinate animation family. */
#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct ActorGlobalRoot *dat_0c2d9658;
extern struct ActorFlags *dat_0c2d6f84;
extern void (*table_0c25e988[])(struct Obj_tu5_03 *),(*table_0c25e9a0[])(struct Obj_tu5_03 *);
extern int func_0c1d91a8(int),func_0c1d8ff8(int,int);
extern void func_0c037688(struct Obj_tu5_03 *);
extern int func_0c1d901e(void);
extern int func_0c1d912a(float *,float *),func_0c1d917e(float *,float *);
void func_0c1c7b6a(struct Obj_tu5_03 *),func_0c1c7c50(struct Obj_tu5_03 *),func_0c1c7cb4(struct Obj_tu5_03 *),func_0c1c7d2c(struct Obj_tu5_03 *);
void func_0c1c7ac4(struct Obj_tu5_03 *source,unsigned char global)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,5,1))!=0){
 a->b12c=1;a->p24=source->p24;a->p200=&source->f136;a->p20=source->p20;a->b32=source->b32;a->b33=source->b33;
 a->l84=((int *)dat_0c2d9658->p0)[175];
 if(global)a->p16=func_0c1c7c50;else a->p16=func_0c1c7b6a;
 a->lcc=0x0810;a->f80=1.0f;a->f84=1.0f;a->f88=1.0f;((struct LinkedActor *)a)->b34=0;
 a->w28=0;a->w30=0;a->i208=6;a->f92=0.01f;func_0c1d91a8(a->l84);
 }
}
void func_0c1c7b6a(struct Obj_tu5_03 *a){table_0c25e988[a->p24->b4](a);}
void func_0c1c7b7e(struct Obj_tu5_03 *a){a->b12c=0;}
void func_0c1c7b86(struct Obj_tu5_03 *a)
{
 switch((unsigned char)a->b5){
 case 0:a->b5++;
 case 1:
 {struct Actor *owner=(struct Actor *)a->p20;
 if(a->b33!=owner->b4c9)a->b12c=0;else a->b12c=1;}
 func_0c1c7cb4(a);func_0c1c7d2c(a);break;
 }
}
void func_0c1c7bd4(struct Obj_tu5_03 *a)
{
 switch(a->b6){
 case 0:a->b6++;a->i208=3;a->f92=0.04f;
 case 1:func_0c1c7cb4(a);func_0c1c7d2c(a);break;
 }
}
void func_0c1c7c3e(struct Obj_tu5_03 *a){a->b12c=0;}
void func_0c1c7c46(struct Obj_tu5_03 *a){a->b12c=0;func_0c037688(a);}
void func_0c1c7c50(struct Obj_tu5_03 *a){table_0c25e9a0[a->p24->b4](a);}
void func_0c1c7c64(struct Obj_tu5_03 *a)
{
 switch((unsigned char)a->b5){
 case 0:a->b5++;
 case 1:
 if(a->b33!=(signed char)dat_0c2d6f84->pad137[0])a->b12c=0;else a->b12c=1;
 func_0c1c7cb4(a);func_0c1c7d2c(a);break;
 }
}
void func_0c1c7cb4(struct Obj_tu5_03 *a)
{
 a->w30--;
 if(a->w30<=0){
 a->w30=((union LinkedActorWcc *)&a->i208)->short_value;
 if(((struct LinkedActor *)a)->b34){
 a->f80+=a->f92;
 if(!(1.03f>a->f80)){a->f80=1.03f;((struct LinkedActor *)a)->b34=0;}
 }else{
 a->f80-=a->f92;
 if(!(a->f80>1.0f)){a->f80=1.0f;((struct LinkedActor *)a)->b34=1;}
 }
 }
}
void func_0c1c7d2c(struct Obj_tu5_03 *a)
{
 float u,v;
 if(!a->b33){
 a->w28++;if(a->w28>=500)a->w28=0;
 func_0c1d8ff8(((int *)dat_0c2d9658->p0)[176],a->l84);
 while(func_0c1d901e()==0){func_0c1d912a(&v,&u);u=u-a->w28*0.0020000001f;func_0c1d917e(&v,&u);}
 }
}
