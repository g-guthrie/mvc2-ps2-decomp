typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;

void func_0017D150(u8 *p)
{
    extern s32 func_001884C0(u8 *);
    f32 z = 0.0f;
    s32 t;
    if (func_001884C0(p) != 0)
        return;
    if (p[0x20D] != 2 && p[0x1B7] != 1) {
        t = *(s8 *)(p + 0x1B2);
        if (t != 0 && ((s8)t & 9) == 0) {
            p[0x1B2] = t | 8;
            if ((p[0x1E6] == 0 && *(f32 *)(p + 0x5C) < z) || (p[0x1E6] != 0 && *(f32 *)(p + 0x5C) > z))
                *(f32 *)(p + 0x68) *= 4.0f;
        }
    }
    (*(void (**)(u8 *))(*(u8 **)(p + 0x43C) + 0x3C))(p);
    if (p[0x214] != 0 && p[0x1E4] == 0x22)
        (*(void (**)(u8 *))(*(u8 **)(p + 0x43C) + 0x3C))(p);
}
