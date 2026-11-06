/* Resource callback dispatch, counter-rotating UV scroll, and timed matrix placement. */
#include "objects.h"
extern struct ActorFlags *dat_0c2d6f84;
extern void (*table_0c25ec68[])(struct Obj_tu5_03 *);
extern int **dat_0c2d966c;
extern struct Vec3_tu5_03 dat_0c25ec20[];
extern int func_0c1d901e(void);
extern void func_0c1d8ff8(int,int),func_0c1d912a(float *,float *),func_0c1d917e(float *,float *);
extern void func_0c037688(struct Obj_tu5_03 *);
extern void func_0c1ee3b0(int),func_0c1edc40(float *),func_0c1eeb60(void),func_0c1eeb40(struct Vec3_tu5_03 *);
extern void func_0c1ee7f0(int),func_0c1ee730(int),func_0c1ee580(int),func_0c1eeb10(float,float,float),func_0c1ed4e0(float *),func_0c1ee360(int);
void func_0c1c9d58(struct Obj_tu5_03 *a){
 if(dat_0c2d6f84->b2>=3){if(a->f120>=0.5f){a->f120-=0.01f;a->f124=a->f120;a->f128=a->f120;}}
 table_0c25ec68[a->b32](a);
}
void func_0c1c9d9e(struct Obj_tu5_03 *a){
 float u,v;
 a->angles.array[0]+=256;
 a->w30++;if(a->w30>=200)a->w30=0;
 func_0c1d8ff8((*dat_0c2d966c)[a->pad34+1],a->l84);
 while(!func_0c1d901e()){
 func_0c1d912a(&u,&v);v+=-(a->w30*0.005f)+1.0f;func_0c1d917e(&u,&v);
 }
}
void func_0c1c9e34(struct Obj_tu5_03 *a){
 float u,v;
 a->angles.array[0]-=256;
 a->w30++;if(a->w30>=200)a->w30=0;
 func_0c1d8ff8((*dat_0c2d966c)[a->pad34+1],a->l84);
 while(!func_0c1d901e()){
 func_0c1d912a(&u,&v);v+=-(a->w30*0.005f)+1.0f;func_0c1d917e(&u,&v);
 }
}
void func_0c1c9efa(struct Obj_tu5_03 *a){
 register float zero;
 if(!--a->w28){a->w28=64;a->pos=dat_0c25ec20[a->b32];if(!--a->w30){func_0c037688(a);return;}}
 func_0c1ee3b0(0);func_0c1edc40(&a->f136);func_0c1eeb60();func_0c1eeb40(&a->pos);
 func_0c1ee7f0(a->angles.scalar.l48);func_0c1ee730(a->angles.scalar.l44);func_0c1ee580(a->angles.array[0]);
 zero=0.0f;func_0c1eeb10(a->f92,zero,zero);func_0c1ed4e0(&a->f136);
 a->pos.x=*(float *)&a->pad7[0xb8-0x8c];a->pos.y=*(float *)&a->pad7[0xbc-0x8c];a->pos.z=*(float *)&a->pad7[0xc0-0x8c];
 func_0c1ee360(1);
}
