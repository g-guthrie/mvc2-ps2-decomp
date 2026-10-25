#ifndef ACTOR_OWNER_MODE_CALLBACKS_H
#define ACTOR_OWNER_MODE_CALLBACKS_H
#include "data/mvc2_state_callbacks.h"
typedef void (*ActorOwnerPhase)(u8 *, u8 *);
typedef struct {
    Mvc2StateCallback lifecycle[4];
    ActorOwnerPhase mode[5];
} ActorOwnerModeTables;
extern const ActorOwnerModeTables jtbl_0044CB90;
extern const ActorOwnerPhase jtbl_0044CBB8[3],jtbl_0044CBC8[3],jtbl_0044CBD8[3];
#endif
