typedef unsigned int u32;
extern u32 D_004C3C00[];
u32 func_00105F10(u32 index) { return D_004C3C00[index]; }
u32 func_00105F28(u32 index, u32 value) { D_004C3C00[index] = value; return value; }

typedef struct { u32 reserved[4]; u32 index; u32 value; } Record;
typedef struct { u32 reserved[7]; u32 *values; } Context;
void func_00105EE0(const Record *record, Context *context) {
    context->values[record->index] = record->value;
}

#include "sony_console_ring.h"
typedef SonyConsoleRing State;
extern State D_004C35C0;
State *func_00105020(u32 value) {
    State *state = &D_004C35C0;
    state->size = value;
    state->count = 0;
    state->tail = (char *)(state + 1);
    state->head = (char *)(state + 1);
    return state;
}
