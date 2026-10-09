typedef unsigned char u8;
typedef signed int s32;

extern void func_0041ABF0(u8 *state, u8 *animationData);
extern void func_00174910(u8 *state, s32 duration);
extern s32 func_00174240(u8 *state);
extern void func_00175910(u8 *state, s32 animation, s32 strength, s32 frame);
extern void func_001E7F60(u8 *state);

void func_0041AA10(u8 *state, u8 *animationData)
{
    func_0041ABF0(state, animationData);
    func_00174910(state, 0x2BC);

    if (func_00174240(state) == 0)
    {
        state[4]++;
        state[0x13C] = 0;
    }
    else
    {
        func_00175910(state, 0x17, 0x0B, (state[0x22] >> 1) & 0x0F);
        func_001E7F60(state);
    }
}
