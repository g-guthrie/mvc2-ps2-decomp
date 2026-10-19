#ifndef MVC2_ACTOR_ACTION_EVENT_H
#define MVC2_ACTOR_ACTION_EVENT_H

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern int func_001757E0(u8 *,int,int);

/* Partial actor view; the action byte is at the verified offset 0x1B5.
 * This is a code view, not a recovered data object or a full actor layout. */
typedef struct { u8 beforeAction[0x1B5]; u8 action; } ActorActionView;
typedef char ActorActionOffsetCheck[
    ((u32)&((ActorActionView *)0)->action == 0x1B5) ? 1 : -1];
static inline void select_event(u8 *p, u8 action, int event)
{
    u32 counterOffset;
    ((ActorActionView *)p)->action=action;
    p[0x1B2]=*(u16 *)(p+0x1C0)=0;
    *(u32 *)(p+0x1D8)=0;
    counterOffset=p[2]*2;
    counterOffset+=(u32)D_004C2794;
    counterOffset+=0x7C;
    ++*(s16 *)counterOffset;
    func_001757E0(p,event,p[0x168]);
}

#endif
