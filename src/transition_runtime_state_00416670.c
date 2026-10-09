#include "runtime_state_types.h"

void func_00416670(struct RuntimeOwner *owner)
{
    struct RuntimeState *state = owner->state;

    if (state->type == 5)
    {
        state->flags &= (u8)~0x40;
        state = owner->state;
        state->flags |= 0x80;
    }
}
