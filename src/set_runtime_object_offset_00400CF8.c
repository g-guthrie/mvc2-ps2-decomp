typedef signed int s32;

extern s32 func_00400658(s32 *object, s32 offset);

s32 func_00400CF8(s32 *object, s32 offset)
{
    object[4] = offset;
    return func_00400658(object, 0);
}
