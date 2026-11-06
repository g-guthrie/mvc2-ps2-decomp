#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c0438de(struct Actor *);
extern void (*table_0c24c0bc[])(struct Actor *);
void func_0c112e04(struct Actor *a)
{
 func_0c02a026(a);a->f56+=a->f96;a->f96+=a->f108;
 if(a->s28--==0){float stopped=0.0f;a->b6++;a->f96=stopped;a->f108=stopped;
  if(a->w34a&0x2000)a->b158=2;else if(a->w34a&0x1000)a->b158=3;else a->b158=1;
  func_0c02a0c4(a,15,a->b158);}
}
void func_0c112e82(struct Actor *a)
{
 struct Actor *other=a->p1c8;int command;
 if(func_0c02a026(a)<0){func_0c0438de(a);return;}
 if(a->b141){a->b141=0;other->p1b4=a;
  if((unsigned char)a->b158==2)command=34;else if((unsigned char)a->b158==3)command=35;else command=33;
  a->b1a1=other->b1a1=command;other->b1f6=1;other->b1d2=a->b1d2;other->b1d2^=1;
 }
}
void func_0c112ef2(struct Actor *a){table_0c24c0bc[a->b6](a);}
