/* Metrowerks 3.0: ./try.sh src/grok_go_16af10.c "-O4,p -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s32 func_0016AF10(u8 *p, u8 *q, s16 *a, s16 *b)
{
    s16 h0;
    f32 c;
    f32 f2;
    f32 f3;
    s32 ret;
    h0 = a[0];
    if (h0 == 0)
        return 1;
    c = 1.6666666269302368164f;
    f2 = *(f32 *)(p + 0x34) + c * (f32)a[2];
    f3 = c * (f32)b[0];
    if (*(s16 *)(q + 0x140) != 0)
        f3 = -f3;
    f3 = f3 + *(f32 *)(q + 0x34);
    f3 = f2 - f3;
    if (f3 < 0.0f)
        f3 = -f3;
    ret = 1;
    if (f3 >= (c * (f32)b[1] + c * (f32)h0))
        ret = 0;
    return ret;
}
