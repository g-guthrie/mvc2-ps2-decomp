typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef double f64;
typedef struct { f32 x, y, z; } V3;

void func_003F4440(V3 *out, f32 ang)
{
    extern double func_001165B0(double);
    extern double func_00116B98(double);
    V3 v;
    f32 pi = 3.14159274101257f;
    v = *out;
    if (pi == ang) {
        out->x = -1.0f * v.x;
        out->z = -1.0f * v.z;
    } else {
        out->x = (f32)((double)v.x * func_001165B0((double)ang) + (double)v.z * func_00116B98((double)ang));
        out->z = (f32)((double)v.x * -func_00116B98((double)ang) + (double)v.z * func_001165B0((double)ang));
    }
}
