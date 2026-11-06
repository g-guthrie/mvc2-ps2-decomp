/* Exact attachment unit with cached signed frame offsets, local follows and shared pools. */
#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern short dat_0c253928[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct LinkedActor *);
extern int func_0c028642(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c037d0c(struct LinkedActor *),func_0c037688(struct LinkedActor *),func_0c0346da(struct LinkedActor *,int),func_0c1d330c(struct LinkedActor *,struct LinkedActorVec3 *,int,int);
extern void (*table_0c253978[])(struct LinkedActor *,struct LinkedActor *);
void func_0c17ac6a(struct LinkedActor *,struct LinkedActor *),func_0c17ae7c(struct LinkedActor *,struct LinkedActor *),func_0c17af16(struct LinkedActor *,struct LinkedActor *),func_0c17af24(struct LinkedActor *,struct LinkedActor *);
void func_0c17ab50(struct LinkedActor *a,struct LinkedActor *owner)
{
 struct AttachmentFrameState *state=(struct AttachmentFrameState *)&a->wcc;
 short *offsets;
 int one;
 a->b4++;a->sdc=owner->sdc;one=1;a->sdc.b12c=one;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 offsets=dat_0c253928;a->sdc.b12c=one;a->b49=-1;a->f52=owner->f52;a->f56=owner->f56;a->f60=owner->f60;
 state->x=(short)(int)(offsets[(unsigned char)a->b33*4]*1.66666663f);
 state->y=(short)(int)(offsets[(unsigned char)a->b33*4+1]*2.1428571f);
 if(A(a)->w130)state->x=-state->x;
 A(a)->b1a1=offsets[(unsigned char)a->b33*4+2];
 if((unsigned char)A(a)->b1a1!=255){a->pad11[0]=67;a->pad11[1]=66;}
 func_0c02a0c4(a,23,offsets[(unsigned char)a->b33*4+3]);func_0c17ac6a(a,owner);
}
void func_0c17ac6a(struct LinkedActor *a,struct LinkedActor *owner)
{
 struct AttachmentFrameState *state=(struct AttachmentFrameState *)&a->wcc;
 if(owner->sdc.w158.short_value!=state->frame){func_0c17af24(a,owner);return;}
 a->b36=owner->b36;a->f52=owner->f52;a->f56=owner->f56;
 a->f52+=state->x;a->f56+=state->y;
 if(func_0c02a026(a)<0){a->b4++;func_0c17af16(a,owner);return;}
 if((unsigned char)A(a)->b1a1!=255)func_0c037d0c(a);
}
void func_0c17ad30(struct LinkedActor *a,struct LinkedActor *owner){table_0c253978[a->b4](a,owner);}
void func_0c17ad42(struct LinkedActor *a,struct LinkedActor *owner)
{
 int one,zero;float distance;
 a->b4++;a->sdc=owner->sdc;one=1;a->sdc.b12c=one;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 a->sdc.b12c=one;a->b49=one;((struct MeActor *)a)->blk_dc.b13e=((struct MeActor *)a)->blk_dc.b13f=34;
 a->f52=owner->f52;a->f56=owner->f56;a->f60=owner->f60;distance=120.0f;
 if(!A(a)->w130)a->f52-=distance;else a->f52+=distance;
 a->f56+=distance;A(a)->f92=-6.66666651f;A(a)->f104=-0.41666666f;
 if(A(a)->w130){A(a)->f92=-A(a)->f92;A(a)->f104=-A(a)->f104;}
 zero=0;A(a)->b1a1=8;A(a)->w1ac=zero;A(a)->b19e=zero;*(void **)&A(a)->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;
 a->pad11[0]=66;a->pad11[1]=66;func_0c02a0c4(a,23,29);func_0c17ae7c(a,owner);
}
void func_0c17ae7c(register struct LinkedActor *a,register struct LinkedActor *owner)
{
 a->b36=owner->b36;a->f52+=A(a)->f92;A(a)->f92+=A(a)->f104;func_0c02a026(a);
 if(!A(a)->b19f){goto draw_motion;draw_motion:func_0c037d0c(a);if(!A(a)->b19e)goto check_lifetime;}
 a->b4++;return;
 check_lifetime:if(!func_0c028642(a))func_0c17af24(a,owner);
}
void func_0c17aeea(struct LinkedActor *a,struct LinkedActor *owner)
{
 func_0c1d330c(a,(struct LinkedActorVec3 *)&a->f52,1,8);func_0c0346da(a,73);a->b4++;a->sdc.b12c=0;
}
void func_0c17af16(struct LinkedActor *a,struct LinkedActor *owner){a->b4++;a->sdc.b12c=0;}
void func_0c17af24(struct LinkedActor *a,struct LinkedActor *owner){a->sdc.b12c=0;func_0c037688(a);}
