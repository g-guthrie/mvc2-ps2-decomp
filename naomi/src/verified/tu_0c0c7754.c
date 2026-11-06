#include "objects.h"
extern void (*table_0c247998[])(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c1accee(struct Actor *,int);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void func_0c0432ca(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern char dat_0c247154[];
extern void func_0c0c9e20(struct Actor *,void *);
extern void func_0c0429a4(struct Actor *,struct LinkedActorVec3 *,int);
void func_0c0c7804(struct Actor *);
void func_0c0c7754(struct Actor *a){((unsigned char *)a)[0x364]=0;table_0c247998[a->b6](a);}
void func_0c0c776e(struct Actor *a){unsigned char *sub=(unsigned char *)&a->sub2a4;int zero;
 if(a->b255==6){a->b3f0=255;a->b3f1=16;}a->b6++;zero=0;sub[24]=zero;sub[4]=255;
 a->b1f9=zero;a->f56=a->f41c;a->b1fc=zero;a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;
 a->b1a1=69;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;
 func_0c1accee(a,3);func_0c02a0c4(a,22,7);func_0c0432ca(a);func_0c0c7804(a);}
void func_0c0c7804(struct Actor *a){unsigned char *sub=(unsigned char *)&a->sub2a4;struct LinkedActorVec3 v;
 a->b3f8=2;a->b328=5;a->b3f1=a->b255==6?2:0;func_0c02a026(a);
 if(!a->b141){a->b6++;a->b3f0=0;a->b3f1=0;sub[11]=2;sub[10]=255;func_0c0c9e20(a,dat_0c247154);v.x=-13.33333302f;v.y=105.0f;v.z=0.0f;func_0c0429a4(a,&v,1);}}
