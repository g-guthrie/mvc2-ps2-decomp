#include "objects.h"
extern unsigned char func_0c046e7e(struct Actor *,unsigned char *,unsigned char *);
extern void func_0c045248(struct Actor *,int),func_0c047aac(struct Actor *,unsigned char *);
extern unsigned char dat_0c24ba9c[],dat_0c24babc[];
int func_0c10c3c4(struct Actor *a)
{
 int zero;
 if(!func_0c046e7e(a,dat_0c24ba9c,a->x364))return 0;
 goto ready;ready:if(!*a->p40c)return 0;
 zero=0;a->b5=zero;a->b7=zero;a->b6=zero;a->b1e9=zero;func_0c045248(a,29);return 1;
}
int func_0c10c40c(struct Actor *a)
{
 int strength;
 if(!func_0c046e7e(a,dat_0c24babc,a->x36c))return 0;
 if(a->b1f9==2 && !a->b1fc){if(a->b1d4)return 0;a->b1d4++;}
 func_0c047aac(a,a->x36c);
 goto select;select:if((unsigned char)a->b1a3==1)strength=1;else strength=2;
 if(a->b1f9==2)a->b1e9=3;else a->b1e9=2;a->b1a3=strength;a->b5=0;a->b7=0;a->b6=0;
 func_0c045248(a,21);return 1;
}
