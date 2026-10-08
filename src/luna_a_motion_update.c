typedef unsigned char u8; typedef signed short s16; typedef signed char s8; typedef unsigned int u32;
typedef struct {
    u8 pad0[0x1c]; u32 flags;
} GlobalState;
typedef struct {
    u8 pad0[4]; u8 count; u8 pad1[0x34-0x5]; float x; float y;
    u8 pad2[0x5c-0x3c]; float vx; float vy;
    u8 pad3[0x68-0x64]; float ax; float ay;
    u8 pad4[0x88-0x70]; float accum;
    u8 pad5[0x140-0x8c]; s16 state;
} Object;
extern volatile float D_004F1FC8, D_004F1FCC;
extern GlobalState *volatile D_004C2840 __attribute__((section(".sdata")));
extern void func_0015B200(Object *, float *, int, int);
extern void func_001E3710(Object *, int);
void func_0019F950(Object *object, void *callbackTarget) {
    float velocity;
    float magnitude;
    float *accum;
    accum = &object->accum;
    velocity = object->vx;
    magnitude = velocity;
    if (velocity < 0.0f)
        magnitude = -velocity;
    *accum += magnitude;
    object->x += object->vx;
    object->vx += object->ax;
    object->y += object->vy;
    object->vy += object->ay;
    if (object->state != 0) {
        float difference = D_004F1FCC - object->x;
        if (difference < 0.0f) {
            object->count++;
            return;
        }
    } else {
        float difference = D_004F1FC8 - object->x;
        if (!(difference <= 0.0f)) {
            object->count++;
            return;
        }
    }
    if ((D_004C2840->flags & 3) == 0) {
        func_0015B200(callbackTarget, &object->x, 1, 0x89);
        func_001E3710(object, 0x49);
    }
}
