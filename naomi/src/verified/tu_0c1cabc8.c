/* Exact positioned effect allocation, scale growth, phase-derived display values, and 60-frame exit. */
#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct Vec3_tu5_03 table_0c25f280[];
extern float table_0c25f2c8[];
extern struct ActorGlobalRoot *dat_0c2d9670;
extern float func_0c1ec2c0(int);
extern void func_0c037688(struct Obj_tu5_03 *);
void func_0c1cac1e(struct Obj_tu5_03 *);
void func_0c1cabc8(int index)
{
 struct Obj_tu5_03 *q;
 if((q=func_0c0374da(0,11,1))){
 q->b12c=1;q->p16=func_0c1cac1e;q->lcc=0xc19;
 q->b32=index;q->pos=table_0c25f280[index];
 q->f80=table_0c25f2c8[index];q->f84=q->f80;
 }
}
void func_0c1cac1e(struct Obj_tu5_03 *q)
{
 q->l84=(int)((void **)dat_0c2d9670->p0)[26];
 q->f80+=0.04f;q->f84+=0.04f;
 q->f120=func_0c1ec2c0((int)(q->w28*3*65536.0f/360.0f+0.5f)&65535);
 q->f124=q->f120;q->f128=q->f120;
 if(++q->w28>=60)func_0c037688(q);
}
