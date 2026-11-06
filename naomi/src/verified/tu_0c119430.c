/* Complete input dispatcher and command selection section. */
#include "objects.h"
extern unsigned char dat_0c24cc64[],dat_0c24cc74[],dat_0c24cc84[],dat_0c24cc94[],dat_0c24cca4[],dat_0c24ccb4[],dat_0c24ccc4[],dat_0c24ccd4[],dat_0c24cce4[];
extern void (*table_0c24ccf4[])(struct Actor *);
extern unsigned char func_0c0465cc(struct Actor *),func_0c046b6c(struct Actor *),func_0c0469f4(struct Actor *),func_0c046d3c(struct Actor *),func_0c046e7e(struct Actor *,unsigned char *,unsigned char *),func_0c046dd0(struct Actor *,int);
extern int func_0c046d54(struct Actor *);
extern void func_0c045f1c(struct Actor *),func_0c0463fc(struct Actor *),func_0c045248(struct Actor *,int),func_0c047aac(struct Actor *,unsigned char *);
unsigned char func_0c119520(struct Actor *),func_0c119586(struct Actor *),func_0c1195cc(struct Actor *),func_0c119648(struct Actor *),func_0c119696(struct Actor *),func_0c119706(struct Actor *),func_0c119778(struct Actor *),func_0c1197e2(struct Actor *),func_0c119842(struct Actor *),func_0c1198f0(struct Actor *);
int func_0c1198b0(struct Actor *),func_0c119928(struct Actor *),func_0c119960(struct Actor *);
void func_0c119430(struct Actor *a)
{
 register unsigned int i; register unsigned int limit=112; register unsigned int *out=(unsigned int *)a->p428; register unsigned int *in=(unsigned int *)table_0c24ccf4;
 i=0;copy_next:*(unsigned int *)((char *)out+i)=*(unsigned int *)((char *)in+i);i+=4;if(i<limit)goto copy_next;
}
void func_0c11944c(struct Actor *a)
{
 if(func_0c0465cc(a))return;
 if(func_0c046b6c(a))return;
 if(func_0c0469f4(a))return;
 if(func_0c046d3c(a))return;
 if(func_0c119520(a))return;
 if(func_0c119586(a))return;
 if(func_0c1195cc(a))return;
 if(func_0c119696(a))return;
 if(func_0c119648(a))return;
 if(func_0c119778(a))return;
 if(func_0c119706(a))return;
 if(func_0c1197e2(a))return;
 if(func_0c119842(a))return;
 if(func_0c1198b0(a))return;
 if(func_0c1198f0(a))return;
 func_0c045f1c(a);func_0c0463fc(a);
}
unsigned char func_0c119520(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24cce4,a->x394)||!*a->p40c)goto fail;
 if(a->b1f9==2 && !a->b1fc){if(a->b1d4){fail:return 0;}a->b1d4++;}
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=8;func_0c045248(a,29);return 1;
}
unsigned char func_0c119586(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24cc64,a->x364))return 0;else if(!*a->p40c)return 0;
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=1;func_0c045248(a,29);return 1;
}
unsigned char func_0c1195cc(struct Actor *a)
{
 struct ActorSub2a4 *s=&a->sub2a4;
 if(!func_0c046e7e(a,dat_0c24ccd4,a->x38c)||!*a->p40c||((char *)s)[5])return 0;
 s->b6=0;s->b7=0;a->b5=0;a->b7=0;a->b6=0;a->b1e9=6;func_0c045248(a,29);return 1;
}
unsigned char func_0c119648(struct Actor *a)
{
 int zero;
 if(!func_0c046e7e(a,dat_0c24cc74,a->x3a4))return 0;
 func_0c047aac(a,a->x3a4);zero=0;a->b5=zero;a->b7=zero;a->b6=zero;a->b1e9=zero;func_0c045248(a,21);a->b1a3=2;return 1;
}
unsigned char func_0c119696(struct Actor *a)
{
 int zero;
 if(!func_0c046e7e(a,dat_0c24cc84,a->x39c))goto fail;
 if(a->b1f9==2 && !a->b1fc){if(a->b1d4){fail:return 0;}a->b1d4++;}
 func_0c047aac(a,a->x39c);zero=0;a->b5=zero;a->b6=zero;a->b7=1;a->b1e9=zero;func_0c045248(a,21);a->b1a3=2;return 1;
}
unsigned char func_0c119706(struct Actor *a)
{
 int zero;
 if(!func_0c046e7e(a,dat_0c24cc94,a->x36c))return 0;
 func_0c047aac(a,a->x36c);zero=0;a->b5=zero;a->b7=zero;a->b6=zero;a->b1e9=zero;func_0c045248(a,21);return 1;
}
unsigned char func_0c119778(struct Actor *a)
{
 int zero;
 if(!func_0c046e7e(a,dat_0c24cca4,a->x374))goto fail;
 if(a->b1f9==2 && !a->b1fc){if(a->b1d4){fail:return 0;}a->b1d4++;}
 func_0c047aac(a,a->x374);zero=0;a->b5=zero;a->b6=zero;a->b7=1;a->b1e9=zero;func_0c045248(a,21);return 1;
}
unsigned char func_0c1197e2(register struct Actor *a)
{
 register struct ActorSub2a4 *s=&a->sub2a4;register int zero;
 if(!func_0c046e7e(a,dat_0c24ccb4,a->x37c)||((char *)s)[5])return 0;
 zero=0;s->b6=zero;s->b7=zero;func_0c047aac(a,a->x37c);
 a->b5=zero;a->b7=zero;a->b6=zero;a->b1e9=2;func_0c045248(a,21);return 1;
}
unsigned char func_0c119842(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24ccc4,a->x384))return 0;func_0c047aac(a,a->x384);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=4;func_0c045248(a,21);return 1;
}
int func_0c1198b0(struct Actor *a)
{
 if(!func_0c046d54(a))goto fail;if(!*a->p40c){fail:return 0;}
 a->b1e9=3;a->b5=0;func_0c045248(a,29);a->b6=a->b7=0;return 1;
}
unsigned char func_0c1198f0(struct Actor *a)
{
 if(!func_0c046dd0(a,7))return 0;
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=7;func_0c045248(a,21);return 1;
}
int func_0c119928(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24cc64,a->x364))return 0;else if(!*a->p40c)return 0;a->b258=1;return 1;
}
int func_0c119960(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24ccd4,a->x38c))return 0;else if(!*a->p40c)return 0;a->b258=6;return 1;
}
int func_0c119996(struct Actor *a)
{
 if(func_0c119928(a))return 1;if(func_0c119960(a))return 1;return 0;
}
