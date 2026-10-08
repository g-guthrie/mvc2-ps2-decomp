typedef unsigned char u8;

typedef struct {
    u8 pad[0x34];
    float position;
} State;

int func_001CB0A0(State *left, State *right) {
    float difference = left->position - right->position;
    u8 result = 0;
    if (difference < 0.0f)
        result = 1;
    return result;
}
