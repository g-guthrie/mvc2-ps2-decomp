#include "objects.h"
extern unsigned char func_0c046e7e(struct Actor *,unsigned char *,unsigned char *);
extern void func_0c045248(struct Actor *,int),func_0c047aac(struct Actor *,unsigned char *);
extern unsigned char dat_0c24baec[],dat_0c24bafc[],dat_0c24bb0c[];
int func_0c10c5c4(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24baec,a->x39c))return 0;
 goto flags;flags:if(!a->b1fc){if(a->b1d4)return 0;a->b1d4++;}
 a->b1a3=4;a->b5=0;a->b7=0;a->b6=0;a->b1e9=3;func_0c045248(a,21);return 1;
}
int func_0c10c61c(struct Actor *a)
{
 int zero;
 if(!func_0c046e7e(a,dat_0c24bafc,a->x37c))return 0;
 func_0c047aac(a,a->x37c);zero=0;
 if((unsigned char)a->b1a3==1)a->b1a3=1;else a->b1a3=zero;
 a->b5=zero;a->b7=zero;a->b6=zero;a->b1e9=4;func_0c045248(a,21);return 1;
}
int func_0c10c67c(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24bb0c,a->x3a4))return 0;
 a->b1a3=2;a->b5=0;a->b7=0;a->b6=0;a->b1e9=4;func_0c045248(a,21);return 1;
}
