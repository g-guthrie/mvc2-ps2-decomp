typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_002641D0(u8 *);

void residual_00264130(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        p[6]++;
        *(u32 *)(p + 0x5C) = 0x417D5555;
        *(u32 *)(p + 0x68) = 0xBEA00000;
        *(u32 *)(p + 0x60) = 0x40CDB6DB;
        *(u32 *)(p + 0x6C) = 0xBF092492;
        if (*(s16 *)(p + 0x140)) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
        *(s16 *)(p + 0x1C) = 16;
        func_002641D0(p);
    }
}
