typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;
extern int func_00370730(u8 *, u8 *, u8 *);
extern void func_0016CEF0(void);
void func_00370110(void *callbackActor, void *callbackOwner, void *callbackEvent) {
    u8 *actor = callbackActor;
    u8 *owner = callbackOwner;
    u8 *event = callbackEvent;
    s16 phase;
    f32 threshold;
    func_00370730(actor, owner, event);
    *(f32 *)(actor + 0x34) += *(f32 *)(actor + 0x5C);
    *(f32 *)(actor + 0x5C) += *(f32 *)(actor + 0x68);
    *(f32 *)(actor + 0x38) += *(f32 *)(actor + 0x60);
    *(f32 *)(actor + 0x60) += *(f32 *)(actor + 0x6C);
    if (actor[0x23] == 0) {
        threshold = *(f32 *)(*(u8 **)(actor + 0x18) + 0x38) + 102.85713958740234f;
        if (*(f32 *)(actor + 0x38) <= threshold) {
            actor[0x23] = 1;
            *(s32 *)(actor + 0x5C) = 0;
            *(s32 *)(actor + 0x68) = 0;
            *(s16 *)(actor + 0x1C) = 0;
            *(f32 *)(actor + 0x60) = *(f32 *)(actor + 0x6C) / 2.0f;
            *(f32 *)(actor + 0x6C) = -(*(f32 *)(actor + 0x6C) / 8.0f);
            return;
        }
    }
    phase = *(s16 *)(actor + 0x1C);
    if (phase < 10) {
        *(f32 *)(actor + 0x50) += 0.12800000607967377f;
        *(f32 *)(actor + 0x54) -= 0.012f;
        *(s16 *)(actor + 0x1C) += 1;
        return;
    }
    if (phase < 20) {
        *(f32 *)(actor + 0x50) -= 0.12800000607967377f;
        *(f32 *)(actor + 0x54) += 0.012f;
        *(s16 *)(actor + 0x1C) += 1;
        return;
    }
    actor[5]++;
    (*(u8 **)(actor + 0x18))[6] = 3;
    *(f32 *)(actor + 0x50) = 1.0f;
    *(f32 *)(actor + 0x54) = 1.0f;
    *(s16 *)(actor + 0x1C) = 0;
    func_0016CEF0();
}
