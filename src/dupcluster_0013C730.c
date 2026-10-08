typedef unsigned char u8;
typedef signed int s32;

typedef struct {
    u8 pad[0x44];
    s32 value;
} Counter;

s32 func_0013C730(Counter *left, Counter *right) {
    s32 total = right->value + left->value;
    float value = (float)total;

    if (value <= 14564.0f)
        goto zero;
    if (!(value < 50972.0f))
        goto zero;
    return 1;

zero:
    return 0;
}
