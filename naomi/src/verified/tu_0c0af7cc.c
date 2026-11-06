/* Physics/landing handlers at 0x0c0af7cc; exact. */
#include "objects.h"
extern char func_0c02a026(struct Actor*);
extern struct Tbl_ub3_01*dat_0c2f83f8;
extern void func_0c0437b8(struct Actor*),func_0c0438de(struct Actor*),func_0c043324(struct Actor*),func_0c0442fa(struct Actor*),func_0c0432ca(struct Actor*),func_0c02a0c4(struct Actor*,int,int);
extern void (*table_0c2435a0[])(struct Actor*);
extern void func_0c0437b8(struct Actor *),func_0c042018(struct Actor *),func_0c0421b8(struct Actor *),func_0c044f1c(struct Actor *),func_0c0346da(struct Actor *,int),func_0c1d2a56(struct LinkedActorVec3 *,int);
extern unsigned char func_0c044e52(struct Actor *),func_0c044846(struct Actor *);
extern short dat_0c23b9d0[],dat_0c23ba08[];
extern void (*table_0c2448f8[])(struct Actor *);
extern int func_0c043c66(struct Actor *);
extern unsigned char func_0c043a10(struct Actor *),func_0c046030(struct Actor *),func_0c0464c4(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c0453c4(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int);
extern unsigned char func_0c043d3a(struct Actor *),func_0c044ae4(struct Actor *);
void func_0c03b37a(struct Actor *);
extern void func_0c02a18c(struct Actor *,int,int,int);

/* func_0c0af7cc: no verified twin. Ghidra draft:
*/
void func_0c0af7cc(struct Actor *a)
{
 func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 a->s28--;
 if(--a->s30<0)a->b7++;
}

/* func_0c0af82c: no verified twin. Ghidra draft:
*/
void func_0c0af82c(struct Actor *a)
{
 a->b1ec=3;
 func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(--a->s28<0){
  struct ActorSub2a4 *s=&a->sub2a4;a->b6++;a->i72=0;a->b7=0;s->b1=1;a->f56=a->f41c;a->b1f9=0;a->i72=0;a->f80=1.0f;a->f84=1.0f;
  func_0c02a18c(a,21,11,5);
  func_0c043324(a);
 }
}

void func_0c0af8d2(struct Actor *a)
{
 if(func_0c02a026(a)>=0)return;
 a->f92=0;a->f96=0;a->f104=0;a->f108=0;func_0c0437b8(a);
}

void func_0c0af904(struct Actor *a){table_0c2448f8[a->b6](a);}

/* func_0c0af916: no verified twin. Ghidra draft:
*/
void func_0c0af916(struct Actor *a)
{
 a->b6++;a->f56=a->f41c;
 func_0c02a0c4(a,20,2);
 a->f92=0;a->f96=0;a->f104=0;a->f108=0;
}
