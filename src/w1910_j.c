typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
u8 *func_003F1B10(u8 *a, s32 n)
{
    extern u32 *func_003F1F00(void *file);
    extern u8 *func_003F1F10(u8 *, s32);
    u8 *p;
    s32 i;
    func_003F1F00(a);
    p = func_003F1F10(a, 2);
    if (p == 0) return 0;
    if (*(u32 *)(p + 4) <= (u32)n) return 0;
    p += 0xC;
    for (i = 0; i < n; i++) {
        p += *(s32 *)(p + 8);
    }
    return p + 0xC;
}
