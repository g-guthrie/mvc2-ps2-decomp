#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern short dat_0c2525f4[];
extern void func_0c037688(struct LinkedActor *),func_0c037d0c(struct LinkedActor *),func_0c02a0c4(struct LinkedActor *,int,int),func_0c02a684(struct LinkedActor *,int,int,int);
extern char func_0c02a026(struct LinkedActor *);
void func_0c16e70c(register struct LinkedActor *a,struct LinkedActor *parent)
{
 register unsigned int zero=0;struct LinkedActor *owner;
 if((owner=parent,!a->b4)){
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;a->b2=owner->b2;a->b1=owner->b1;a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 a->pad11[0]=66;a->pad11[1]=zero;A(a)->f92=0.0f;a->f96=0.0f;A(a)->f104=0.0f;A(a)->f108=0.0f;A(a)->f92=-8.33333302f;
 if(A(a)->w130){a->f52=owner->f52+106.666664124f;A(a)->f92=-A(a)->f92;}else a->f52=owner->f52+-106.666664124f;
 a->f56=owner->f56;A(a)->b1a1=7;A(a)->w1ac=zero;*(unsigned char *)&A(a)->b19e=zero;A(a)->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;A(a)->b1a0=zero;func_0c02a684(owner,1,1,1);a->s28=16;func_0c02a0c4(a,20,1);a->b49=-8;
 }
 a->b36=owner->b36;
 if(! --a->s28)goto cleanup;
 a->f52+=A(a)->f92;A(a)->f92+=A(a)->f104;
 if(func_0c02a026(a)<0){cleanup:if(!a->b32)((unsigned char *)&A(owner)->sub2a4.s12)[0]=zero;func_0c037688(a);return;}
 goto draw;draw:func_0c037d0c(a);
}
void func_0c16e8aa(struct LinkedActor *a,struct LinkedActor *owner)
{
 unsigned int zero=0;a->sdc.b12c=zero;
 if(!a->b4){
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;a->b2=owner->b2;a->b1=owner->b1;a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 a->pad11[0]=67;a->pad11[1]=zero;A(a)->b1a0=zero;A(a)->b19e=zero;A(a)->b1a1=((unsigned char)A(a)->b1a3<<1)+48;A(a)->w1ac=zero;*(unsigned char *)&A(a)->b19e=zero;A(a)->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,20,dat_0c2525f4[a->b1a3]);a->b49=-8;a->wcc.dword_value=(unsigned short)owner->sdc.w158.short_value;
 }
 a->b36=owner->b36;
 if(!owner->b5 &&a->wcc.dword_value==(unsigned short)owner->sdc.w158.short_value){
 a->f52=owner->f52;a->f56=owner->f56;A(a)->w130=A(owner)->w130;
 if(!A(a)->b19e &&func_0c02a026(a)>=0){func_0c037d0c(a);return;}
 }
 if(!a->b32)((unsigned char *)&A(owner)->sub2a4.s12)[0]=zero;func_0c037688(a);
}
