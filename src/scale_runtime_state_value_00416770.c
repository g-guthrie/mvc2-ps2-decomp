#include "runtime_state_types.h"

extern const s32 D_004BEDC0[];

s32 func_00416770(struct RuntimeOwner *owner, s32 scale)
{
    s32 factor = D_004BEDC0[owner->stateIndex];
    return (scale * factor) >> 3;
}
