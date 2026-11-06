#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern unsigned int func_0c02849a(void);
extern void func_0c043352(struct Actor *),func_0c0437b8(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c04337e(struct Actor *,int),func_0c02a684(struct Actor *,int,int,int);
extern struct LinkedActor *func_0c1b1910(struct LinkedActor *,unsigned char);
extern void (*table_0c248d28[])(struct Actor *),(*table_0c248d38[])(struct Actor *);
#define MOVE a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108
void func_0c0db02e(struct Actor *),func_0c0db0d4(struct Actor *);
void func_0c0daec4(struct Actor *a)
{
 MOVE;func_0c02a026(a);
 if(a->b141){a->b6++;a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;}
 func_0c043352(a);
}
void func_0c0daf32(struct Actor *a)
{
 if(!a->i204){if(!a->b141)a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;}
 if(func_0c02a026(a)<0)func_0c0437b8(a);
}
void func_0c0daf9c(struct Actor *a){table_0c248d28[a->b6](a);if(a->i204)func_0c043352(a);}
void func_0c0dafc8(struct Actor *a)
{
 a->b6++;
 if(!a->i204){func_0c0db02e(a);return;}
 a->f96=0.0f;a->f108=0.0f;a->f92=a->b1d2?-16.666666031f:16.666666031f;a->f104=a->b1d2?0.41666666f:-0.41666666f;func_0c02a0c4(a,2,5);
}
void func_0c0db02e(struct Actor *a)
{
 func_0c02a026(a);
 if(a->b141){
  a->b6++;a->b141=0;
  if(!a->i204){
   a->f92=a->b1d2?-13.33333302f:13.33333302f;a->f104=a->b1d2?0.3645833135f:-0.3645833135f;
   a->f52+=a->b1d2?-40:40;
  }else func_0c0db0d4(a);
 }
}
void func_0c0db0d4(struct Actor *a)
{
 MOVE;
 if(a->i204==0){
  func_0c02a026(a);if(a->b141){a->b6++;a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;}
  if(a->b14b)func_0c04337e(a,3);
 }else{
  if(a->f104*a->f92>0.0f){a->b6++;func_0c02a0c4(a,2,7);}else func_0c02a026(a);
 }
}
void func_0c0db188(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c0db1aa(struct Actor *a)
{
 if(!a->b6){
  a->b6++;a->b7=0;
  if((char)a->p20c->b1==(char)a->b1){
   if(!a->p20c->b6){if(!(func_0c02849a()&1))goto select_five;}
   else if(a->p20c->b7<5){select_five:a->b7=5;}
  }
 }
 table_0c248d38[a->b7](a);
}
void func_0c0db224(struct Actor *a)
{
 float offset,speed;
 a->b7++;a->b12c=1;*(float *)((char *)a+0x2a4)=a->f52;offset=320.0f;speed=10.0f;
 if(a->w130){offset=-320.0f;speed=-10.0f;}
 a->f92=speed;a->f52-=offset;a->f104=a->f96=a->f108=0.0f;
 func_0c02a684(a,1,a->b37*2+8,2);func_0c1b1910((struct LinkedActor *)a,2);func_0c02a0c4(a,18,3);
}
void func_0c0db29a(struct Actor *a){if(func_0c02a026(a)<0){a->b7++;a->s28=18;func_0c02a0c4(a,18,0);}}
void func_0c0db2c8(struct Actor *a)
{
 func_0c02a026(a);MOVE;
 if(--a->s28<=0){a->b7++;a->f104=a->w130?0.4296875f:-0.4296875f;func_0c02a0c4(a,18,1);}
}
