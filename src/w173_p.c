typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_002A48D0(u8 *p)
{
    extern int func_00175700(u8 *);
    f32 v, a, z = 0.0f;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        v = (f32)(u32)p[0x15B];
        if (v != z) {
            if (p[0x1E6] == 0) v = -v;
            *(f32 *)(p + 0x34) += v;
        }
    } else {
        p[6]++;
        p[0x151] = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x6C) = 0;
        if (p[0x1E6] != 0) v = 8.333333015f; else v = -8.333333015f;
        *(f32 *)(p + 0x5C) = v;
        if (p[0x1E6] != 0) a = 1.25f; else a = -1.25f;
        *(f32 *)(p + 0x68) = a;
        *(u32 *)(p + 0x60) = 0x41AD5555;
        *(s16 *)(p + 0x1C) = 0x28;
    }
}
