#ifndef MVC2_OWNER_VERTICAL_THRESHOLD_H
#define MVC2_OWNER_VERTICAL_THRESHOLD_H

/* Actual owner and child fields read by 00184110. These are partial views. */
typedef struct OwnerThresholdValue {
    unsigned char pad[0x34];
    float value;
} OwnerThresholdValue;

typedef struct OwnerThresholdState {
    unsigned char pad[0x34];
    float value;
    unsigned char pad2[0x220 - 0x38];
    OwnerThresholdValue *child;
} OwnerThresholdState;

int func_00184110(OwnerThresholdState *owner, float limit);

#endif
