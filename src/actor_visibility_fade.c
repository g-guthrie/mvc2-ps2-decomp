/* Fade state driven by the owning actor; opacity crosses zero before reset. */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef struct {
    u8 unknown00[0x74];
    float opacity;
    u8 unknown78[0xC4];
    s8 active;
} FadeActor;
typedef struct {
    u8 state;
    u8 unknown01;
    u8 side;
    u8 unknown03[0x1ED];
    u8 enabled;
    u8 unknown1F1[0x234];
    u8 overrideFade;
    u8 unknown426[0xE];
    s16 timer;
} FadeOwner;
extern s8 D_004D18D6[];
void func_00132B00(u8 *actor_data, u8 *owner_data)
{
    FadeActor *actor = (FadeActor *)actor_data;
    FadeOwner *owner = (FadeOwner *)owner_data;
    if (owner->enabled == 0 && owner->timer <= 0)
        actor->active = 0;
    if (actor->active != 0) {
        if (owner->enabled != 0 && owner->state == 0) {
            if (D_004D18D6[owner->side] >= 3 && owner->overrideFade == 0) {
                actor->opacity = 1.0f;
            } else {
                actor->opacity -= 0.03125f;
                if (actor->opacity < 0.0f) {
                    actor->active = 0;
                    actor->opacity = 0.0f;
                }
            }
        }
    } else {
        if (owner->enabled == 0 && owner->timer > 0) {
            actor->active = 1;
            actor->opacity = 1.0f;
        }
    }
}
