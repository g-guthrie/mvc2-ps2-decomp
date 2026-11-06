/* Assembled by tools/clone.py from verified twins. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c02a0c4(struct Actor *,int,char),func_0c0429a4(struct Actor *,struct LinkedActorVec3 *,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;

void func_0c074880(struct Actor *a)
{
 unsigned char command;
 if(a->b255==6){a->b3f0=255;a->b3f1=16;}
 a->b7++;a->b1f9=0;a->f56=a->f41c;a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;
 a->b1a1=65;a->w1ac=0;a->b19e=0;*(unsigned int *)&a->p1c4=0;dat_0c2f83f8->arr[a->b2]++;
 func_0c0442fa(a);func_0c0432ca(a);
 command=5;if(a->b255==4)command=6;if(a->b255==5)command=6;func_0c02a0c4(a,22,command);
}

void func_0c074920(struct Actor *a)
{
 struct LinkedActorVec3 position;
 a->b3f8=2;a->b328=5;a->b3f1=a->b255==6?2:0;func_0c02a026(a);
 if(a->b141){a->b7++;if(a->b255!=5){a->b3f0=0;a->b3f1=0;position.x=-80.0f;position.y=34.2857132f;func_0c0429a4(a,&position,1);}}
}
