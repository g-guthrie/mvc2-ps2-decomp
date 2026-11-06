#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c0344a0(struct Actor *,int),func_0c1b94ec(struct Actor *,int,int);
extern unsigned char dat_0c2f8338;
extern void (*table_0c24bf94[])(struct Actor *);
void func_0c110bf8(struct Actor *a){table_0c24bf94[a->b6](a);}
void func_0c110c0a(struct Actor *a)
{
 float stopped;
 if(dat_0c2f8338<2){a->b12c=0;return;}
 a->b6++;a->b12c=1;a->f52-=a->w130?-13.33333302f:13.33333302f;a->f56-=188.5714264f;
 stopped=0.0f;a->f92=stopped;a->f104=stopped;a->f96=3.214285612107f;a->f108=0.050223213f;
 func_0c02a0c4(a,18,0);func_0c0344a0(a,32);func_0c1b94ec(a,0,0);func_0c1b94ec(a,0,1);
}
void func_0c110cb0(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(func_0c02a026(a)<0){a->b6++;a->s28=16;}
}
void func_0c110d0a(struct Actor *a)
{
 func_0c02a026(a);
 if(--a->s28==0){a->b6++;a->f96=-4.8214283f;a->f108=-0.133928575f;func_0c02a0c4(a,18,1);}
}
