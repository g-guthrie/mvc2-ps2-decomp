/* Resource group construction and timed angular keyframe interpolation. */
#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct ActorGlobalRoot *dat_0c2d9678;
extern struct Vec3_tu5_03 dat_0c230b48[];
extern struct Vec3_tu5_03 *table_0c260a7c[];
extern int dat_0c231dc0[];
void func_0c1ccf2c(void),func_0c1cd0f8(int);
void func_0c1ccfb2(struct Obj_tu5_03 *),func_0c1cd180(struct Obj_tu5_03 *);
void func_0c1ccf0c(void){int i;func_0c1ccf2c();for(i=0;i<7;i++)func_0c1cd0f8(i);}
void func_0c1ccf2c(void){
 struct Obj_tu5_03 *a;struct Vec3_tu5_03 *angles;
 if((a=func_0c0374da(0,5,1))){
 a->b12c=1;a->p16=func_0c1ccfb2;a->l84=((int *)dat_0c2d9678->p0)[0];a->lcc=0x80e;a->b32=0;
 a->angles.array[0]=(int)((angles=dat_0c230b48)->x*65536.0f/360.0f+0.5f)&65535;
 a->angles.scalar.l44=(int)(angles->y*65536.0f/360.0f+0.5f)&65535;
 a->angles.scalar.l48=(int)(angles->z*65536.0f/360.0f+0.5f)&65535;
 }
}
void func_0c1ccfb2(struct Obj_tu5_03 *a){
 switch(a->b4){
 case 0:{
 int frame=a->w30,next=frame+1;
 int duration=dat_0c231dc0[next]-dat_0c231dc0[frame];
 struct Vec3_tu5_03 *start=&dat_0c230b48[frame],*end=&dat_0c230b48[next];
 a->angles.array[0]+=((int)((end->x-start->x)/duration*65536.0f/360.0f+0.5f)&65535);
 a->angles.array[1]+=((int)((end->y-start->y)/duration*65536.0f/360.0f+0.5f)&65535);
 a->angles.array[2]+=((int)((end->z-start->z)/duration*65536.0f/360.0f+0.5f)&65535);
 if(++a->w28>=duration){
 a->w28=0;
 a->angles.array[0]=(int)(end->x*65536.0f/360.0f+0.5f)&65535;
 a->angles.scalar.l44=(int)(end->y*65536.0f/360.0f+0.5f)&65535;
 a->angles.scalar.l48=(int)(end->z*65536.0f/360.0f+0.5f)&65535;
 if((unsigned int)++a->w30>=49)a->b4++;
 }
 break;
 }
 case 1:break;
 }
}
void func_0c1cd0f8(int index){
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,5,1))){
 a->b12c=1;a->p16=func_0c1cd180;a->l84=((int *)dat_0c2d9678->p0)[index+1];a->lcc=0x801;a->b32=index;a->pos=*table_0c260a7c[index];
 }
}
