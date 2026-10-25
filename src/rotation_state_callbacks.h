#ifndef ROTATION_STATE_CALLBACKS_H
#define ROTATION_STATE_CALLBACKS_H
#include "data/mvc2_state_callbacks.h"
typedef void (*RotationOwnerCallback)(u8 *, u8 *);
/* Six adjacent two-state tables; only the two rotation groups consume owner. */
typedef struct {
    Mvc2StateCallback lifecycle[2];
    RotationOwnerCallback rotation[2][2];
    Mvc2StateCallback meter[3][2];
} RotationStateTables;
#endif
