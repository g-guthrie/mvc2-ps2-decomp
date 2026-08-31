/* Exact MWCCPS2 3.0.3 O3 reconstruction: event value dispatchers. */
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct EventValueSource {
    u8 padding[360];
    u16 value;
} EventValueSource;

typedef struct EventState {
    u8 padding[24];
    EventValueSource *value_source;
} EventState;

extern void func_001CF6F0(EventState *state);
extern void func_001754A0(EventState *state, int event_class, int event_id);
extern u16 *D_004C2718;

#define DEFINE_EVENT_VALUE_DISPATCH(address, event_id) \
void address(EventState *state) { \
    func_001CF6F0(state); \
    *D_004C2718 = state->value_source->value; \
    func_001754A0(state, 27, event_id); \
}

DEFINE_EVENT_VALUE_DISPATCH(func_001CEC80, 1)
DEFINE_EVENT_VALUE_DISPATCH(func_001CECD0, 2)
DEFINE_EVENT_VALUE_DISPATCH(func_001CED20, 3)
DEFINE_EVENT_VALUE_DISPATCH(func_001CED70, 4)
DEFINE_EVENT_VALUE_DISPATCH(func_001CEDC0, 5)
DEFINE_EVENT_VALUE_DISPATCH(func_001CEE10, 6)
DEFINE_EVENT_VALUE_DISPATCH(func_001CEE60, 7)
DEFINE_EVENT_VALUE_DISPATCH(func_001CEEB0, 8)
DEFINE_EVENT_VALUE_DISPATCH(func_001CEF50, 12)
