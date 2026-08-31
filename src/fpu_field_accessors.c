typedef struct FpuFields {
    char pad[0x24];
    float first;
    float second;
} FpuFields;

void func_003F6480(FpuFields *state, float value) { state->first = value; }
float func_003F6488(FpuFields *state) { return state->first; }
void func_003F6490(FpuFields *state, float value) { state->second = value; }
float func_003F6498(FpuFields *state) { return state->second; }
