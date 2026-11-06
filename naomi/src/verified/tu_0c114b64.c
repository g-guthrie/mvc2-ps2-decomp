#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void (*table_0c24c2a8[])(struct Actor *);
void func_0c114b64(struct Actor *a)
{
 float stopped;
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 stopped=0.0f;
 if(a->f92*a->f104>0.0f){a->f92=stopped;a->f104=stopped;}
 if(a->b1f9==2){
  func_0c02a026(a);
  if(a->f41c<a->f56)return;
  a->f96=stopped;a->f108=stopped;a->b1f9=0;a->f56=a->f41c;
 }else{goto grounded;grounded:if(func_0c02a026(a)>=0)return;}
 func_0c0437b8(a);
}
void func_0c114c10(struct Actor *a){table_0c24c2a8[a->b6](a);}
