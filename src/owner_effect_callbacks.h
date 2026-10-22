#ifndef OWNER_EFFECT_CALLBACKS_H
#define OWNER_EFFECT_CALLBACKS_H
#include "data/mvc2_state_callbacks.h"

/* Adjacent native tables share catalog owners, but have distinct contracts. */
typedef struct {
    Mvc2StateCallback lifecycle[4];
    Mvc2OwnerStateCallback owner[22];
} OwnerEffectDispatchTables;
extern const OwnerEffectDispatchTables jtbl_0044C1B0;

typedef struct {
    Mvc2StateCallback setup[4];
    Mvc2OwnerStateCallback owner[3];
} OwnerEffectPhaseTables;
extern const OwnerEffectPhaseTables jtbl_0044C270;

typedef struct {
    Mvc2StateCallback before[12];
    Mvc2OwnerStateCallback owner[3][2];
    Mvc2StateCallback after[12];
} OwnerEffectSmallTables;
#endif
