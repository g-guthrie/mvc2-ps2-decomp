/* Exact 0x0c173f00..0x0c17426c effect group: seven functions and all pools.
 * End the hit-target scope before the callback. Keep the first animation test
 * as else-if and the second as a sibling if: both affect SHC register allocation.
 */
#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern int func_0c02849a(void);
extern void (*table_0c252bb0[])(struct LinkedActor *,struct LinkedActor *);
void func_0c174014(struct LinkedActor *);
struct LinkedActor *func_0c173f00(struct LinkedActor *owner)
{
 register int mode;struct LinkedActor *a;
 for(mode=0;mode<4;mode+=2){
 if((a=func_0c0374da(0,1,0))){float dx;a->p16=func_0c174014;a->p24=owner;a->w38=0x2f04;a->b32=mode;dx=-13.33333302f;if(A(owner)->w130)dx=13.33333302f;a->f52=owner->f52+dx;a->f56=A(owner)->f41c+102.85714f;}
 }
 return a;
}
void func_0c173f80(struct LinkedActor *source,struct LinkedActor *owner)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,0))){float y,dx;
 a->p16=func_0c174014;a->p24=owner;a->w38=0x2f04;a->b32=source->b32;
 y=source->f56+-34.2857132f;dx=0.0f;
 if(A(owner)->f41c>y){dx=33.3333321f;if(source->b32)dx=-33.3333321f;y=A(owner)->f41c+(unsigned int)(func_0c02849a()&7)*2.1428571f;a->b33=1;}
 a->f52=source->f52+dx;a->f56=y;
 }

}
void func_0c174014(struct LinkedActor *a){table_0c252bb0[a->b4](a,a->p24);}

extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern int func_0c028642(struct LinkedActor *),func_0c1b8c4c(struct LinkedActor *,int);
extern char func_0c02a026(struct LinkedActor *),func_0c029fc4(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c029e70(struct LinkedActor *,int,int),func_0c037d0c(struct LinkedActor *),func_0c037688(struct LinkedActor *),func_0c0346da(struct LinkedActor *,int);
void func_0c17423c(struct LinkedActor *,struct LinkedActor *);
void func_0c174060(struct LinkedActor *a,struct LinkedActor *owner)
{
 int color,zero;
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;a->b2=owner->b2;a->b1=owner->b1;a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;a->b36=8;color=32;a->s28=color;
 a->pad11[0]=67;a->pad11[1]=66;zero=0;A(a)->b1a1=64;A(a)->w1ac=zero;A(a)->b19e=zero;*(void **)&A(a)->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;
 ((struct MeActor *)a)->blk_dc.b13c=((struct MeActor *)a)->blk_dc.b13d=((struct MeActor *)a)->blk_dc.b13e=((struct MeActor *)a)->blk_dc.b13f=color;
 func_0c02a0c4(a,22,a->b33+8);
 if(func_0c028642(a))func_0c173f80(a,owner);
}
void func_0c174136(struct LinkedActor *a,struct LinkedActor *owner)
{
 if(a->b5)goto ending;
 if(--a->s28<=0){a->b5++;if(!a->b33)func_0c029e70(a,27,(func_0c02849a()&3)+10);goto check_hit;}
 if(!A(a)->b141)func_0c02a026(a);func_0c037d0c(a);
 check_hit:if(A(a)->b6 || !A(a)->b19e)return;{struct Actor *hit=A(a)->p1b0;if(((unsigned char *)hit)[0x233]!=9)return;}if(func_0c1b8c4c(owner,1)){A(a)->b6++;func_0c0346da(a,10);}return;
 ending:goto mode;mode:if(a->b33){if(func_0c02a026(a)<0)goto cleanup;return;}
 else if(func_0c029fc4(a)<0)goto cleanup;if(func_0c029fc4(a)<0)goto cleanup;return;
 cleanup:func_0c17423c(a,owner);
}
void func_0c174238(struct LinkedActor *a,struct LinkedActor *owner){}
void func_0c17423c(struct LinkedActor *a,struct LinkedActor *owner){a->sdc.b12c=0;func_0c037688(a);}
