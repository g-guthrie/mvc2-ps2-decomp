/* sb20_b: MW 3.0: ./try30.sh src/sb20_b.c "-O4,p -sdatathreshold 8" */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern u8 *func_003DA750(s32, s32, s32);
extern void func_0033BF80(u8 *);
extern void func_0033B850(s32, u8 *);
extern u32 D_004C283C;
extern V3 D_0045EC60;
extern f32 D_0045EC70[];

void func_0033BE20(void)
{
    u8 *p;
    s32 i;
    double k = 65536.0;
    u32 mask = 0xFFFF;

    if ((p = func_003DA750(0, 6, 1)) != 0) {
        p[0x13C] = 1;
        *(void (**)(u8 *))(p + 0x10) = func_0033BF80;
        *(s16 *)(p + 0xCC) = 0x1A;
        *(u32 *)(p + 0x84) = D_004C283C;
        *(V3 *)(p + 0x34) = D_0045EC60;
        *(u32 *)(p + 0x40) = ((u32)(s32)(0.5 + k * (double)D_0045EC70[0] / 360.0) & mask);
        *(u32 *)(p + 0x44) = ((u32)(s32)(0.5 + k * (double)D_0045EC70[1] / 360.0) & mask);
        *(u32 *)(p + 0xD0) = 0xC07;
        for (i = 0; i < 2; i++)
            func_0033B850(i, p);
        return;
    }
}
