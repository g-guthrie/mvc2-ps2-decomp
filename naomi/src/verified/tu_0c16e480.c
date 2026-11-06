#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c2525d8[])(struct LinkedActor *,struct LinkedActor *);
extern int dat_0c2525e4[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c037688(struct LinkedActor *),func_0c02a0c4(struct LinkedActor *,int,int),func_0c037d0c(struct LinkedActor *);
extern char func_0c02a026(struct LinkedActor *);
extern int func_0c02850e(struct LinkedActor *);
void func_0c16e4ce(struct LinkedActor *);
struct LinkedActor *func_0c16e480(struct LinkedActor *owner,char mode)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,0))){a->p16=func_0c16e4ce;a->b32=mode;a->b33=0;a->p24=owner;a->b1=owner->b1;a->f52=owner->f52;a->f56=owner->f56;a->w38=0x2c00;}
 return a;
}
void func_0c16e4ce(struct LinkedActor *a)
{
 struct LinkedActor *owner=a->p24;
 if(a->b4>=2){if(!a->b32)((unsigned char *)&A(owner)->sub2a4.s12)[0]=0;func_0c037688(a);}
 else table_0c2525d8[a->b32](a,owner);
}
void func_0c16e506(struct LinkedActor *a,struct LinkedActor *owner)
{
 if(a->b4)goto motion;
 {
 int *velocities;int zero;
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 zero=0;velocities=dat_0c2525e4;
 a->pad11[0]=66;A(a)->b19d=zero;((struct MeActor *)a)->blk_dc.b13c=((struct MeActor *)a)->blk_dc.b13d=((struct MeActor *)a)->blk_dc.b13e=48;((struct MeActor *)a)->blk_dc.b13f=96;
 A(a)->f104=A(a)->f108=0.0f;A(a)->f92=velocities[a->b1a3*2];a->f96=velocities[a->b1a3*2+1];
 if(A(a)->w130)a->f52=owner->f52+106.666664124f;
 else{a->f52=owner->f52+-106.666664124f;A(a)->f92=-A(a)->f92;}
 a->f56=owner->f56+180.0f;
 A(a)->b1a1=((unsigned char)A(a)->b1a3<<1)+54;A(a)->w1ac=zero;A(a)->b19e=zero;*(void **)&A(a)->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;A(a)->b1a0=zero;func_0c02a0c4(a,20,0);a->b49=-8;
 }
motion:a->b36=owner->b36;
 if(A(a)->b19e)goto cleanup;
 a->f52+=A(a)->f92;A(a)->f92+=A(a)->f104;a->f56+=a->f96;a->f96+=A(a)->f108;
 if(A(owner)->f41c>a->f56 || !func_0c02850e(a)){cleanup:a->b4=3;return;}
 goto animate;animate:func_0c02a026(a);func_0c037d0c(a);
}
