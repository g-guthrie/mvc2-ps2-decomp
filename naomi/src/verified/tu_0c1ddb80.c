#include "objects.h"
extern void (*table_0c262310[])(struct Obj_tu5_03 *);
extern struct Vec3_tu5_03 dat_0c2330b0[];
extern struct Vec3_tu5_03 dat_0c2fb610[];
void func_0c1ddb80(struct Obj_tu5_03 *a);
void func_0c1ddb94(struct Obj_tu5_03 *a);
void func_0c1ddc44(struct Obj_tu5_03 *a);

void func_0c1ddb80(struct Obj_tu5_03 *a)
{
 table_0c262310[a->b4](a);
 return;
}

void func_0c1ddb94(struct Obj_tu5_03 *a)
{
 float duration;
 *(struct Vec3_tu5_03 *)&a->f92=dat_0c2330b0[(unsigned char)a->b5];
 a->b5=a->b5+1;
 a->b5 &= 1;
 *(struct Vec3_tu5_03 *)((char *)a+104)=dat_0c2330b0[(unsigned char)a->b5];
 duration=100.0f;
 dat_0c2fb610[a->b35].x=(a->f104-a->f92)/duration;
 dat_0c2fb610[a->b35].y=(a->f108-a->f96)/duration;
 dat_0c2fb610[a->b35].z=(a->f112-a->f100)/duration;
 a->b4=1;
 func_0c1ddc44(a);
 return;
}

void func_0c1ddc44(struct Obj_tu5_03 *a)
{
 a->w28++;
 if(a->w28>100){a->b4=0;a->w28=0;return;}
 a->angles.array[0]=(int)(a->f92*65536.0f/360.0f+0.5f)&65535;
 a->angles.array[1]=(int)(a->f96*65536.0f/360.0f+0.5f)&65535;
 a->angles.array[2]=(int)(a->f100*65536.0f/360.0f+0.5f)&65535;
 a->angles.array[0]+=(int)(dat_0c2fb610[a->b35].x*a->w28*65536.0f/360.0f+0.5f)&65535;
 a->angles.array[1]+=(int)(dat_0c2fb610[a->b35].y*a->w28*65536.0f/360.0f+0.5f)&65535;
 a->angles.array[2]+=(int)(dat_0c2fb610[a->b35].z*a->w28*65536.0f/360.0f+0.5f)&65535;
}
