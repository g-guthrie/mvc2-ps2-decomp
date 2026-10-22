/* Create the scene object from its separate position, angle and speed data. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern u8 *func_003DA750(s32, s32, s32);
extern void func_0033AB50(u8 *);
extern s32 D_004C283C;
extern V3 D_0045EB38;
extern f32 D_0045EB48[];
extern f32 D_0045EB4C[];
extern f32 D_0045EB50[];

void func_0033ABD0(void)
{
    u8 *p;
    double k = 65536.0;
    u32 mask = 0xFFFF;

    if ((p = func_003DA750(0, 6, 1)) != 0) {
        p[0x13C] = 1;
        *(void (**)(u8 *))(p + 0x10) = func_0033AB50;
        *(s16 *)(p + 0xCC) = 7;
        *(s32 *)(p + 0x84) = D_004C283C;
        *(V3 *)(p + 0x34) = D_0045EB38;
        *(u32 *)(p + 0x40) = ((u32)(s32)(0.5 + k * (double)D_0045EB48[0] / 360.0) & mask);
        *(u32 *)(p + 0x44) = ((u32)(s32)(0.5 + k * (double)D_0045EB4C[0] / 360.0) & mask);
        *(u32 *)(p + 0x48) = ((u32)(s32)(0.5 + k * (double)D_0045EB50[0] / 360.0) & mask);
        *(s32 *)(p + 0xD0) = 0x80D;
    }
}
