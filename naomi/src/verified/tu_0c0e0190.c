#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c0437b8(struct Actor *);
extern struct ActorInputRecord20 dat_0c2d6f24[];
extern void (*table_0c249118[])(struct Actor *),(*table_0c249120[])(struct Actor *),(*table_0c249130[])(struct Actor *);
void func_0c0e01f0(struct Actor *);
void func_0c0e036e(struct Actor *);
void func_0c0e04ae(struct Actor *);

void func_0c0e0190(struct Actor *a)
{
 func_0c02a026(a);
 if(!a->b141){
  a->b6++;a->s28=16;a->f96=0;a->f108=0;
  a->f92=a->b1d2?-12.5f:12.5f;
  a->f104=a->b1d2?0.3125f:-0.3125f;
  func_0c0e01f0(a);
 }
}
void func_0c0e01f0(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c02a026(a);a->s28--;
 if(a->s28<=0)a->b6++;
}
void func_0c0e024c(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;
 if(func_0c02a026(a)<0){
  a->b6++;a->f92=a->b1d2?-2.5f:2.5f;
  a->f104=a->b1d2?0.20833333f:-0.20833333f;
  func_0c02a0c4(a,2,3);
 }
}
void func_0c0e02e4(struct Actor *a)
{
 if(func_0c02a026(a)>=0)return;
 a->f92=0;a->f96=0;a->f104=0;a->f108=0;func_0c0437b8(a);
}
void func_0c0e0316(struct Actor *a){table_0c249118[a->b7](a);}
void func_0c0e0328(struct Actor *a)
{
 a->b7++;a->b33=0;
 if(!a->b525){if(dat_0c2d6f24[a->b2].buttons&0x200)a->b33=1;}
}
void func_0c0e035e(struct Actor *a)
{
 if(a->b33)func_0c0e04ae(a);else func_0c0e036e(a);
}
void func_0c0e036e(struct Actor *a){table_0c249120[a->b6](a);}
void func_0c0e0380(struct Actor *a)
{
 a->b6++;a->b12c=1;a->f92=0;a->f96=0;a->f104=0;a->f108=0;
 func_0c02a0c4(a,18,0);
 if(a->w130){a->f92=3.3333333f;a->f52+=-106.666664124f;}
 else {a->f92=-3.3333333f;a->f52+=106.666664124f;}
}
void func_0c0e0418(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;func_0c02a026(a);
 if(a->b141){a->b6++;a->b141=0;}
}
void func_0c0e045a(struct Actor *a)
{
 if(func_0c02a026(a)<0){a->b6++;a->s28=60;func_0c02a0c4(a,18,1);}
}
void func_0c0e0488(struct Actor *a)
{
 func_0c02a026(a);a->s28--;
 if(a->s28<=0){a->b5++;a->b6=0;}
}
void func_0c0e04ae(struct Actor *a){table_0c249130[a->b6](a);}
void func_0c0e04c0(struct Actor *a)
{
 a->b6++;a->b12c=1;
 if(a->w130){a->f92=10.0f;a->f104=-0.1041666642f;a->f52+=-126.666664124f;}
 else{a->f92=-10.0f;a->f104=0.1041666642f;a->f52+=126.666664124f;}
 a->f96=-8.5714283f;a->f108=-0.80357140303f;a->f56+=514.28571f;
 func_0c02a0c4(a,23,2);
}
