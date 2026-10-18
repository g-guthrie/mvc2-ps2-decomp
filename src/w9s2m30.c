typedef signed int s32;
typedef unsigned int u32;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned char u8;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
extern void func_003DE530(V3 *);
extern f32 func_003DE7A0(f32);
f32 func_00417EB0(V3 *out) {
    V3 v, o;
    v.x = out->x; v.y = out->y; v.z = out->z;
    o = v;
    func_003DE530(&v);
    out->x = v.x; out->y = v.y; out->z = v.z;
    return func_003DE7A0(o.x * o.x + o.y * o.y + o.z * o.z);
}
