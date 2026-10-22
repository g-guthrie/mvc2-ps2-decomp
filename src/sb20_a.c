/* sb20_a: MW 3.0.3: ./try.sh src/sb20_a.c "-O4,p -sdatathreshold 8" */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern u8 *func_003DA750(s32, s32, s32);
extern void func_00144EF0(u8 *);
extern void func_00170DF0(u32);
extern u32 D_004C2808;
extern V3 D_004B3380;
extern f32 D_004B33A0[3];

void func_00144D50(void)
{
    u8 *p;
    double k = 65536.0;
    u32 mask = 0xFFFF;

    if ((p = func_003DA750(0, 0xD, 1)) != 0) {
        p[0x13C] = 1;
        *(void (**)(u8 *))(p + 0x10) = func_00144EF0;
        *(s16 *)(p + 0xCC) = 6;
        *(u32 *)(p + 0x84) = D_004C2808;
        *(V3 *)(p + 0x34) = D_004B3380;
        *(u32 *)(p + 0x40) = ((u32)(s32)(0.5 + k * (double)D_004B33A0[0] / 360.0) & mask);
        *(u32 *)(p + 0x44) = ((u32)(s32)(0.5 + k * (double)D_004B33A0[1] / 360.0) & mask);
        *(u32 *)(p + 0x48) = ((u32)(s32)(0.5 + k * (double)D_004B33A0[2] / 360.0) & mask);
        *(u32 *)(p + 0xD0) = 0x80F;
        *(s16 *)(p + 0x1C) = 0;
        *(s16 *)(p + 0x1E) = 0;
        func_00170DF0(*(u32 *)(p + 0x84));
    }
}
