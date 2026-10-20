typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern s32 D_004B7270[];

void func_00235C40(u8 *p, s32 idx)
{
    f32 k1 = 1.6666666269302368f;
    f32 k2 = 65536.0f;
    f32 k3 = 2.142857074737549f;
    u8 *r = (u8 *)D_004B7270 + (idx << 5);
    r += p[0x1B7] << 4;

    *(f32 *)(p + 0x5C) = k1 * (f32)*(s32 *)(r + 0) / k2;
    *(f32 *)(p + 0x68) = k1 * (f32)*(s32 *)(r + 4) / k2;
    *(f32 *)(p + 0x60) = k3 * (f32)*(s32 *)(r + 8) / k2;
    *(f32 *)(p + 0x6C) = k3 * (f32)*(s32 *)(r + 12) / k2;
    if (*(s16 *)(p + 0x140) != 0) {
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
    }
}
