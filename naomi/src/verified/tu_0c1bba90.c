#include "objects.h"
extern int func_0c02849a(void);
extern void func_0c029e70(struct LinkedActor *,int,int);
extern void func_0c029fc4(struct LinkedActor *);
extern void func_0c037688(struct LinkedActor *);
extern struct ActorFlags *dat_0c2d6f84;
void func_0c1bbb68(struct LinkedActor *,struct Actor *);
void func_0c1bba90(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;
 a->b2=owner->b2;a->b1=owner->b1;a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;
 a->b36=owner->b36;a->b36=8;
 a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;
 {int r;float k;r=(unsigned char)func_0c02849a();r-=0x80;k=65536.0f;a->f92=(float)(r<<7)*1.66666663f/k;
 r=(unsigned char)func_0c02849a();r+=96;a->f96=(float)(r<<10)*2.1428571f/k;}
 a->f108=-0.401785702f;
 func_0c029e70(a,27,(func_0c02849a()&3)+9);
 func_0c1bbb68(a,(struct Actor *)owner);
}
void func_0c1bbb68(struct LinkedActor *a,struct Actor *owner)
{
 func_0c029fc4(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 a->sdc.b12c=(dat_0c2d6f84->flags+a->b34)&1;
 if(a->f56>owner->f41c)return;
 a->b4++;
}
void func_0c1bbbe2(struct LinkedActor *a){a->b4++;a->sdc.b12c=0;func_0c037688(a);}
