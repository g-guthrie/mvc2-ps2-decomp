/* Unary actor dispatch via func_0027DF30 and jtbl_00455340 slot 2. */
#include "actor_action_event.h"
typedef signed char s8;
typedef float f32;
extern int func_00175700(u8 *);
extern int func_00175910(u8 *,int,int,int);
extern u8 *func_001BFCA0(u8 *,int);
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
void func_0027E090(u8 *p)
{
    f32 *vx=(f32 *)(p+0x5C), *vy=(f32 *)(p+0x60), *ax=(f32 *)(p+0x68), *ay=(f32 *)(p+0x6C);
    F(p,0x34)+=F(p,0x5C);
    F(p,0x5C)+=F(p,0x68);
    F(p,0x38)+=F(p,0x60);
    F(p,0x60)+=F(p,0x6C);
    func_00175700(p);
    if(*(s8 *)(p+0x1B2) && p[7]==0 && *(s16 *)(p+0x1C)<=3) {
        p[7]=1;
        *(s16 *)(p+0x1E)=3;
    }
    if(p[7]) {
        if(--*(s16 *)(p+0x1E)<=0) {
            u8 action;
            p[7]=0;
            ++*(s16 *)(p+0x1C);
            action=50;
            if(*(s16 *)(p+0x1C)>=4) action=51;
            reset_action(p,action);
        }
    }
    if(p[0x20]==0 && F(p,0x60)<0.0f) {
        p[0x20]=1;
        func_00175910(p,21,1,8);
    }
    if(F(p,0x38)<=F(p,0x430)) {
        u8 *child;
        f32 distance;
        p[6]++;
        F(p,0x38)=F(p,0x430);
        func_001BFCA0(p,2);
        child=func_001BFCA0(p,2);
        if(child) child[0x21]=1;
        distance=200.0f*F(p,0x50);
        if(*(s16 *)(p+0x140)==0) distance=-distance;
        F(p,0x34)+=distance;
        *(u32 *)vx=0;
        *(u32 *)vy=0;
        *(u32 *)ax=0;
        *(u32 *)ay=0;
        func_001757E0(p,21,2);
        p[0x20D]=0;
    }
}
