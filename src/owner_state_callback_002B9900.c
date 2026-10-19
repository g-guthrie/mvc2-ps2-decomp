typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

extern s32 func_00175700(u8 *);

void func_002B9900(u8 *p)
{
    func_00175700(p);
    if (*(signed char *)(p + 0x151) == 0) {
        p[6]++;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        *(f32 *)(p + 0x5C) = p[0x1E6] ? 16.666666f : -16.666666f;
        *(s16 *)(p + 0x1C) = 0x1E;
    }
}
