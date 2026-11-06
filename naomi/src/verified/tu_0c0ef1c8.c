#include "objects.h"
struct Pos_0ef1c8 {float x,y,z;};
extern void func_0c169f54(struct Actor *),func_0c0442fa(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c02a39a(struct Actor *,int),func_0c0429a4(struct Actor *,struct Pos_0ef1c8 *,int);
extern char func_0c02a026(struct Actor *);
void func_0c0ef1c8(struct Actor *a){a->b3f8=2;a->b328=5;a->b3f1=a->b255==6?2:0;a->b12c=0;a->b1f5=1;if(--a->s28<0){a->b6++;a->b12c=1;func_0c169f54(a);func_0c0442fa(a);func_0c02a0c4(a,21,17);}}
void func_0c0ef230(struct Actor *a,char *p){struct Pos_0ef1c8 v;int zero;a->b3f8=2;a->b328=5;a->b3f1=a->b255==6?2:0;zero=0;if(((char *)&a->w150)[1])p[4]=1;if(a->b141){a->b141=zero;func_0c02a39a(a,0);}if(func_0c02a026(a)<0){a->b6++;a->b3f0=zero;a->b3f1=zero;v.x=-93.33333f;v.y=171.42856f;v.z=0;func_0c0429a4(a,&v,1);a->b1ed=10;}}
