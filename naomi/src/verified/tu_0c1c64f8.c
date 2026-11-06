/* Selection resource construction, completion flags, and state dispatch. */
#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern int **dat_0c2d9658;
extern struct Vec3_tu5_03 dat_0c25e240[];
extern unsigned char dat_0c2fb15a[],dat_0c2d96a8,dat_0c2d96a9;
extern struct SelectionFlags59e8 dat_0c2fb158;
extern struct ActorFlags *dat_0c2d6f84;
extern void func_0c02c50c(int);
extern void (*table_0c25e258[])(struct Obj_tu5_03 *);
void func_0c1c6620(struct Obj_tu5_03 *);
void func_0c1c64f8(struct Obj_tu5_03 *parent){
 struct Obj_tu5_03 *a;
 if(!(a=func_0c0374da(0,5,1)))return;
 a->b12c=1;a->p16=func_0c1c6620;a->p24=parent;a->p200=&parent->f136;a->p20=parent->p20;
 a->b32=parent->b32;a->b33=parent->b33;a->pos=dat_0c25e240[parent->b32];
 a->l84=(*dat_0c2d9658)[parent->b32*3+parent->b33+76];
 a->angles.array[0]=0;a->angles.scalar.l44=0;a->angles.scalar.l48=0;a->lcc=0x805;
 if(dat_0c2fb15a[parent->b32]&(1<<parent->b33)){
 a->b4=6;dat_0c2d96a8=1;dat_0c2d96a9|=a->b32+1;
 func_0c02c50c(a->b33*2+a->b32);
 if(!a->b32)a->angles.scalar.l44=0x8000;
 if(dat_0c2d6f84->b81==7 || a->b33==2)dat_0c2fb158.state[a->b32]=1;
 }else a->w28=parent->b33*10;
}
void func_0c1c6620(struct Obj_tu5_03 *a){table_0c25e258[a->b4](a);}
