typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_001757E0(u8 *, int, int);

void residual_001920B0(u8 *p)
{
    p[6]++;
    *(s16 *)(p + 0x1C) = 16;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x5C) = 0xC17D5555;
    *(u32 *)(p + 0x68) = 0x3EA00000;
    if (p[0x1E6]) {
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
    }
    func_001757E0(p, 2, 4);
}
