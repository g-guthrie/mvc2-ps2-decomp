#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c0437b8(struct Actor *);
extern void func_0c02a39a(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c0344a0(struct Actor *,int),func_0c178bd4(struct Actor *,int,int);
extern void func_0c0429a4(struct Actor *,struct LinkedActorVec3 *,int);
extern void (*table_0c24c080[])(struct Actor *),(*table_0c24c08c[])(struct Actor *);
void func_0c1126ba(struct Actor *,int);

void func_0c11262c(struct Actor *a,int b)
{
 if(a->b255==6){a->b3f0=255;a->b3f1=16;}
 a->b6++;func_0c0442fa(a);func_0c02a39a(a,0);func_0c0432ca(a);
 a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;
 a->f56=a->f41c;a->b1a1=59;a->w1ac=0;a->b19e=0;*(unsigned int*)&a->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,22,11);func_0c1126ba(a,b);
}
void func_0c1126ba(struct Actor *a,int b)
{
 struct LinkedActorVec3 p;
 (void)b;
 a->b3f8=2;a->b328=5;a->b3f1=a->b255==6?2:0;
 func_0c02a026(a);
 if(a->b141){
  a->b141=0;a->b6++;p.x=11.666666031f;p.y=137.142853f;
  a->b3f0=0;a->b3f1=0;func_0c0429a4(a,&p,1);a->s28=10;a->s30=3;
 }
}
void func_0c11272a(struct Actor *a)
{
 int z=0,i;
 a->b3f8=2;a->b328=5;
 if(func_0c02a026(a)<0){a->b3f9=z;a->b3f8=z;a->b327=z;a->b328=z;func_0c0437b8(a);return;}
 if(a->s30 && a->s28--==0){
  a->s28=30;a->s30--;
  for(i=0;i<6;i++)func_0c178bd4(a,0,i);
  func_0c0344a0(a,34);
 }
}
void func_0c112808(struct Actor *a){table_0c24c080[a->b6](a);}
void func_0c11281a(struct Actor *a){table_0c24c08c[a->b6](a);}

void func_0c11282c(struct Actor *a)
{
    func_0c02a39a(a, 0);
    a->b6++;
    a->b1f9 = 2;
    a->f92 = 30.0f;
    if (a->b1d2 == 0)
        a->f92 = -a->f92;
    a->f104 = 0.0f;
    a->f96 = 4.285714149475098f;
    a->f108 = -0.80357140303f;
    a->b1a1 = 48;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 20, 0);
}
