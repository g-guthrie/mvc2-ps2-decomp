/* Exact MWCCPS2 3.0.3 O3 reconstruction candidates. */
typedef struct CounterState {
    char pad[0x40];
    int value;
} CounterState;

void func_0033AED0(CounterState *state) { state->value -= 16; }
void func_0033B0D0(CounterState *state) { state->value += 16; }
void func_0033C240(CounterState *state) { state->value += 512; }
