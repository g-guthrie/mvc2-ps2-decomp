typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;
typedef unsigned int u32;

extern int func_00175700(u8 *);

void residual_00317EC0(u8 *p)
{
    func_00175700(p);
    if ((s8)p[0x151] == 0) {
        p[6]++;
        *(f32 *)(p + 0x60) = 0;
        *(f32 *)(p + 0x6C) = 0;
        *(s16 *)(p + 0x1C) = 0xA;
        *(u32 *)(p + 0x5C) = 0x417D5555;
        *(u32 *)(p + 0x68) = 0xBEA00000;
        if (p[0x1E6]) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
    }
}
