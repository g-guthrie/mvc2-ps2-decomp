#include "actor_inherited_state.h"
typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef float f32;
typedef struct V3 { f32 x, y, z; } V3;
typedef void (*EventCallback)(u8 *);
typedef struct EventRecord {
    u8 padding0[16];
    EventCallback callback;
    u8 padding14[4];
    u8 *owner;
} EventRecord;
extern void *func_003DA750(void *, s32, s32);
extern void func_001B5540(u8 *);

/* Direct callers pass (owner, kind, value); the returned event is reusable. */
u8 *func_001B53E0(u8 *owner, s32 kind, s32 value)
{
    EventRecord *record = (EventRecord *)func_003DA750(0, 3, 0);
    u8 *event = (u8 *)record;
    if (record != 0) {
        record->callback = func_001B5540;
        record->owner = owner;
        *(ActorState *)(event + 236) = *(ActorState *)(record->owner + 236);

        event[316] = 1;
        event[2] = record->owner[2];
        event[1] = record->owner[1];
        *(f32 *)(event + 80) = *(f32 *)(record->owner + 80);
        *(f32 *)(event + 84) = *(f32 *)(record->owner + 84);
        event[439] = record->owner[439];
        event[440] = record->owner[440];
        *(s8 *)(event + 48) = *(s8 *)(record->owner + 48);
        *(V3 *)(event + 80) = *(V3 *)(record->owner + 80);
        *(s8 *)(event + 36) = *(s8 *)(record->owner + 36);
        *(u16 *)(event + 38) = 0x1402;
        event[333] = 32;
        event[332] = 32;
        event[335] = 36;
        event[334] = 36;
        event[32] = kind;
        event[4] = 1;
        event[5] = value;
        *(u16 *)(event + 208) = *(u16 *)(owner + 360);
        event[209] = owner[361];
        *(f32 *)(event + 52) = *(f32 *)(owner + 52);
        *(f32 *)(event + 56) = *(f32 *)(owner + 56);
    }
    return event;
}
