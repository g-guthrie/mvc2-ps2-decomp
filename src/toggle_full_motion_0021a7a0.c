/* Actor callback witnessed at table slot 0045109C; padding is uncredited. */
#include "actor_action_event.h"
typedef signed char s8;
typedef signed int s32;
typedef float f32;
extern int func_00175700(u8 *);
extern int func_00354460(u8 *,int);
extern void func_001E3210(u8 *,int);
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
void func_0021A7A0(u8 *p)
{
    f32 *vx=(f32 *)(p+0x5C), *vy=(f32 *)(p+0x60), *ax=(f32 *)(p+0x68), *ay=(f32 *)(p+0x6C);
    s32 direction;
    p[0x40C]=2;
    p[0x33C]=5;
    F(p,0x34)+=F(p,0x5C);
    F(p,0x5C)+=F(p,0x68);
    F(p,0x38)+=F(p,0x60);
    F(p,0x60)+=F(p,0x6C);
    direction=*(s8 *)(p+0x211);
    if(direction==0) {
        if((s8)func_00175700(p)>=0) goto done;
        if(--*(s16 *)(p+0x1C)==0) goto finish;
        *(s16 *)(p+0x1E)^=1;
        func_00354460(p,*(s16 *)(p+0x1E));
        func_001E3210(p,31);
        reset_action(p,*(s8 *)(p+0x1C)+0x41);
        func_001757E0(p,22,(u8)(*(s16 *)(p+0x1E)+7));
        return;
    }
    if((s8)direction == (1<<p[0x1E6])) goto done;
finish:
    {
        s32 action=0x43;
        p[0x40D]=0;
        p[0x40C]=0;
        p[0x33B]=0;
        p[0x33C]=0;
        p[6]++;
        p[7]=0;
        *(u32 *)vx=0;
        *(u32 *)vy=0;
        *(u32 *)ax=0;
        *(u32 *)ay=0;
        if(p[0x269]==4 || p[0x269]==5) action=0x62;
        reset_action(p,action);
        func_001757E0(p,22,10);
    }
done:;
}
