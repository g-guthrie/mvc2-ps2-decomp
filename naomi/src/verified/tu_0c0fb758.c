#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a39a(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int);
extern void func_0c16d39c(struct Actor *),func_0c0438de(struct Actor *),func_0c0fc938(struct Actor *);
extern void func_0c02a684(struct Actor *,int,int,int);
extern void (*table_0c24ab30[])(struct Actor *);
void func_0c0fb82a(struct Actor *);
void func_0c0fb758(struct Actor *a)
{
 a->b3f8=2;a->b328=5;func_0c0fb82a(a);func_0c02a026(a);
 if(--a->s28==0){a->b6++;func_0c02a39a(a,1);func_0c02a0c4(a,21,27);}
 else if(a->b141<0){a->b141=0;if(a->w34e&0x360){if(--a->s30>=0)a->s28++;}func_0c16d39c(a);}
}
void func_0c0fb7d6(struct Actor *a)
{
 int zero;
 a->b3f8=2;a->b328=5;
 if(func_0c02a026(a)<0){zero=0;a->b3f9=zero;a->b3f8=zero;a->b327=zero;a->b328=zero;
 if(a->b1f9==2)func_0c0438de(a);else func_0c0fc938(a);}
}
void func_0c0fb82a(struct Actor *a)
{
 if(--a->l2c8==0){a->l2c8=2;if(++*(int *)&a->pad10c[0]>2)*(int *)&a->pad10c[0]=0;
 func_0c02a684(a,0,*(int *)&a->pad10c[0],1);}
}
void func_0c0fb864(struct Actor *a){struct Actor *p=a;table_0c24ab30[p->b6](a);}
