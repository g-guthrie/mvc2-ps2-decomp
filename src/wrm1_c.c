typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

typedef struct { f32 x, y, z; } V3;

void func_003F42B0(V3 *p, f32 ang)
{
    extern f64 func_001165B0(f64);
    extern f64 func_00116B98(f64);
    V3 v;
    f32 pi = 3.1415927410125732f;
    v = *p;
    if (pi == ang) {
        p->y = -1.0f * v.y;
        p->z = -1.0f * v.z;
    } else {
        p->y = (f32)((f64)v.y * func_001165B0((f64)ang) - (f64)v.z * func_00116B98((f64)ang));
        p->z = (f32)((f64)v.y * func_00116B98((f64)ang) + (f64)v.z * func_001165B0((f64)ang));
    }
}
