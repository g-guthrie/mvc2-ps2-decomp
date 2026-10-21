#include "owner_vertical_threshold.h"

int func_00184110(OwnerThresholdState *owner, float limit) {
    float difference = owner->child->value - owner->value;

    if (limit < difference)
        goto one;
    if (-limit <= difference)
        goto zero;

one:
    return 1;
zero:
    return 0;
}
