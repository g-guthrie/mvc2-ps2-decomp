#ifndef ACTOR_EFFECT_WORK_CALLBACKS_H
#define ACTOR_EFFECT_WORK_CALLBACKS_H
#include "data/mvc2_state_callbacks.h"
typedef void (*ActorEffectWorkCallback)(u8 *, u8 *);
extern const ActorEffectWorkCallback jtbl_0044ACC0[11];
/* 0x0044ABD0 and 0x0044ABF0 are actor/owner phase pairs.
 * The surrounding legacy owner boundaries are tracked separately. */
typedef struct {
    Mvc2StateCallback before[12];
    ActorEffectWorkCallback randomOffset[2];
    Mvc2StateCallback middle[6];
    ActorEffectWorkCallback copy[2];
    Mvc2StateCallback after[10];
} ActorCopyCallbackTables;
void func_0019D300(u8 *, u8 *);
void func_0019D4A0(u8 *, u8 *);
void func_0019D860(u8 *, u8 *);
void func_0019D970(u8 *, u8 *);
void func_0019E670(u8 *, u8 *);
#endif
