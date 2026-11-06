#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern unsigned int func_0c02849a(void);
extern int func_0c028642(struct Actor *);
extern void func_0c025900(struct Actor *,int,int),func_0c02a0c4(struct Actor *,int,char),func_0c18b3f8(struct Actor *,int);
extern char dat_0c2f837e;
extern void (*table_0c24e0b4[][11])(struct Actor *),(*table_0c24e138[])(struct Actor *);
void func_0c12f088(struct Actor *a)
{
 int choice;
 if(!a->b6){a->b6++;func_0c025900(a,1,0);choice=func_0c02849a()&1;if(!dat_0c2f837e)choice=0;func_0c02a0c4(a,19,a->b7=choice);}
 else{func_0c02a026(a);if(a->b7){a->b1f5=2;a->b1f4=2;
  if(a->b141){int zero=0;a->b141=zero;func_0c18b3f8(a,zero);}
  if(a->b140){int step=10;if(!a->w130)step=-10;a->f52+=step;}
  if(!func_0c028642(a)){a->w130^=1;choice=func_0c02849a()&1;func_0c02a0c4(a,19,choice+3);func_0c18b3f8(a,choice);}
 }}
}
void func_0c12f158(struct Actor *a)
{
 if(!a->b6){a->b6++;func_0c02a0c4(a,19,2);}else func_0c02a026(a);
}
void func_0c12f172(struct Actor *a){table_0c24e0b4[a->b4c9][a->b1e9](a);}
void func_0c12f196(struct Actor *a){table_0c24e138[a->b6](a);}
