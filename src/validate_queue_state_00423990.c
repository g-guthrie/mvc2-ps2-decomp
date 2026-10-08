typedef signed int s32;
extern s32 func_004238A0(void);
extern s32 func_00423930(s32 reset);
s32 func_00423990(void)
{
    s32 result;

    result = func_004238A0();
    if (result < 0)
        return result;
    return func_00423930(0);
}
