typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern f32 D_004442D0[];

void residual_0014E0FC(u8 *p)
{
    asm { nop }
    if (*(u32 *)(p + 0xDC) != 0) {
        p[0x13C] = 1;
        *(u32 *)(p + 0x74) = 0;
        *(s16 *)(p + 0x1C) = 10;
        if (p[4] == 1) {
            *(f32 *)(p + 0x38) = 3.3399999141693115f + D_004442D0[0];
            *(u32 *)(p + 0x60) = 0xBEAB020Cu;
            *(s16 *)(p + 0x1E) = -1;
        } else {
            *(f32 *)(p + 0x38) = D_004442D0[2] - 3.3399999141693115f;
            *(u32 *)(p + 0x60) = 0x3EAB020Cu;
            *(s16 *)(p + 0x1E) = 3;
        }
    } else {
        p[0x13C] = 1;
        *(s16 *)(p + 0x1C) = 10;
        if (p[4] == 1)
            *(u32 *)(p + 0x60) = 0xBEAB020Cu;
        else
            *(u32 *)(p + 0x60) = 0x3EAB020Cu;
    }
    {
        u32 t = p[5];
        p[5] = (u8)(t + 1);
    }
}
