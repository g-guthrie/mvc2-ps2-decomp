/* Create the scene object from its separate position, angle and speed data. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern u8 *func_003DA750(s32, s32, s32);
extern void func_00145ED0(u8 *);
extern void func_00145560(u8 *);
extern u32 D_004C2808;
extern V3 D_004B33C0;
extern f32 data_f32_004B33D8[3];
extern f32 data_f32_004B3414[1] __attribute__((section(".data")));

void func_001453B0(void)
{
    u8 *p;
    double k = 65536.0;
    u32 mask = 0xFFFF;

    if ((p = func_003DA750(0, 0xD, 0)) != 0) {
        p[0x13C] = 1;
        *(void (**)(u8 *))(p + 0x10) = func_00145ED0;
        *(s16 *)(p + 0xCC) = 8;
        *(u32 *)(p + 0x84) = D_004C2808;
        *(V3 *)(p + 0x34) = D_004B33C0;
        *(u32 *)(p + 0x40) = ((u32)(s32)(0.5 + k * (double)data_f32_004B33D8[0] / 360.0) & mask);
        *(u32 *)(p + 0x44) = ((u32)(s32)(0.5 + k * (double)data_f32_004B33D8[1] / 360.0) & mask);
        *(u32 *)(p + 0x48) = ((u32)(s32)(0.5 + k * (double)data_f32_004B33D8[2] / 360.0) & mask);
        *(u32 *)(p + 0xD0) = 0x80F;
        *(s16 *)(p + 0x1C) = 0;
        *(s16 *)(p + 0x1E) = 0;
        *(f32 *)(p + 0x5C) = data_f32_004B3414[0];
        func_00145560(p);
    }
}
