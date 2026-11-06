#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c0437b8(struct Actor *);
extern void func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c0451f2(struct Actor *);
extern void func_0c0429a4(struct Actor *,struct LinkedActorVec3 *,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c2492c4[])(struct Actor *);
void func_0c0e200c(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c02a026(a);
 if(func_0c044e52(a)){a->b6++;func_0c02a0c4(a,21,23);}
}
void func_0c0e2076(struct Actor *a)
{
 if(func_0c02a026(a)<0){float stopped=0.0f;
  a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;func_0c0437b8(a);
 }
}
void func_0c0e20a8(struct Actor *a){table_0c2492c4[a->b6](a);}
void func_0c0e20ba(struct Actor *a)
{
 int zero;float stopped;
 a->b6++;func_0c0442fa(a);func_0c0432ca(a);
 a->b1a1=77;zero=0;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;
 dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,22,4);
 stopped=0.0f;a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;
}
void func_0c0e211a(struct Actor *a)
{
 struct LinkedActorVec3 position;
 func_0c02a026(a);
 if(a->b141){
  int zero=0;a->b6++;a->b141=zero;func_0c0451f2(a);
  position.x=-26.666666031f;position.y=102.85714f;position.z=0.0f;
  func_0c0429a4(a,&position,1);a->s28=10;
 }
}
