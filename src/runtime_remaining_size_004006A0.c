typedef signed int s32;

extern s32 func_00406890(s32 handle);

s32 func_004006A0(s32 *object)
{
    if (object[2] != 0)
        return func_00406890(object[2]) - object[4];
    return 0;
}
