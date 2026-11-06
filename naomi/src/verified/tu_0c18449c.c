#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern void (*table_0c2558ac[])(struct LinkedActor *);
extern void (*table_0c2558bc[])(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int);
void func_0c18458a(struct LinkedActor *,struct LinkedActor *);
void func_0c18449c(struct LinkedActor *a)
{
 struct AttachmentFrameState *state=(struct AttachmentFrameState *)&a->wcc;
 a->f52=dat_0c2d9260.f88+320.0f;
 state->x=dat_0c2d9260.f94+-274.28571f;
 a->f56=state->frame+state->x;
}
void func_0c1844d0(struct LinkedActor *a){table_0c2558ac[a->b4](a);}
void func_0c1844e2(struct LinkedActor *a,struct LinkedActor *owner)
{
 struct AttachmentFrameState *state=(struct AttachmentFrameState *)&a->wcc;
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;
 a->b2=owner->b2;a->b1=owner->b1;a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;
 a->b36=owner->b36;a->sdc.b12c=1;a->b49=-4;a->sdc.w130=0;state->frame=0;
 a->f60=owner->f60;
 a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;
 a->f96=2.1428571f;
 func_0c02a0c4(a,22,15);
 func_0c18458a(a,owner);
}
void func_0c18458a(struct LinkedActor *a,struct LinkedActor *owner)
{
 struct ActorSub2a4 *sub=&A(owner)->sub2a4;
 if(owner->b5||owner->sdc.w158.bytes[1]!=22||!*(char *)&sub->s12){a->b4++;return;}
 a->b36=owner->b36;
 table_0c2558bc[(unsigned char)a->b5](a);
}
