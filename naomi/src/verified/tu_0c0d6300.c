/* Assembled by tools/clone.py from verified twins. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0438de(struct Actor *);
extern void func_0c025900(struct Actor *,char,char);
extern void func_0c04b02a(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void func_0c1cea66(struct Actor *,struct LinkedActorVec3 *,int);
extern void func_0c0346da(struct Actor *,int);
extern void (*table_0c244c58[])(struct Actor *);

void func_0c0d6300(struct Actor *a)
{
 struct Actor *child;
 func_0c02a026(a);
 if (!a->b141) return;
 a->b6++;
 a->b141=0;
 child=a->p1c8;
 child->p1b4=a;
 child->b1f6=1;
 child->b1a1=32;
 func_0c025900(a,0,0);
 a->b1f9=2;
 a->f92=a->b1d2?-6.66666651f:6.66666651f;
 a->f104=a->b1d2?0.0325520821f:-0.0325520821f;
 a->f96=19.2857132f;
 a->f108=-1.54017854f;
 if(!a->b1d2) a->f52+=53.3333321f;
 else a->f52-=53.3333321f;
 a->f56+=51.42857f;
}

void func_0c0d63ae(struct Actor *a)
{
 func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if (a->f96>0) return;
 if (a->f56>a->f41c) return;
 {
  a->b6++;a->f56=a->f41c;a->b1f9=0;
  func_0c02a0c4(a,1,3);
 }
}
