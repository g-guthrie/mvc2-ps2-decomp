typedef unsigned char u8;
typedef signed short s16;

typedef struct {
    u8 pad[0x34];
    float value;
    u8 pad2[0x140 - 0x38];
    s16 direction;
} State;

float func_001CB150(State *left, State *right) {
    float result = 106.666664f;

    if (right->direction)
        result = -result;
    result += right->value;
    result -= left->value;
    return result;
}
