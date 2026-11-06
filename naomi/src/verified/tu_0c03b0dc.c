#include "objects.h"
extern void func_0c0437b8(struct Actor *),func_0c042018(struct Actor *),func_0c0421b8(struct Actor *),func_0c044f1c(struct Actor *),func_0c0346da(struct Actor *,int),func_0c1d2a56(struct LinkedActorVec3 *,int);
extern unsigned char func_0c044e52(struct Actor *),func_0c044846(struct Actor *);
extern short dat_0c23b9d0[],dat_0c23ba08[];
extern void (*table_0c23ba0c[])(struct Actor *);
extern int func_0c043c66(struct Actor *);
extern unsigned char func_0c043a10(struct Actor *),func_0c046030(struct Actor *),func_0c0464c4(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c0453c4(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int);
extern unsigned char func_0c043d3a(struct Actor *),func_0c044ae4(struct Actor *);
void func_0c03b37a(struct Actor *);

/* Assembled by tools/clone.py from verified twins. */


/* func_0c03b0dc: no verified twin. Ghidra draft:
*/
void func_0c03b0dc(struct Actor *a)
{
 if(func_0c043c66(a))return;
 if(func_0c043a10(a))return;
 if(func_0c046030(a))return;
 if(func_0c0464c4(a)){func_0c0453c4(a,19);return;}
 if(func_0c02a026(a)<0){
  a->b6++;a->b158=a->b1f9==1?5:1;
  func_0c02a0c4(a,5,a->b158);
 }
}

/* func_0c03b154: no verified twin. Ghidra draft:
*/
void func_0c03b154(struct Actor *a)
{
 unsigned char saved;
 if(a->b1dd<0 && a->b1de){func_0c03b37a(a);return;}
 if(a->b1f9!=1){
  if(a->w340&0x1000){a->b1f9=1;func_0c02a0c4(a,5,5);}
 }else if(!(a->w340&0x1000)){a->b1f9=0;func_0c02a0c4(a,5,1);}
 func_0c02a026(a);
 if(a->b1de){a->b1de--;return;}
 a->b211=0;
 if(func_0c046030(a))return;
 if(func_0c0464c4(a)){saved=a->b6;func_0c0453c4(a,19);a->b6=saved;return;}
 if(func_0c043c66(a))return;
 if(func_0c043a10(a))return;
 if(func_0c043d3a(a)){saved=a->b6;func_0c0453c4(a,19);a->b6=saved;return;}
 if(func_0c044ae4(a))return;
 a->b6=2;a->b158=a->b1f9==1?6:2;func_0c02a0c4(a,5,a->b158);return;

}

/* func_0c03b1fc: no verified twin. Ghidra draft:
*/
/* 03b1fc is an internal continuation of func_0c03b154. */

/* func_0c03b28c: no verified twin. Ghidra draft:
*/
void func_0c03b28c(struct Actor *a)
{
 if(a->b1dd>=0){
  if(func_0c046030(a)||func_0c0464c4(a))return;
  if(a->w340&0x360)goto remove;
 }
 if(func_0c02a026(a)>=0)return;
 a->f92=0;a->f96=0;a->f104=0;a->f108=0;
remove:func_0c0437b8(a);
}

/* func_0c03b31c: no verified twin. Ghidra draft:
*/
void func_0c03b31c(struct Actor *a)
{
 struct Actor *target=a->p1b8;
 float offset;
 if(!target)target=a->p20c;
 offset=dat_0c23b9d0[a->s28]*1.66666663f/256.0f;
 if(offset==0){func_0c0437b8(a);return;}
 a->s28++;
 if(target->w130)offset=-offset;
 if(!((signed char)target->b1fd&(1<<(short)target->w130)))target->f52+=offset;
}

/* func_0c03b37a: no verified twin. Ghidra draft:
*/
void func_0c03b37a(struct Actor *a)
{
 struct LinkedActorVec3 position;
 *(short **)((char *)a+0x214)=dat_0c23ba08;
 a->b6=3;a->s28=0;a->b1dd=0;
 position.x=a->position24c.x;position.y=a->position24c.y;position.z=a->f60;
 func_0c1d2a56(&position,(short)a->w130);func_0c0346da(a,68);
}

/* func_0c03b3da: no verified twin. Ghidra draft:
*/

void func_0c03b3c8(struct Actor *a){table_0c23ba0c[a->b6](a);}

void func_0c03b3da(struct Actor *a)
{
 func_0c042018(a);func_0c0421b8(a);
 if(func_0c02a026(a)<0){a->b6++;func_0c02a0c4(a,6,1);return;}
 if(func_0c043a10(a))return;
 if(!func_0c044e52(a))return;
 if(!func_0c044846(a))func_0c044f1c(a);
}
