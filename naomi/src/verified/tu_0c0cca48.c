#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *),func_0c025900(struct Actor *,int,int),func_0c02a0c4(struct Actor *,int,int),func_0c1d4610(struct Actor *,struct LinkedActorVec3 *),func_0c044548(struct Actor *,struct Actor *),func_0c026980(void);
extern struct Actor *func_0c037d54(struct Actor *);
extern int dat_0c2d9634;
void func_0c0cca48(struct Actor *a)
{
 struct Actor *target;struct LinkedActorVec3 position;
 a->b3f8=2;a->b328=5;func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(((signed char)a->b1fd&(1<<(a->b1d2^1)))||--a->s28<=0){
  a->b3f9=0;a->b3f8=0;a->b327=0;a->b328=0;func_0c0437b8(a);return;
 }
 if((target=func_0c037d54(a))){
  a->b6++;func_0c025900(a,5,5);func_0c02a0c4(a,15,2);
  position.x=-83.33333f;position.y=158.57143f;
  func_0c1d4610(a,&position);a->s28=16;a->b1f7=194;func_0c044548(a,target);
 }
}
void func_0c0ccb36(struct Actor *a)
{
 a->b3f8=2;a->b328=5;a->b1ea=1;a->b1ed=2;a->b1f5=2;
 if(--a->s28<=0){a->b6++;a->s28=64;a->s30=4;func_0c02a0c4(a,15,3);func_0c026980();dat_0c2d9634=2;}
}
