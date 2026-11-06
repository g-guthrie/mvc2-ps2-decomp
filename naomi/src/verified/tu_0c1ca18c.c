/* Resource construction, timed endpoint interpolation, and paired UV scroll. */
#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern unsigned char dat_0c25eca8[];
extern int **dat_0c2d966c;
extern struct Vec3_tu5_03 dat_0c25ecb8[],dat_0c25ed18[],dat_0c25ed78[];
extern struct ActorFlags *dat_0c2d6f84;
extern void (*table_0c25edd8[])(struct Obj_tu5_03 *);
extern void func_0c037688(struct Obj_tu5_03 *);
extern void func_0c1d91a8(int);
extern int func_0c1d901e(void);
extern void func_0c1d8ff8(int,int),func_0c1d912a(float *,float *),func_0c1d917e(float *,float *);
void func_0c1ca314(struct Obj_tu5_03 *);
void func_0c1ca18c(int index,int resource){
 struct Obj_tu5_03 *a;struct Vec3_tu5_03 *angles;
 if((a=func_0c0374da(0,5,1))){
 a->b12c=0;a->b32=index;a->p16=func_0c1ca314;a->pad34=dat_0c25eca8[resource];a->l84=(*dat_0c2d966c)[a->pad34];
 a->pos=dat_0c25ecb8[index];
 a->angles.array[0]=(int)((angles=&dat_0c25ed18[index])->x*65536.0f/360.0f+0.5f)&65535;
 a->angles.scalar.l44=(int)(angles->y*65536.0f/360.0f+0.5f)&65535;
 a->angles.scalar.l48=(int)(angles->z*65536.0f/360.0f+0.5f)&65535;
 a->lcc=0x80f;a->w28=0;a->w30=0;
 if(index>=4)return;func_0c1d91a8(a->l84);
 }
}
void func_0c1ca26a(struct Obj_tu5_03 *a){
 struct Vec3_tu5_03 *start=&dat_0c25ecb8[a->b32],*end=&dat_0c25ed78[a->b32];
 a->pos.x=start->x+(end->x-start->x)/30.0f*a->w28;
 a->pos.y=start->y+(end->y-start->y)/30.0f*a->w28;
 a->pos.z=start->z+(end->z-start->z)/30.0f*a->w28;
}
void func_0c1ca314(struct Obj_tu5_03 *a){
 struct ActorFlags *state=dat_0c2d6f84;
 if(state->b3!=4 || state->b8d){func_0c037688(a);return;}
 if(!a->b4){
 if(state->s14){a->b12c=1;
 if(a->w28>=30){a->b4++;a->pos=dat_0c25ed78[a->b32];return;}
 else{a->w28++;func_0c1ca26a(a);}
 }
 return;
 }
 table_0c25edd8[a->b32](a);
}
void func_0c1ca39e(struct Obj_tu5_03 *a){
 float u,v;
 a->w30++;if(a->w30>=200)a->w30=0;
 func_0c1d8ff8((*dat_0c2d966c)[a->pad34+1],a->l84);
 while(!func_0c1d901e()){
 func_0c1d912a(&u,&v);u+=a->w30*0.005f;v+=a->w30*0.005f;func_0c1d917e(&u,&v);
 }
}
