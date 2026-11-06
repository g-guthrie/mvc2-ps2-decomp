/* Assembled by tools/clone.py from verified twins. */
#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*dat_0c24b094[])(struct Actor *);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c0439c4(struct Actor *);
typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c24123c[];
extern ActorHandler table_0c241220[],table_0c24122c[];
extern void func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *);
extern void func_0c042ad2(struct Actor *,struct LinkedActorVec3 *,int);
extern void func_0c1c1678(struct Actor *,unsigned short *,int);
extern void func_0c191980(struct Actor *,int);

void func_0c0f9de4(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c044e52(a) != 0) {
        func_0c043324(a);
        a->b6++;
        func_0c02a0c4(a, 20, 1);
    }
}

void func_0c0f9e52(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        func_0c02a39a(a, 0);
        func_0c0439c4(a);
    }
}


extern void func_0c0437b8(struct Actor *),func_0c043014(struct Actor *,struct LinkedActorVec3 *),func_0c025900(struct Actor *,char,char);
extern struct Actor *func_0c037d54(struct Actor *);
extern struct LinkedActor *func_0c1b3e6c(struct LinkedActor *,unsigned char);
void func_0c0f9e7a(struct Actor *a)
{
 struct LinkedActorVec3 position;int zero=0;
 if(!a->b6){
  a->b6++;a->f92=0;a->f96=0;a->f104=0;a->f108=0;a->b1f9=zero;a->f56=a->f41c;
  func_0c02a39a(a,0);func_0c0442fa(a);func_0c0432ca(a);
  a->b1a1=64;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;
  func_0c02a0c4(a,21,32);func_0c1b3e6c((struct LinkedActor *)a,1);
 }else if(func_0c02a026(a)<0)func_0c0437b8(a);
 else if(a->b6==1&&a->b141){
  a->b6++;a->b141=zero;position.x=90;position.y=180;func_0c043014(a,&position);
 }
}
struct Actor *func_0c0f9f82(struct Actor *a)
{
 struct Actor *target=0;
 if((a->w1fa&0x0c00)&&a->b1a3){
  if(a->b1f9==2){if(!a->b1fe){if((target=func_0c037d54(a)))a->b1f7=2;}}
  else if((target=func_0c037d54(a))){if(!a->b1fe)a->b1f7=1;else a->b1f7=0;}
 }
 return target;
}
void func_0c0f9ff0(struct Actor *a)
{
 func_0c025900(a,5,5);
 if(!(a->w1fa&0x800)){a->w130^=1;a->b1d2^=1;}
 a->p1c8->b1d2=a->p1c8->w130=a->b1d2^1;
 a->b6=0;*(signed char *)&a->sub2a4.b6=-1;func_0c02a0c4(a,15,(signed char)a->b1f7);
}
