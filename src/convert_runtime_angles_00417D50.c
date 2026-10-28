typedef double f64;
typedef float f32;

extern f64 func_001173B8(f64 left, f64 right);

f32 func_00417D50(f32 first, f32 second)
{
    f64 left = first;
    f64 right = second;
    f64 combined = func_001173B8(left, right);
    return (f32)combined;
}
