#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0432ca(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c10c188(struct Actor *),func_0c0344a0(struct Actor *,int),func_0c173d38(struct Actor *,struct Actor *);
extern short dat_0c2f6830;
extern void (*table_0c24b980[])(struct Actor *);
void func_0c10a71c(struct Actor *);
void func_0c10a6b0(struct Actor *a)
{
 a->b6++;a->b1f9=0;a->f56=a->f41c;a->s28=1;a->s30=44;a->b32=3;
 func_0c0432ca(a);func_0c02a0c4(a,21,15);
 if(dat_0c2f6830<2)func_0c10c188(a);
 else{func_0c0344a0(a,30);func_0c173d38(a,a);func_0c0344a0(a,21);func_0c10a71c(a);}
}
void func_0c10a71c(struct Actor *a)
{
 if(--a->s30<0){a->b6++;func_0c02a0c4(a,21,16);}
 func_0c02a026(a);
 if(a->b32>=0){if(--a->s28<0){a->s28=1;if(dat_0c2f6830>=2)a->b32--;}}
}
void func_0c10a776(struct Actor *a){if(func_0c02a026(a)<0)func_0c10c188(a);}
void func_0c10a798(struct Actor *a){table_0c24b980[a->b6](a);}
