/* Unary actor callback at table slot 00454C94; table contents stay uncredited. */
#include "actor_action_event.h"
typedef signed char s8;
/* Partial code view of the two status bytes at actor + 0x160. */
typedef struct { s8 first,status; } StateView;
typedef char StateStatusOffsetCheck[((u32)&((StateView *)0)->status == 1) ? 1 : -1];
typedef float f32;
typedef struct { f32 x,y; } MotionPair;
extern MotionPair D_004B73B0[], D_004B73C0[];
extern int func_00175700(u8 *);
extern void func_00186A20(u8 *);
#define F(o,n) (*(f32 *)((o)+(n)))
static inline void reset_action(u8 *p, u8 action)
{
    u32 counterOffset;
    ((ActorActionView *)p)->action=action;
    p[0x1B2]=*(u16 *)(p+0x1C0)=0;
    *(u32 *)(p+0x1D8)=0;
    counterOffset=p[2]*2;
    counterOffset+=(u32)D_004C2794;
    counterOffset+=0x7C;
    ++*(s16 *)counterOffset;
}
void func_002763B0(u8 *p)
{
    MotionPair *velocity=D_004B73B0;
    MotionPair *acceleration=D_004B73C0;
    if ((s8)func_00175700(p)<0) {
        p[6]++;
        func_00186A20(p);
        F(p,0x5C)=*(s16 *)(p+0x140) ? velocity[p[0x1B7]].x : -velocity[p[0x1B7]].x;
        F(p,0x60)=velocity[p[0x1B7]].y;
        F(p,0x68)=*(s16 *)(p+0x140) ? acceleration[p[0x1B7]].x : -acceleration[p[0x1B7]].x;
        F(p,0x6C)=acceleration[p[0x1B7]].y;
        func_001757E0(p,21,(u8)(p[0x1B7]+11));
        if(p[0x1B7]) reset_action(p,0x4A);
        else reset_action(p,0x49);
    }
    {
        StateView *state=(StateView *)(p+0x160);
        s8 *status=&state->status;
        if(state->status==1) {
            *status=0;
            if(p[0x1B7]) reset_action(p,0x3D);
            else reset_action(p,0x3B);
        }
    }
}
