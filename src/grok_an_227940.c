typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;

extern u8 D_004D18A0;
extern void func_001757E0(u8 *, int, int);

void residual_00227940(u8 *p)
{
    p[0x13C] = 0;
    p[0x159] = 255;
    if (D_004D18A0 >= 2) {
        f32 f2, f3;
        *(u32 *)&f3 = 0x41A00000;
        *(u32 *)&f2 = 0xC4200000;
        p[6]++;
        p[0x13C] = 1;
        p[0x20D] = 2;
        *(u16 *)(p + 0x1C) = 0x20;
        *(f32 *)(p + 0x64) = *(f32 *)(p + 0x34);
        if (*(s16 *)(p + 0x140)) {
            f2 = -f2;
            f3 = -f3;
        }
        *(f32 *)(p + 0x34) += f2;
        *(f32 *)(p + 0x5C) = f3;
        *(u32 *)(p + 0x68) = 0;
        {
            f32 t;
            *(u32 *)&t = 0x44092492;
            *(f32 *)(p + 0x38) = t + *(f32 *)(p + 0x430);
        }
        *(u32 *)(p + 0x60) = 0xC1892492;
        *(u32 *)(p + 0x6C) = 0;
        func_001757E0(p, 18, 0);
    }
}
