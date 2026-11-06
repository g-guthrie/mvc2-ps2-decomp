/* Resource, position and angle construction from indexed placement tables. */
#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern void func_0c1c9d58(struct Obj_tu5_03 *);
extern int func_0c1d91a8(int);
extern unsigned char dat_0c25ec1c[];
extern int **dat_0c2d966c;
extern struct Vec3_tu5_03 dat_0c25ec20[],dat_0c25ec44[];
void func_0c1c9c0c(int index){
 struct Obj_tu5_03 *a;struct Vec3_tu5_03 *angles;
 if((a=func_0c0374da(0,5,1))){
 a->b12c=1;a->b32=index;a->p16=func_0c1c9d58;a->pad34=dat_0c25ec1c[index];
 a->l84=(*dat_0c2d966c)[a->pad34];
 a->pos=dat_0c25ec20[index];
 a->angles.array[0]=(int)((angles=&dat_0c25ec44[index])->x*65536.0f/360.0f+0.5f)&65535;
 a->angles.scalar.l44=(int)(angles->y*65536.0f/360.0f+0.5f)&65535;
 a->angles.scalar.l48=(int)(angles->z*65536.0f/360.0f+0.5f)&65535;
 switch(index){
 case 0:case 1:func_0c1d91a8(a->l84);a->lcc=0x80f;a->w30=0;break;
 case 2:a->lcc=0x4800;a->w28=64;a->w30=3;a->f92=48.0f;break;
 }
 a->lcc|=0x400;a->f120=1.0f;a->f124=1.0f;a->f128=1.0f;
 }
}
