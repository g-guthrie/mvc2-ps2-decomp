typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00175700(u8 *);

void func_002C1E80(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        p[6]++;
        *(s16 *)(p + 0x1C) = 0x14;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        *(f32 *)(p + 0x5C) = p[0x1E6] ? 15.833333f : -15.833333f;
        *(f32 *)(p + 0x68) = p[0x1E6] ? -0.3125f : 0.3125f;
    }
}
