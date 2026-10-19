/* Owner-linked spawn state fields used by the native effect callback. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[0x34];
    f32 x, y, z;
    u8 pad40[0x100];
    s16 side;
    u8 pad142[0x75];
    u8 state;
    u8 pad1b8[0x100];
    u8 effect_spawn;
    u8 effect_spawn_alt;
} SpawnEffectOwner;

typedef struct {
    u8 pad0[0x18];
    SpawnEffectOwner *owner;
    u16 timer;
    u8 pad1e[6];
    u8 action;
    u8 pad25[0xF];
    f32 x, y, z;
    u8 pad40[0x10];
    f32 scale_x, scale_y;
    u8 pad58[0x10];
    u32 zero68, zero6c;
    u8 pad70[0xCC];
    u8 active;
    u8 pad13d[0x2C];
    u8 animation;
} SpawnEffectEvent;

typedef char SpawnEffectOwnerOffsetsCheck[
    ((unsigned int)&((SpawnEffectOwner *)0)->x == 0x34 &&
     (unsigned int)&((SpawnEffectOwner *)0)->side == 0x140 &&
     (unsigned int)&((SpawnEffectOwner *)0)->state == 0x1B7 &&
     (unsigned int)&((SpawnEffectOwner *)0)->effect_spawn == 0x2B8 &&
     (unsigned int)&((SpawnEffectOwner *)0)->effect_spawn_alt == 0x2B9)
        ? 1
        : -1];
typedef char SpawnEffectEventOffsetsCheck[
    ((unsigned int)&((SpawnEffectEvent *)0)->owner == 0x18 &&
     (unsigned int)&((SpawnEffectEvent *)0)->timer == 0x1C &&
     (unsigned int)&((SpawnEffectEvent *)0)->action == 0x24 &&
     (unsigned int)&((SpawnEffectEvent *)0)->x == 0x34 &&
     (unsigned int)&((SpawnEffectEvent *)0)->scale_x == 0x50 &&
     (unsigned int)&((SpawnEffectEvent *)0)->zero68 == 0x68 &&
     (unsigned int)&((SpawnEffectEvent *)0)->active == 0x13C &&
     (unsigned int)&((SpawnEffectEvent *)0)->animation == 0x169)
        ? 1
        : -1];

extern const u16 D_004C1C88[] __attribute__((section(".sdata")));
extern void func_0036C050(u8 *, u8);
extern int func_001757E0(u8 *, int, int);

void func_0036D460(SpawnEffectEvent *event) {
    SpawnEffectOwner *owner = event->owner;
    s16 direction;
    s16 offset = 96;
    s16 reverse_offset = -96;
    u8 action = 11;
    f32 height = 20.0f;
    const u16 *timer_table = D_004C1C88;

    event->active = 1;
    event->x = event->owner->x;
    event->y = event->owner->y;
    event->z = event->owner->z;
    direction = event->owner->side;
    event->x += direction ? offset : reverse_offset;
    event->y += height;
    event->action = action;
    owner->effect_spawn_alt = 1;
    event->scale_x = 1.5f;
    event->scale_y = 1.5f;
    event->zero68 = 0;
    event->zero6c = 0;
    timer_table += event->owner->state;
    event->timer = *timer_table;
    func_0036C050((u8 *)event, 25);
    event->animation = 23;
    func_001757E0((u8 *)event, event->animation, 58);
}
