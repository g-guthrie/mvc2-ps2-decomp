#include "objects.h"
extern void (*table_0c24bdac[])(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void func_0c0438de(struct Actor *);
extern struct Actor *func_0c037d54(struct Actor *);
extern void func_0c048ce6(struct Actor *);
extern void func_0c025900(struct Actor *,char,char);
extern void func_0c1d4610(struct Actor *,struct LinkedActorVec3 *);
void func_0c10ef32(struct Actor *a);
void func_0c10eee8(struct Actor *a)
{
 a->b6++;
 a->f96=4.28571415f;a->f108=-0.401785702f;a->f92=13.33333302f;a->f104=0;
 if(!a->w130)a->f92=-a->f92;
 func_0c02a0c4(a,2,4);
 func_0c10ef32(a);
}
void func_0c10ef32(struct Actor *a)
{
 func_0c02a026(a);
 if(!a->b141)a->b6++;
}
void func_0c10ef50(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c02a026(a);
 if(a->b141){a->b6++;a->f92=0;a->f96=0;a->f104=0;a->f108=0;a->f108=-0.80357140303f;}
}
void func_0c10efc2(struct Actor *a)
{
 if(func_0c02a026(a)<0)func_0c0438de(a);
}
struct Actor *func_0c10efe4(struct Actor *a)
{
 struct Actor *t;
 if(a->b1f9==1)return 0;
 else if(!(a->w1fa&0xc00))return 0;
 if(!a->b1a3)return 0;
 if(a->b1f9==2&&(unsigned char)a->b1fe==1)return 0;
 if((t=func_0c037d54(a))!=0){
  goto s; s: a->b34=(a->w1fa&0x3c00)>>10;
  if(a->b1f9==2)a->b1f7=3;
  else a->b1f7=!a->b1fe?2:1;
 }
 return t;
}
void func_0c10f09c(struct Actor *a)
{
 struct Actor *t;
 func_0c048ce6(a);
 t=a->p1c8;
 t->w130=t->b1d2=a->w130^1;
 a->b1a0=10;
 table_0c24bdac[a->b1f7&63](a);
}
void func_0c10f0da(struct Actor *a)
{
 struct LinkedActorVec3 position;
 func_0c025900(a,5,5);
 a->f92=0;a->f96=0;a->f104=0;a->f108=0;
 a->b1f9=0;
 a->f56=a->f41c;
 position.x=-213.33333f;position.y=137.142853f;
 func_0c1d4610(a,&position);
 func_0c02a0c4(a,15,1);
}
void func_0c10f132(struct Actor *a)
{
 struct LinkedActorVec3 position;
 func_0c025900(a,5,5);
 a->f92=0;a->f96=0;a->f104=0;a->f108=0;
 a->b1f9=0;
 a->f56=a->f41c;
 position.x=-213.33333f;position.y=137.142853f;
 func_0c1d4610(a,&position);
 func_0c02a0c4(a,15,2);
}
