#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c0429a4(struct Actor *,struct LinkedActorVec3 *,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c12f5b4(struct Actor *a)
{
 int zero;
 if(a->b255==6){a->b3f0=255;a->b3f1=16;}
 a->b6++;func_0c0442fa(a);func_0c0432ca(a);
 a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;zero=0;a->f56=a->f41c;a->b1f9=zero;
 *(unsigned int *)&a->sub2a4.byte16=0x04050405u;*(unsigned int *)&a->sub2a4.b20=0x01020405u;a->sub2a4.l24=0x01020101u;*(unsigned int *)&a->pad10b[0]=0x00010202u;
 a->b1a1=63;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,22,2);
}
void func_0c12f64c(struct Actor *a)
{
 struct LinkedActorVec3 position;
 a->b3f8=2;a->b328=5;a->b3f1=a->b255==6?2:0;func_0c02a026(a);
 if(a->b141){int zero=0;a->b3f0=zero;a->b3f1=zero;a->b6++;a->b141=zero;a->s28=240;position.x=0.0f;position.y=55.714283f;func_0c0429a4(a,&position,1);}
}
