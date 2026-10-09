typedef signed int s32;
typedef float f32;

extern s32 func_00119058(f32 value);
extern s32 func_001173B8(s32 left, s32 right);
extern s32 func_00119C90(s32 value);

s32 func_00417D50(f32 first, f32 second)
{
    s32 left = func_00119058(first);
    s32 right = func_00119058(second);
    s32 combined = func_001173B8(left, right);
    return func_00119C90(combined);
}
