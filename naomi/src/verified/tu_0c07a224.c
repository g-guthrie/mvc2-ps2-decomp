#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0438de(struct Actor *);
extern void func_0c025762(void);
extern void (*table_0c241574[])(struct Actor *);
extern void (*table_0c241580[])(struct Actor *);
void func_0c07a224(struct Actor *a)
{
 func_0c02a026(a);
 if(a->b141==2){a->b6++;a->b1d2^=1;}
}
void func_0c07a24c(struct Actor *a)
{
 if(func_0c02a026(a)<0)func_0c0437b8(a);
}
void func_0c07a26e(struct Actor *a)
{
 table_0c241574[a->b6](a);
}
void func_0c07a280(struct Actor *a)
{
 a->b6++;
 a->f92=a->b1d2?6.66666651f:-6.66666651f;
 a->f104=0;a->f96=25.714285f;a->f108=-0.80357140303f;
 a->b1f9=2;
}
void func_0c07a2ba(struct Actor *a)
{
 if(a->b141<=0)a->f52+=a->f92;
 a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(func_0c02a026(a)<0){a->f108=-0.80357140303f;func_0c0438de(a);}
 else if(a->b141<0){
 a->b141=0;
 a->p1c8->p1b4=a;a->p1c8->b1f6=1;a->p1c8->b1d2=a->b1d2^1;a->p1c8->b1a1=32;a->p1c8->b1f9=2;
 a->f92=0;
 func_0c025762();
 }
}
void func_0c07a39a(struct Actor *a)
{
 if(func_0c02a026(a)<0)func_0c0437b8(a);
}
void func_0c07a3bc(struct Actor *a)
{
 table_0c241580[a->b6](a);
}
void func_0c07a3ce(struct Actor *a)
{
 a->b6++;
 a->f92=a->b1d2?8.33333302f:-8.33333302f;
 a->f104=0;
 if(a->f108>0){a->f108/=4.28571415f;a->f108=-a->f108;}
}
