typedef unsigned char u8;
typedef signed int s32;
typedef float f32;

extern void func_001757E0(u8 *, int, int);

void residual_00205680(u8 *p)
{
    {
        extern unsigned char D_004D18A0;
        if (D_004D18A0 < 2)
            p[0x13C] = 0;
        else {
            p[6] = p[6] + 1;
            p[0x13C] = 1;
            p[0x20D] = 2;
            *(f32 *)(p + 0x38) = 531.4285278320312f + *(f32 *)(p + 0x38);
            *(s32 *)(p + 0x5C) = 0;
            *(s32 *)(p + 0x68) = 0;
            *(s32 *)(p + 0x60) = 0xC0CDB6DB;
            *(s32 *)(p + 0x6C) = 0;
            func_001757E0(p, 18, 0);
        }
    }
}
