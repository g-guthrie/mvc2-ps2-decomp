#include "data/mvc2_state_callbacks.h"

typedef struct {
    u8 prefix[4];
    u8 state;
    u8 gap05[0x33];
    float y;
    u8 gap3C[0x24];
    float velocity;
    u8 gap64[8];
    float acceleration;
    u8 gap70[0xA8];
    float timer;
    u8 gap11C[0x20];
    u8 phase;
} TimedEffect;

void func_003CD5A0(u8 *p, void *owner) {
    TimedEffect *effect = (TimedEffect *)p;
    float timer;
    effect->y += effect->velocity;
    effect->velocity += effect->acceleration;
    timer = effect->timer - 0.05f;
    effect->timer = timer;
    if (timer < 0.0f) {
        effect->state++;
        effect->phase = 0;
    }
}
