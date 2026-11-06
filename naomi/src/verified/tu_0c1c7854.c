/* Allocate and update seventeen scrolling display elements. */
#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct ActorGlobalRoot *dat_0c2d9658;
extern struct ActorFlags *dat_0c2d6f84;
extern int dat_0c25e914[];
extern void func_0c037688(struct Obj_tu5_03 *);
extern void (*table_0c25e958[])(struct Obj_tu5_03 *);
void func_0c1c78ea(struct Obj_tu5_03 *);
void func_0c1c7854(void){
 unsigned char index;struct Obj_tu5_03 *a;
 for(index=0;index<17;index++){
 if(!(a=func_0c0374da(0,5,1)))break;
 a->b12c=1;a->p16=func_0c1c78ea;a->b32=index;
 a->pos.x=0;a->pos.y=400.0f;a->pos.z=0;
 a->angles.array[0]=0;a->angles.array[1]=dat_0c25e914[index];a->angles.array[2]=0;
 a->l84=((int *)dat_0c2d9658->p0)[134+index];a->lcc=0x805;
 }
}
void func_0c1c78ea(struct Obj_tu5_03 *a){table_0c25e958[a->b4](a);}
void func_0c1c78fc(struct Obj_tu5_03 *a){
 if((signed char)dat_0c2d6f84->b3>=2){a->b4++;a->b12c=0;}else a->angles.array[1]-=256;
}
void func_0c1c7928(struct Obj_tu5_03 *a){a->b4++;}
void func_0c1c7930(struct Obj_tu5_03 *a){func_0c037688(a);}
