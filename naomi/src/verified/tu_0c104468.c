#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c025900(struct Actor *,int,int);
extern short table_0c24b194[];
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
void func_0c104468(struct Actor *a)
{
 short *row;float horizontal;
 a->b3f8=2;a->b328=5;a->b1ea=1;
 if(func_0c02a026(a)<0){float stopped=0.0f;a->b7++;a->b1f9=2;a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;}
 if(a->b141&1){
  a->b141^=1;row=&table_0c24b194[a->b1f9*2];horizontal=*row++*1.66666663f;
  if(a->b1d2)horizontal=-horizontal;
  a->f52+=horizontal;a->f56+=*row*2.1428571f;
 }
}
void func_0c104504(struct Actor *a)
{
 struct MotionGlobal_0c2d9260 *global=&dat_0c2d9260;
 a->b3f8=2;a->b328=5;a->b1ea=1;func_0c02a026(a);
 if(!a->b141){a->b7++;func_0c025900(a,5,5);a->f92=global->f88+320.0f;a->f96=*(float *)((char *)global+160)+-308.571411133f;}
}
