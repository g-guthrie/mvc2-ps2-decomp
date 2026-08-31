/* Exact MWCCPS2 3.0.3 O3 reconstruction candidates. */
typedef struct DivX {
    int count;
    char pad0[4];
    float source;
    char pad1[8];
    float result;
    int clear;
} DivX;

typedef struct DivY {
    int count;
    char pad0[8];
    float source;
    char pad1[12];
    float result;
    int clear;
} DivY;

typedef struct DivZ {
    int count;
    char pad0[12];
    float source;
    char pad1[16];
    float result;
    int clear;
} DivZ;

void func_0032D0B0(DivX *state) {
    state->result = state->source / (float)state->count;
    state->clear = 0;
}

void func_0032D0D0(DivY *state) {
    state->result = state->source / (float)state->count;
    state->clear = 0;
}

void func_0032D0F0(DivZ *state) {
    state->result = state->source / (float)state->count;
    state->clear = 0;
}
