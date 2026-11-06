#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern int func_0c047bbe(struct Actor *);
extern unsigned char dat_0c2f8338;
extern void func_0c02a0c4(struct Actor *,int,int),func_0c0437b8(struct Actor *);
extern void (*table_0c248744[])(struct Actor *);
void func_0c0d58f4(struct Actor *a,unsigned char *p)
{
 a->b3f8=2;a->b328=5;func_0c02a026(a);
 if(a->b34 && func_0c047bbe(a)) {
  a->s30++;
  if(a->s30>4){a->s30=0;a->s28+=4;a->b34--;}
 }
 if(dat_0c2f8338>=5 || --a->s28==0){a->b7++;p[9]=2;a->s28=24;func_0c02a0c4(a,22,6);}
}
void func_0c0d5982(struct Actor *a,unsigned char *p)
{
 a->b3f8=2;a->b328=5;
 if(--a->s28==0){a->b7++;p[9]=3;a->b3f8=a->b3f9=0;a->b328=a->b327=0;}
}
void func_0c0d59ba(struct Actor *a)
{
 if(func_0c02a026(a)>=0)return;
 a->f92=0;a->f96=0;a->f104=0;a->f108=0;func_0c0437b8(a);
}
void func_0c0d59ec(struct Actor *a){table_0c248744[a->b6](a);}
