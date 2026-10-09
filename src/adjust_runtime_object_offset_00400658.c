typedef signed int s32;

extern void func_004068F8(s32 handle, s32 offset, s32 mode);
extern s32 func_00406890(s32 handle);

s32 func_00400658(s32 *object, s32 offset)
{
    func_004068F8(object[2], object[4] + offset, 0);
    return func_00406890(object[2]) - object[4];
}
