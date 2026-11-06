/* Complete attachment-effect translation. Seven of eight routines match.
 * The drifting-variant initializer still differs in temporary registers
 * and position-offset evaluation. */
#include "objects.h"
#define A(a) ((struct Actor *)(a))
struct AttachmentState172 {short frame,x,y;};
struct AttachmentOffset172 {short x,y,attack,animation;};
extern short dat_0c2529a8[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c037d0c(struct LinkedActor *),func_0c172d20(struct LinkedActor *,struct LinkedActor *),func_0c172d2e(struct LinkedActor *,struct LinkedActor *);
extern void (*table_0c2529f8[])(struct LinkedActor *,struct LinkedActor *);
void func_0c1729c2(struct LinkedActor *,struct LinkedActor *);
void func_0c1728a8(struct LinkedActor *a,struct LinkedActor *owner)
{
 struct AttachmentState172 *state=(struct AttachmentState172 *)&a->wcc;
 short *offsets;
 int one;
 a->b4++;a->sdc=owner->sdc;one=1;a->sdc.b12c=one;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 offsets=dat_0c2529a8;a->sdc.b12c=one;a->b49=-1;a->f52=owner->f52;a->f56=owner->f56;a->f60=owner->f60;
 state->x=(short)(int)(offsets[(unsigned char)a->b33*4]*1.66666663f);
 state->y=(short)(int)(offsets[(unsigned char)a->b33*4+1]*2.1428571f);
 if(A(a)->w130)state->x=-state->x;
 A(a)->b1a1=offsets[(unsigned char)a->b33*4+2];
 if((unsigned char)A(a)->b1a1!=255){a->pad11[0]=67;a->pad11[1]=66;}
 func_0c02a0c4(a,23,offsets[(unsigned char)a->b33*4+3]);func_0c1729c2(a,owner);
}
void func_0c1729c2(struct LinkedActor *a,struct LinkedActor *owner)
{
 struct AttachmentState172 *state=(struct AttachmentState172 *)&a->wcc;
 if(owner->sdc.w158.short_value!=state->frame){func_0c172d2e(a,owner);return;}
 a->b36=owner->b36;a->f52=owner->f52;a->f56=owner->f56;
 a->f52+=state->x;a->f56+=state->y;
 if(func_0c02a026(a)<0){a->b4++;func_0c172d20(a,owner);return;}
 if((unsigned char)A(a)->b1a1!=255)func_0c037d0c(a);
}
void func_0c172a88(struct LinkedActor *a,struct LinkedActor *owner){table_0c2529f8[a->b4](a,owner);}

extern short dat_0c252948[];
extern int func_0c02849a(void),func_0c028642(struct LinkedActor *);
extern void func_0c1d330c(struct LinkedActor *,struct LinkedActorVec3 *,int,int),func_0c0346da(struct LinkedActor *,int),func_0c037688(struct LinkedActor *);
void func_0c172c52(struct LinkedActor *,struct LinkedActor *);
void func_0c172a9a(struct LinkedActor *a,struct LinkedActor *owner)
{
 short *offsets;int one,zero,cursor;register float scale;
 a->b4++;a->sdc=owner->sdc;one=1;a->sdc.b12c=one;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 offsets=dat_0c252948;a->sdc.b12c=one;a->b49=one;((struct MeActor *)a)->blk_dc.b13e=((struct MeActor *)a)->blk_dc.b13f=34;
 a->f52=owner->f52;a->f56=owner->f56;a->f60=owner->f60;scale=1.66666663f;
 cursor=(int)offsets;
 if(!A(a)->w130){cursor=(int)((short *)cursor+*(unsigned char *)((char *)a+33)*2);a->f52-=*(short *)cursor*scale;}
 else{cursor=(int)((short *)cursor+*(unsigned char *)((char *)a+33)*2);a->f52+=*(short *)cursor*scale;}
 offsets+=*(unsigned char *)((char *)a+33)*2;
 a->f56+=offsets[1]*2.1428571f;
 {short random=func_0c02849a()&31;a->f56+=16-random;}
 if(!owner->b1a3)A(a)->f92=-23.3333321f;else A(a)->f92=-26.666666031f;
 A(a)->f104=-0.20833333f;
 if(A(a)->w130){A(a)->f92=-A(a)->f92;A(a)->f104=-A(a)->f104;}
 zero=0;A(a)->b1a1=68;A(a)->w1ac=zero;A(a)->b19e=zero;*(void **)&A(a)->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;
 a->pad11[0]=68;a->pad11[1]=68;func_0c02a0c4(a,23,41);func_0c172c52(a,owner);
}
void func_0c172c52(register struct LinkedActor *a,register struct LinkedActor *owner)
{
 a->b36=owner->b36;a->f52+=A(a)->f92;A(a)->f92+=A(a)->f104;func_0c02a026(a);
 if(!A(a)->b19f){goto draw_motion;draw_motion:func_0c037d0c(a);if(!A(a)->b19e)goto check_lifetime;}
 a->b4++;return;
 check_lifetime:if(!func_0c028642(a))func_0c172d2e(a,owner);
}
void func_0c172cf4(struct LinkedActor *a,struct LinkedActor *owner)
{
 func_0c1d330c(a,(struct LinkedActorVec3 *)&a->f52,1,8);func_0c0346da(a,73);a->b4++;a->sdc.b12c=0;
}
void func_0c172d20(struct LinkedActor *a,struct LinkedActor *owner){a->b4++;a->sdc.b12c=0;}
void func_0c172d2e(struct LinkedActor *a,struct LinkedActor *owner){a->sdc.b12c=0;func_0c037688(a);}
