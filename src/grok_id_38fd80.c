typedef unsigned char u8;
typedef float f32;

void residual_0038FD80(u8 *p)
{
    if ((*(u8 **)(p + 0x18))[0x1E4] != 0x14)
        p[0x22] = 1;
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) < *(f32 *)(*(u8 **)(p + 0x18) + 0x430)) {
        p[6]++;
        *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x430);
    }
}
