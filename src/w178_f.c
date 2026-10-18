typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004C2A42[2];
extern u8 D_004C2A43[2];
void func_0033FCE0(u8 *p) {
    switch (p[0x20]) {
    case 0:
        *(u32 *)(p + 0x40) = (u16)(0.5 + 65536.0 * (double)(D_004C2A42[0] * 3 * 2) / 360.0);
        break;
    case 1:
        *(u32 *)(p + 0x40) = (u16)(0.5 + 65536.0 * (double)((D_004C2A42[0] + (D_004C2A43[0] % 12) * 60) / 2) / 360.0);
        break;
    }
}

