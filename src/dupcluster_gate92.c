#include "data/dispatch_state_6.h"

typedef struct {
    DispatchState_6 state;
    unsigned char gap07[0x2D];
    float x;
    unsigned char gap38[0x24];
    float velocity;
    unsigned char gap60[8];
    float acceleration;
} MotionActor;
void func_00229040(DispatchState_6 *state) {
    MotionActor *actor = (MotionActor *)state;
    float *velocity = &actor->velocity;
    float *acceleration = &actor->acceleration;
    actor->x += actor->velocity;
    actor->velocity += actor->acceleration;
    if (!(actor->velocity * actor->acceleration <= 0.0f)) {
        unsigned int step = actor->state.index;
        actor->state.index = step + 1;
        *velocity = 0.0f;
        *acceleration = 0.0f;
    }
}
