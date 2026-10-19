/* jtbl_00452320 slot 2; unary dispatch by func_002356A0. */
#include "actor_action_event.h"
typedef signed char s8;
typedef signed int s32;
typedef float f32;
extern int func_00175700(u8 *);
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
void func_002357F0(u8 *p)
{
    u8 *q=p+0x2B8;
    f32 *vx=(f32 *)(p+0x5C), *ax=(f32 *)(p+0x68);
    F(p,0x34)+=F(p,0x5C);
    F(p,0x5C)+=F(p,0x68);
    F(p,0x38)+=F(p,0x60);
    F(p,0x60)+=F(p,0x6C);
    if (!(*vx * *ax < 0.0f)) *vx=0.0f;
    *(u32 *)ax=0;
    func_00175700(p);
    if (*(s8 *)(p+0x151)&1) {
        s32 flag=0;
        s32 state=*(s8 *)(p+0x1B2);
        if(state && !((s8)state&1)) {
            if (*(s8 *)(p+0x539)) flag=1;
            else if (*(u16 *)(p+0x362)&0x300) flag=1;
        }
        q[4]|=(u8)flag;
    }
    if(F(p,0x60)<=0.0f) {
        p[7]++;
        *vx=0.0f;
        *ax=0.0f;
        if(q[4]) {
            F(p,0x60)+=10.714284896850586f;
            reset_action(p,(s8)p[0x1B7]+0x33);
            func_001757E0(p,21,2);
        } else {
            p[7]++;
            if(p[0x1B7]==0) *(u32 *)(p+0x60)=0x40092492;
            else *(u32 *)(p+0x60)=0x40892492;
            *(u32 *)(p+0x6C)=0xBFCDB6DB;
            func_001757E0(p,21,3);
        }
    }
}
