#ifndef INHERITED_EFFECT_PHASE_TABLES_H
#define INHERITED_EFFECT_PHASE_TABLES_H
#include "data/mvc2_state_callbacks.h"
typedef void (*InheritedEffectPhase)(u8 *, u8 *);
typedef struct {
    InheritedEffectPhase lifecycle[4];
    InheritedEffectPhase phase[3];
} InheritedEffectPhaseTables;
extern const InheritedEffectPhaseTables jtbl_004634F0;
#endif
