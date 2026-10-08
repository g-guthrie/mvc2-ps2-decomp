typedef signed int s32;
extern s32 func_004238A0(s32 type, s32 value);
extern s32 func_00423930(s32 reset);
s32 func_00423990(s32 type, s32 value)
{
    s32 result;

    result = func_004238A0(type, value);
    if (result < 0)
        return result;
    return func_00423930(0);
}
