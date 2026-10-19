typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef float f32;

extern s32 func_00175700(u8 *);

void func_002C6B10(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x161) != 0) {
        p[6]++;
        *(f32 *)(p + 0x5C) = p[0x1E6] ? 14.166666f : -14.166666f;
        *(f32 *)(p + 0x68) = p[0x1E6] ? -0.7291666f : 0.7291666f;
    }
}
