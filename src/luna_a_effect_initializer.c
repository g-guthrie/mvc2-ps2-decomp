typedef unsigned char u8;
typedef signed short s16;

typedef struct {
    u8 pad0[5];
    u8 counter;
    u8 pad1[0x1C - 0x06];
    s16 state;
    u8 pad2[0x50 - 0x1E];
    float value50;
    float value54;
    u8 pad3[0x118 - 0x58];
    float value118;
} Object;

extern void func_001BEDE0(Object *, int);

void func_001BEDB0(Object *object, int parameter) {
    object->counter++;
    object->state = 10;
    object->value118 = 1.0f;
    object->value54 = 1.0f;
    object->value50 = 1.0f;
    func_001BEDE0(object, parameter);
}
