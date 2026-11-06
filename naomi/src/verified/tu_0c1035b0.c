#include "objects.h"
extern unsigned char dat_0c2f8338;
extern char table_0c24b11c[];
extern int func_0c02849a(void);
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c043324(struct Actor *),func_0c1b69e8(struct Actor *,int),func_0c02a39a(struct Actor *,int),func_0c0344a0(struct Actor *,int);
extern void (*table_0c24b26c[])(struct Actor *);
void func_0c1035b0(struct Actor *a)
{
 a->b12c=0;if(dat_0c2f8338==2){a->b6++;a->b12c=1;func_0c02a0c4(a,18,0);}
}
void func_0c1035d8(struct Actor *a)
{
 if(func_0c02a026(a)<0){a->b6++;func_0c02a0c4(a,1,3);func_0c043324(a);func_0c1b69e8(a,1);}
}
void func_0c103610(struct Actor *a)
{
 if(func_0c02a026(a)<0){a->b5++;func_0c02a0c4(a,0,0);func_0c02a39a(a,0);}
}
void func_0c103642(struct Actor *a){table_0c24b26c[a->b6](a);}
void func_0c103654(struct Actor *a)
{
 struct ActorSub2a4 *sub=&a->sub2a4;unsigned int index;
 a->b6++;
 switch(a->b32){case 0:case 2:
  index=func_0c02849a()&15;sub->b1=table_0c24b11c[index];func_0c02a0c4(a,19,(char)sub->b1);func_0c0344a0(a,10);break;
 case 1:case 3:case 4:func_0c02a0c4(a,19,2);break;
 }
}
