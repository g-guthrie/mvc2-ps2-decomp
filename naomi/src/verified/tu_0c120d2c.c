/* Priority-ordered command selectors and their four pools. */
#include "objects.h"
extern unsigned char func_0c0465cc(struct Actor *),func_0c046b6c(struct Actor *),func_0c0469f4(struct Actor *),func_0c046d3c(struct Actor *);
extern unsigned char func_0c047068(struct Actor *,unsigned char *,unsigned char *),func_0c046e7e(struct Actor *,unsigned char *,unsigned char *),func_0c046dd0(struct Actor *,int);
extern int func_0c046d54(struct Actor *);
extern void func_0c045f1c(struct Actor *),func_0c0463fc(struct Actor *),func_0c047aac(struct Actor *,unsigned char *),func_0c045248(struct Actor *,int);
extern unsigned char dat_0c24d450[],dat_0c24d45e[],dat_0c24d46c[],dat_0c24d47c[],dat_0c24d48c[],dat_0c24d49c[];
extern unsigned int dat_0c24d4b0[];
unsigned char func_0c120dde(struct Actor *);
unsigned char func_0c120e4e(struct Actor *);
unsigned char func_0c120e94(struct Actor *);
unsigned char func_0c120eda(struct Actor *);
unsigned char func_0c120f20(struct Actor *);
unsigned char func_0c120f96(struct Actor *);
unsigned char func_0c121056(struct Actor *);
unsigned char func_0c1210a8(struct Actor *);
unsigned char func_0c1210de(struct Actor *);
unsigned char func_0c121114(struct Actor *);
int func_0c120fdc(struct Actor *),func_0c121016(struct Actor *);
void func_0c120d2c(struct Actor *a)
{
 register unsigned int i;register unsigned int limit=112;
 register unsigned int *out=(unsigned int *)a->p428;register unsigned int *in=dat_0c24d4b0;
 i=0;
 copy_next:*(unsigned int *)((char *)out+i)=*(unsigned int *)((char *)in+i);i+=4;if(i<limit)goto copy_next;
}

void func_0c120d48(struct Actor *a)
{
 if(func_0c0465cc(a))return;
 if(func_0c046b6c(a))return;
 if(func_0c0469f4(a))return;
 if(func_0c046d3c(a))return;
 if(func_0c120e94(a))return;
 if(func_0c120eda(a))return;
 if(func_0c120f20(a))return;
 if(func_0c120dde(a))return;
 if(func_0c120e4e(a))return;
 if(func_0c120f96(a))return;
 if(func_0c120fdc(a))return;
 if(func_0c121016(a))return;
 func_0c045f1c(a);func_0c0463fc(a);
}
unsigned char func_0c120dde(struct Actor *a)
{
 if(!func_0c047068(a,dat_0c24d450,a->x364))return 0;
 func_0c047aac(a,a->x364);
 {int zero=0;a->b5=zero;a->b7=zero;a->b6=zero;a->b1e9=zero;}
 func_0c045248(a,21);return 1;
}
unsigned char func_0c120e4e(struct Actor *a)
{
 if(!func_0c047068(a,dat_0c24d45e,a->x36c))return 0;
 func_0c047aac(a,a->x36c);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=1;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c120e94(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24d46c,a->x374))return 0;
 else if(!*a->p40c)return 0;
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=2;
 func_0c045248(a,29);return 1;
}
unsigned char func_0c120eda(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24d47c,a->x37c))return 0;
 else if(!*a->p40c)return 0;
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=3;
 func_0c045248(a,29);return 1;
}
unsigned char func_0c120f20(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24d48c,a->x384))return 0;
 else if(!*a->p40c)return 0;
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=4;
 func_0c045248(a,29);return 1;
}
unsigned char func_0c120f96(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24d49c,a->x38c))return 0;
 func_0c047aac(a,a->x38c);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=5;
 func_0c045248(a,21);return 1;
}
int func_0c120fdc(struct Actor *a)
{
 if(!func_0c046dd0(a,8))return 0;
 a->b1e9=8;a->b5=0;func_0c045248(a,21);a->b6=(((char *)a)[7]=0);return 1;
}
int func_0c121016(struct Actor *a)
{
 if(!func_0c046d54(a))return 0;else if(!*a->p40c)return 0;
 a->b1e9=9;a->b5=0;func_0c045248(a,29);a->b6=(((char *)a)[7]=0);return 1;
}
unsigned char func_0c121056(struct Actor *a)
{
 if(func_0c1210a8(a))return 1;
 if(func_0c1210de(a))return 1;
 if(func_0c121114(a))return 1;
 return 0;
}
unsigned char func_0c1210a8(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24d46c,a->x374))return 0;else if(!*a->p40c)return 0;
 a->b258=2;return 1;
}
unsigned char func_0c1210de(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24d47c,a->x37c))return 0;else if(!*a->p40c)return 0;
 a->b258=3;return 1;
}
unsigned char func_0c121114(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24d48c,a->x384))return 0;else if(!*a->p40c)return 0;
 a->b258=4;return 1;
}
