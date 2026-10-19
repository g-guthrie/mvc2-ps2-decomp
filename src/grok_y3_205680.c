typedef unsigned char u8;
typedef signed int s32;
typedef float f32;

extern void func_001757E0(u8 *, int, int);
extern u8 D_004D18A0;

void residual_00205680(u8 *p)
{
    int z = 0;

    if (D_004D18A0 < 2)
        p[0x13C] = 0;
    else {
        p[6]++;
        p[0x13C] = 1;
        p[0x20D] = 2;
        *(f32 *)(p + 0x38) += 531.4285278320312f;
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x60) = (s32)0xC0CDB6DB;
        *(s32 *)(p + 0x6C) = 0;
        func_001757E0(p, 18, z);
    }
}
