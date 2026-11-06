#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void (*table_0c24112c[])(struct Actor *);
extern struct ActorFlags *dat_0c2d6f84;
void func_0c072cb8(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c02a026(a);
 if(func_0c044e52(a)){
 int zero=0;
 a->b6++;a->b7=zero;a->f52-=a->f92;a->b1f9=zero;
 func_0c02a0c4(a,18,2);
 }
}
void func_0c072d3c(struct Actor *a)
{
 if(func_0c02a026(a)<0){a->b5++;func_0c02a0c4(a,0,0);}
}
void func_0c072d66(struct Actor *a){table_0c24112c[a->b6](a);}
void func_0c072d78(register struct Actor *a)
{
 a->b6++;
 switch(a->b32){
 case 0:case 2:a->b33=dat_0c2d6f84->flags&1;func_0c02a0c4(a,19,(signed char)a->b33);break;
 case 1:case 3:case 4:func_0c02a0c4(a,19,2);break;
 default:break;
 }
}
