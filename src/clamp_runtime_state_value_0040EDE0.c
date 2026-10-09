typedef signed int s32;

void func_0040EDE0(s32 *state, s32 value)
{
    if (value > 0)
        value = 0;
    if (value < -999)
        value = -999;
    state[12] = value;
}
