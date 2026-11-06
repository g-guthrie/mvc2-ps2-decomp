#include "objects.h"
struct Rec16 { int l0, l4; short w8, w10; char b12; unsigned char b13, pad14[2]; };
struct V3 { float x, y, z; };
extern int func_0c02850e(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c037d0c(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern struct Rec16 dat_0c250fcc[];
extern void (*table_0c251268[])(struct Actor *);
void func_0c15f3aa(struct Actor *, struct Actor *);
void func_0c15f204(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;if(!func_0c02850e(a)){a->b4++;a->b12c=0;}func_0c02a026(a);func_0c037d0c(a);
}
void func_0c15f24e(struct Actor *a){table_0c251268[a->b5](a);}
void func_0c15f260(struct Actor *a, struct Actor *owner)
{
 struct Rec16 *t;
 a->b5++;((struct MeActor *)a)->blk_dc.b13c=24;((struct MeActor *)a)->blk_dc.b13d=24;((struct MeActor *)a)->blk_dc.b13e=16;((struct MeActor *)a)->blk_dc.b13f=16;
 t=&dat_0c250fcc[a->b32];
 *(struct V3 *)&a->f52=*(struct V3 *)&owner->f52;
 if(!a->w130){a->f52+=1.66666663f*t->w8;a->f92=t->l0*1.66666663f/65536.0f;}
 else{a->f52+=-(t->w8*1.66666663f);a->f92=-(t->l0*1.66666663f/65536.0f);}
 a->f56+=2.1428571f*t->w10;a->f96=t->l4*2.1428571f/65536.0f;
 a->f104=0.0f;a->f108=-1.07142854f;
 a->b19c=68;a->b19d=68;a->b1a1=t->b13;a->w1ac=0;a->b19e=0;a->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,23,t->b12);
 func_0c15f3aa(a,owner);
}
void func_0c15f3aa(struct Actor *a,struct Actor *owner)
{
 func_0c02a026(a);if(!a->b141){a->b5++;a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;}func_0c037d0c(a);
}
void func_0c15f404(struct Actor *a,struct Actor *owner)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(!(a->f56>owner->f41c)){a->b5++;a->f56=owner->f41c;}func_0c02a026(a);func_0c037d0c(a);
}
