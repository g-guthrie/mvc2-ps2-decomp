typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_001B67C0(u8 *, u32);
void func_001B62A0(u8 *actor) {
    u8 *event;
    u8 *context;
    u8 state;
    context = *(u8 **)(actor + 0x18);
    event = context + 0x2B8;
    state = actor[5];
    switch (state) {
    case 0:
        func_00175700(actor);
        if (*(s8 *)(actor + 0x151) != 0) {
            actor[5]++;
            func_001B67C0(actor, 2);
        }
        break;
    case 1:
        if (event[1] != 0) {
            actor[5] = state + 1;
            *(f32 *)(actor + 0x34) = *(f32 *)(*(u8 **)(actor + 0x18) + 0x34);
            break;
        }
        if (context[0x1E4] == 0x15 && context[5] == 0) break;
        actor[5] = 3;
        func_001757E0(actor, 0x15, 0xD);
        break;
    case 2:
        if (context[0x1E4] != 0x15) goto state2_transition;
        if (context[5] == 0) goto state2_special;
    state2_transition:
        actor[5] = 3;
        func_001757E0(actor, 0x15, 0xD);
        break;
    state2_special:
        if (*(u16 *)(context + 0x168) == 0x150B) {
            actor[4]++;
            actor[0x13C] = 0;
        }
        break;
    case 3:
        if ((s8)func_00175700(actor) < 0) {
            actor[4]++;
            actor[0x13C] = 0;
        }
        break;
    default:
        break;
    }
    return;
}
