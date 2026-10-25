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
extern const OwnerEffectPhaseTables jtbl_0044B850;

typedef void (*ControllerEffectCallback)(u8 *, u8 *);
typedef struct {
    Mvc2StateCallback before[12];
    Mvc2OwnerStateCallback owner[3][2];
    ControllerEffectCallback inherited[2];
    Mvc2StateCallback after[10];
} OwnerEffectSmallTables;
typedef struct {
    Mvc2StateCallback unary[3][4];
    ControllerEffectCallback controller[5];
} ControllerEffectDispatchTables;
extern const ControllerEffectDispatchTables jtbl_00445770;

/* The lifecycle dispatcher and its mode/launch aliases have distinct inputs. */
typedef struct {
    Mvc2StateCallback lifecycle[4];
    ControllerEffectCallback mode[12];
    ControllerEffectCallback launch[3];
} OwnerLaunchDispatchTables;
typedef char OwnerLaunchDispatchSize[sizeof(OwnerLaunchDispatchTables) == 0x4C ? 1 : -1];
extern const OwnerLaunchDispatchTables jtbl_0044B620;

typedef struct {
    Mvc2StateCallback selector[8];
    Mvc2StateCallback state[24];
    ControllerEffectCallback owner[3][4];
    Mvc2StateCallback other[8];
    ControllerEffectCallback last[4];
} CloneOwnerDispatchTables;
typedef char CloneOwnerDispatchSize[sizeof(CloneOwnerDispatchTables) == 224 ? 1 : -1];
extern const CloneOwnerDispatchTables jtbl_0045E120;

typedef struct {
    ControllerEffectCallback owner[2];
    Mvc2StateCallback other[4];
} SideOwnerDispatchTables;
#endif
