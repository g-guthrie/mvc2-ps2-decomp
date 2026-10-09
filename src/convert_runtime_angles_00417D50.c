typedef double f64;
typedef float f32;

extern f64 func_00119058(f32 value);
extern f64 func_001173B8(f64 left, f64 right);
extern f32 func_00119C90(f64 value);

f32 func_00417D50(f32 first, f32 second)
{
    f64 left = func_00119058(first);
    f64 right = func_00119058(second);
    f64 combined = func_001173B8(left, right);
    return func_00119C90(combined);
}
