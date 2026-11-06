/* Path-effect state machine: idle wait, then drift along a random path segment with a sine fade.
 * The unsigned 9U in the l84 index keeps retail's add before the scale (no displacement fold). */
#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct ActorFlags *dat_0c2d6f84;
extern struct ActorGlobalRoot *dat_0c2d964c;
extern struct Vec3_tu5_03 dat_0c261cec[][2];
extern int func_0c1ec190(void);
extern float func_0c1ec2c0(int);
void func_0c1d9d98(struct Obj_tu5_03 *);
void func_0c1d9d70(void){
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,5,1))){a->b12c=0;a->p16=func_0c1d9d98;a->lcc=0xb21;}
}
void func_0c1d9d98(struct Obj_tu5_03 *a){
 switch(a->b4){
 case 0:{
 unsigned int scene;
 a->b12c=0;
 if(++a->w28<60)break;
 a->w28=60;scene=dat_0c2d6f84->i90;
 if((scene>500 && scene<1000)||(scene>3500 && scene<4500))break;
 a->b4++;a->b32=(unsigned int)func_0c1ec190()%6;
 a->w28=0;a->b12c=1;
 a->l84=((int *)dat_0c2d964c->p0)[(int)(func_0c1ec190()%2+9U)];
 a->pos=dat_0c261cec[a->b32][0];a->angles.array[2]=func_0c1ec190()%16384;
 break;
 }
 case 1:
 a->pos.x+=(dat_0c261cec[a->b32][1].x-dat_0c261cec[a->b32][0].x)/120.0f;
 a->pos.y+=(dat_0c261cec[a->b32][1].y-dat_0c261cec[a->b32][0].y)/120.0f;
 a->pos.z+=(dat_0c261cec[a->b32][1].z-dat_0c261cec[a->b32][0].z)/120.0f;
 a->f116=func_0c1ec2c0((int)(a->w28/120.0f*(180.0f*65536.0f)/360.0f+0.5f)&65535);
 if(++a->w28>=120){a->b4=0;a->w28=0;}
 break;
 }
}
