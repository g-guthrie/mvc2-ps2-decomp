/* Two-pointer helper called with actor/context at 0022F728 and 0022F770. */
#include "actor_action_event.h"
typedef signed char s8;
typedef signed int s32;
/* Checked partial context view; no data object is allocated by this view. */
typedef struct {u8 beforeKind[0xE];u8 kind;u8 beforeCount[5];s8 count;} QueueView;
typedef char QueueOffsetsCheck[((u32)&((QueueView *)0)->kind == 0xE && (u32)&((QueueView *)0)->count == 0x14) ? 1 : -1];
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
void func_0022F590(u8 *p,u8 *q)
{
    QueueView *queue=(QueueView *)q;
    u8 event;
    s32 flags,count;
    if(queue->count==0) return;
    flags=*(s8 *)(p+0x151);
    event=flags&0x7F;
    if(event==0) return;
    p[0x151]=flags&0x80;
    count=queue->count;
    if(count<0) queue->count=count&0x7F;
    if(*(s8 *)(p+0x1B2)<0) {
        --queue->count;
        if(queue->count<=0) {queue->count=0;return;}
    }
    if(p[0x269]==3) {
        if(queue->kind==0) reset_action(p,(s8)event+0x23);
        else reset_action(p,(s8)event+0x1B);
    } else reset_action(p,(s8)event+0x2F);
}
