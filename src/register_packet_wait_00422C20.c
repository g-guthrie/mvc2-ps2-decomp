typedef unsigned short u16;
typedef signed int s32;

extern s32 func_00103CD0(s32 mode);
extern s32 func_00103B60(u16 mode, void (*callback)(s32, s32, s32), s32 token);
extern s32 func_00103D00(void);
extern void func_00422BF0(s32 context, s32 ignored, s32 token);

s32 func_00422C20(s32 mode)
{
    s32 token;
    s32 result;

    token = func_00103CD0(mode);
    result = func_00103B60((u16)mode, func_00422BF0, token);
    if (result < 0)
        return -2;
    return func_00103D00();
}
