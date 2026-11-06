/* Selection-mask initialization, dispatch and phase synchronization. */
#include "objects.h"
extern struct ActorFlags *dat_0c2d6f84;
extern struct SelectionFlags59e8 dat_0c2fb158;
extern unsigned char dat_0c2fb18b,dat_0c2fb18e;
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern void func_0c037688(struct Obj_tu5_03 *);
void func_0c1c81be(struct Obj_tu5_03 *),func_0c1c81e4(struct Obj_tu5_03 *);
void func_0c1c8148(void){
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,5,1))){
 a->b12c=0;a->p16=func_0c1c81be;a->b35=dat_0c2d6f84->b85|dat_0c2d6f84->b84;
 switch(a->b35){
 case 1:a->b32=1;a->b33=2;goto reset;
 case 2:a->b32=2;a->b33=1;reset:a->b4=0;a->b5=0;break;
 case 3:a->b4=2;dat_0c2fb18b=3;break;
 }
 }
}
void func_0c1c81be(struct Obj_tu5_03 *a){
 if(!dat_0c2fb18e){switch(a->b4){case 0:func_0c1c81e4(a);break;case 2:func_0c037688(a);break;}}
}
void func_0c1c81e4(struct Obj_tu5_03 *a){
 switch(a->b6){
 case 0:if(dat_0c2d6f84->b3<3)break;a->b6++;dat_0c2fb158.combined_mask|=a->b32;
 case 1:
 if(dat_0c2d6f84->b3==3){if(dat_0c2d6f84->b85&a->b33){dat_0c2fb158.combined_mask|=3;a->b6++;}}
 else if(dat_0c2d6f84->b3==5){a->b6++;dat_0c2fb158.combined_mask|=3;}
 break;
 case 2:break;
 }
}
