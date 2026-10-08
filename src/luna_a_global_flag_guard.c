typedef unsigned char u8;
typedef signed char s8;

typedef struct {
    u8 pad[0x88];
    volatile s8 first;
    volatile s8 second;
    u8 pad2[2];
    volatile s8 gate;
} GlobalState;

typedef struct {
    u8 pad[0x4D1];
    s8 counter;
    u8 pad2[0x4DC - 0x4D2];
    s8 mask;
} Object;

extern GlobalState *volatile D_004C2840;

void func_00172D40(Object *object) {
    GlobalState *global = D_004C2840;
    int flags = global->first | global->second;

    if ((object->mask & flags) != 0 && global->gate == 0)
        return;
    object->counter++;
}
