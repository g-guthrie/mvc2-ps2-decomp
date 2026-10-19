/* Unary caller at 00249220 supplies the actor; local position is exactly Vec3. */
#include "actor_action_event.h"
typedef signed char s8;
typedef float f32;
typedef struct { f32 x,y,z; } Vec3;
extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_001E3240(u8 *,int);
extern void func_001ACD40(Vec3 *,int,s8);
extern u8 *D_004C2840 __attribute__((section(".sdata")));
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
void func_002498D0(u8 *p)
{
    if ((s8)func_00175700(p)<0) {func_001843A0(p); return;}
    switch(p[0x1FC]) {
    case 0:
        if (*(s8 *)(p+0x151)) {
            p[0x151]=0;
            reset_action(p,9);
            func_001E3240(p,35);
        }
        break;
    case 1:
        break;
    case 2:
        if (*(s8 *)(p+0x539)==0) {
            if (*(u16 *)(p+0x35E)&0x800) {
                if (p[0x1E6]==0) F(p,0x34)+=-5.0f;
                else F(p,0x34)-=-5.0f;
            } else if (*(u16 *)(p+0x35E)&0x400) {
                if (p[0x1E6]==0) F(p,0x34)+=4.166666507720947f;
                else F(p,0x34)-=4.166666507720947f;
            }
        }
        if ((*(u32 *)(D_004C2840+0x1C)&15)==0) {
            Vec3 pos=*(Vec3 *)(p+0x34);
            func_001ACD40(&pos,p[0x140],0);
        }
        break;
    }
    {
        u16 distance=*(u16 *)(p+0x160);
        if(distance) {
            if (*(s16 *)(p+0x140)==0) F(p,0x34)+=1.6666666269302368f*(s16)distance;
            else F(p,0x34)-=1.6666666269302368f*(s16)distance;
            *(u16 *)(p+0x160)=0;
        }
    }
}
