typedef signed int s32;

extern s32 func_004006A0(s32 *object);

s32 func_00400B58(s32 *object, s32 *output)
{
    output[0] = func_004006A0(object) - object[3];
    return 1;
}
