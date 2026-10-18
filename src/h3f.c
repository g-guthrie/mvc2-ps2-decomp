typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *func_003DCFE0(u32, s32);
extern u8 *func_003DD030(u8 *);
u8 *func_003DE7E0(u8 *p)
{
    u8 *s0;
    u8 *s1;
    u8 *d;
    u32 i;
    u8 *src;
    s1 = *(u8 **)(p + 8);
    s0 = func_003DCFE0(*(u32 *)(s1 + 0xC), 3);
    d = func_003DD030(s0);
    src = s1;
    for (i = 0; i < *(u32 *)(s1 + 0xC); i++) {
        *d++ = *src++;
    }
    return s0;
}
