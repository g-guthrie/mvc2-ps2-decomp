typedef unsigned char u8;
typedef unsigned int u32;
struct RuntimeValueState
{
    u8 active;
    u8 unk01[15];
    u32 value;
};
extern void func_00409708(u32 command, u32 *value, u32 count,
                          u32 argument3, u32 argument4);
void func_00411228(struct RuntimeValueState *state)
{
    u32 value = state->value;
    func_00409708(1, &value, 1, 0, 0);
    state->active = 0;
}
