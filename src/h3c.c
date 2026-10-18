typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00185550(u8 *p)
{
    u8 flag = p[0x1E6];
    f32 k = -23.333332062f;
    f32 q, x;
    if (flag) {
        k = -k;
    }
    q = *(f32 *)(*(u8 **)(p + 0x1CC) + 0x34);
    x = *(f32 *)(p + 0x34);
    q += k;
    if ((q < x && flag) || (!(q < x) && !flag)) {
        p[0x1E6] ^= 1;
    }
    *(s16 *)(p + 0x140) = p[0x1E6];
}
