#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c0437b8(struct Actor *);
extern void (*table_0c249108[])(struct Actor *);
void func_0c0e0058(struct Actor *a)
{
 func_0c02a026(a);a->f52+=a->f92;a->f92+=a->f104;
 a->s28--;if(a->s28<=0)a->b6++;
}
void func_0c0e0096(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;
 if(func_0c02a026(a)<0){
  a->b6++;a->f92=a->b1d2?2.5f:-2.5f;
  a->f104=a->b1d2?-0.20833332837f:0.20833332837f;
  func_0c02a0c4(a,2,2);
 }
}
void func_0c0e010a(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;
 if(func_0c02a026(a)<0){
  float stopped=0.0f;
  a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;
  func_0c0437b8(a);
 }
}
void func_0c0e015a(struct Actor *a){table_0c249108[a->b6](a);}
