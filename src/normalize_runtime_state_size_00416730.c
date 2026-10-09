#include "runtime_state_types.h"

extern s32 func_004166B0(struct RuntimeOwner *owner);

s32 func_00416730(struct RuntimeOwner *owner)
{
    s32 value = owner->state->size * func_004166B0(owner);
    return value / 8;
}
