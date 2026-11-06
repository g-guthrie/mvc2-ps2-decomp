/* Selection indicator construction, activation, and grow/shrink animation. */
#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern int **dat_0c2d9658;
extern unsigned char dat_0c2fb15a[];
extern void (*table_0c25e0c4[])(struct Obj_tu5_03 *);
void func_0c1c591a(struct Obj_tu5_03 *);
void func_0c1c5878(struct Actor *parent){
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,5,1))){
 a->b12c=1;a->p24=(struct Obj_tu5_03 *)parent;a->b32=parent->b524;a->b33=parent->s30;a->p16=func_0c1c591a;
 a->l84=(*dat_0c2d9658)[a->b32+4];
 if(parent->b524){a->pos.x=146.0f;a->angles.scalar.l48=0x11c7;}else{a->pos.x=-146.0f;a->angles.scalar.l48=0xee3a;}
 a->pos.y=36.0f;a->pos.z=260.0f;a->angles.array[0]=0xd556;a->angles.scalar.l44=0;
 a->f80=1.0f;a->f84=1.0f;a->f88=1.0f;a->lcc=0x81b;
 }
}
void func_0c1c591a(struct Obj_tu5_03 *a){table_0c25e0c4[a->b4](a);}
void func_0c1c592c(struct Obj_tu5_03 *a){if(dat_0c2fb15a[a->b32]&(1<<a->b33))a->b4++;}
void func_0c1c5950(struct Obj_tu5_03 *a){a->f80+=0.1000000015f;a->f84+=0.1000000015f;if(a->f80>=1.3f)a->b4++;}
void func_0c1c597a(struct Obj_tu5_03 *a){a->f80-=0.1000000015f;a->f84-=0.1000000015f;if(a->f80<=1.0f){a->f80=a->f84=1.0f;a->b4++;}}
