typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;

typedef struct {
    u8 pad[0xAA];
    s8 enabled;
} GlobalState;

typedef struct {
    u8 pad0[0x290];
    s16 initial;
    u8 pad1[0x33E - 0x292];
    s16 mode;
    u8 pad2[0x342 - 0x340];
    s16 delta;
    u8 pad3[0x434 - 0x344];
    s16 current;
} Object;

extern GlobalState *volatile D_004C2840;

void func_00190540(Object *object, int update) {
    if (update) {
        object->delta = object->initial - object->current;
        object->initial = object->current;
    }
    if (D_004C2840->enabled)
        object->mode = 0x32;
}
