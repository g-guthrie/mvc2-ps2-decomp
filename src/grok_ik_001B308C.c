typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

void residual_001B308C(u8 *p)
{
    u8 *q;
    f32 vx;
    f32 vz;
    asm { nop }
    q = *(u8 **)(p + 0x18);
    if (*(s8 *)(q + 0x151) == 1) {
        unsigned int t = p[5];
        p[5] = t + 1;
        if (*(s16 *)(p + 0x140))
            vx = -15.833333015441895f;
        else
            vx = 15.833333015441895f;
        *(f32 *)(p + 0x5C) = vx;
        if (*(s16 *)(p + 0x140))
            vz = -0.3125f;
        else
            vz = 0.3125f;
        *(f32 *)(p + 0x68) = vz;
        *(u32 *)(p + 0x60) = 0x40CDB6DB;
        *(u32 *)(p + 0x6C) = 0xBF092492;
        *(s16 *)(p + 0x1C) = 0x1E;
    }
}
