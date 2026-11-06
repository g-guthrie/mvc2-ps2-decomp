#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
void func_0c12a93e(struct Actor *);
void func_0c12a8e0(struct Actor *a)
{
 float offset,speed;
 a->b7++;a->b1f9=2;a->s28=32;a->f96=21.42857f;a->f108=-0.66964281f;
 offset=-213.33333f;speed=3.3333333f;if(a->b2){offset=213.33333f;speed=-3.3333333f;}
 a->f52+=offset;a->f92=speed;a->f104=0.0f;func_0c02a0c4(a,18,0);func_0c12a93e(a);
}
void func_0c12a93e(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;func_0c02a026(a);
 if(--a->s28==0){if(func_0c044e52(a)){int zero=0;a->b6++;a->b7=zero;a->f52-=a->f92;a->b1f9=zero;func_0c02a0c4(a,18,2);}}
 else{a->b7++;func_0c02a0c4(a,18,1);}
}
