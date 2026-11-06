#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c1910d0(struct Actor *,int),func_0c02a39a(struct Actor *,int),func_0c0344a0(struct Actor *,int);
extern void func_0c02a684(struct Actor *,int,int,int);
extern struct Actor *func_0c13a394(struct Actor *,char,char,char);
extern int func_0c03916c(struct Actor *);
extern struct ActorFlags *dat_0c2d6f84;
extern void (*table_0c240d48[])(struct Actor *),(*table_0c240d5c[])(struct Actor *),(*table_0c240d70[])(struct Actor *),(*dat_0c240d80[])(struct Actor *);
void func_0c06e7a2(struct Actor *);
void func_0c06e938(struct Actor *),func_0c06e96e(struct Actor *);
void func_0c06e774(struct Actor *a)
{
 a->f92=0;a->f96=0;a->f104=0;a->f108=0;a->b6++;a->f92=a->b1d2?-13.33333302f:13.33333302f;func_0c06e7a2(a);
}
void func_0c06e7a2(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c02a026(a);if(a->b141)a->b6++;
}
void func_0c06e7fa(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c06e81c(struct Actor *a){table_0c240d48[a->b6](a);}
void func_0c06e82e(struct Actor *a){a->b6++;a->b12c=1;func_0c1910d0(a,2);func_0c02a0c4(a,18,0);}
void func_0c06e856(struct Actor *a)
{
 func_0c02a026(a);if(a->b140){struct ActorSub2a4 *sub=&a->sub2a4;a->b140=0;a->b6++;sub->b7=0;sub->b6=0;}
}
void func_0c06e884(struct Actor *a)
{
 func_0c06e938(a);func_0c02a026(a);if(a->b140){struct ActorSub2a4 *sub=&a->sub2a4;a->b140=0;a->b6++;sub->b7=0;sub->b6=0;}
}
void func_0c06e8dc(struct Actor *a)
{
 func_0c06e96e(a);if(func_0c02a026(a)<0){a->b6++;func_0c02a0c4(a,18,1);{struct ActorSub2a4 *sub=&a->sub2a4;sub->b6=sub->b7=0;}}
}
void func_0c06e910(struct Actor *a){if(func_0c02a026(a)<0){a->b5++;func_0c02a39a(a,0);}}
void func_0c06e938(struct Actor *a)
{
 struct ActorSubByteState *sub=(struct ActorSubByteState *)&a->sub2a4;
 int effect;
 if(sub->b6<8){effect=a->b37*8+sub->b6+32;sub->b6++;func_0c02a684(a,0,effect,1);}
}
void func_0c06e96e(struct Actor *a)
{
 struct ActorSubByteState *sub=(struct ActorSubByteState *)&a->sub2a4;
 int effect;
 if(sub->b6<8){effect=a->b37*8-sub->b6+39;sub->b6++;func_0c02a684(a,0,effect,1);}
}
void func_0c06e9a4(struct Actor *a)
{
 if(func_0c03916c(a)){func_0c0344a0(a,43);func_0c0437b8(a);}
 else table_0c240d5c[a->b32](a);
}
void func_0c06e9d8(struct Actor *a){table_0c240d70[a->b6](a);}
void func_0c06e9ea(struct Actor *a)
{
 if(!(dat_0c2d6f84->flags&1)||dat_0c2d6f84->b88){a->b6=3;a->b158=1;}
 else{a->b6++;a->b158=0;}
 func_0c02a0c4(a,19,a->b158);
}
void func_0c06ea56(struct Actor *a)
{
 func_0c02a026(a);
 if(a->b141){struct ActorSubByteState *sub=(struct ActorSubByteState *)&a->sub2a4;a->b6++;a->b141=0;sub->b1=64;sub->w2=4;sub->b0=0;func_0c13a394(a,1,0,0);sub->b4=255;}
}
void func_0c06ea9c(struct Actor *a){((struct ActorSubByteState *)&a->sub2a4)->b4=255;func_0c02a026(a);}
void func_0c06eaa8(struct Actor *a){func_0c02a026(a);if(a->b141){a->b141=0;func_0c1910d0(a,4);}}
void func_0c06ead0(struct Actor *a){if(!a->b6){a->b6++;func_0c02a0c4(a,19,2);}else func_0c02a026(a);}
void func_0c06eaea(struct Actor *a){if(!a->b6){a->b6++;func_0c02a0c4(a,19,5);}else func_0c02a026(a);}
void func_0c06eb04(struct Actor *a){if(!a->b6){a->b6++;func_0c02a0c4(a,19,3);}else func_0c02a026(a);}
void func_0c06eb1e(struct Actor *a){dat_0c240d80[a->b1e9](a);}
