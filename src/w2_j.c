typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_003F38E0(f32 *m, f32 ang)
{
    extern void func_003F42B0(f32 *, f32);
    f32 v[3];
    v[0] = m[0];
    v[1] = m[1];
    v[2] = m[2];
    func_003F42B0(v, ang);
    m[0] = v[0];
    m[1] = v[1];
    m[2] = v[2];
    v[0] = m[4];
    v[1] = m[5];
    v[2] = m[6];
    func_003F42B0(v, ang);
    m[4] = v[0];
    m[5] = v[1];
    m[6] = v[2];
    v[0] = m[8];
    v[1] = m[9];
    v[2] = m[10];
    func_003F42B0(v, ang);
    m[8] = v[0];
    m[9] = v[1];
    m[10] = v[2];
}
