typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef float f32;
typedef struct { f32 x, y, z; } V3;
void func_001CB680(u8 *p, u8 *o)
{
    s32 n;
    u32 *d, *s;
    p[4]++;
    s = (u32 *)(o + 236);
    d = (u32 *)(p + 236);
    for (n = 49; n > 0; n--) *d++ = *s++;
    p[316] = 1;
    p[2] = o[2];
    p[1] = o[1];
    *(f32 *)(p + 80) = *(f32 *)(o + 80);
    *(f32 *)(p + 84) = *(f32 *)(o + 84);
    p[439] = o[439];
    p[440] = o[440];
    *(s8 *)(p + 48) = *(s8 *)(o + 48);
    *(V3 *)(p + 80) = *(V3 *)(o + 80);
    *(s8 *)(p + 36) = *(s8 *)(o + 36);
}
