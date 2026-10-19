typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;

extern u8 D_004D18A0;
extern int func_001757E0(void *, int, int);

void func_00205680(u8 *p)
{
    if (D_004D18A0 < 2)
        p[0x13C] = 0;
    else {
        p[6]++;
        p[0x13C] = 1;
        p[0x20D] = 2;
        *(f32 *)(p + 0x38) += 531.4285f;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0xC0CDB6DB;
        *(u32 *)(p + 0x6C) = 0;
        func_001757E0(p, 0x12, 0);
    }
}
