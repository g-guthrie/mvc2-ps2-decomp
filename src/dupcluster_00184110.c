typedef unsigned char u8;

typedef struct {
    u8 pad[0x34];
    float value;
} Value;

typedef struct {
    u8 pad[0x34];
    float value;
    u8 pad2[0x220 - 0x38];
    Value *child;
} Owner;

int func_00184110(Owner *owner, float limit) {
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
