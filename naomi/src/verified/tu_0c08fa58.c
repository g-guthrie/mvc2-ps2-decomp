#include "objects.h"
extern void func_0c02a0c4(struct Actor *,int,int),func_0c0437b8(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern int func_0c02849a(void),func_0c03916c(struct Actor *);
extern void (*table_0c242b44[])(struct Actor *),(*table_0c242b4c[])(struct Actor *),(*table_0c242b6c[])(struct Actor *);
void func_0c08fa58(struct Actor *a)
{
 if(!a->b6){a->b6++;a->b12c=1;func_0c02a0c4(a,18,0);}
 if(func_0c02a026(a)<0){a->b5++;func_0c02a0c4(a,0,0);}
}
void func_0c08faa0(struct Actor *a)
{
 table_0c242b44[a->b6](a);
}
void func_0c08fab2(struct Actor *a)
{
 a->b6++;
 switch(a->b32){
 case 0:case 2:func_0c02a0c4(a,19,func_0c02849a()&1);break;
 case 1:case 3:case 4:func_0c02a0c4(a,19,2);break;
 }
}
void func_0c08fafc(struct Actor *a)
{
 if(a->b1d0==22 && func_0c03916c(a))func_0c0437b8(a);
 else func_0c02a026(a);
}
void func_0c08fb2a(struct Actor *a)
{
 table_0c242b4c[a->b1e9](a);
}
void func_0c08fb3e(struct Actor *a)
{
 table_0c242b6c[a->b6](a);
}
