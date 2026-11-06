#include "objects.h"
extern struct Vec3_tu5_03 *table_0c260a7c[];
extern int dat_0c231dc0[];
void func_0c1cd180(struct Obj_tu5_03 *a){
 switch(a->b4){
 case 0:{
 int frame=a->w30,next=frame+1;
 int duration=dat_0c231dc0[next]-dat_0c231dc0[frame];
 struct Vec3_tu5_03 *start=&table_0c260a7c[a->b32][frame],*end=&table_0c260a7c[a->b32][next];
 a->pos.x+=(end->x-start->x)/duration;
 a->pos.y+=(end->y-start->y)/duration;
 a->pos.z+=(end->z-start->z)/duration;
 if(++a->w28>=duration){
 a->w28=0;
 a->pos=*end;
 if((unsigned int)++a->w30>=48)a->b4++;
 }
 break;
 }
 case 1:break;
 }
 if(a->b32==4)a->b5++;
}
