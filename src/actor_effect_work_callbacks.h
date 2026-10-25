#ifndef ACTOR_EFFECT_WORK_CALLBACKS_H
#define ACTOR_EFFECT_WORK_CALLBACKS_H
#include "data/mvc2_state_callbacks.h"
typedef void (*ActorEffectWorkCallback)(u8 *, u8 *);
extern const ActorEffectWorkCallback jtbl_0044ACC0[11];
/* 0x0044ABF0 is a two-entry actor/owner phase pair inside this object.
 * The surrounding legacy owner boundaries are tracked separately. */
typedef struct {
    Mvc2StateCallback before[20];
    ActorEffectWorkCallback copy[2];
    Mvc2StateCallback after[14];
} ActorCopyCallbackTables;
void func_0019D860(u8 *, u8 *);
void func_0019D970(u8 *, u8 *);
void func_0019E670(u8 *, u8 *);
#endif
