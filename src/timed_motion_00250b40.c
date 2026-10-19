/* jtbl_00453360 slot 2; func_002509B0 supplies context = actor + 0x2B8. */
#include "actor_action_event.h"
typedef signed char s8;
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
void func_00250B40(u8 *p, u8 *context)
{
    func_00175700(p);
    F(p,0x34)+=F(p,0x5C);
    F(p,0x5C)+=F(p,0x68);
    F(p,0x38)+=F(p,0x60);
    F(p,0x60)+=F(p,0x6C);
    if (--*(s16 *)(p+0x1C)==0) {
        p[7]++;
        F(p,0x5C)=p[0x1E6] ? 5.0f : -5.0f;
        F(p,0x68)=p[0x1E6] ? -0.0520833320915699f : 0.0520833320915699f;
        *(u32 *)(p+0x60)=0xC0CDB6DB;
        *(u32 *)(p+0x6C)=0xBF4DB6DB;
        reset_action(p,0x3B);
        func_001757E0(p,21,(u8)(p[0x1B7]+13));
        return;
    }
    if (*(s8 *)(p+0x1B2)) {
        if (--p[0x22] == 0) {
            p[0x22]=1;
            ++*(s16 *)(p+0x1C);
            ++context[7];
            if (--*(s16 *)(p+0x1E)==0) { *(s16 *)(p+0x1C)=1; return; }
            if (context[7]>1) reset_action(p,0x4D);
            else reset_action(p,0x3A);
        }
    }
}
