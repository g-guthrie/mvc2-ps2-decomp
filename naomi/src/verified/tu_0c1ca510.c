/* Slot emblem family: constructor with per-index start tables and four update callbacks (exact under SHC 5.1R08). */
#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern unsigned char dat_0c25edf8[];
extern struct ActorGlobalRoot *dat_0c2d966c;
extern struct Vec3_tu5_03 dat_0c25edfc[],dat_0c25ee38[],dat_0c25ee74,dat_0c25ee80[],dat_0c25eebc,dat_0c2d926c;
extern struct ActorFlags *dat_0c2d6f84;
extern void (*table_0c25eec8[])(struct Obj_tu5_03 *);
extern void func_0c037688(struct Obj_tu5_03 *);
void func_0c1ca608(struct Obj_tu5_03 *);
void func_0c1ca510(int index,int variant){
 struct Obj_tu5_03 *a;struct Vec3_tu5_03 *position,*angles;
 if((a=func_0c0374da(0,5,1))){
 a->b12c=0;a->b32=index;a->pad34=variant;a->p16=func_0c1ca608;
 a->l84=((int *)dat_0c2d966c->p0)[dat_0c25edf8[index]];
 a->f80=1.0f;a->f84=1.0f;a->f88=1.0f;a->lcc=0x81f;a->w28=0;a->w30=30;
 switch(index){
 case 0:case 3:position=&dat_0c25edfc[variant];angles=&dat_0c25ee80[variant];break;
 case 1:position=&dat_0c25ee38[variant];angles=&dat_0c25ee80[variant];break;
 case 2:position=&dat_0c25ee74;angles=&dat_0c25eebc;break;
 }
 a->pos=*position;
 a->angles.array[0]=(int)(angles->x*65536.0f/360.0f+0.5f)&65535;
 a->angles.scalar.l44=(int)(angles->y*65536.0f/360.0f+0.5f)&65535;
 a->angles.scalar.l48=(int)(angles->z*65536.0f/360.0f+0.5f)&65535;
 }
}
void func_0c1ca608(struct Obj_tu5_03 *a){
 struct ActorFlags *state=dat_0c2d6f84;
 if(state->b3!=4 || state->b8d){func_0c037688(a);return;}
 if(state->s14==3)table_0c25eec8[a->b32](a);
}
void func_0c1ca68c(struct Obj_tu5_03 *a){
 a->b12c=1;
 if(a->w30){struct Vec3_tu5_03 *start,*end;
 a->w30--;start=&dat_0c25edfc[a->pad34];end=&dat_0c2d926c;
 a->pos.x=start->x+(end->x-start->x)/30.0f*a->w30;
 a->pos.y=start->y+(end->y-start->y)/30.0f*a->w30;
 a->pos.z=start->z+(end->z-start->z)/30.0f*a->w30;
 }
}
void func_0c1ca706(struct Obj_tu5_03 *a){
 if(a->w30){a->w30--;return;}
 a->b12c=1;
 if(a->w28==30)a->f80=128.2f;
 else{a->w28++;a->f80=a->w28*127.2f/30.0f+1.0f;}
}
void func_0c1ca74a(struct Obj_tu5_03 *a){
 if(a->w28++==30){a->w28=0;a->b12c^=1;}
}
