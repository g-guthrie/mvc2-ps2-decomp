#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a39a(struct Actor *,int),func_0c043324(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c0346da(struct Actor *,int),func_0c0437b8(struct Actor *);
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern void (*table_0c24c2d4[])(struct Actor *);
void func_0c1152fc(struct Actor *a,struct ActorSub2a4 *sub)
{
 a->b3f8=2;a->b328=5;a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c02a026(a);
 if(a->f56<a->f41c+-68.57143f){int zero=0;float stopped;
  a->b6++;a->b1f9=zero;a->f56=a->f41c;sub->b7=zero;func_0c02a39a(a,zero);
  stopped=0.0f;a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;func_0c043324(a);func_0c02a0c4(a,22,2);
  dat_0c2d9260.b5=3;dat_0c2d9260.b6=1;func_0c0346da(a,49);
  a->b3f9=zero;a->b3f8=zero;a->b327=zero;a->b328=zero;
 }
}
void func_0c1153d6(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c1153f8(struct Actor *a){table_0c24c2d4[a->b6](a);}
