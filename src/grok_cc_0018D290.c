typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef float f32;

extern s32 func_00118FA8(f32);
extern void func_0018D0C0(u8 *);

void func_0018D290(u8 *p)
{
    f32 saved_x;
    f32 saved_y;
    f32 tmp;
    if (p[5] != 0)
        return;
    if (*(s8 *)(p + 0x1B4) != 0)
        return;
    if (*(s8 *)(p + 0x296) == 0)
        goto done;
    p[0x296] = (u8)(*(s8 *)(p + 0x296) - 1);
    tmp = *(f32 *)(p + 0x2A4);
    if (func_00118FA8(tmp)) {
        saved_x = *(f32 *)(p + 0x5C);
        saved_y = *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x5C) = tmp;
        *(f32 *)(p + 0x68) = *(f32 *)(p + 0x2A8);
        func_0018D0C0(p);
        *(f32 *)(p + 0x2A4) = *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x2A8) = *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x5C) = saved_x;
        *(f32 *)(p + 0x68) = saved_y;
    }
done:
    return;
}
