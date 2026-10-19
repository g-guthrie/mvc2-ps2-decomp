typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;
typedef unsigned int u32;

extern int func_00175700(u8 *);

void residual_00217BC0(u8 *p)
{
    func_00175700(p);
    if ((s8)p[0x151] == 0) {
        p[6]++;
        if (p[0x214] == 0) {
            *(u32 *)(p + 0x5C) = 0x41A00000;
            *(u32 *)(p + 0x68) = 0xBF4DB6DB;
            *(u32 *)(p + 0x60) = 0x40A00000;
            *(u32 *)(p + 0x6C) = 0xBF092492;
        } else {
            *(u32 *)(p + 0x5C) = 0x41C80000;
            *(u32 *)(p + 0x68) = 0xBF4DB6DB;
            *(u32 *)(p + 0x60) = 0x40D55555;
            *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        }
        if (*(s16 *)(p + 0x140) != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
    }
}
