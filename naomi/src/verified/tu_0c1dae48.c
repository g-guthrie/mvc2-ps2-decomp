#include "objects.h"
extern void (*table_0c262164[])(struct Obj_tu5_03 *);
extern short dat_0c232d74[];
extern float dat_0c232d60;
extern float func_0c1ec2c0(int);
void func_0c1dae48(struct Obj_tu5_03 *a);
void func_0c1dae5c(struct Obj_tu5_03 *a);
void func_0c1dae7e(struct Obj_tu5_03 *a);
void func_0c1daef8(struct Obj_tu5_03 *a);

void func_0c1dae48(struct Obj_tu5_03 *a)
{
 table_0c262164[(unsigned char)a->b5](a);
 return;
}

void func_0c1dae5c(struct Obj_tu5_03 *a)
{
 short *p=dat_0c232d74;int i;
 for(i=0;i<a->b4;i++)p+=*p*2;
 a->b7=*p;
 a->b5=1;
 func_0c1dae7e(a);
 return;
}

void func_0c1dae7e(struct Obj_tu5_03 *a)
{
 short *p;int i;
 if(a->b6<a->b7-1){
  p=dat_0c232d74;
  for(i=0;i<a->b4;i++)p+=*p*2;
  p++;
  a->i208=p[a->b6];
  p+=a->b7-1;
  p+=a->b6;
  *(int *)a->pad8=*p;
  a->b5=2;
  func_0c1daef8(a);
  return;
 }
 a->b4++;
 a->b4%=6;
 a->b5=0;
 a->b6=0;
 func_0c1dae5c(a);
 return;
}

void func_0c1daef8(struct Obj_tu5_03 *a)
{
 register float base;
 a->w28++;
 if(*(int *)a->pad8)a->w30++;
 if(a->w30>=360)a->w30=0;
 base=dat_0c232d60;
 a->pos.y=base+10.0f*func_0c1ec2c0((int)(a->w30*65536.0f/360.0f+0.5f)&65535);
 if(a->w28>a->i208){a->w28=0;a->b5=1;a->b6++;}
}
