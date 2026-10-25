#ifndef CHARACTER_OWNER_CALLBACKS_H
#define CHARACTER_OWNER_CALLBACKS_H
#include "data/mvc2_state_callbacks.h"

typedef void (*CharacterOwnerCallback)(u8 *, u8 *);

/* Native aliases at +0x10, +0x20, +0x30 and +0x40 select separate ranges. */
typedef struct {
    Mvc2StateCallback state[4];
    Mvc2StateCallback inherited[4];
    Mvc2StateCallback effect[4];
    Mvc2StateCallback phase[4];
    CharacterOwnerCallback owner[4];
} CharacterStateTables;
extern const CharacterStateTables jtbl_004492D0;
extern const CharacterOwnerCallback jtbl_00449400[7];

/* The callback ranges are followed by four signed-short cooldowns. */
typedef struct {
    Mvc2StateCallback controller[2];
    CharacterOwnerCallback owner[2];
    short cooldown[4];
} CharacterControllerTables;
#endif
